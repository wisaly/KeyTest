#include "QXml.h"
#include <QFile>
#include <QTextStream>

QXml::QXml(void)
{
}

QXml::~QXml(void)
{
	//Close();
}

bool QXml::Open( QString strXmlFilePath )
{
	QFile file(strXmlFilePath);
	if (!file.open(QFile::ReadOnly | QFile::Text))
	{
		return false;
	}

	if (!m_doc.setContent(&file,false))
	{
		return false;
	}

	m_strFilePath = strXmlFilePath;

	return true;
}

bool QXml::Create( QString strXmlFilePath,QString strRootName )
{
	if(QFile::exists(strXmlFilePath))
	{
		return false;
	}
	QFile file(strXmlFilePath);
	file.open(QFile::WriteOnly);
	file.close();

	m_doc.clear();
	m_strFilePath = strXmlFilePath;

	QDomNode node = m_doc.createProcessingInstruction("xml","version=\"1.0\"");
	m_doc.appendChild(node);
	node = m_doc.createElement(strRootName);
	m_doc.appendChild(node);

	return Save();
}

QXmlNodePtr QXml::GetRoot( void )
{
	Q_ASSERT(!m_doc.isNull());

	QDomElement element = m_doc.documentElement();

	// 不存在 则 创建 
	if(element.isNull())
	{ 
		element = m_doc.createElement("xmlRoot");
		Q_ASSERT(!element.isNull()); 

		m_doc.appendChild(element); 
	} 

	QXmlNodePtr pNode(new QXmlNode(element));

	return pNode; 
}

bool QXml::Save( QString strFilePath /*= ""*/ )
{
	Q_ASSERT(!m_doc.isNull());

	if( !strFilePath.isEmpty() ) 
	{
		m_strFilePath = strFilePath;
	}
	
	QFile f(m_strFilePath);
	if(!f.open(QFile::WriteOnly | QFile::Text))
		return false;

	QTextStream out(&f);

	out.setCodec("UTF-8"); //中文编码

	m_doc.save(out,4,QDomDocument::EncodingFromDocument);

	return true; 
}

//QXmlNodePtr QXml::SelectSingleNode( QString strPath )
//{
//	Q_ASSERT(!m_doc.isNull());
//
//	QDomNode node = m_doc.namedItem(strPath);
//
//	QXmlNodePtr pNode ( new QXmlNode(node) ); 
//
//	return pNode; 
//}
//
//QXmlNodesPtr QXml::SelectNodes( QString strPath )
//{
//	Q_ASSERT(!m_doc.isNull());
//
//	QDomNodeList nodeList = m_doc.elementsByTagName(strPath);
//
//	QXmlNodesPtr pNodes ( new QXmlNodes(nodeList) ); 
//
//	return pNodes; 
//}
#include "QXmlNode.h"
#include "QXmlNodes.h" 

// 构造函数
QXmlNode::QXmlNode( QDomNode node )
{
	m_node = node;
}

QXmlNode::QXmlNode(void)
{
}

QXmlNode::QXmlNode( QXmlNode & refNode )
{
	m_node = refNode.m_node; 
}

// 析构函数
QXmlNode::~QXmlNode(void)
{
}

QXmlNodePtr QXmlNode::operator=( QXmlNodePtr pNode )
{
	m_node = pNode->m_node; 
	return pNode; 
}

QXmlNode & QXmlNode::operator=( QXmlNode & refNode )
{
	m_node = refNode.m_node; 
	return (*this); 
}

bool QXmlNode::IsNull( void )
{
	return m_node.isNull(); 
}

QXmlNodePtr QXmlNode::GetChild( QString strName )
{
	Q_ASSERT(!m_node.isNull());

	QDomNode childNode = m_node.namedItem(strName);
	
	if (childNode.isNull())
	{
		return AppendChild(strName);
	}

	QXmlNodePtr pChild( new QXmlNode(childNode) ); 

	return pChild; 
}

QXmlNodePtr QXmlNode::AppendChild( QString strName )
{
	Q_ASSERT(!m_node.isNull());

	QDomDocument doc = m_node.ownerDocument();
	Q_ASSERT(!doc.isNull());

	QDomNode childNode = doc.createElement(strName);
	Q_ASSERT(!childNode.isNull());

	m_node.appendChild(childNode);

	QXmlNodePtr pChild( new QXmlNode(childNode) ); 

	return pChild; 
}

bool QXmlNode::_getValue( QString &strValue )
{
	Q_ASSERT( !m_node.isNull() ); 

	if( HasChildren() ) 
	{ 
		// 下面有子结点 
		Q_ASSERT( false ); 
		return false; 
	} 

	strValue = m_node.nodeValue();

	return true; 
}

bool QXmlNode::_setValue( QString &strValue )
{
	Q_ASSERT( !m_node.isNull() ); 

	if( HasChildren() ) 
	{ 
		// 下面有子结点 
		Q_ASSERT( false ); 
		return false; 
	} 

	m_node.setNodeValue(strValue);

	return true; 
}

QString QXmlNode::GetName( void )
{
	Q_ASSERT( !m_node.isNull() ); 

	QString strRet = m_node.nodeName();

	return strRet; 
}

QString QXmlNode::GetAttribute( QString strName, QString strDefault /*= ""*/ )
{
	Q_ASSERT( !m_node.isNull() ); 

	QDomNamedNodeMap nodemap = m_node.attributes();

	QDomNode node = nodemap.namedItem(strName);


	QString strValue; 
	if( node.isNull() ) 
	{ 
		strValue = strDefault; 
		SetAttribute( strName, strValue);		 
	} 
	else 
	{ 
		strValue = node.nodeValue();
	} 

	return strValue; 
}

bool QXmlNode::SetAttribute( QString strName, QString strValue )
{
	Q_ASSERT( !m_node.isNull() ); 

	QDomElement element = m_node.toElement();
	element.setAttribute(strName,strValue);

	return true; 
}

bool QXmlNode::GetAttribute( QString strName,bool bDefault )
{
	QString strValue = GetAttribute(strName);

	return _stringToBool(strValue,bDefault);
}

bool QXmlNode::SetAttribute( QString strName,bool bValue )
{
	return SetAttribute(strName,_boolToString(bValue));
}

int QXmlNode::GetAttribute( QString strName,int nDefault )
{
	QString strValue = GetAttribute(strName);

	bool bOk;
	int nRet = strValue.toInt(&bOk);
	
	return bOk ? nRet : nDefault;
}

bool QXmlNode::SetAttribute( QString strName,int nValue )
{
	QString strValue; 

	strValue.sprintf("%d",nValue);

	return SetAttribute(strName,strValue);
}

 QColor QXmlNode::GetAttribute( QString strName,QColor crDefault )
 {
 	int nVal = GetAttribute(strName,int(-1));
 
 	if (nVal == -1)
 	{
 		return crDefault;
 	}
 	
 	return QColor(nVal & 255, nVal >> 8 & 255, nVal >> 16 & 255);
 }
 bool QXmlNode::SetAttribute( QString strName,QColor crValue )
 {
 	int nVal = (((uint)crValue.blue()<< 16) | (ushort)(((ushort)crValue.green()<< 8) | crValue.red()));
 
 	return SetAttribute(strName,nVal);
 }
 
 QFont QXmlNode::GetAttribute( QString strName,QFont fontDefault )
 {
 	QFont fontRet;
 	if(!fontRet.fromString(GetAttribute(strName)))
 	{
 		return fontDefault;
 	}
 
 	return fontRet;
 }
 
 bool QXmlNode::SetAttribute( QString strName,QFont fontValue )
 {
 	return SetAttribute(strName,fontValue.toString());
 }

bool QXmlNode::DelAttribute( QString strName )
{
	Q_ASSERT( !m_node.isNull() );

	QDomNamedNodeMap nodemap = m_node.attributes();

	nodemap.removeNamedItem(strName);

	return true; 
}

bool QXmlNode::HasChildren( void )
{
	Q_ASSERT( !m_node.isNull() );

	bool bHasChildren = FALSE; 

	QDomNode node;
	QDomNodeList nodelist = m_node.childNodes();

	for (uint i = 0; i < nodelist.length(); i++)
	{
		node = nodelist.item(i);

		if(node.nodeType() == QDomNode::ElementNode)
		{
			bHasChildren = true;
			break;
		}
	}

	return bHasChildren; 
}

bool QXmlNode::Remove( void )
{
	Q_ASSERT( !m_node.isNull() );

	QDomNode node = m_node.parentNode();

	node.removeChild(m_node);

	return TRUE; 
}

bool QXmlNode::RemoveChildren( void )
{
	Q_ASSERT( !m_node.isNull() );

	QDomNode node;
	QDomNodeList nodelist = m_node.childNodes();

	for (int i = nodelist.length() - 1; i >= 0; i--)
	{
		node = nodelist.item(i);

		if(node.nodeType() == QDomNode::ElementNode)
		{
			m_node.removeChild(node);
		}
	}

	return true;
}

QXmlNodesPtr QXmlNode::GetChildren()
{
	Q_ASSERT( !m_node.isNull() );

	QDomNodeList nodelist = m_node.childNodes();

	QXmlNodesPtr pNodes(new QXmlNodes(nodelist)); 

	return pNodes; 
}

QString QXmlNode::GetString( QString strDefault /*= ""*/ )
{
	QString strValue; 
	_getValue(strValue); 

	if( strValue.isEmpty() && 
		!strDefault.isEmpty() ) 
	{ 
		strValue = strDefault; 
		_setValue(strValue); 
	} 

	return strValue; 
}

bool QXmlNode::GetBool( bool bDefault /*= false */ )
{
	QString strValue; 
	_getValue(strValue); 

	return _stringToBool(strValue,bDefault);
}

int QXmlNode::GetInt( int nDefault /*= 0 */ )
{
	QString strValue; 
	_getValue(strValue); 

	if(strValue.isEmpty())
	{ 
		SetInt(nDefault);
	} 

	return strValue.toInt();
}

double QXmlNode::GetFloat( double fDefault /*= 0.0f */ )
{
	QString strValue; 
	_getValue(strValue); 

	if(strValue.isEmpty()) 
	{ 
		SetFloat(fDefault);
	} 

	return strValue.toDouble();
}

bool QXmlNode::SetString( QString strValue )
{
	return _setValue(strValue);
}

bool QXmlNode::SetBool( bool bValue )
{ 
	return _setValue(_boolToString(bValue)); 
}

bool QXmlNode::SetInt( int nValue )
{
	QString strValue; 

	strValue.sprintf("%d",nValue);
	return _setValue(strValue); 
}

bool QXmlNode::SetFloat( double fValue )
{
	QString strValue; 

	strValue.sprintf("%f",fValue);
	return _setValue(strValue); 
}

bool QXmlNode::_stringToBool( QString strValue,bool bDefault )
{
	if((strValue.toLower() == "true") || (strValue == "1"))
	{ 
		return true; 
	} 
	else if((strValue.toLower() == "false") || (strValue == "0"))
	{ 
		return false; 
	} 
	else
	{
		return bDefault;
	}
}

QString QXmlNode::_boolToString( bool bValue )
{
	return bValue ? "true" : "false";
}
#include "QXmlNodes.h"

QXmlNodes::QXmlNodes( QDomNodeList nodeList )
{
	m_nodeList = nodeList; 

}

QXmlNodes::QXmlNodes( QXmlNodes & refNodes )
{
	m_nodeList = refNodes.m_nodeList; 

}

QXmlNodes::QXmlNodes(void)
{
}

QXmlNodes::~QXmlNodes(void)
{
}

QXmlNodesPtr QXmlNodes::operator=( QXmlNodesPtr pNodes )
{
	m_nodeList = pNodes->m_nodeList; 
	return pNodes; 
}

QXmlNodes & QXmlNodes::operator=( QXmlNodes & refNodes )
{
	m_nodeList = refNodes.m_nodeList; 
	return (*this); 
}

int QXmlNodes::GetCount( void )
{
	int nCount = 0; 
	QDomNode node; 

	for( uint i = 0; i < m_nodeList.length(); i++) 
	{ 
		node = m_nodeList.item(i);

		if (node.nodeType() == QDomNode::ElementNode)
		{
			nCount ++;
		}
	} 

	return nCount;
}

QXmlNodePtr QXmlNodes::GetItem( int nIndex )
{
	Q_ASSERT( nIndex >= 0 && nIndex < GetCount() ); 

	int nCount = 0;

	QDomNode node;

	QXmlNodePtr pNode ( new QXmlNode() ); 

	for( uint i = 0; i < m_nodeList.length(); i++) 
	{ 
		node = m_nodeList.item(i);

		if (node.nodeType() == QDomNode::ElementNode)
		{
			if( nCount == nIndex ) 
			{ 
				pNode->m_node = node; 

				break;
			} 
			nCount ++;
		}
	} 

	return pNode; 
}

QXmlNodePtr QXmlNodes::GetItem( QString strName )
{
	Q_ASSERT( strName != "" );

	QDomNode node;
	QXmlNodePtr pNode ( new QXmlNode() ); 

	for( uint i = 0; i < m_nodeList.length(); i++) 
	{ 
		node = m_nodeList.item(i);

		QString strFindName = node.nodeName();

		if (strName == strFindName)
		{
			pNode->m_node = node; 
			break;
		}
	}

	return pNode; 
}
QXmlNodePtr QXmlNodes::operator[]( int iIndex )
{
	return GetItem(iIndex); 
}

QXmlNodePtr QXmlNodes::operator[]( QString strName )
{
	return GetItem(strName);
}
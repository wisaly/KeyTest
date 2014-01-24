#pragma once

#include ".\QXmlNode.h" 

class QXmlNodes
{
	friend class QXml; 
	friend class QXmlNode; 
	friend class QXmlNodes; 

public: 
	~QXmlNodes(void); 
	QXmlNodes(void); 
	QXmlNodes( QXmlNodes & refNodes ); 

	QXmlNodesPtr operator = (QXmlNodesPtr pNodes); 
	QXmlNodes & operator = (QXmlNodes & refNodes); 
	QXmlNodePtr operator[] ( int iIndex ); 
	QXmlNodePtr operator[] ( QString strName ); 


	int GetCount(void); 

	QXmlNodePtr GetItem( int nIndex ); 
	QXmlNodePtr GetItem( QString strName ); 

protected: 
	QXmlNodes(QDomNodeList nodeList); 
	QDomNodeList m_nodeList; 
};

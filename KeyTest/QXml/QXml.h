#pragma once
#include <QDomDocument>
#include "QXmlNode.h"
#include "QXmlNodes.h" 

//------------------------------------------------------------------------- 
// Classes Name	    :QXml QXmlNode QXmlNodes 
// Author			:Ma Qiming
// CreateTime       :2012-09-18 
// Memo             :非常牛逼的xml解析库
// Version          :v1.0 
//------------------------------------------------------------------------- 

class QXml
{
public:
	QXml(void);
	~QXml(void);

protected:
	QDomDocument	m_doc;
	QString			m_strFilePath;

public: 
	bool Open(QString strXmlFilePath); 
	bool Create(QString strXmlFilePath,QString strRootName = "xml");
	bool Save(QString strFilePath = ""); 
	//void Close(void); 

	//QString GetLastError(void); 

	QXmlNodePtr GetRoot(void);		 

// 	QXmlNodePtr SelectSingleNode(QString strPath); 
// 	QXmlNodesPtr SelectNodes(QString strPath); 
};

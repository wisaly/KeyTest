#pragma once

#include <QDomNode>
#include <memory> 
#include <QColor>
#include <QFont>

class QXml; 

class QXmlNode; 
typedef std::auto_ptr<QXmlNode>  QXmlNodePtr; 

class QXmlNodes; 
typedef std::auto_ptr<QXmlNodes>  QXmlNodesPtr; 


class QXmlNode
{
	friend class QXml; 
	friend class QXmlNode; 
	friend class QXmlNodes; 
public:
	~QXmlNode(void);

protected:
	QXmlNode(QDomNode node);
	QDomNode m_node;
	bool _getValue(QString &strValue);
	bool _setValue(QString &strValue);
	bool _stringToBool(QString strValue,bool bDefault);
	QString _boolToString(bool bValue);
public: 

	//		_____________
	//______|	构造函数	|___________________________________________________________________ 
	QXmlNode(void); 
	QXmlNode( QXmlNode & refNode ); 

	//		_________________ 
	//______|	重载 = 号	|___________________________________________________________________ 
	QXmlNodePtr operator = ( QXmlNodePtr pNode); 
	QXmlNode & operator = ( QXmlNode & refNode); 



	//		_________________ 
	//______|  获取结点名称	|___________________________________________________________________ 
	QString GetName(void); 



	//		_____________
	//______|	属性操作	|___________________________________________________________________ 
	QString GetAttribute( QString strName, QString strDefault = ""); 
	bool SetAttribute(QString strName, QString strValue); 
	bool SetAttribute(QString strName, char *szValue) 
	{ return SetAttribute(strName,QString(szValue)); }

	bool GetAttribute(QString strName,bool bDefault);
	bool SetAttribute(QString strName,bool bValue);

	int GetAttribute(QString strName,int nDefault);
	bool SetAttribute(QString strName,int nValue);

	QColor GetAttribute(QString strName,QColor crDefault);
	bool SetAttribute(QString strName,QColor crValue);

	QFont GetAttribute(QString strName,QFont fontDefault);
	bool SetAttribute(QString strName,QFont fontValue);


	bool DelAttribute( QString strName ); 
	//		_________________ 
	//______|	子结点操作	|___________________________________________________________________ 
	QXmlNodePtr GetChild(QString strName); 
	QXmlNodePtr AppendChild(QString strName);
	QXmlNodesPtr GetChildren(); 
	bool HasChildren(void); 
	bool RemoveChildren(void); 



	//		_____________
	//______|	删除结点	|___________________________________________________________________ 
	bool Remove(void); 



	//		_____________
	//______|	取值操作	|___________________________________________________________________	 
	QString GetString( QString strDefault = ""); 
	bool GetBool( bool bDefault = false ); 
	int GetInt( int nDefault = 0 ); 
	double GetFloat( double fDefault = 0.0f ); 



	//		_____________
	//______|	赋值操作	|___________________________________________________________________ 
	bool SetString( QString strValue ); 
	bool SetBool( bool bValue ); 
	bool SetInt( int nValue ); 
	bool SetFloat( double fValue ); 

	bool IsNull(void); 
};

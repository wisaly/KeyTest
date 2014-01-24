#pragma once
#include <QThread>
#include <QBitArray>
#include <QStringList>
#include <QMap>

class AccKeys;
class AccKeyNotifier;
// Define accelerate key detect thread
class AccKeyThread : public QThread
{
	Q_OBJECT
public:
	// Interval indicate detect frequency
	AccKeyThread(uint interval = 300);
	~AccKeyThread(void);

	// Indicate virtual key code limit
	enum {COUNT_VK = 256};

	// Singleton pattern instance function
	static AccKeyThread *inst();

signals:
	// Key press signal
	void accKeyPressed(AccKeys keys);

public slots:
	// Stop thread
	void stop();

protected:
	// Thread main function
	void run();
protected:
	bool m_stop;				// Indicate is thread should stop
	uint m_interval;			// Indicate thread detect frequency
	QBitArray m_caredKeys;	// Indicate which key code is cared
};

// Define accelerate key combination
class AccKeys
{
	friend class AccKeyThread;
protected:
	// Construct with combination data
	AccKeys(QBitArray &d) : m_arrData(d) {};
public:
	AccKeys() : m_arrData(AccKeyThread::COUNT_VK) {}
	// Add key to combination
	AccKeys &setKey(int vkey);
	// Is key exist combination
	bool existKey(int vkey);
	// Extract combination to a string separator with specify separator
	QString toString(QString separator = "+");
	
	// Logical equal compare
	bool operator ==(AccKeys &keys) const;
	// Logical Unequal compare
	bool operator !=(AccKeys &keys) const;

	// Parse string to key type
	static AccKeys fromString(QString keys,QString separator = "+");
	// Convert virtual key code to string
	static QString translateVKey(int vkey,QString nullString = "<Invalid>");

protected:
	QBitArray m_arrData;
};

// Define accelerate key notifier
class AccKeyNotifier : public QObject
{
	Q_OBJECT
public:
	AccKeyNotifier(AccKeys keys,QObject *reciever,const char *slot);
	~AccKeyNotifier();

protected slots:
	void on_accKeyPressed(AccKeys keys);

signals:
	void accPressed();
protected:
	AccKeys m_accKeys;
	QString m_slotName;
	static QList<AccKeyNotifier*> m_instances;
};

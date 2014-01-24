#include "keytest.h"
#include <QDebug>
#include "QXml\QXml.h"
#include <windows.h>
#define CONFIG_FILE QApplication::applicationDirPath() + "/config.xml"

KeyTest::KeyTest(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	ui.setupUi(this);

	ui.tableAccs->horizontalHeader()->setResizeMode(QHeaderView::ResizeToContents);

	connect(
		AccKeyThread::inst(),SIGNAL(accKeyPressed(AccKeys)),
		this,SLOT(on_accPressed(AccKeys)));

	loadConfig();

	new AccKeyNotifier(
		AccKeys().setKey(VK_CONTROL).setKey('4'),
		this,
		SLOT(close()));
}

KeyTest::~KeyTest()
{
}

void KeyTest::on_accPressed( AccKeys keys )
{
	QString strKeys = keys.toString();

	ui.editAccKeys->setText(strKeys);

	if (strKeys.isEmpty())
	{
		ui.lblKeyTriggered->setText("");
	}
	else
	{
		for (int i = 0;i < ui.tableAccs->rowCount();i ++)
		{
			QString strAccKeys = ui.tableAccs->item(i,0)->text();
			QString strKeyName = ui.tableAccs->item(i,1)->text();
			
			if (keys == AccKeys::fromString(strAccKeys))
			{
				ui.lblKeyTriggered->setText(strKeyName);
			}
		}
	}
}

void KeyTest::on_btnAdd_clicked()
{
	if (!ui.editAccKeys->text().isEmpty())
	{
		int nRow = ui.tableAccs->rowCount();
		ui.tableAccs->insertRow(nRow);
		ui.tableAccs->setItem(nRow,0,new QTableWidgetItem(ui.editAccKeys->text()));
		ui.tableAccs->setItem(nRow,1,new QTableWidgetItem(ui.editKeyName->text()));

		saveConfig();
	}
}

void KeyTest::saveConfig()
{
	QXml xml;
	if(!xml.Open(CONFIG_FILE))
	{
		xml.Create(CONFIG_FILE,"KeyTestConfig");
	}

	xml.GetRoot()->RemoveChildren();
	for (int i = 0;i < ui.tableAccs->rowCount();i ++)
	{
		QString strAccKeys = ui.tableAccs->item(i,0)->text();
		QString strKeyName = ui.tableAccs->item(i,1)->text();
		QXmlNodePtr pAccKeys = xml.GetRoot()->AppendChild("Item");
		pAccKeys->SetAttribute("AccKey",strAccKeys);
		pAccKeys->SetAttribute("KeyName",strKeyName);
	}

	xml.Save();
}

void KeyTest::on_btnDel_clicked()
{
	if(ui.tableAccs->currentRow() > 0)
	{
		ui.tableAccs->removeRow(ui.tableAccs->currentRow());
		saveConfig();
	}
}

void KeyTest::loadConfig()
{
	QXml xml;
	if(!xml.Open(CONFIG_FILE))
	{
		return;
	}

	QXmlNodesPtr pNodes = xml.GetRoot()->GetChildren();
	for (int i = 0;i < pNodes->GetCount();i ++)
	{
		QString strAccKeys = (*pNodes)[i]->GetAttribute("AccKey");
		QString strKeyName = (*pNodes)[i]->GetAttribute("KeyName");
		ui.tableAccs->insertRow(i);
		ui.tableAccs->setItem(i,0,new QTableWidgetItem(strAccKeys));
		ui.tableAccs->setItem(i,1,new QTableWidgetItem(strKeyName));
	}
}

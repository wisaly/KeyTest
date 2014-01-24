#ifndef KEYTEST_H
#define KEYTEST_H

#include <QtGui/QMainWindow>
#include "ui_keytest.h"
#include <Qt>
#include <QKeyEvent>
#include <QAction> 
#include "AccKeyNotifier.h"

class KeyTest : public QMainWindow
{
	Q_OBJECT

public:
	KeyTest(QWidget *parent = 0, Qt::WFlags flags = 0);
	~KeyTest();


private:
	Ui::KeyTestClass ui;
	void loadConfig();
	void saveConfig();

private slots:
	void on_accPressed(AccKeys keys);
	void on_btnAdd_clicked();
	void on_btnDel_clicked();
};

#endif // KEYTEST_H

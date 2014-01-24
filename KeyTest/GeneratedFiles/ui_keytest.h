/********************************************************************************
** Form generated from reading UI file 'keytest.ui'
**
** Created: Thu Dec 12 15:05:54 2013
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KEYTEST_H
#define UI_KEYTEST_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QTableWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_KeyTestClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QLabel *lblKeyTriggered;
    QTableWidget *tableAccs;
    QLineEdit *editAccKeys;
    QLineEdit *editKeyName;
    QPushButton *btnAdd;
    QPushButton *btnDel;

    void setupUi(QMainWindow *KeyTestClass)
    {
        if (KeyTestClass->objectName().isEmpty())
            KeyTestClass->setObjectName(QString::fromUtf8("KeyTestClass"));
        KeyTestClass->resize(447, 733);
        centralWidget = new QWidget(KeyTestClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        lblKeyTriggered = new QLabel(centralWidget);
        lblKeyTriggered->setObjectName(QString::fromUtf8("lblKeyTriggered"));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        font.setPointSize(72);
        font.setBold(true);
        font.setWeight(75);
        lblKeyTriggered->setFont(font);
        lblKeyTriggered->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lblKeyTriggered, 0, 0, 1, 4);

        tableAccs = new QTableWidget(centralWidget);
        if (tableAccs->columnCount() < 2)
            tableAccs->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableAccs->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableAccs->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        tableAccs->setObjectName(QString::fromUtf8("tableAccs"));
        tableAccs->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableAccs->setSelectionMode(QAbstractItemView::SingleSelection);
        tableAccs->setSelectionBehavior(QAbstractItemView::SelectRows);

        gridLayout->addWidget(tableAccs, 1, 0, 1, 4);

        editAccKeys = new QLineEdit(centralWidget);
        editAccKeys->setObjectName(QString::fromUtf8("editAccKeys"));
        editAccKeys->setReadOnly(true);

        gridLayout->addWidget(editAccKeys, 2, 0, 1, 1);

        editKeyName = new QLineEdit(centralWidget);
        editKeyName->setObjectName(QString::fromUtf8("editKeyName"));
        editKeyName->setMaximumSize(QSize(41, 16777215));

        gridLayout->addWidget(editKeyName, 2, 1, 1, 1);

        btnAdd = new QPushButton(centralWidget);
        btnAdd->setObjectName(QString::fromUtf8("btnAdd"));
        btnAdd->setMaximumSize(QSize(51, 16777215));

        gridLayout->addWidget(btnAdd, 2, 2, 1, 1);

        btnDel = new QPushButton(centralWidget);
        btnDel->setObjectName(QString::fromUtf8("btnDel"));
        btnDel->setMaximumSize(QSize(51, 16777215));

        gridLayout->addWidget(btnDel, 2, 3, 1, 1);

        KeyTestClass->setCentralWidget(centralWidget);

        retranslateUi(KeyTestClass);

        QMetaObject::connectSlotsByName(KeyTestClass);
    } // setupUi

    void retranslateUi(QMainWindow *KeyTestClass)
    {
        KeyTestClass->setWindowTitle(QApplication::translate("KeyTestClass", "KeyTest", 0, QApplication::UnicodeUTF8));
        lblKeyTriggered->setText(QApplication::translate("KeyTestClass", "\341\203\232(\342\225\271\342\227\241\342\225\271\341\203\232)", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableAccs->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("KeyTestClass", "Accelerator", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableAccs->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("KeyTestClass", "Key Name", 0, QApplication::UnicodeUTF8));
        btnAdd->setText(QApplication::translate("KeyTestClass", "Add", 0, QApplication::UnicodeUTF8));
        btnDel->setText(QApplication::translate("KeyTestClass", "Del", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class KeyTestClass: public Ui_KeyTestClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KEYTEST_H

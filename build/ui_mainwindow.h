/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLineEdit *lineEditHost;
    QLineEdit *lineEditTopic;
    QLineEdit *lineEditMessage;
    QTextEdit *editLog;
    QPushButton *buttonConnect;
    QPushButton *buttonSubscribe;
    QPushButton *buttonPublish;
    QSpinBox *spinBoxPort;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        lineEditHost = new QLineEdit(centralwidget);
        lineEditHost->setObjectName(QString::fromUtf8("lineEditHost"));
        lineEditHost->setGeometry(QRect(180, 50, 261, 25));
        lineEditTopic = new QLineEdit(centralwidget);
        lineEditTopic->setObjectName(QString::fromUtf8("lineEditTopic"));
        lineEditTopic->setGeometry(QRect(180, 140, 281, 25));
        lineEditMessage = new QLineEdit(centralwidget);
        lineEditMessage->setObjectName(QString::fromUtf8("lineEditMessage"));
        lineEditMessage->setGeometry(QRect(180, 190, 281, 25));
        editLog = new QTextEdit(centralwidget);
        editLog->setObjectName(QString::fromUtf8("editLog"));
        editLog->setGeometry(QRect(110, 240, 541, 301));
        buttonConnect = new QPushButton(centralwidget);
        buttonConnect->setObjectName(QString::fromUtf8("buttonConnect"));
        buttonConnect->setGeometry(QRect(460, 50, 89, 51));
        buttonSubscribe = new QPushButton(centralwidget);
        buttonSubscribe->setObjectName(QString::fromUtf8("buttonSubscribe"));
        buttonSubscribe->setGeometry(QRect(470, 140, 89, 25));
        buttonPublish = new QPushButton(centralwidget);
        buttonPublish->setObjectName(QString::fromUtf8("buttonPublish"));
        buttonPublish->setGeometry(QRect(470, 190, 89, 25));
        spinBoxPort = new QSpinBox(centralwidget);
        spinBoxPort->setObjectName(QString::fromUtf8("spinBoxPort"));
        spinBoxPort->setGeometry(QRect(180, 80, 261, 26));
        spinBoxPort->setMaximum(3000);
        spinBoxPort->setValue(1883);
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(110, 54, 67, 17));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(110, 84, 67, 17));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(110, 140, 67, 17));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(110, 192, 67, 17));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MQTT Test", nullptr));
        lineEditHost->setText(QCoreApplication::translate("MainWindow", "test.mosquitto.org", nullptr));
        lineEditTopic->setText(QCoreApplication::translate("MainWindow", "amr/topic", nullptr));
        buttonConnect->setText(QCoreApplication::translate("MainWindow", "Connect", nullptr));
        buttonSubscribe->setText(QCoreApplication::translate("MainWindow", "Subscribe", nullptr));
        buttonPublish->setText(QCoreApplication::translate("MainWindow", "publish", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Host", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "port", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Topic", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Message", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

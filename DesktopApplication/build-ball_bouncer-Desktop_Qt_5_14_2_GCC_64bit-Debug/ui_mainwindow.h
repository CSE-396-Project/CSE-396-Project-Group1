/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include "qcircledrawingwidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionConnect;
    QAction *actionCalibrate;
    QAction *actionSet_Server_IP;
    QCircleDrawingWidget *MainArea;
    QGridLayout *gridLayout_3;
    QLabel *EnterIPLabel;
    QMenuBar *menuBar;
    QMenu *menuSet_Server_IP;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setWindowModality(Qt::ApplicationModal);
        MainWindow->resize(500, 500);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setCursor(QCursor(Qt::ArrowCursor));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/ping-pong-layered.svg"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        actionConnect = new QAction(MainWindow);
        actionConnect->setObjectName(QString::fromUtf8("actionConnect"));
        actionCalibrate = new QAction(MainWindow);
        actionCalibrate->setObjectName(QString::fromUtf8("actionCalibrate"));
        actionSet_Server_IP = new QAction(MainWindow);
        actionSet_Server_IP->setObjectName(QString::fromUtf8("actionSet_Server_IP"));
        QFont font;
        font.setFamily(QString::fromUtf8("Ubuntu"));
        actionSet_Server_IP->setFont(font);
        MainArea = new QCircleDrawingWidget(MainWindow);
        MainArea->setObjectName(QString::fromUtf8("MainArea"));
        gridLayout_3 = new QGridLayout(MainArea);
        gridLayout_3->setSpacing(0);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        EnterIPLabel = new QLabel(MainArea);
        EnterIPLabel->setObjectName(QString::fromUtf8("EnterIPLabel"));
        EnterIPLabel->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(EnterIPLabel, 0, 0, 1, 1);

        MainWindow->setCentralWidget(MainArea);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 500, 22));
        menuSet_Server_IP = new QMenu(menuBar);
        menuSet_Server_IP->setObjectName(QString::fromUtf8("menuSet_Server_IP"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuSet_Server_IP->menuAction());
        menuSet_Server_IP->addAction(actionSet_Server_IP);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Ball Bouncer Desktop", nullptr));
        actionConnect->setText(QCoreApplication::translate("MainWindow", "Connect", nullptr));
        actionCalibrate->setText(QCoreApplication::translate("MainWindow", "Calibrate", nullptr));
        actionSet_Server_IP->setText(QCoreApplication::translate("MainWindow", "Set Server IP", nullptr));
        EnterIPLabel->setText(QCoreApplication::translate("MainWindow", "Enter Server IP Using Menu Bar", nullptr));
        menuSet_Server_IP->setTitle(QCoreApplication::translate("MainWindow", "Settings", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

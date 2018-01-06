/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include <videowidget.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionWebcam;
    QAction *actionPlay;
    QWidget *centralWidget;
    VideoWidget *inputFrame;
    VideoWidget *hsvFrame;
    QLabel *position;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1310, 540);
        actionWebcam = new QAction(MainWindow);
        actionWebcam->setObjectName(QStringLiteral("actionWebcam"));
        actionPlay = new QAction(MainWindow);
        actionPlay->setObjectName(QStringLiteral("actionPlay"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setAutoFillBackground(false);
        inputFrame = new VideoWidget(centralWidget);
        inputFrame->setObjectName(QStringLiteral("inputFrame"));
        inputFrame->setGeometry(QRect(10, 10, 640, 480));
        hsvFrame = new VideoWidget(centralWidget);
        hsvFrame->setObjectName(QStringLiteral("hsvFrame"));
        hsvFrame->setGeometry(QRect(660, 10, 640, 480));
        position = new QLabel(centralWidget);
        position->setObjectName(QStringLiteral("position"));
        position->setGeometry(QRect(6, 500, 571, 20));
        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "PhotonenGitarre", Q_NULLPTR));
        actionWebcam->setText(QApplication::translate("MainWindow", "Webcam", Q_NULLPTR));
        actionPlay->setText(QApplication::translate("MainWindow", "Play", Q_NULLPTR));
        position->setText(QApplication::translate("MainWindow", "x = 0; y = 0;", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
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
    QLabel *hueMinLabel;
    QSpinBox *hueMinValue;
    QLabel *hueMaxLabel;
    QSpinBox *hueMaxValue;
    QLabel *saturationMinLabel;
    QLabel *saturationMaxLabel;
    QSpinBox *saturationMinValue;
    QSpinBox *saturationMaxValue;
    QLabel *valueMaxLabel;
    QLabel *valueMinLabel;
    QSpinBox *valueMinValue;
    QSpinBox *valueMaxValue;
    QPushButton *saveButton;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1310, 600);
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
        hueMinLabel = new QLabel(centralWidget);
        hueMinLabel->setObjectName(QStringLiteral("hueMinLabel"));
        hueMinLabel->setGeometry(QRect(10, 500, 50, 22));
        hueMinValue = new QSpinBox(centralWidget);
        hueMinValue->setObjectName(QStringLiteral("hueMinValue"));
        hueMinValue->setGeometry(QRect(65, 500, 43, 22));
        hueMinValue->setMaximum(360);
        hueMaxLabel = new QLabel(centralWidget);
        hueMaxLabel->setObjectName(QStringLiteral("hueMaxLabel"));
        hueMaxLabel->setGeometry(QRect(10, 530, 47, 22));
        hueMaxValue = new QSpinBox(centralWidget);
        hueMaxValue->setObjectName(QStringLiteral("hueMaxValue"));
        hueMaxValue->setGeometry(QRect(65, 530, 43, 22));
        hueMaxValue->setMaximum(360);
        hueMaxValue->setValue(360);
        saturationMinLabel = new QLabel(centralWidget);
        saturationMinLabel->setObjectName(QStringLiteral("saturationMinLabel"));
        saturationMinLabel->setGeometry(QRect(150, 500, 90, 22));
        saturationMaxLabel = new QLabel(centralWidget);
        saturationMaxLabel->setObjectName(QStringLiteral("saturationMaxLabel"));
        saturationMaxLabel->setGeometry(QRect(150, 530, 90, 22));
        saturationMinValue = new QSpinBox(centralWidget);
        saturationMinValue->setObjectName(QStringLiteral("saturationMinValue"));
        saturationMinValue->setGeometry(QRect(240, 500, 43, 22));
        saturationMinValue->setMaximum(100);
        saturationMaxValue = new QSpinBox(centralWidget);
        saturationMaxValue->setObjectName(QStringLiteral("saturationMaxValue"));
        saturationMaxValue->setGeometry(QRect(240, 530, 43, 22));
        saturationMaxValue->setMaximum(100);
        saturationMaxValue->setValue(100);
        valueMaxLabel = new QLabel(centralWidget);
        valueMaxLabel->setObjectName(QStringLiteral("valueMaxLabel"));
        valueMaxLabel->setGeometry(QRect(320, 530, 90, 22));
        valueMinLabel = new QLabel(centralWidget);
        valueMinLabel->setObjectName(QStringLiteral("valueMinLabel"));
        valueMinLabel->setGeometry(QRect(320, 500, 90, 22));
        valueMinValue = new QSpinBox(centralWidget);
        valueMinValue->setObjectName(QStringLiteral("valueMinValue"));
        valueMinValue->setGeometry(QRect(410, 500, 43, 22));
        valueMinValue->setMaximum(100);
        valueMaxValue = new QSpinBox(centralWidget);
        valueMaxValue->setObjectName(QStringLiteral("valueMaxValue"));
        valueMaxValue->setGeometry(QRect(410, 530, 43, 22));
        valueMaxValue->setMaximum(100);
        valueMaxValue->setValue(100);
        saveButton = new QPushButton(centralWidget);
        saveButton->setObjectName(QStringLiteral("saveButton"));
        saveButton->setGeometry(QRect(510, 500, 100, 52));
        QFont font;
        font.setPointSize(20);
        saveButton->setFont(font);
        saveButton->setAutoDefault(false);
        saveButton->setFlat(false);
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
        hueMinLabel->setText(QApplication::translate("MainWindow", "Hue-Min:", Q_NULLPTR));
        hueMaxLabel->setText(QApplication::translate("MainWindow", "Hue-Max:", Q_NULLPTR));
        saturationMinLabel->setText(QApplication::translate("MainWindow", "Saturation-Min:", Q_NULLPTR));
        saturationMaxLabel->setText(QApplication::translate("MainWindow", "Saturation-Max:", Q_NULLPTR));
        valueMaxLabel->setText(QApplication::translate("MainWindow", "Value-Max:", Q_NULLPTR));
        valueMinLabel->setText(QApplication::translate("MainWindow", "Value-Min:", Q_NULLPTR));
        saveButton->setText(QApplication::translate("MainWindow", "Save", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

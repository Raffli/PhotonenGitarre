#include "mainwindow.h"
#include "ui_mainwindow.h"


using namespace cv;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    videoThread(new VideoEngine),
    hsvProcessor(new HSVProcessor())
{
    ui->setupUi(this);
    videoThread->setProcessor(hsvProcessor);
    connect(videoThread, &VideoEngine::sendInputImage,
            ui->inputFrame, &VideoWidget::setImage);
    connect(videoThread, &VideoEngine::sendProcessedImage,
            ui->hsvFrame, &VideoWidget::setImage);

    videoThread->openCamera();
    videoThread->start();
}

MainWindow::~MainWindow()
{
    delete videoThread;
    delete hsvProcessor;
    delete ui;
}

void MainWindow::on_hueMaxValue_valueChanged(int arg1)
{
    hsvProcessor->setHueMax(arg1);
}

void MainWindow::on_hueMinValue_valueChanged(int arg1)
{
    hsvProcessor->setHueMin(arg1);
}

void MainWindow::on_saturationMaxValue_valueChanged(int arg1)
{
    hsvProcessor->setSaturationMax(arg1);
}

void MainWindow::on_saturationMinValue_valueChanged(int arg1)
{
    hsvProcessor->setSaturationMin(arg1);
}

void MainWindow::on_valueMaxValue_valueChanged(int arg1)
{
    hsvProcessor->setValueMax(arg1);
}

void MainWindow::on_valueMinValue_valueChanged(int arg1)
{
    hsvProcessor->setValueMin(arg1);
}

void MainWindow::on_saveButton_clicked()
{
    hsvProcessor->saveCalibration();
}

#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace cv;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    videoThread(new VideoEngine)
{
    ui->setupUi(this);
    connect(videoThread, &VideoEngine::sendInputImage,
            ui->inputFrame, &VideoWidget::setImage);

    videoThread->openCamera();
    videoThread->start();
}

MainWindow::~MainWindow()
{
    delete videoThread;
    delete ui;
}

void MainWindow::on_actionPlay_triggered()
{

}

void MainWindow::on_actionWebcam_triggered()
{

}

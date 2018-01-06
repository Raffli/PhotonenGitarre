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

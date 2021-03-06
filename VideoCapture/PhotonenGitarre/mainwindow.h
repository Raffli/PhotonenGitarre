#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QImage>
#include "videoengine.h"
#include "hsvprocessor.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_hueMaxValue_valueChanged(int arg1);

    void on_hueMinValue_valueChanged(int arg1);

    void on_saturationMaxValue_valueChanged(int arg1);

    void on_saturationMinValue_valueChanged(int arg1);

    void on_valueMaxValue_valueChanged(int arg1);

    void on_valueMinValue_valueChanged(int arg1);

    void on_saveButton_clicked();

    void on_blueButton_toggled(bool checked);

    void on_cyanButton_toggled(bool checked);

    void on_greenButton_toggled(bool checked);

    void on_magentaButton_toggled(bool checked);

    void on_redButton_toggled(bool checked);

    void on_yellowButton_toggled(bool checked);

private:
    Ui::MainWindow *ui;
    VideoEngine *videoThread;
    HSVProcessor* hsvProcessor;
};

#endif // MAINWINDOW_H

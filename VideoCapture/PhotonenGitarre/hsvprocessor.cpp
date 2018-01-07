#include "hsvprocessor.h"
#include <QDebug>

using namespace cv;
using namespace std;

HSVProcessor::HSVProcessor():
    hueMax(70),
    hueMin(50),
    saturationMax(255),
    saturationMin(200),
    valueMax(255),
    valueMin(0)
{

}

cv::Mat HSVProcessor::process(const cv::Mat &input) {
    // convert to HSV
    Mat hsvFrame;
    cvtColor(input, hsvFrame, CV_BGR2HSV);

    //initialize for output
    Mat binaryMask = colorKeying(hsvFrame);

    medianBlur(binaryMask, binaryMask, 5);

    erode(binaryMask, binaryMask, Mat());
    dilate(binaryMask, binaryMask, Mat());

    findCenterOfObject(binaryMask);

    Mat output;
    cvtColor(binaryMask, output, CV_GRAY2BGR);
    drawCross(output, center, 5, Scalar(0, 0, 255));

    return output;
}

Mat HSVProcessor::colorKeying(Mat &hsvFrame) {
    Mat output(hsvFrame.rows, hsvFrame.cols, CV_8UC1);
    for (int x = 0; x < hsvFrame.cols; x++) {
        for (int y = 0; y < hsvFrame.rows; y++) {
            Vec3b hsvPixel = hsvFrame.at<Vec3b>(y,x);
            int hue = hsvPixel[0];
            int saturation = hsvPixel[1];
            int value = hsvPixel[2];

            bool isWhite = false;
            if ((saturation >= saturationMin)
                    && (hue >= hueMin && hue <= hueMax)
                    && (value >= valueMin && value <= valueMax)) {
                    isWhite = true;
            }

            if (isWhite) {
                output.at<uchar>(y, x) = 255;
            } else {
                output.at<uchar>(y,x) = 0;
            }
        }
    }

    return output;
}

void HSVProcessor::findCenterOfObject(Mat &image){
    // analyse all pixels
    int whitePixels = 0;
    int sumX = 0;
    int sumY = 0;

    for (int x = 0; x < image.cols; x++) {
        for (int y = 0; y < image.rows; y++) {
            if (image.at<uchar>(y,x) == 255) {
                sumX += x;
                sumY += y;
                whitePixels++;
            }
        }
    }

    if (whitePixels > 0) {
        center = Point(sumX/whitePixels, sumY/whitePixels);
    }
}

void HSVProcessor::drawCross(Mat &image, Point center, int length, Scalar color) {
    line(image, center - Point(0, length), center + Point(0, length), color, 1);
    line(image, center - Point(length, 0), center + Point(length, 0), color, 1);
}

void HSVProcessor::setHueMax(const int value){
    hueMax = value/2;
    qDebug() << hueMax;
}

void HSVProcessor::setHueMin(const int value){
    hueMin = value/2;
    qDebug() << hueMin;
}

void HSVProcessor::setSaturationMax(const int value){
    saturationMax = 255 * value / 100;
    qDebug() << saturationMax;
}

void HSVProcessor::setSaturationMin(const int value){
    saturationMin = 255 * value / 100;
    qDebug() << saturationMin;
}

void HSVProcessor::setValueMax(const int value){
    valueMax = 255 * value / 100;
    qDebug() << valueMax;
}

void HSVProcessor::setValueMin(const int value){
    valueMin = 255 * value / 100;
    qDebug() << valueMin;
}

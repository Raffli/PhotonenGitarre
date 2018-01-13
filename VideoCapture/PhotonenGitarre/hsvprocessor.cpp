#include "hsvprocessor.h"
#include <QDebug>

using namespace cv;
using namespace std;

HSVProcessor::HSVProcessor():
    hueMax(180),
    hueMin(0),
    saturationMax(255),
    saturationMin(0),
    valueMax(255),
    valueMin(0)
{
    midiOutput.open("LoopBe Internal MIDI");
}

cv::Mat HSVProcessor::process(cv::Mat &input) {
    // convert to HSV
    Mat hsvFrame;
    cvtColor(input, hsvFrame, CV_BGR2HSV);

    //initialize for output
    testObject.threshold = colorKeying(hsvFrame, testObject);

    medianBlur(testObject.threshold, testObject.threshold, 5);

    erode(testObject.threshold, testObject.threshold, Mat());
    dilate(testObject.threshold, testObject.threshold, Mat());

    findCenterOfObject(testObject.threshold, testObject);

    Mat output;
    cvtColor(testObject.threshold, output, CV_GRAY2BGR);
    drawCross(output, testObject.center, 5, Scalar(0, 0, 255));

    for (unsigned int i = 0; i<objects.size(); i++) {
        objects[i].threshold = colorKeying(hsvFrame, objects[i]);
        medianBlur(objects[i].threshold, objects[i].threshold, 5);

        erode(objects[i].threshold, objects[i].threshold, Mat());
        dilate(objects[i].threshold, objects[i].threshold, Mat());

        findCenterOfObject(objects[i].threshold, objects[i]);
        if (objects[i].y > 0) {
            midiOutput.sendNoteOn(1, objects[i].y / 4, 127);
        }
        drawCross(input, objects[i].center, 5, Scalar(0, 0, 255));
    }
    drawGridLines(input);

    return output;
}

Mat HSVProcessor::colorKeying(Mat &hsvFrame, item &currentItem) {
    Mat output(hsvFrame.rows, hsvFrame.cols, CV_8UC1);
    for (int x = 0; x < hsvFrame.cols; x++) {
        for (int y = 0; y < hsvFrame.rows; y++) {
            Vec3b hsvPixel = hsvFrame.at<Vec3b>(y,x);
            int hue = hsvPixel[0];
            int saturation = hsvPixel[1];
            int value = hsvPixel[2];

            bool isWhite = false;
            if ((saturation >= currentItem.saturationMin)
                    && (hue >= currentItem.hueMin && hue <= currentItem.hueMax)
                    && (value >= currentItem.valueMin && value <= currentItem.valueMax)) {
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

void HSVProcessor::findCenterOfObject(Mat &image, item &currentItem){
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
        currentItem.x = sumX/whitePixels;
        currentItem.y = sumY/whitePixels;
    } else {
        currentItem.x = -100;
        currentItem.y = -100;
    }
    currentItem.center = Point(currentItem.x, currentItem.y);
}

void HSVProcessor::drawCross(Mat &image, Point center, int length, Scalar color) {
    line(image, center - Point(0, length), center + Point(0, length), color, 1);
    line(image, center - Point(length, 0), center + Point(length, 0), color, 1);
}

void HSVProcessor::drawGridLines (Mat &image) {
    for (unsigned int i = 0; i < 5; i++) {
        line(image, Point(image.size().width * (i+1) / 6, 0),
             Point(image.size().width * (i+1) / 6, image.size().height), Scalar(0, 0, 0), 3);
    }
}

HSVProcessor::item HSVProcessor::setUpItemObject (int x, int y, cv::Point center, int hmin, int hmax, int smin, int smax, int vmin, int vmax) {
    item temp;
    temp.x = x;
    temp.y = y;
    temp.center = center;
    temp.hueMin = hmin;
    temp.hueMax = hmax;
    temp.saturationMin = smin;
    temp.saturationMax = smax;
    temp.valueMin = vmin;
    temp.valueMax = vmax;
    qDebug() << "save";
    return temp;
}

void HSVProcessor::saveCalibration(){
    objects.push_back(setUpItemObject(testObject.x, testObject.y, testObject.center, testObject.hueMin, testObject.hueMax,
                                      testObject.saturationMin, testObject.saturationMax, testObject.valueMin, testObject.valueMax));
}

void HSVProcessor::setHueMax(const int value){
    hueMax = value/2;
    testObject.hueMax = hueMax;
    qDebug() << hueMax;
}

void HSVProcessor::setHueMin(const int value){
    hueMin = value/2;
    testObject.hueMin = hueMin;
    qDebug() << hueMin;
}

void HSVProcessor::setSaturationMax(const int value){
    saturationMax = 255 * value / 100;
    testObject.saturationMax = saturationMax;
    qDebug() << saturationMax;
}

void HSVProcessor::setSaturationMin(const int value){
    saturationMin = 255 * value / 100;
    testObject.saturationMin = saturationMin;
    qDebug() << saturationMin;
}

void HSVProcessor::setValueMax(const int value){
    valueMax = 255 * value / 100;
    testObject.valueMax = valueMax;
    qDebug() << valueMax;
}

void HSVProcessor::setValueMin(const int value){
    valueMin = 255 * value / 100;
    testObject.valueMin = valueMin;
    qDebug() << valueMin;
}

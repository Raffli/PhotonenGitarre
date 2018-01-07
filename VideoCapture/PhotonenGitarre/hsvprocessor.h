#ifndef HSVPROCESSOR_H
#define HSVPROCESSOR_H

#include "videoprocessor.h"

class HSVProcessor : public VideoProcessor
{
public:
    HSVProcessor();
    void startProcessing(const VideoFormat &format) {}
    cv::Mat process(const cv::Mat &input);
    void setHueMax (const int value);
    void setHueMin (const int value);
    void setSaturationMax (const int value);
    void setSaturationMin (const int value);
    void setValueMax (const int value);
    void setValueMin (const int value);

private:
    int hueMax;
    int hueMin;
    int saturationMax;
    int saturationMin;
    int valueMax;
    int valueMin;
    cv::Point center;
    cv::Mat colorKeying (cv::Mat& hsvFrame);
    void findCenterOfObject(cv::Mat& image);
    void drawCross(cv::Mat& mat, cv::Point center, int length, cv::Scalar color);
};

#endif // HSVPROCESSOR_H

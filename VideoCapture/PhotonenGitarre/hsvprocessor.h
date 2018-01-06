#ifndef HSVPROCESSOR_H
#define HSVPROCESSOR_H

#include "videoprocessor.h"

class HSVProcessor : public VideoProcessor
{
public:
    HSVProcessor();
    void startProcessing(const VideoFormat &format) {}
    cv::Mat process(const cv::Mat &input);
};

#endif // HSVPROCESSOR_H

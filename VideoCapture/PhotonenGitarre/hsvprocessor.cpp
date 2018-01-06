#include "hsvprocessor.h"

using namespace cv;

HSVProcessor::HSVProcessor()
{

}

cv::Mat HSVProcessor::process(const cv::Mat &input) {
    Mat hsvFrame;
    cvtColor(input, hsvFrame, CV_BGR2HSV);
    return hsvFrame;
}

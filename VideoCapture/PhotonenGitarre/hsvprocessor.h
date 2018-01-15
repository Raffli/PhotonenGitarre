#ifndef HSVPROCESSOR_H
#define HSVPROCESSOR_H

#include "videoprocessor.h"
#include "midioutput.h"
#include <string>

using namespace std;

class HSVProcessor : public VideoProcessor
{
public:
    HSVProcessor();
    void startProcessing(const VideoFormat &format) {}
    cv::Mat process(cv::Mat &input);
    void setHueMax (const int value);
    void setHueMin (const int value);
    void setSaturationMax (const int value);
    void setSaturationMin (const int value);
    void setValueMax (const int value);
    void setValueMin (const int value);
    void saveCalibration ();
    void setBlue (const bool checked);
    void setCyan (const bool checked);
    void setGreen (const bool checked);
    void setMagenta (const bool checked);
    void setRed (const bool checked);
    void setYellow (const bool checked);

    //Struct to define the attributes of the objects to be tracked.
    typedef struct {
        QString color;
        int startMidiNote;
        int lastNote;
        int x;
        int y;
        cv::Point center;
        int hueMin = hueMin;
        int hueMax = hueMax;
        int saturationMin = saturationMin;
        int saturationMax = saturationMax;
        int valueMin = valueMin;
        int valueMax = valueMax;
        cv::Mat threshold;
    }item ;

    // Dynamic object who's attributes (specifically HSV) can be changed in real time.
    item testObject;
    // To store objects with defined values.
    std::vector<item> objects;

private:
    drumstick::rt::MIDIOutput midiOutput;
    int hueMax;
    int hueMin;
    int saturationMax;
    int saturationMin;
    int valueMax;
    int valueMin;
    bool blueChecked, cyanChecked, greenChecked, magentaChecked, redChecked, yellowChecked;
    cv::Point center;
    cv::Mat colorKeying (cv::Mat& hsvFrame, item& currentItem, const int startCol, const int endCol);
    void findCenterOfObject(cv::Mat& image, item& currentItem);
    void drawCross(cv::Mat& image, cv::Point center, int length, cv::Scalar color);
    void drawGridLines(cv::Mat& image);
    void drawColorNames(cv::Mat& image, QString color, cv::Point center);
    item setUpItemObject(int x, int y, cv::Point center, int hmin, int hmax, int smin,
                         int smax, int vmin, int vmax, QString color, int startMidiNote);
};

#endif // HSVPROCESSOR_H

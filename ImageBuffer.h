#ifndef IMAGEBUFFER_H
#define IMAGEBUFFER_H

// Qt header files
#include <QMutex>
#include <QQueue>
#include <QSemaphore>
// OpenCV header files
//#include <opencv/highgui.h>
#include"opencv2/opencv.hpp"

using namespace cv;

class ImageBuffer
{

public:    
    static ImageBuffer* getInstance();
    void addFrame(const Mat& frame);
    Mat getFrame();
    void clearBuffer();
    int getSizeOfImageBuffer();
private:   
    ImageBuffer(int size, bool dropFrame);
    static ImageBuffer* myself;

    QMutex imageQueueProtect;
    QQueue<Mat> imageQueue;//帧缓冲区队列
    QSemaphore *freeSlots;
    QSemaphore *usedSlots;
    QSemaphore *clearBuffer1;
    QSemaphore *clearBuffer2;
    int bufferSize;
    bool dropFrame;
};


#endif // IMAGEBUFFER_H

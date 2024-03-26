#ifndef GRABTHREAD_H
#define GRABTHREAD_H

#include <QObject>
#include<QThread>
#include "include/halconcpp/HalconCpp.h"
#include"MvCameraControl.h"
#include"MvCamera.h"
#include"Windows.h"
#include<opencv2/opencv.hpp>
#include"ImageBuffer.h"
#include<iostream>
#include<QImage>

using namespace cv;
using namespace std;
using namespace HalconCpp;

class GrabThread : public QThread
{
public:
    GrabThread();
    void startRun(CMvCamera* ptr,HWND showlab);
    void getData(unsigned char* &pData,int& Width,int& Height);
    void getimage(QImage& qimage);
    void setThreadStart(bool threadStart);
    int countNumber();
    void getNum(int& num);
    void clearNum();
signals:
    void show();
protected:
    void run();
private:
    CMvCamera* m_pcMyCamera;
    ImageBuffer* imageBuffer;  //缓存对象
    HWND m_showwin;
    unsigned char* pdata;
    int width;
    int height;
    bool m_threadStart;
    int m_num;

    int m;
    int n;
    QImage m_qimage;
};

#endif // GRABTHREAD_H

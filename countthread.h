#ifndef COUNTTHREAD_H
#define COUNTTHREAD_H

#include <QObject>
#include<QThread>
#include"ImageBuffer.h"
#include"opencv2/opencv.hpp"

class CountThread : public QThread
{
    Q_OBJECT
public:
    CountThread();
    void clearNum();
    void getNum(int& num);
    void setCountStart(bool countstart);
protected:
    void run();
private:
    ImageBuffer* imageBuffer;
    int m_num;
    bool m_countstart;
};

#endif // COUNTTHREAD_H

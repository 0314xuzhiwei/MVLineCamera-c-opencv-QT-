#include "countthread.h"
#include<time.h>
#include<QDebug>

clock_t time1,time2;

CountThread::CountThread()
{
    imageBuffer = ImageBuffer::getInstance();
    m_num = 0;
    m_countstart = true;
}

void CountThread::clearNum()
{
    this->m_num = 0;
}

void CountThread::getNum(int &num)
{
    num = this->m_num;
}

void CountThread::setCountStart(bool countstart)
{
    this->m_countstart = countstart;
}

void CountThread::run()
{
    while(m_countstart)
    {
        time1 = clock();

        Mat src_color, g_src, labels, stats, centroids;

        Mat image = this->imageBuffer->getFrame();

        if(image.empty())
        {
            qDebug()<<"No imageData";
            return;
        }
        resize(image,image,Size(1000,700));
        //cvtColor(image, image, COLOR_BGR2RGBA);
        //threshold(image, g_src, 0, 255, THRESH_OTSU| THRESH_BINARY_INV); //大津法二值化
        threshold(image, g_src, 30, 255, THRESH_BINARY_INV);

        //    string Img_Name = "picture//" + to_string(n++)+ ".bmp";
        //    imwrite(Img_Name,g_src);
        int count = connectedComponentsWithStats(g_src, labels, stats, centroids);
        //qDebug()<<"count:"<<count;
        int num = 0;
        for (int i = 0; i < count; i++)
        {
            int area = stats.at<int>(i, CC_STAT_AREA);
            if (area < 10000 && area > 50)
            {
                num++;
            }
        }
        time2 = clock();
        //qDebug() << "time:" << time2 - time1;
        m_num = m_num + num;
    }
}

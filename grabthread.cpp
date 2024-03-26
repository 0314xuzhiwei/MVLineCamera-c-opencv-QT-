#include "grabthread.h"
#include<QDebug>
#include<QImage>
#include<time.h>

clock_t t1,t2;

GrabThread::GrabThread()
{
    m_pcMyCamera = new CMvCamera();
    imageBuffer = ImageBuffer::getInstance();
    m_showwin = NULL;
    pdata = NULL;
    m_threadStart = false;

    m = 0;
    m_num = 0;
    n = 0;
}

void GrabThread::startRun(CMvCamera* ptr,HWND showwin)
{
    this->start((QThread::Priority)7);
    this->m_pcMyCamera = ptr;
    this->m_showwin = showwin;
}

void GrabThread::getimage(QImage &qimage)
{
    qimage = this->m_qimage;
}

void GrabThread::getData(unsigned char* &pData,int& Width,int& Height)
{
    pData = this->pdata;
    Width = this->width;
    Height = this->height;
}

void GrabThread::setThreadStart(bool m_threadStart)
{
    this->m_threadStart = m_threadStart;
}

//int GrabThread::countNumber()
//{

//    if(pdata == NULL)
//    {
//        qDebug()<<"Not data";
//        return 0;
//    }
//    // Local iconic variables
//      HObject  ho_Image, ho_GrayImage, ho_Regions, ho_ConnectedRegions;
//      HObject  ho_SelectedRegions;

//      // Local control variables
//      HTuple  hv_Number;



////      ReadImage(&ho_Image, //'D:/VS/干涉图像融合2/干涉图像融合2/8.bmp'
////          "D:/VS/\270\311\311\346\315\274\317\361\310\332\272\3172/\270\311\311\346\315\274\317\361\310\332\272\3172/8.bmp");
////      GetImageSize(ho_Image, &hv_Width, &hv_Height);

//      //GenImageInterleaved(&ho_Image,(Hlong)pdata,"rgb", width,height, 0,"byte",0,0,0,0,-1,0);
//      GenImage1(&ho_Image, "byte", width, height, (Hlong)pdata);

////      //Rgb1ToGray(ho_Image, &ho_GrayImage);
//      Threshold(ho_Image, &ho_Regions, 0, 26);
//      Connection(ho_Regions, &ho_ConnectedRegions);
//      SelectShape(ho_ConnectedRegions, &ho_SelectedRegions, "area", "and", 0, 8333.33);
//      CountObj(ho_SelectedRegions, &hv_Number);
//      int num = hv_Number[0].I();
//      //return 0;
//      return num;
//}

//int GrabThread::countNumber()
//{
//    if(pdata == NULL)
//    {
//        qDebug()<<"Not data";
//        return 0;
//    }

//    Mat image = Mat(height, width, CV_8UC1, pdata);

//    //qDebug()<<"channels1:"<<image.channels();
////    qDebug()<<*pdata;
////    qDebug()<<"size:"<<image.size;
////    qDebug()<<"w:"<<image.cols;
////    qDebug()<<"h:"<<image.rows;
//    /*int height = image.rows;
//        int width = image.cols;
//        cout <<"图片的高度为：" << height << "图片的宽度为" << width << endl;*/

//    Mat imageBW;
//    //cvtColor(image, imageGray, COLOR_BGR2GRAY);

//    threshold(image, imageBW, 55, 200, THRESH_BINARY);

//    //时间作为随机种子防止重复
//    //RNG rng(time(NULL));
//    Mat outImage, stats, centroids;
//    t1 = clock();
//    int count = connectedComponentsWithStats(imageBW, outImage, stats, centroids, 8, CV_16U);
//    t2 = clock();
//    qDebug()<<"time:"<<t2 - t1;
////    qDebug()<<"count:"<<count;
////    vector<Vec3b> colors;//颜色容器
////    for (int i = 0; i < count; i++) {
////        Vec3b vec3 = Vec3b(rng.uniform(0, 256), rng.uniform(0, 256), rng.uniform(0, 256));
////        colors.push_back(vec3);
////    }
////    Mat dst = Mat::zeros(imageGray.size(), imageGray.type());
//    //int width = dst.cols;
//    //int height = dst.rows;
//    int num = 0;
//    for (int i = 1; i < count; i++)
//    {
////        //找到连通域的质心
////        int center_x = centroids.at<double>(i, 0);
////        int center_y = centroids.at<double>(i, 1);

////        //矩形的点和边
////        int x = stats.at<int>(i, CC_STAT_LEFT);
////        int y = stats.at<int>(i, CC_STAT_TOP);
////        int w = stats.at<int>(i, CC_STAT_WIDTH);
////        int h = stats.at<int>(i, CC_STAT_HEIGHT);
//        int area = stats.at<int>(i, CC_STAT_AREA);

//        //qDebug()<<"1";
//        if (area < 30000 && area>500)
//        {
//            num++;
////            //绘制中心点
////            circle(image, Point(center_x, center_y), 2, Scalar(0, 255, 122), 2, 8, 0);
////            //外接矩形
////            Rect rect(x, y, w, h);
////            rectangle(image, rect, colors[i], 1, 8, 0);
////            putText(image, format("%d", num), Point(center_x, center_y), FONT_HERSHEY_COMPLEX, 0.5, Scalar(0, 0, 255), 1);
//            //qDebug() << "cout:" <<num << " 线圈面积为" << area;
//        }
//    }
////    namedWindow("picture",WINDOW_FREERATIO);
////    imshow("picture",image);

//    //qDebug()<<"channels2:"<<image.channels();
////    string Img_Name = "picture//" + to_string(n++)+ ".bmp";
////    imwrite(Img_Name,image);

////    qDebug()<<"num:"<<num;

//    //qDebug()<<"time:"<<endtime - starttime;
//    return num;
//}

int GrabThread::countNumber()
{

    t1 = clock();
    if(pdata == NULL)
    {
        qDebug()<<"Not data";
        return 0;
    }

    Mat src_color, g_src, labels, stats, centroids;
    Mat image = Mat(height, width, CV_8UC1, pdata);

    if(image.empty())
    {
        qDebug()<<"No imageData";
        return 0;
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
    t2 = clock();
    //qDebug() << "time:" << t2 - t1;
    return num;
}

void GrabThread::getNum(int& num)
{
    num = this->m_num;
}

void GrabThread::clearNum()
{
    this->m_num = 0;
}

void GrabThread::run()
{
    MV_FRAME_OUT stImageInfo = {0};
    MV_DISPLAY_FRAME_INFO stDisplayInfo = {0};
    int nRet = MV_OK;
    qDebug()<<"thread";
    while(m_threadStart)
    {
        //clock_t time1,time2;
        //m++;
        //qDebug()<<m;
        nRet = m_pcMyCamera->GetImageBuffer(&stImageInfo, 1000);
        //nRet = m_pcMyCamera->GetImageBuffer(&stImageInfo, INFINITE);  //无限等待，直到获取一帧数据
        //memcpy(&m_stImageInfo, &(stImageInfo.stFrameInfo), sizeof(MV_FRAME_OUT_INFO_EX));

        stDisplayInfo.hWnd = m_showwin;
        stDisplayInfo.pData = stImageInfo.pBufAddr;
        stDisplayInfo.nDataLen = stImageInfo.stFrameInfo.nFrameLen;
        stDisplayInfo.nWidth = stImageInfo.stFrameInfo.nWidth;
        stDisplayInfo.nHeight = stImageInfo.stFrameInfo.nHeight;
        stDisplayInfo.enPixelType = stImageInfo.stFrameInfo.enPixelType;
        m_pcMyCamera->DisplayOneFrame(&stDisplayInfo);

        pdata = stImageInfo.pBufAddr;
        width = stImageInfo.stFrameInfo.nWidth;
        height = stImageInfo.stFrameInfo.nHeight;
        Mat image = Mat(height, width, CV_8UC1, pdata);

        this->imageBuffer->addFrame(image);
//        qDebug()<<"1:"<<pdata;
//        int width = stImageInfo.stFrameInfo.nWidth;
//        int height = stImageInfo.stFrameInfo.nHeight;
//        QImage image((unsigned char*)stImageInfo.pBufAddr,width,height,width,QImage::Format_Grayscale8);
//        QString qstr = QString("picture//%1.bmp").arg(n++);
//        image.save(qstr,"BMP",100);
//        m_qimage = image;



        //计数
//        t1 = clock();
//        int number = 0;
//        number = countNumber();
//        m_num = m_num + number;
//        t2 = clock();
//        qDebug()<< "time:" << t2-t1;


        m_pcMyCamera->FreeImageBuffer(&stImageInfo);
        //qDebug()<<stImageInfo.stFrameInfo.nWidth;

//        int width = stImageInfo.stFrameInfo.nWidth;
//        int height = stImageInfo.stFrameInfo.nHeight;
//        QImage image((unsigned char*)stImageInfo.pBufAddr,width,height,width,QImage::Format_Grayscale8);
//        qDebug()<<image.size();
//        ui->saveLab->setPixmap(QPixmap::fromImage(image.scaled(ui->saveLab->size())));

        //qDebug()<<"time:"<<time2 - time1;
//        time2 = clock();
//        qDebug()<<"2:"<<time2;
//        qDebug()<<"time:"<<time2 - time1;
    }
    m_threadStart = false;
    //qDebug()<<m_threadStart;

}

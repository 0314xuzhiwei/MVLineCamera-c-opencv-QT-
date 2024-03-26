#include "widget.h"
#include "ui_widget.h"
#include<QMessageBox>
#include<QDebug>
#include<QString>

#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QModbusClient>
#include <QModbusRtuSerialMaster>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    update = new QTimer();
    this->update->setInterval(20);  //20ms运行一次
    connect(update, SIGNAL(timeout()), this, SLOT(onTimerOut()));//计时器
    readTimer = new QTimer();
    this->readTimer->setInterval(100);  //20ms运行一次
    connect(readTimer, SIGNAL(timeout()), this, SLOT(readData()));

    connect(this,SIGNAL(showWaring()),this,SLOT(Waring()));

    initialize();   //主界面数据初始化
   // this->plc->InitialSetting();//plc控制界面初始化

    m_pcMyCamera = NULL;
    modbusDevice = nullptr;
    grabthread = new GrabThread();
    countThread = new CountThread();
    plc = new PlcControl();//为plc对象开辟内存空间
    connect(plc,SIGNAL(sendData(int)),this,SLOT(showReceiveData(int)));
//    this->plc->InitialSetting();//plc控制界面初始化
//    this->plc->hide();



    threadstart = false;
    countstart = false;
    timestart = false;
    grabStart = false;
    ifwritedata1 = true;
    ifwritedata2 = true;
    ifreaddata1 = true;
    m_Index = 0;
    textNum = 0;
    setEnablefalse();
}

Widget::~Widget()
{
    delete ui;

    if (m_pcMyCamera)
    {
        m_pcMyCamera->Close();
        m_pcMyCamera->StopGrabbing();
        delete m_pcMyCamera;
        m_pcMyCamera = NULL;
    }
}

void Widget::initialize()
{
    m_width = 2048;
    m_height = 1500;
    m_lineRate = 3000;
    ui->widthlineEdit->setText(QString("%1").arg(m_width));
    ui->heightlineEdit->setText(QString("%1").arg(m_height));
    ui->lineEdit->setText(QString("%1").arg(m_lineRate));
    m_selectIndex = 0;
    m_modeIndex = 0;
    m_sourceIndex = 0;
    m_sourceNum = 8;  //变频器触发
    m_num = 0;
}

void Widget::attributeinitia()
{
    //各属性初始化
    //帧触发属性
    this->m_pcMyCamera->SetEnumValue("TriggerSelector",6);
    this->m_pcMyCamera->SetEnumValue("TriggerMode",0);
    this->m_pcMyCamera->SetEnumValue("TriggerSource",8);
    //行触发属性
    this->m_pcMyCamera->SetEnumValue("TriggerSelector",9);
    this->m_pcMyCamera->SetEnumValue("TriggerMode",0);
    this->m_pcMyCamera->SetEnumValue("TriggerSource",8);
    //编码器选择
    this->m_pcMyCamera->SetEnumValue("EncoderSelector",0);
    //编码器源A
    this->m_pcMyCamera->SetEnumValue("EncoderSourceA",0);
    //编码器源B
    this->m_pcMyCamera->SetEnumValue("EncoderSourceB",0);
    //变频器输入源
    this->m_pcMyCamera->SetEnumValue("InputSource",0);
}

void Widget::setEnablefalse()
{
    //按钮
    ui->openBtn->setEnabled(false);
    ui->stopBtn->setEnabled(false);
    ui->startBtn->setEnabled(false);
    ui->closeBtn->setEnabled(false);
    //ui->showBtn->setEnabled(false);

//    ui->setSoftBtn->setEnabled(false);
//    ui->softBtn->setEnabled(false);

    //下拉框
    ui->selectCob->setEnabled(false);
    ui->modeCob->setEnabled(false);
    ui->sourceCob->setEnabled(false);
    ui->encselectCob->setEnabled(false);
    ui->encsourceACob->setEnabled(false);
    ui->encsourceBCob->setEnabled(false);
    ui->inputCob->setEnabled(false);

    //编辑框
    ui->widthlineEdit->setEnabled(false);
    ui->heightlineEdit->setEnabled(false);
    ui->lineEdit->setEnabled(false);
}

void Widget::timerstart()
{
    this->update->start();
}

void Widget::setlineEdit()
{
    this->m_pcMyCamera->SetIntValue("Width",m_width);
    this->m_pcMyCamera->SetIntValue("Height",m_height);
    this->m_pcMyCamera->SetIntValue("Acquisitionlinerate",m_lineRate);
}

void Widget::setcombox(int fselect,int fmode,int fsource,int lselect,int lmode,int lsource)
{
    //设置帧触发
    this->m_pcMyCamera->SetEnumValue("TriggerSelector",fselect);
    this->m_pcMyCamera->SetEnumValue("TriggerMode",fmode);
    this->m_pcMyCamera->SetEnumValue("TriggerSource",fsource);
    //设置行触发
    this->m_pcMyCamera->SetEnumValue("TriggerSelector",lselect);
    this->m_pcMyCamera->SetEnumValue("TriggerMode",lmode);
    this->m_pcMyCamera->SetEnumValue("TriggerSource",lsource);
}

void Widget::writeData(quint16 value)
{
    QList<quint16> values;
    values.append(value);
    this->plc->writeRequest(values);
}

void Widget::startGather()
{
    this->countThread->clearNum();  //开始采集之前清空个数
    //开始采集时设置属性
    timerstart();
    setlineEdit();
    m_pcMyCamera->StartGrabbing();
    grabStart = true;
    threadstart = true;
    countstart = true;
    this->grabthread->setThreadStart(this->threadstart);
    this->countThread->setCountStart(this->countstart);
    this->grabthread->startRun(m_pcMyCamera,(HWND)ui->showLab->winId());
    this->countThread->start((QThread::Priority)7);
}

void Widget::stopGather()
{
    threadstart = false;
    this->grabthread->setThreadStart(this->threadstart);
    countstart = false;
    this->countThread->setCountStart(this->countstart);
    int nRet = m_pcMyCamera->StopGrabbing();
    grabStart = false;
    if (MV_OK != nRet)
    {
        qDebug()<<"Stop grabbing fail";
        return;
    }
}

void Widget::readData()
{
    this->plc->ReadRequest();
}

void Widget::onTimerOut()
{
    m_width = this->ui->widthlineEdit->text().toInt();
    m_height = this->ui->heightlineEdit->text().toInt();
    m_lineRate = this->ui->lineEdit->text().toInt();

    this->countThread->getNum(m_num);
    if(m_num >= 2 && m_num < 5 && ifwritedata1)
    {
        qDebug()<<"write1";
        writeData(1);
        ifwritedata1 = false;
    }
    if(m_num == 5 && ifwritedata2)
    {
        qDebug()<<"write0";
        writeData(0);
        stopGather();  //停止采集
        ifwritedata2 = false;
    }
    ui->numberEdit->setText(QString("%1").arg(m_num));
}

void Widget::Waring()
{
    QMessageBox::warning(this, "提示","The number has reached 10",QMessageBox::Ok|QMessageBox::Cancel,QMessageBox::Ok);
    this->grabthread->clearNum();
}

void Widget::showReceiveData(int data)
{
    //qDebug()<<textNum++;
    if(data == 0 && ifreaddata1)  //收到信号，开始采集图像
    {
        ifreaddata1 = false;
        startGather();  //开始采集
    }
}


void Widget::on_openBtn_clicked()
{
    ifwritedata1 = true;
    ifwritedata2 = true;
    ifreaddata1 = true;
    //按钮
    ui->closeBtn->setEnabled(true);
    ui->startBtn->setEnabled(true);
    ui->openBtn->setEnabled(false);
    //下拉框
    ui->selectCob->setEnabled(true);
    ui->modeCob->setEnabled(true);
    ui->sourceCob->setEnabled(true);
    ui->encselectCob->setEnabled(true);
    ui->encsourceACob->setEnabled(true);
    ui->encsourceBCob->setEnabled(true);
    ui->inputCob->setEnabled(true);
    //编辑框
    ui->widthlineEdit->setEnabled(true);
    ui->heightlineEdit->setEnabled(true);
    ui->lineEdit->setEnabled(true);
    int nRet = MV_OK;
    qDebug()<<"1";
    //打开设备
    //由设备信息创建设备实例
    m_pcMyCamera = new CMvCamera;  //实例化相机对象
    if (NULL == m_pcMyCamera)
    {
        return;
    }

//    if(timestart == false)
//    {
//        this->update->start();
//        timestart = true;
//    }
    m_Index = ui->comboBox->currentIndex();
    nRet = m_pcMyCamera->Open(m_stDevList.pDeviceInfo[m_Index]);
    if (MV_OK != nRet)
    {
        QMessageBox::warning(this, "提示","Open Fail",QMessageBox::Ok|QMessageBox::Cancel,QMessageBox::Ok);
        delete m_pcMyCamera;
        m_pcMyCamera = NULL;
        return;
    }

    qDebug()<<"2";
     // 探测网络最佳包大小(只对GigE相机有效)
    if (m_stDevList.pDeviceInfo[0]->nTLayerType == MV_GIGE_DEVICE)
    {
        unsigned int nPacketSize = 0;
        nRet = m_pcMyCamera->GetOptimalPacketSize(&nPacketSize);
        if (nRet == MV_OK)
        {
            nRet = m_pcMyCamera->SetIntValue("GevSCPSPacketSize",nPacketSize);
            if(nRet != MV_OK)
            {
                //ShowErrorMsg(TEXT("Warning: Set Packet Size fail!"), nRet);
                QMessageBox::warning(this, "提示","Set Packet Size fail!",QMessageBox::Ok|QMessageBox::Cancel,QMessageBox::Ok);
            }
        }
        else
        {
            //ShowErrorMsg(TEXT("Warning: Get Packet Size fail!"), nRet);
            QMessageBox::warning(this, "提示","Get Packet Size fail!",QMessageBox::Ok|QMessageBox::Cancel,QMessageBox::Ok);
        }
    }

    //开始采集
    qDebug()<<"3";
    qDebug()<<"the camera open";
    attributeinitia();  //打开设备之后才可以设置相机属性初始化
    this->readTimer->start();  //启动信号检测定时器
}

void Widget::on_setSoftBtn_clicked()
{
//    threadstart = false;
//    this->grabthread->setThreadStart(this->threadstart);
    m_pcMyCamera->SetEnumValue("TriggerMode", 1);  //触发模式打开
    m_pcMyCamera->SetEnumValue("TriggerSource", 7);  //设置为软触发
}

void Widget::on_softBtn_clicked()
{
    m_pcMyCamera->CommandExecute("TriggerSoftware");
}

void Widget::on_stopBtn_clicked()
{
    ui->startBtn->setEnabled(true);
    ui->stopBtn->setEnabled(false);

    //编辑框
    ui->widthlineEdit->setEnabled(true);
    ui->heightlineEdit->setEnabled(true);
    ui->lineEdit->setEnabled(true);

    //this->update->stop();
    //this->grabthread->wait();

//    if(timestart == false)
//    {
//        this->update->start();
//        timestart = true;
//    }

    threadstart = false;
    this->grabthread->setThreadStart(this->threadstart);
    countstart = false;
    this->countThread->setCountStart(this->countstart);
    int nRet = m_pcMyCamera->StopGrabbing();
    grabStart = false;
    if (MV_OK != nRet)
    {
        qDebug()<<"Stop grabbing fail";
        return;
    }
}

void Widget::on_startBtn_clicked()
{
    ui->stopBtn->setEnabled(true);
    ui->startBtn->setEnabled(false);

    //编辑框
    ui->widthlineEdit->setEnabled(false);
    ui->heightlineEdit->setEnabled(false);
    ui->lineEdit->setEnabled(false);
    //timerstart();  //启动定时器，设置宽高

    //开始采集时设置属性
    setlineEdit();
    timerstart();  //启动定时器更新编辑框数据

//    if(timestart == true)
//    {
//        this->update->stop();
//        timestart = false;
//    }

    m_pcMyCamera->StartGrabbing();
    grabStart = true;
    threadstart = true;
    countstart = true;
    this->grabthread->setThreadStart(this->threadstart);
    this->countThread->setCountStart(this->countstart);
    this->grabthread->startRun(m_pcMyCamera,(HWND)ui->showLab->winId());
    this->countThread->start((QThread::Priority)7);
}

void Widget::on_searchBtn_clicked()
{
    ui->openBtn->setEnabled(true);
    QString str1;

    memset(&m_stDevList, 0, sizeof(MV_CC_DEVICE_INFO_LIST));

    // ch:枚举子网内所有设备 | en:Enumerate all devices within subnet
    int nRet = CMvCamera::EnumDevices(MV_GIGE_DEVICE | MV_USB_DEVICE, &m_stDevList);
    if (MV_OK != nRet)
    {
        return;
    }

    // ch:将值加入到信息列表框中并显示出来 | en:Add value to the information list box and display
    for (unsigned int i = 0; i < m_stDevList.nDeviceNum; i++)
    {
        MV_CC_DEVICE_INFO* pDeviceInfo = m_stDevList.pDeviceInfo[i];
        if (NULL == pDeviceInfo)
        {
            continue;
        }

        wchar_t* pUserName = NULL;
        if (pDeviceInfo->nTLayerType == MV_GIGE_DEVICE)
        {
//            int nIp1 = ((m_stDevList.pDeviceInfo[i]->SpecialInfo.stGigEInfo.nCurrentIp & 0xff000000) >> 24);
//            int nIp2 = ((m_stDevList.pDeviceInfo[i]->SpecialInfo.stGigEInfo.nCurrentIp & 0x00ff0000) >> 16);
//            int nIp3 = ((m_stDevList.pDeviceInfo[i]->SpecialInfo.stGigEInfo.nCurrentIp & 0x0000ff00) >> 8);
//            int nIp4 = (m_stDevList.pDeviceInfo[i]->SpecialInfo.stGigEInfo.nCurrentIp & 0x000000ff);

            if (strcmp("", (LPCSTR)(pDeviceInfo->SpecialInfo.stGigEInfo.chUserDefinedName)) != 0)
            {
                DWORD dwLenUserName = MultiByteToWideChar(CP_ACP, 0, (LPCSTR)(pDeviceInfo->SpecialInfo.stGigEInfo.chUserDefinedName), -1, NULL, 0);
                pUserName = new wchar_t[dwLenUserName];
                MultiByteToWideChar(CP_ACP, 0, (LPCSTR)(pDeviceInfo->SpecialInfo.stGigEInfo.chUserDefinedName), -1, pUserName, dwLenUserName);
            }
            else
            {
                char strUserName[256] = {0};
                sprintf_s(strUserName, 256, "%s %s (%s)", pDeviceInfo->SpecialInfo.stGigEInfo.chManufacturerName,
                    pDeviceInfo->SpecialInfo.stGigEInfo.chModelName,
                    pDeviceInfo->SpecialInfo.stGigEInfo.chSerialNumber);
                DWORD dwLenUserName = MultiByteToWideChar(CP_ACP, 0, (LPCSTR)(strUserName), -1, NULL, 0);
                pUserName = new wchar_t[dwLenUserName];
                MultiByteToWideChar(CP_ACP, 0, (LPCSTR)(strUserName), -1, pUserName, dwLenUserName);
            }
            str1= QString::fromLocal8Bit("[")+QString::number(i)+QString::fromLocal8Bit("]")
                    +QString::fromLocal8Bit("GigE")+QString::fromLocal8Bit("   ")+QString::fromWCharArray(pUserName);
            //str1 = QString::fromLocal8Bit(reinterpret_cast<char*>(pDeviceInfo->SpecialInfo.stGigEInfo.chModelName));
        }
        else if (pDeviceInfo->nTLayerType == MV_USB_DEVICE)
        {
            if (strcmp("", (char*)pDeviceInfo->SpecialInfo.stUsb3VInfo.chUserDefinedName) != 0)
            {
                DWORD dwLenUserName = MultiByteToWideChar(CP_ACP, 0, (LPCSTR)(pDeviceInfo->SpecialInfo.stUsb3VInfo.chUserDefinedName), -1, NULL, 0);
                pUserName = new wchar_t[dwLenUserName];
                MultiByteToWideChar(CP_ACP, 0, (LPCSTR)(pDeviceInfo->SpecialInfo.stUsb3VInfo.chUserDefinedName), -1, pUserName, dwLenUserName);
            }
            else
            {
                char strUserName[256] = {0};
                sprintf_s(strUserName, 256, "%s %s (%s)", pDeviceInfo->SpecialInfo.stUsb3VInfo.chManufacturerName,
                    pDeviceInfo->SpecialInfo.stUsb3VInfo.chModelName,
                    pDeviceInfo->SpecialInfo.stUsb3VInfo.chSerialNumber);
                DWORD dwLenUserName = MultiByteToWideChar(CP_ACP, 0, (LPCSTR)(strUserName), -1, NULL, 0);
                pUserName = new wchar_t[dwLenUserName];
                MultiByteToWideChar(CP_ACP, 0, (LPCSTR)(strUserName), -1, pUserName, dwLenUserName);
            }
            str1= QString::fromLocal8Bit("[")+QString::number(i)+QString::fromLocal8Bit("]")
                    +QString::fromLocal8Bit("UsbV3")+QString::fromLocal8Bit("   ")+QString::fromWCharArray(pUserName);
            //str1 = QString::fromLocal8Bit(reinterpret_cast<char*>(pDeviceInfo->SpecialInfo.stGigEInfo.chModelName));
            //qDebug() << QString::fromLocal8Bit(reinterpret_cast<char*>(pDeviceInfo->SpecialInfo.stGigEInfo.chModelName));
            //qDebug() << QString::fromLocal8Bit(reinterpret_cast<char*>(pDeviceInfo->SpecialInfo.stGigEInfo.chSerialNumber));
        }
        else
        {
            QMessageBox::warning(this, "提示","Unknown device enumerated!",QMessageBox::Ok|QMessageBox::Cancel,QMessageBox::Ok);
            return;
        }
        ui->comboBox->addItem(str1);
        if (pUserName)
        {
            delete[] pUserName;
            pUserName = NULL;
        }
    }
}

void Widget::on_closeBtn_clicked()
{
    if(this->readTimer->isActive())
    {
        this->readTimer->stop();  //停止信号检测定时器
    }
    if(this->update->isActive())
    {
        this->update->stop();  //停止信号发送定时器
    }
    //按钮
    ui->startBtn->setEnabled(false);
    ui->stopBtn->setEnabled(false);
    ui->openBtn->setEnabled(true);
    ui->closeBtn->setEnabled(false);
    //下拉框
    ui->selectCob->setEnabled(false);
    ui->modeCob->setEnabled(false);
    ui->sourceCob->setEnabled(false);
    ui->encselectCob->setEnabled(false);
    ui->encsourceACob->setEnabled(false);
    ui->encsourceBCob->setEnabled(false);
    ui->inputCob->setEnabled(false);
    //编辑框
    ui->widthlineEdit->setEnabled(false);
    ui->heightlineEdit->setEnabled(false);
    ui->lineEdit->setEnabled(false);
    //this->grabthread->wait();
    //this->update->stop();

//    if(timestart == true)
//    {
//        this->update->stop();
//        timestart = false;
//    }

    //关闭定时器
    threadstart = false;
    this->grabthread->setThreadStart(this->threadstart);
    countstart = false;
    this->countThread->setCountStart(this->countstart);

    if(grabStart == true)
    {
        m_pcMyCamera->StopGrabbing();
    }

    if (m_pcMyCamera)
    {
        m_pcMyCamera->Close();
        delete m_pcMyCamera;
        m_pcMyCamera = NULL;
    }
    ui->showLab->clear();
}

void Widget::on_selectCob_currentIndexChanged(int index)
{
    m_selectIndex = index;
    if(m_selectIndex == 0)
    {
        ft.fselector = 6;
        //setcombox(ft.fselector,ft.fmode,ft.fsource[1]);  //将模式设置到相机
        ui->modeCob->setCurrentIndex(ft.fmode);
        ui->sourceCob->setCurrentIndex(ft.fsource[0]);
    }
    else
    {
        lt.lselector = 9;
        //setcombox(lt.lselector,lt.lmode,lt.lsource[1]);  //将模式设置到相机
        ui->modeCob->setCurrentIndex(lt.lmode);
        ui->sourceCob->setCurrentIndex(lt.lsource[0]);
    }

    setcombox(ft.fselector,ft.fmode,ft.fsource[1],lt.lselector,lt.lmode,lt.lsource[1]);
}

void Widget::on_modeCob_currentIndexChanged(int index)
{
    m_modeIndex = index;
    if(m_selectIndex == 0)
    {
        ft.fmode = m_modeIndex;
        //setcombox(ft.fselector,ft.fmode,ft.fsource[1]);  //将模式设置到相机
    }
    else
    {
        lt.lmode = m_modeIndex;
        //setcombox(lt.lselector,lt.lmode,lt.lsource[1]);  //将模式设置到相机
    }
    setcombox(ft.fselector,ft.fmode,ft.fsource[1],lt.lselector,lt.lmode,lt.lsource[1]);
}

void Widget::on_sourceCob_currentIndexChanged(int index)
{
    switch (index)
    {
    case 0:
        m_sourceNum = 8;
    case 1:
        m_sourceNum = 0;
    case 2:
        m_sourceNum = 2;
    case 3:
        m_sourceNum = 3;
    case 4:
        m_sourceNum = 7;
    }

    m_sourceIndex = index;
    if(m_selectIndex == 0)
    {
        ft.fsource[0] = m_sourceIndex;
        ft.fsource[1] = m_sourceNum;
        //setcombox(ft.fselector,ft.fmode,ft.fsource[1]);  //将模式设置到相机
    }
    else
    {
        lt.lsource[0] = m_sourceIndex;
        lt.lsource[1] = m_sourceNum;
        //setcombox(lt.lselector,lt.lmode,lt.lsource[1]);  //将模式设置到相机
    }
    setcombox(ft.fselector,ft.fmode,ft.fsource[1],lt.lselector,lt.lmode,lt.lsource[1]);
}

void Widget::on_pushButton_clicked()
{
//    if(grabthread->isRunning())
//    {
//        qDebug()<<"run";
//    }
//    qDebug()<<"-----------------------------------";
//    qDebug()<<"fselector:"<<ft.fselector;
//    qDebug()<<"fmode:"<<ft.fmode;
//    qDebug()<<"fsource[0]:"<<ft.fsource[0];
//    qDebug()<<"fsource[1]:"<<ft.fsource[1];
//    qDebug()<<"lselector:"<<lt.lselector;
//    qDebug()<<"lmode:"<<lt.lmode;
//    qDebug()<<"lsource[0]:"<<lt.lsource[0];
//    qDebug()<<"lsource[1]:"<<lt.lsource[1];

//    int num = this->grabthread->countNumber();
//    qDebug()<<"num:"<<num;

    writeData(1);
    this->readTimer->start();
//    this->readData();
}


void Widget::on_encselectCob_currentIndexChanged(int index)
{

}

void Widget::on_encsourceACob_currentIndexChanged(int index)
{
    switch(index)
    {
    case 0:
        this->m_pcMyCamera->SetEnumValue("EncoderSourceA",0);
    case 1:
        this->m_pcMyCamera->SetEnumValue("EncoderSourceA",2);
    case 2:
        this->m_pcMyCamera->SetEnumValue("EncoderSourceA",3);
    }
}

void Widget::on_encsourceBCob_currentIndexChanged(int index)
{
    switch(index)
    {
    case 0:
        this->m_pcMyCamera->SetEnumValue("EncoderSourceB",0);
    case 1:
        this->m_pcMyCamera->SetEnumValue("EncoderSourceB",2);
    case 2:
        this->m_pcMyCamera->SetEnumValue("EncoderSourceB",3);
    }
}

void Widget::on_inputCob_currentIndexChanged(int index)
{
    switch(index)
    {
    case 0:
        this->m_pcMyCamera->SetEnumValue("InputSource",0);
    case 1:
        this->m_pcMyCamera->SetEnumValue("InputSource",2);
    case 2:
        this->m_pcMyCamera->SetEnumValue("InputSource",3);
    case 3:
        this->m_pcMyCamera->SetEnumValue("InputSource",7);
    }
}

void Widget::on_clearBtn_clicked()
{
    //this->grabthread->clearNum();
    this->countThread->clearNum();
}

void Widget::on_plcControl_clicked()
{
   //打开plc控制界面
    this->plc->show();
}

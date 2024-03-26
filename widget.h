#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include"MvCamera.h"
#include"grabthread.h"
#include"countthread.h"
#include<QTimer>
#include"plccontrol.h"


struct frametrigger
{
    int fselector = 0;
    int fmode = 0;
    int fsource[2] = {0,8};
};

struct linetrigger
{
    int lselector = 0;
    int lmode = 0;
    int lsource[2] = {0,8};
};

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    void initialize();  //初始化数据
    void attributeinitia();  //属性设置初始化
    void setEnablefalse();  //设置按钮是都可按
    void timerstart();  //更新数据与定时器启动
    void setlineEdit();  //设置lineEdit属性
    void setcombox(int fselect,int fmode,int fsource,int lselect,int lmode,int lsource);  //将属性设置到相机
    void writeData(quint16 value);  //串口写入数据
    void startGather();  //开始采集图像
    void stopGather();  //停止采集图像

signals:
    void showWaring();

public slots:
    void onTimerOut();
    void Waring();
    void showReceiveData(int data);
    void readData();  //串口读取函数

private slots:
    void on_openBtn_clicked();

    void on_setSoftBtn_clicked();

    void on_softBtn_clicked();

    void on_stopBtn_clicked();

    void on_startBtn_clicked();

    void on_searchBtn_clicked();

    void on_closeBtn_clicked();

    void on_selectCob_currentIndexChanged(int index);

    void on_modeCob_currentIndexChanged(int index);

    void on_pushButton_clicked();

    void on_sourceCob_currentIndexChanged(int index);

    void on_encselectCob_currentIndexChanged(int index);

    void on_encsourceACob_currentIndexChanged(int index);

    void on_encsourceBCob_currentIndexChanged(int index);

    void on_inputCob_currentIndexChanged(int index);

    void on_clearBtn_clicked();

    void on_plcControl_clicked();

   // void on_numberEdit_textEdited(const QString &arg1);

private:
    Ui::Widget *ui;

    MV_CC_DEVICE_INFO_LIST m_stDevList;  //存储各个相机
    CMvCamera* m_pcMyCamera;  //相机对象
    GrabThread* grabthread;  //取流线程对象
    CountThread* countThread;  //计数线程对象
    PlcControl *plc;           // plc通信类对象
    QModbusClient *modbusDevice;  //modbus线程对象

    bool threadstart;  //线程是否启动
    bool countstart;  //计数线程是否启动
    bool grabStart;  //是否启动取流
    bool timestart;  //定时器是否启动
    bool ifwritedata1;  //是否传递信号1
    bool ifwritedata2;  //是否传递数据2
    bool ifreaddata1;  //是否接受数据1
    int m_Index;  //选择的相机标识
    QTimer* update;  //更新数据定时器
    QTimer* readTimer;  //读取信号定时器

    int m_width;
    int m_height;
    int m_lineRate;  //行频
    int m_selectIndex;  //
    int m_modeIndex;
    int m_sourceIndex;
    int m_sourceNum;

    frametrigger ft;
    linetrigger lt;

    int m_num;  //线圈个数
    int textNum;  //用于测试的数字
};
#endif // WIDGET_H

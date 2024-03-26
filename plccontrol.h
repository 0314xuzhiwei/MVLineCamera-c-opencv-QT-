#ifndef PLCCONTROL_H
#define PLCCONTROL_H

#include <QWidget>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QTime>
#include<QTimer>
#include <QModbusClient>
//#include <QLineSeries>
#include <QDebug>
#include<QMessageBox>
#include <QModbusRtuSerialMaster>
#include<QStatusBar>
#include<QString>

typedef unsigned short     uint16_t;

namespace Ui {
class PlcControl;
}

class PlcControl : public QWidget
{
    Q_OBJECT

public:
    explicit PlcControl(QWidget *parent = nullptr);
    ~PlcControl();

    void InitialSetting();//初始化设置
    void SearchSerialPorts();
    void ReadRequest();//读信号请求
    void writeRequest(QList<quint16> values);//写信号请求
    void ReadSerialData();//接收串口数据

signals:
    void sendData(int data);

private slots:


    void on_pushButton_clicked();

    void on_actionConnect1_clicked();

    void on_actionDisconnect1_clicked();

    void on_pushButtonRead_clicked();

    void on_pushButtonWrite_clicked();

    void on_checkBoxAuto_stateChanged(int arg1);

private:
    Ui::PlcControl *ui;
    QModbusReply *lastRequest = nullptr;//更新串口对象
    QModbusClient *modbusDevice = nullptr;//连接串口对象
    QTime         *time;
    QTimer        *pollTimer;
    //QChart *mChart;`
    //QValueAxis *axisY;
    //QValueAxis *axisX;
    //QLineSeries *lineSeries[8];
    //QTimer *chartTimer;
    uint16_t values[8];
    int ifcheck;  //判断是否自动读取
    int receiveData;  //接收到的值

};

#endif // PLCCONTROL_H

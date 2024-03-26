#include "plccontrol.h"
#include "ui_plccontrol.h"

#include <QModbusRtuSerialMaster>
#include <QLoggingCategory>

PlcControl::PlcControl(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PlcControl)
{
    ui->setupUi(this);
    modbusDevice = new QModbusRtuSerialMaster(this);//给modbus对象分配内存
    pollTimer=new QTimer();

    InitialSetting();//数据初始化

    //QLoggingCategory::setFilterRules(QStringLiteral("qt.modbus* = true"));
}

PlcControl::~PlcControl()
{
    pollTimer->stop();
    delete ui;

}

void PlcControl::InitialSetting()
{
    //对串口进行初始化

    //填充串口号组合框
    SearchSerialPorts();

    //填充串口波特率
    QStringList baud={"4800","9600","14400","19200","28800","38400","56000","57600","115200","128000","230400","256000"};
    ui->comboBoxBaud->addItems(baud);
    ui->comboBoxBaud->setCurrentIndex(1);

    //填充串口数据位
    ui->comboBoxData->addItem(u8"7位");
    ui->comboBoxData->addItem(u8"8位");
    ui->comboBoxData->addItem(u8"9位");
    ui->comboBoxData->setCurrentIndex(1);

    //填充串口校验位
    ui->comboBoxParity->addItem(u8"无校验");
    ui->comboBoxParity->addItem(u8"奇校验");
    ui->comboBoxParity->addItem(u8"偶校验");

    //填充串口停止位
    ui->comboBoxStop->addItem(u8"1位");
    ui->comboBoxStop->addItem(u8"1.5位");
    ui->comboBoxStop->addItem(u8"2位");

    //填充寄存器类型
    ui->comboBoxDataType->addItem("0 Coils");
    ui->comboBoxDataType->addItem("1 Input Status");
    ui->comboBoxDataType->addItem("3 Input Registers");
    ui->comboBoxDataType->addItem("4 Holding Registers");
    ui->comboBoxDataType->setCurrentIndex(3);

    //填充报文格式
    ui->comboBoxFormat->addItem("Modbus-RTU");
    ui->comboBoxFormat->addItem("Modbus-ASCII");

    //设置界面操作的初始状态
    ui->spinBoxInterval->setValue(1000);
}

void PlcControl::SearchSerialPorts()
{
    //搜索串口
    ui->comboBoxPort->clear();

    foreach(const QSerialPortInfo &info,QSerialPortInfo::availablePorts())//QSerialPortInfo()静态函数可以用来查看串口列表
    {
        ui->comboBoxPort->addItem(info.portName());
    }
}


void PlcControl::ReadRequest()
{
    //读数据请求

    if (!modbusDevice)
    {
        QMessageBox::information(NULL,  "Title",  u8"尚未连接从站设备");
        return;
    }

    QModbusDataUnit::RegisterType type;

    switch(ui->comboBoxDataType->currentIndex())
    {
        case 0:type=QModbusDataUnit::Coils;break;
        case 1:type=QModbusDataUnit::DiscreteInputs;break;
        case 2:type=QModbusDataUnit::InputRegisters;break;
        case 3:type=QModbusDataUnit::HoldingRegisters;break;
        default:type=QModbusDataUnit::Invalid;
    }

    int startAddress = ui->spinBoxStartRead->value();
    //Q_ASSERT(startAddress >= 0 && startAddress < 10);

    // do not go beyond 10 entries
    quint16 numberOfEntries = qMin(quint16(ui->spinBoxNumberRead->value()), quint16(10 - startAddress));
    QModbusDataUnit readUnit=QModbusDataUnit(type, startAddress, numberOfEntries);

     ui->statusShow->clear();
     //statusBar()->clearMessage();

    if (auto *reply = modbusDevice->sendReadRequest(readUnit, ui->spinBoxStation->value()))
    {
        if (!reply->isFinished())
        {
            //qDebug()<<"connect";
            connect(reply, &QModbusReply::finished, this, &PlcControl::ReadSerialData);
        }
        else
        {
            delete reply; // broadcast replies return immediately
        }
    }
    else
    {
      // statusBar()->showMessage(tr("Read error: ") + modbusDevice->errorString(), 5000);
        ui->statusShow->setText(tr("read error( 1%)").arg(modbusDevice->errorString()));
    }

}

void PlcControl::writeRequest(QList<quint16> values)
{
    qDebug()<<"run";
    if (!modbusDevice)
    {
        QMessageBox::information(NULL,  "Title",  u8"尚未连接从站设备");
        return;
    }

    QModbusDataUnit::RegisterType type;

    switch(ui->comboBoxDataType->currentIndex())
    {
        case 0:type=QModbusDataUnit::Coils;break;//线圈类型
        case 1:type=QModbusDataUnit::DiscreteInputs;break;//异地寄存器
        case 2:type=QModbusDataUnit::InputRegisters;break;
        case 3:type=QModbusDataUnit::HoldingRegisters;break;
        default:type=QModbusDataUnit::Invalid;
    }

    int startAddress = ui->spinBoxStartWrite->value();
    //Q_ASSERT(startAddress >= 0 && startAddress < 10);//Q_ASSERT用来调试前后程序是否符合条件

    QModbusDataUnit writeUnit = QModbusDataUnit(type,startAddress, values.size());

    for(int i=0; i<values.size(); i++)
    {
        writeUnit.setValue(i, values.at(i));
    }

    //serverEdit 发生给slave的ID
    if (auto *reply = modbusDevice->sendWriteRequest(writeUnit,ui->spinBoxStation->value()))
    {
        if (!reply->isFinished())
        {
            connect(reply, &QModbusReply::finished, this, [this, reply]()
            {
                if (reply->error() == QModbusDevice::ProtocolError)
                {
                    qDebug() << QString("Write response error: %1 (Mobus exception: 0x%2)")
                                .arg(reply->errorString()).arg(reply->rawResult().exceptionCode(), -1, 16);
                }
                else if (reply->error() != QModbusDevice::NoError)
                {
                    qDebug() << QString("Write response error: %1 (code: 0x%2)").
                                arg(reply->errorString()).arg(reply->error(), -1, 16);
                }
                reply->deleteLater();
            });
        }
        else
        {
            reply->deleteLater();
        }
    }
    else
    {
        qDebug() << QString(("Write error: ") + modbusDevice->errorString());
    }

}

void PlcControl::ReadSerialData()
{
    //接收串口数据
    auto reply = qobject_cast<QModbusReply *>(sender());
    if (!reply)
    {
        return;
    }
    if (reply->error() == QModbusDevice::NoError)
    {
        const QModbusDataUnit unit = reply->result();

        for (int i = 0, total = int(unit.valueCount()); i < total; ++i)
        {
            const QString entry = tr("Address: %1, Value: %2").arg(unit.startAddress() + i)
                                     .arg(QString::number(unit.value(i),
                                          unit.registerType() <= QModbusDataUnit::Coils ? 16 : 10));
            ui->textBrowser->append(entry);
            this->receiveData = unit.value(i);
            emit sendData(unit.value(i));

            if((unit.startAddress() + i)<8)
            {
                values[(unit.startAddress() + i)]=unit.value(i);
            }
        }
    }
    else if (reply->error() == QModbusDevice::ProtocolError)
    {
        ui->statusShow->setText(tr("Read response error: %1 (Mobus exception: 0x%2)").
                                    arg(reply->errorString()).
                                    arg(reply->rawResult().exceptionCode(), -1, 16));
//        ui->statusShow->setText(tr(""))
    }
    else
    {
        ui->statusShow->setText(tr("Read response error: %1 (code: 0x%2)").
                                    arg(reply->errorString()).
                                    arg(reply->error(), -1, 16));
    }

    reply->deleteLater();

}

void PlcControl::on_pushButtonRead_clicked()
{
    //手动读取
    //ReadRequest();
}

void PlcControl::on_pushButtonWrite_clicked()
{
    QList<quint16> values;

    QStringList str1=ui->lineEditWriteValue->text().split(",");

    //qDebug()<<str1.size();
    //qDebug()<<ui->spinBoxNumberWrite->value();

    for(int i=0;i<ui->spinBoxNumberWrite->value();i++)
    {
        values.append(str1[i].toUShort());
    }

    qDebug()<<values.size();
    writeRequest(values);
    qDebug()<<"ok";
}

void PlcControl::on_actionConnect1_clicked()
{
    //连接串口

    //检查是否搜索到串口，没有则返回
    if (!modbusDevice)
    {   qDebug()<<"there is no slot";
        return;}


    modbusDevice->setConnectionParameter(QModbusDevice::SerialPortNameParameter,ui->comboBoxPort->currentText());
    modbusDevice->setConnectionParameter(QModbusDevice::SerialBaudRateParameter,ui->comboBoxBaud->currentText().toInt());

    switch(ui->comboBoxParity->currentIndex())                   //设置奇偶校验
    {
        case 0: modbusDevice->setConnectionParameter(QModbusDevice::SerialParityParameter,QSerialPort::NoParity);break;
        default: break;
    }

    switch(ui->comboBoxData->currentIndex())                   //设置数据位数
    {
        case 1:modbusDevice->setConnectionParameter(QModbusDevice::SerialDataBitsParameter,QSerialPort::Data8);break;
        default: break;
    }

    switch(ui->comboBoxStop->currentIndex())                     //设置停止位
    {
        case 1: modbusDevice->setConnectionParameter(QModbusDevice::SerialStopBitsParameter,QSerialPort::OneStop);break;
        case 2: modbusDevice->setConnectionParameter(QModbusDevice::SerialStopBitsParameter,QSerialPort::TwoStop);break;
        default: break;
    }

    modbusDevice->setTimeout(1000);
    modbusDevice->setNumberOfRetries(3);

    if (modbusDevice->connectDevice())
    {
        //开启自动读取
        if(ui->checkBoxAuto->isChecked())
        {
            connect(pollTimer,&QTimer::timeout, this, &PlcControl::ReadRequest);
            pollTimer->setInterval(ui->spinBoxInterval->value());
            pollTimer->start();
            qDebug()<<"start";
        }

        //连接槽函数
        //QObject::connect(serialPort, &QSerialPort::readyRead, this, &MainWindow::ReadSerialData);

        // 设置控件可否使用
       ui->actionConnect1->setEnabled(false);
       ui->actionDisconnect1->setEnabled(true);
        //ui->actionRefresh->setEnabled(false);
    }
    else    //打开失败提示
    {

        QMessageBox::information(this,tr(u8"错误"),tr(u8"连接从站失败！"),QMessageBox::Ok);
    }
}


void PlcControl::on_actionDisconnect1_clicked()
{
    qDebug()<<"disconnect";
    //断开连接
    modbusDevice->disconnectDevice();
    pollTimer->stop();

    // 设置控件可否使用
    ui->actionConnect1->setEnabled(true);
    ui->actionDisconnect1->setEnabled(false);
    //ui->actionRefresh->setEnabled(true);
}



void PlcControl::on_pushButton_clicked()
{
    //测试
    ui->statusShow->setText("successfully");
}

void PlcControl::on_checkBoxAuto_stateChanged(int arg1)
{
    ifcheck = arg1;
}

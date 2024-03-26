/********************************************************************************
** Form generated from reading UI file 'plccontrol.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLCCONTROL_H
#define UI_PLCCONTROL_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PlcControl
{
public:
    QGridLayout *gridLayout;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_3;
    QLabel *label_6;
    QSpinBox *spinBoxStation;
    QLabel *label_10;
    QComboBox *comboBoxDataType;
    QLabel *label_13;
    QComboBox *comboBoxFormat;
    QLabel *label_9;
    QSpinBox *spinBoxStartRead;
    QLabel *label_7;
    QSpinBox *spinBoxNumberRead;
    QLabel *label_8;
    QSpinBox *spinBoxInterval;
    QPushButton *pushButtonRead;
    QLabel *label_11;
    QSpinBox *spinBoxStartWrite;
    QLabel *label_12;
    QSpinBox *spinBoxNumberWrite;
    QLabel *label_15;
    QLineEdit *lineEditWriteValue;
    QPushButton *pushButtonWrite;
    QCheckBox *checkBoxAuto;
    QPushButton *pushButton;
    QGroupBox *groupBox_5;
    QTextBrowser *textBrowser;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QLabel *label;
    QComboBox *comboBoxPort;
    QLabel *label_2;
    QComboBox *comboBoxBaud;
    QLabel *label_3;
    QComboBox *comboBoxData;
    QLabel *label_4;
    QComboBox *comboBoxParity;
    QLabel *label_5;
    QComboBox *comboBoxStop;
    QPushButton *actionDisconnect1;
    QPushButton *actionConnect1;
    QGroupBox *groupBox_3;
    QLabel *label_14;
    QLineEdit *lineEditSend;
    QPushButton *pushButtonSend;
    QLineEdit *statusShow;
    QLabel *label_16;

    void setupUi(QWidget *PlcControl)
    {
        if (PlcControl->objectName().isEmpty())
            PlcControl->setObjectName(QString::fromUtf8("PlcControl"));
        PlcControl->resize(1064, 762);
        gridLayout = new QGridLayout(PlcControl);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBox_2 = new QGroupBox(PlcControl);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy);
        groupBox_2->setMaximumSize(QSize(250, 16777215));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font.setPointSize(12);
        groupBox_2->setFont(font);
        gridLayout_3 = new QGridLayout(groupBox_2);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font);

        gridLayout_3->addWidget(label_6, 0, 0, 1, 1);

        spinBoxStation = new QSpinBox(groupBox_2);
        spinBoxStation->setObjectName(QString::fromUtf8("spinBoxStation"));
        spinBoxStation->setMinimumSize(QSize(50, 30));
        spinBoxStation->setFont(font);
        spinBoxStation->setAlignment(Qt::AlignCenter);
        spinBoxStation->setMinimum(1);
        spinBoxStation->setMaximum(254);

        gridLayout_3->addWidget(spinBoxStation, 0, 1, 1, 1);

        label_10 = new QLabel(groupBox_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setFont(font);

        gridLayout_3->addWidget(label_10, 1, 0, 1, 1);

        comboBoxDataType = new QComboBox(groupBox_2);
        comboBoxDataType->setObjectName(QString::fromUtf8("comboBoxDataType"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(comboBoxDataType->sizePolicy().hasHeightForWidth());
        comboBoxDataType->setSizePolicy(sizePolicy1);
        comboBoxDataType->setMinimumSize(QSize(50, 30));
        comboBoxDataType->setFont(font);

        gridLayout_3->addWidget(comboBoxDataType, 1, 1, 1, 1);

        label_13 = new QLabel(groupBox_2);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setFont(font);

        gridLayout_3->addWidget(label_13, 2, 0, 1, 1);

        comboBoxFormat = new QComboBox(groupBox_2);
        comboBoxFormat->setObjectName(QString::fromUtf8("comboBoxFormat"));
        sizePolicy1.setHeightForWidth(comboBoxFormat->sizePolicy().hasHeightForWidth());
        comboBoxFormat->setSizePolicy(sizePolicy1);
        comboBoxFormat->setMinimumSize(QSize(50, 30));
        comboBoxFormat->setFont(font);

        gridLayout_3->addWidget(comboBoxFormat, 2, 1, 1, 1);

        label_9 = new QLabel(groupBox_2);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setFont(font);

        gridLayout_3->addWidget(label_9, 3, 0, 1, 1);

        spinBoxStartRead = new QSpinBox(groupBox_2);
        spinBoxStartRead->setObjectName(QString::fromUtf8("spinBoxStartRead"));
        spinBoxStartRead->setMinimumSize(QSize(50, 30));
        spinBoxStartRead->setFont(font);
        spinBoxStartRead->setAlignment(Qt::AlignCenter);
        spinBoxStartRead->setMaximum(65535);

        gridLayout_3->addWidget(spinBoxStartRead, 3, 1, 1, 1);

        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font);

        gridLayout_3->addWidget(label_7, 4, 0, 1, 1);

        spinBoxNumberRead = new QSpinBox(groupBox_2);
        spinBoxNumberRead->setObjectName(QString::fromUtf8("spinBoxNumberRead"));
        spinBoxNumberRead->setMinimumSize(QSize(50, 30));
        spinBoxNumberRead->setFont(font);
        spinBoxNumberRead->setAlignment(Qt::AlignCenter);
        spinBoxNumberRead->setMinimum(1);
        spinBoxNumberRead->setMaximum(125);

        gridLayout_3->addWidget(spinBoxNumberRead, 4, 1, 1, 1);

        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setFont(font);

        gridLayout_3->addWidget(label_8, 5, 0, 1, 1);

        spinBoxInterval = new QSpinBox(groupBox_2);
        spinBoxInterval->setObjectName(QString::fromUtf8("spinBoxInterval"));
        spinBoxInterval->setMinimumSize(QSize(50, 30));
        spinBoxInterval->setFont(font);
        spinBoxInterval->setAlignment(Qt::AlignCenter);
        spinBoxInterval->setMinimum(1);
        spinBoxInterval->setMaximum(3600000);
        spinBoxInterval->setValue(1000);

        gridLayout_3->addWidget(spinBoxInterval, 5, 1, 1, 1);

        pushButtonRead = new QPushButton(groupBox_2);
        pushButtonRead->setObjectName(QString::fromUtf8("pushButtonRead"));
        pushButtonRead->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/images/books.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonRead->setIcon(icon);

        gridLayout_3->addWidget(pushButtonRead, 7, 1, 1, 1);

        label_11 = new QLabel(groupBox_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setFont(font);

        gridLayout_3->addWidget(label_11, 8, 0, 1, 1);

        spinBoxStartWrite = new QSpinBox(groupBox_2);
        spinBoxStartWrite->setObjectName(QString::fromUtf8("spinBoxStartWrite"));
        spinBoxStartWrite->setFont(font);
        spinBoxStartWrite->setAlignment(Qt::AlignCenter);
        spinBoxStartWrite->setMaximum(65535);

        gridLayout_3->addWidget(spinBoxStartWrite, 8, 1, 1, 1);

        label_12 = new QLabel(groupBox_2);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setFont(font);

        gridLayout_3->addWidget(label_12, 9, 0, 1, 1);

        spinBoxNumberWrite = new QSpinBox(groupBox_2);
        spinBoxNumberWrite->setObjectName(QString::fromUtf8("spinBoxNumberWrite"));
        spinBoxNumberWrite->setFont(font);
        spinBoxNumberWrite->setAlignment(Qt::AlignCenter);
        spinBoxNumberWrite->setMinimum(1);
        spinBoxNumberWrite->setMaximum(125);

        gridLayout_3->addWidget(spinBoxNumberWrite, 9, 1, 1, 1);

        label_15 = new QLabel(groupBox_2);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setFont(font);

        gridLayout_3->addWidget(label_15, 10, 0, 1, 1);

        lineEditWriteValue = new QLineEdit(groupBox_2);
        lineEditWriteValue->setObjectName(QString::fromUtf8("lineEditWriteValue"));
        lineEditWriteValue->setFont(font);

        gridLayout_3->addWidget(lineEditWriteValue, 10, 1, 1, 1);

        pushButtonWrite = new QPushButton(groupBox_2);
        pushButtonWrite->setObjectName(QString::fromUtf8("pushButtonWrite"));
        pushButtonWrite->setFont(font);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/images/Write.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonWrite->setIcon(icon1);

        gridLayout_3->addWidget(pushButtonWrite, 11, 1, 1, 1);

        checkBoxAuto = new QCheckBox(groupBox_2);
        checkBoxAuto->setObjectName(QString::fromUtf8("checkBoxAuto"));
        checkBoxAuto->setFont(font);
        checkBoxAuto->setCheckable(true);

        gridLayout_3->addWidget(checkBoxAuto, 7, 0, 1, 1);

        pushButton = new QPushButton(groupBox_2);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout_3->addWidget(pushButton, 11, 0, 1, 1);


        gridLayout->addWidget(groupBox_2, 1, 0, 2, 1);

        groupBox_5 = new QGroupBox(PlcControl);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        groupBox_5->setMinimumSize(QSize(700, 0));
        groupBox_5->setMaximumSize(QSize(850, 16777215));
        groupBox_5->setFont(font);
        textBrowser = new QTextBrowser(groupBox_5);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(20, 40, 741, 511));
        textBrowser->setFont(font);

        gridLayout->addWidget(groupBox_5, 0, 1, 2, 1);

        groupBox = new QGroupBox(PlcControl);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        groupBox->setMinimumSize(QSize(200, 0));
        groupBox->setMaximumSize(QSize(250, 16777215));
        groupBox->setFont(font);
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);
        label->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        comboBoxPort = new QComboBox(groupBox);
        comboBoxPort->setObjectName(QString::fromUtf8("comboBoxPort"));
        sizePolicy1.setHeightForWidth(comboBoxPort->sizePolicy().hasHeightForWidth());
        comboBoxPort->setSizePolicy(sizePolicy1);
        comboBoxPort->setMinimumSize(QSize(0, 30));
        comboBoxPort->setFont(font);

        gridLayout_2->addWidget(comboBoxPort, 0, 1, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        gridLayout_2->addWidget(label_2, 1, 0, 1, 1);

        comboBoxBaud = new QComboBox(groupBox);
        comboBoxBaud->setObjectName(QString::fromUtf8("comboBoxBaud"));
        sizePolicy1.setHeightForWidth(comboBoxBaud->sizePolicy().hasHeightForWidth());
        comboBoxBaud->setSizePolicy(sizePolicy1);
        comboBoxBaud->setMinimumSize(QSize(0, 30));
        comboBoxBaud->setFont(font);

        gridLayout_2->addWidget(comboBoxBaud, 1, 1, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        gridLayout_2->addWidget(label_3, 2, 0, 1, 1);

        comboBoxData = new QComboBox(groupBox);
        comboBoxData->setObjectName(QString::fromUtf8("comboBoxData"));
        sizePolicy1.setHeightForWidth(comboBoxData->sizePolicy().hasHeightForWidth());
        comboBoxData->setSizePolicy(sizePolicy1);
        comboBoxData->setMinimumSize(QSize(0, 30));
        comboBoxData->setFont(font);

        gridLayout_2->addWidget(comboBoxData, 2, 1, 1, 1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);
        label_4->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        gridLayout_2->addWidget(label_4, 3, 0, 1, 1);

        comboBoxParity = new QComboBox(groupBox);
        comboBoxParity->setObjectName(QString::fromUtf8("comboBoxParity"));
        sizePolicy1.setHeightForWidth(comboBoxParity->sizePolicy().hasHeightForWidth());
        comboBoxParity->setSizePolicy(sizePolicy1);
        comboBoxParity->setMinimumSize(QSize(0, 30));
        comboBoxParity->setFont(font);

        gridLayout_2->addWidget(comboBoxParity, 3, 1, 1, 1);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font);
        label_5->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        gridLayout_2->addWidget(label_5, 4, 0, 1, 1);

        comboBoxStop = new QComboBox(groupBox);
        comboBoxStop->setObjectName(QString::fromUtf8("comboBoxStop"));
        sizePolicy1.setHeightForWidth(comboBoxStop->sizePolicy().hasHeightForWidth());
        comboBoxStop->setSizePolicy(sizePolicy1);
        comboBoxStop->setMinimumSize(QSize(0, 30));
        comboBoxStop->setFont(font);

        gridLayout_2->addWidget(comboBoxStop, 4, 1, 1, 1);

        actionDisconnect1 = new QPushButton(groupBox);
        actionDisconnect1->setObjectName(QString::fromUtf8("actionDisconnect1"));

        gridLayout_2->addWidget(actionDisconnect1, 6, 1, 1, 1);

        actionConnect1 = new QPushButton(groupBox);
        actionConnect1->setObjectName(QString::fromUtf8("actionConnect1"));

        gridLayout_2->addWidget(actionConnect1, 6, 0, 1, 1);


        gridLayout->addWidget(groupBox, 0, 0, 1, 1);

        groupBox_3 = new QGroupBox(PlcControl);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setFont(font);
        label_14 = new QLabel(groupBox_3);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(20, 40, 91, 51));
        label_14->setFont(font);
        lineEditSend = new QLineEdit(groupBox_3);
        lineEditSend->setObjectName(QString::fromUtf8("lineEditSend"));
        lineEditSend->setGeometry(QRect(110, 40, 511, 61));
        lineEditSend->setFont(font);
        pushButtonSend = new QPushButton(groupBox_3);
        pushButtonSend->setObjectName(QString::fromUtf8("pushButtonSend"));
        pushButtonSend->setGeometry(QRect(630, 40, 81, 51));
        pushButtonSend->setFont(font);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/images/send.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonSend->setIcon(icon2);
        statusShow = new QLineEdit(groupBox_3);
        statusShow->setObjectName(QString::fromUtf8("statusShow"));
        statusShow->setGeometry(QRect(110, 130, 641, 61));
        label_16 = new QLabel(groupBox_3);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(20, 140, 91, 41));

        gridLayout->addWidget(groupBox_3, 2, 1, 1, 1);


        retranslateUi(PlcControl);

        QMetaObject::connectSlotsByName(PlcControl);
    } // setupUi

    void retranslateUi(QWidget *PlcControl)
    {
        PlcControl->setWindowTitle(QCoreApplication::translate("PlcControl", "Form", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("PlcControl", "\344\272\244\344\272\222\351\205\215\347\275\256", nullptr));
        label_6->setText(QCoreApplication::translate("PlcControl", "\344\273\216\347\253\231\345\234\260\345\235\200\357\274\232", nullptr));
        label_10->setText(QCoreApplication::translate("PlcControl", "\346\225\260\346\215\256\347\261\273\345\236\213\357\274\232", nullptr));
        label_13->setText(QCoreApplication::translate("PlcControl", "\346\212\245\346\226\207\346\240\274\345\274\217\357\274\232", nullptr));
        label_9->setText(QCoreApplication::translate("PlcControl", "\350\265\267\345\247\213\345\234\260\345\235\200\357\274\232", nullptr));
        label_7->setText(QCoreApplication::translate("PlcControl", "\350\257\273\345\217\226\346\225\260\351\207\217\357\274\232", nullptr));
        label_8->setText(QCoreApplication::translate("PlcControl", "\351\227\264\351\232\224\345\221\250\346\234\237\357\274\232", nullptr));
        pushButtonRead->setText(QCoreApplication::translate("PlcControl", "  \350\257\273\345\217\226", nullptr));
        label_11->setText(QCoreApplication::translate("PlcControl", "\350\265\267\345\247\213\345\234\260\345\235\200\357\274\232", nullptr));
        label_12->setText(QCoreApplication::translate("PlcControl", "\345\206\231\345\205\245\346\225\260\351\207\217\357\274\232", nullptr));
        label_15->setText(QCoreApplication::translate("PlcControl", "\345\206\231\345\205\245\346\225\260\345\200\274\357\274\232", nullptr));
        pushButtonWrite->setText(QCoreApplication::translate("PlcControl", "  \345\206\231\345\205\245", nullptr));
        checkBoxAuto->setText(QCoreApplication::translate("PlcControl", "\350\207\252\345\212\250\350\257\273\345\217\226", nullptr));
        pushButton->setText(QCoreApplication::translate("PlcControl", "test", nullptr));
        groupBox_5->setTitle(QCoreApplication::translate("PlcControl", "\346\224\266\345\217\221\346\230\276\347\244\272", nullptr));
        groupBox->setTitle(QCoreApplication::translate("PlcControl", "\344\270\262\345\217\243\351\205\215\347\275\256", nullptr));
        label->setText(QCoreApplication::translate("PlcControl", "\344\270\262\345\217\243\345\217\267\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("PlcControl", "\346\263\242\347\211\271\347\216\207\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("PlcControl", "\346\225\260\346\215\256\344\275\215\357\274\232", nullptr));
        label_4->setText(QCoreApplication::translate("PlcControl", "\346\240\241\351\252\214\344\275\215\357\274\232", nullptr));
        label_5->setText(QCoreApplication::translate("PlcControl", "\345\201\234\346\255\242\344\275\215\357\274\232", nullptr));
        actionDisconnect1->setText(QCoreApplication::translate("PlcControl", "\346\226\255\345\274\200\350\277\236\346\216\245", nullptr));
        actionConnect1->setText(QCoreApplication::translate("PlcControl", "\350\277\236\346\216\245", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("PlcControl", "\346\223\215\344\275\234\345\214\272\345\237\237", nullptr));
        label_14->setText(QCoreApplication::translate("PlcControl", "\345\217\221\351\200\201\345\221\275\344\273\244\357\274\232", nullptr));
        pushButtonSend->setText(QCoreApplication::translate("PlcControl", "\345\217\221\351\200\201", nullptr));
        label_16->setText(QCoreApplication::translate("PlcControl", "\347\212\266\346\200\201\344\277\241\346\201\257\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PlcControl: public Ui_PlcControl {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLCCONTROL_H

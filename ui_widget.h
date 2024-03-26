/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QComboBox *comboBox;
    QSpacerItem *verticalSpacer_2;
    QFormLayout *formLayout_2;
    QGridLayout *gridLayout_2;
    QPushButton *openBtn;
    QSpacerItem *verticalSpacer_3;
    QPushButton *searchBtn;
    QPushButton *setSoftBtn;
    QPushButton *softBtn;
    QSpacerItem *verticalSpacer;
    QPushButton *startBtn;
    QPushButton *stopBtn;
    QPushButton *closeBtn;
    QPushButton *clearBtn;
    QPushButton *pushButton;
    QPushButton *plcControl;
    QFormLayout *formLayout;
    QLabel *widthLab;
    QLabel *heightLab;
    QLabel *lineLab;
    QLabel *selectLab;
    QLabel *modeLab;
    QLabel *sourceLab;
    QLabel *encselectLab;
    QLabel *encsourceALab;
    QLabel *encsourceBLab;
    QLabel *inputLab;
    QLineEdit *widthlineEdit;
    QLineEdit *heightlineEdit;
    QLineEdit *lineEdit;
    QComboBox *selectCob;
    QComboBox *modeCob;
    QComboBox *sourceCob;
    QComboBox *encselectCob;
    QComboBox *encsourceACob;
    QComboBox *encsourceBCob;
    QComboBox *inputCob;
    QLabel *numberLab;
    QLineEdit *numberEdit;
    QVBoxLayout *verticalLayout_2;
    QLabel *showLab;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(1248, 657);
        QFont font;
        font.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font.setPointSize(12);
        Widget->setFont(font);
        Widget->setStyleSheet(QString::fromUtf8("background-color:rgb(199,237,233)"));
        gridLayout = new QGridLayout(Widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(-1, 0, -1, -1);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setSizeConstraint(QLayout::SetMaximumSize);
        label = new QLabel(Widget);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setStyleSheet(QString::fromUtf8("font-size: 20px"));

        horizontalLayout_2->addWidget(label);

        comboBox = new QComboBox(Widget);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(comboBox->sizePolicy().hasHeightForWidth());
        comboBox->setSizePolicy(sizePolicy1);
        comboBox->setMinimumSize(QSize(0, 50));
        comboBox->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font-size: 20px"));

        horizontalLayout_2->addWidget(comboBox);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Maximum);

        verticalLayout->addItem(verticalSpacer_2);

        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        openBtn = new QPushButton(Widget);
        openBtn->setObjectName(QString::fromUtf8("openBtn"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(openBtn->sizePolicy().hasHeightForWidth());
        openBtn->setSizePolicy(sizePolicy2);

        gridLayout_2->addWidget(openBtn, 3, 0, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 30, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout_2->addItem(verticalSpacer_3, 1, 0, 1, 1);

        searchBtn = new QPushButton(Widget);
        searchBtn->setObjectName(QString::fromUtf8("searchBtn"));
        sizePolicy2.setHeightForWidth(searchBtn->sizePolicy().hasHeightForWidth());
        searchBtn->setSizePolicy(sizePolicy2);

        gridLayout_2->addWidget(searchBtn, 0, 0, 1, 2);

        setSoftBtn = new QPushButton(Widget);
        setSoftBtn->setObjectName(QString::fromUtf8("setSoftBtn"));
        sizePolicy2.setHeightForWidth(setSoftBtn->sizePolicy().hasHeightForWidth());
        setSoftBtn->setSizePolicy(sizePolicy2);

        gridLayout_2->addWidget(setSoftBtn, 6, 0, 1, 1);

        softBtn = new QPushButton(Widget);
        softBtn->setObjectName(QString::fromUtf8("softBtn"));
        sizePolicy2.setHeightForWidth(softBtn->sizePolicy().hasHeightForWidth());
        softBtn->setSizePolicy(sizePolicy2);

        gridLayout_2->addWidget(softBtn, 6, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_2->addItem(verticalSpacer, 5, 1, 1, 1);

        startBtn = new QPushButton(Widget);
        startBtn->setObjectName(QString::fromUtf8("startBtn"));
        sizePolicy2.setHeightForWidth(startBtn->sizePolicy().hasHeightForWidth());
        startBtn->setSizePolicy(sizePolicy2);

        gridLayout_2->addWidget(startBtn, 4, 0, 1, 1);

        stopBtn = new QPushButton(Widget);
        stopBtn->setObjectName(QString::fromUtf8("stopBtn"));
        sizePolicy2.setHeightForWidth(stopBtn->sizePolicy().hasHeightForWidth());
        stopBtn->setSizePolicy(sizePolicy2);

        gridLayout_2->addWidget(stopBtn, 4, 1, 1, 1);

        closeBtn = new QPushButton(Widget);
        closeBtn->setObjectName(QString::fromUtf8("closeBtn"));
        sizePolicy2.setHeightForWidth(closeBtn->sizePolicy().hasHeightForWidth());
        closeBtn->setSizePolicy(sizePolicy2);

        gridLayout_2->addWidget(closeBtn, 3, 1, 1, 1);

        clearBtn = new QPushButton(Widget);
        clearBtn->setObjectName(QString::fromUtf8("clearBtn"));
        sizePolicy2.setHeightForWidth(clearBtn->sizePolicy().hasHeightForWidth());
        clearBtn->setSizePolicy(sizePolicy2);

        gridLayout_2->addWidget(clearBtn, 7, 0, 1, 1);

        pushButton = new QPushButton(Widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        sizePolicy2.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy2);

        gridLayout_2->addWidget(pushButton, 7, 1, 1, 1);

        plcControl = new QPushButton(Widget);
        plcControl->setObjectName(QString::fromUtf8("plcControl"));
        plcControl->setMinimumSize(QSize(0, 50));

        gridLayout_2->addWidget(plcControl, 5, 0, 1, 1);


        formLayout_2->setLayout(0, QFormLayout::LabelRole, gridLayout_2);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        widthLab = new QLabel(Widget);
        widthLab->setObjectName(QString::fromUtf8("widthLab"));
        sizePolicy.setHeightForWidth(widthLab->sizePolicy().hasHeightForWidth());
        widthLab->setSizePolicy(sizePolicy);
        widthLab->setStyleSheet(QString::fromUtf8("font-size: 20px"));

        formLayout->setWidget(1, QFormLayout::LabelRole, widthLab);

        heightLab = new QLabel(Widget);
        heightLab->setObjectName(QString::fromUtf8("heightLab"));
        heightLab->setStyleSheet(QString::fromUtf8("font-size: 20px"));

        formLayout->setWidget(2, QFormLayout::LabelRole, heightLab);

        lineLab = new QLabel(Widget);
        lineLab->setObjectName(QString::fromUtf8("lineLab"));
        lineLab->setStyleSheet(QString::fromUtf8("font-size: 20px"));

        formLayout->setWidget(3, QFormLayout::LabelRole, lineLab);

        selectLab = new QLabel(Widget);
        selectLab->setObjectName(QString::fromUtf8("selectLab"));
        selectLab->setStyleSheet(QString::fromUtf8("font-size: 20px"));

        formLayout->setWidget(4, QFormLayout::LabelRole, selectLab);

        modeLab = new QLabel(Widget);
        modeLab->setObjectName(QString::fromUtf8("modeLab"));
        modeLab->setStyleSheet(QString::fromUtf8("font-size: 20px"));

        formLayout->setWidget(5, QFormLayout::LabelRole, modeLab);

        sourceLab = new QLabel(Widget);
        sourceLab->setObjectName(QString::fromUtf8("sourceLab"));
        sourceLab->setStyleSheet(QString::fromUtf8("font-size: 20px"));

        formLayout->setWidget(6, QFormLayout::LabelRole, sourceLab);

        encselectLab = new QLabel(Widget);
        encselectLab->setObjectName(QString::fromUtf8("encselectLab"));
        encselectLab->setStyleSheet(QString::fromUtf8("font-size: 20px"));

        formLayout->setWidget(7, QFormLayout::LabelRole, encselectLab);

        encsourceALab = new QLabel(Widget);
        encsourceALab->setObjectName(QString::fromUtf8("encsourceALab"));
        encsourceALab->setStyleSheet(QString::fromUtf8("font-size: 20px"));

        formLayout->setWidget(8, QFormLayout::LabelRole, encsourceALab);

        encsourceBLab = new QLabel(Widget);
        encsourceBLab->setObjectName(QString::fromUtf8("encsourceBLab"));
        encsourceBLab->setStyleSheet(QString::fromUtf8("font-size: 20px"));

        formLayout->setWidget(9, QFormLayout::LabelRole, encsourceBLab);

        inputLab = new QLabel(Widget);
        inputLab->setObjectName(QString::fromUtf8("inputLab"));
        inputLab->setStyleSheet(QString::fromUtf8("font-size: 20px"));

        formLayout->setWidget(10, QFormLayout::LabelRole, inputLab);

        widthlineEdit = new QLineEdit(Widget);
        widthlineEdit->setObjectName(QString::fromUtf8("widthlineEdit"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(widthlineEdit->sizePolicy().hasHeightForWidth());
        widthlineEdit->setSizePolicy(sizePolicy3);
        widthlineEdit->setStyleSheet(QString::fromUtf8("font-size: 20px"));

        formLayout->setWidget(1, QFormLayout::FieldRole, widthlineEdit);

        heightlineEdit = new QLineEdit(Widget);
        heightlineEdit->setObjectName(QString::fromUtf8("heightlineEdit"));
        sizePolicy3.setHeightForWidth(heightlineEdit->sizePolicy().hasHeightForWidth());
        heightlineEdit->setSizePolicy(sizePolicy3);
        heightlineEdit->setStyleSheet(QString::fromUtf8("font-size: 20px"));

        formLayout->setWidget(2, QFormLayout::FieldRole, heightlineEdit);

        lineEdit = new QLineEdit(Widget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        sizePolicy3.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy3);
        lineEdit->setStyleSheet(QString::fromUtf8("font-size: 20px"));

        formLayout->setWidget(3, QFormLayout::FieldRole, lineEdit);

        selectCob = new QComboBox(Widget);
        selectCob->addItem(QString());
        selectCob->addItem(QString());
        selectCob->setObjectName(QString::fromUtf8("selectCob"));
        sizePolicy3.setHeightForWidth(selectCob->sizePolicy().hasHeightForWidth());
        selectCob->setSizePolicy(sizePolicy3);
        selectCob->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font-size: 20px"));

        formLayout->setWidget(4, QFormLayout::FieldRole, selectCob);

        modeCob = new QComboBox(Widget);
        modeCob->addItem(QString());
        modeCob->addItem(QString());
        modeCob->setObjectName(QString::fromUtf8("modeCob"));
        sizePolicy3.setHeightForWidth(modeCob->sizePolicy().hasHeightForWidth());
        modeCob->setSizePolicy(sizePolicy3);
        modeCob->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font-size: 20px"));

        formLayout->setWidget(5, QFormLayout::FieldRole, modeCob);

        sourceCob = new QComboBox(Widget);
        sourceCob->addItem(QString());
        sourceCob->addItem(QString());
        sourceCob->addItem(QString());
        sourceCob->addItem(QString());
        sourceCob->addItem(QString());
        sourceCob->setObjectName(QString::fromUtf8("sourceCob"));
        sizePolicy3.setHeightForWidth(sourceCob->sizePolicy().hasHeightForWidth());
        sourceCob->setSizePolicy(sizePolicy3);
        sourceCob->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font-size: 20px"));

        formLayout->setWidget(6, QFormLayout::FieldRole, sourceCob);

        encselectCob = new QComboBox(Widget);
        encselectCob->addItem(QString());
        encselectCob->setObjectName(QString::fromUtf8("encselectCob"));
        sizePolicy3.setHeightForWidth(encselectCob->sizePolicy().hasHeightForWidth());
        encselectCob->setSizePolicy(sizePolicy3);
        encselectCob->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font-size: 20px"));

        formLayout->setWidget(7, QFormLayout::FieldRole, encselectCob);

        encsourceACob = new QComboBox(Widget);
        encsourceACob->addItem(QString());
        encsourceACob->addItem(QString());
        encsourceACob->addItem(QString());
        encsourceACob->setObjectName(QString::fromUtf8("encsourceACob"));
        sizePolicy3.setHeightForWidth(encsourceACob->sizePolicy().hasHeightForWidth());
        encsourceACob->setSizePolicy(sizePolicy3);
        encsourceACob->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font-size: 20px"));

        formLayout->setWidget(8, QFormLayout::FieldRole, encsourceACob);

        encsourceBCob = new QComboBox(Widget);
        encsourceBCob->addItem(QString());
        encsourceBCob->addItem(QString());
        encsourceBCob->addItem(QString());
        encsourceBCob->setObjectName(QString::fromUtf8("encsourceBCob"));
        sizePolicy3.setHeightForWidth(encsourceBCob->sizePolicy().hasHeightForWidth());
        encsourceBCob->setSizePolicy(sizePolicy3);
        encsourceBCob->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font-size: 20px"));

        formLayout->setWidget(9, QFormLayout::FieldRole, encsourceBCob);

        inputCob = new QComboBox(Widget);
        inputCob->addItem(QString());
        inputCob->addItem(QString());
        inputCob->addItem(QString());
        inputCob->addItem(QString());
        inputCob->setObjectName(QString::fromUtf8("inputCob"));
        sizePolicy3.setHeightForWidth(inputCob->sizePolicy().hasHeightForWidth());
        inputCob->setSizePolicy(sizePolicy3);
        inputCob->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font-size: 20px"));

        formLayout->setWidget(10, QFormLayout::FieldRole, inputCob);

        numberLab = new QLabel(Widget);
        numberLab->setObjectName(QString::fromUtf8("numberLab"));
        numberLab->setStyleSheet(QString::fromUtf8("font-size: 20px"));

        formLayout->setWidget(0, QFormLayout::LabelRole, numberLab);

        numberEdit = new QLineEdit(Widget);
        numberEdit->setObjectName(QString::fromUtf8("numberEdit"));
        sizePolicy3.setHeightForWidth(numberEdit->sizePolicy().hasHeightForWidth());
        numberEdit->setSizePolicy(sizePolicy3);
        numberEdit->setStyleSheet(QString::fromUtf8("font-size: 20px"));
        numberEdit->setReadOnly(true);

        formLayout->setWidget(0, QFormLayout::FieldRole, numberEdit);


        formLayout_2->setLayout(0, QFormLayout::FieldRole, formLayout);


        verticalLayout->addLayout(formLayout_2);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        showLab = new QLabel(Widget);
        showLab->setObjectName(QString::fromUtf8("showLab"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(showLab->sizePolicy().hasHeightForWidth());
        showLab->setSizePolicy(sizePolicy4);
        showLab->setMinimumSize(QSize(750, 0));
        showLab->setSizeIncrement(QSize(0, 0));
        showLab->setBaseSize(QSize(0, 0));
        showLab->setStyleSheet(QString::fromUtf8("background-color:rgb(0,0,0)"));
        showLab->setFrameShape(QFrame::Panel);
        showLab->setFrameShadow(QFrame::Plain);

        verticalLayout_2->addWidget(showLab);


        gridLayout->addLayout(verticalLayout_2, 0, 1, 1, 1);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "\347\233\270\346\234\272\346\216\247\345\210\266\347\225\214\351\235\242", nullptr));
        label->setText(QCoreApplication::translate("Widget", "\345\217\257\347\224\250\350\256\276\345\244\207:", nullptr));
        openBtn->setText(QCoreApplication::translate("Widget", "\346\211\223\345\274\200\350\256\276\345\244\207", nullptr));
        searchBtn->setText(QCoreApplication::translate("Widget", "\346\237\245\350\257\242\350\256\276\345\244\207", nullptr));
        setSoftBtn->setText(QCoreApplication::translate("Widget", "\350\256\276\347\275\256\350\275\257\350\247\246\345\217\221", nullptr));
        softBtn->setText(QCoreApplication::translate("Widget", "\346\211\247\350\241\214\344\270\200\346\254\241", nullptr));
        startBtn->setText(QCoreApplication::translate("Widget", "\345\274\200\345\247\213\351\207\207\351\233\206", nullptr));
        stopBtn->setText(QCoreApplication::translate("Widget", "\345\201\234\346\255\242\351\207\207\351\233\206", nullptr));
        closeBtn->setText(QCoreApplication::translate("Widget", "\345\205\263\351\227\255\350\256\276\345\244\207", nullptr));
        clearBtn->setText(QCoreApplication::translate("Widget", "\344\270\252\346\225\260\346\270\205\351\233\266", nullptr));
        pushButton->setText(QCoreApplication::translate("Widget", "\346\265\213\350\257\225\346\214\211\351\222\256", nullptr));
        plcControl->setText(QCoreApplication::translate("Widget", "PLC\350\256\276\347\275\256", nullptr));
        widthLab->setText(QCoreApplication::translate("Widget", "\345\256\275\345\272\246:", nullptr));
        heightLab->setText(QCoreApplication::translate("Widget", "\351\253\230\345\272\246:", nullptr));
        lineLab->setText(QCoreApplication::translate("Widget", "\350\241\214\351\242\221:", nullptr));
        selectLab->setText(QCoreApplication::translate("Widget", "\350\247\246\345\217\221\345\231\250\351\200\211\346\213\251:", nullptr));
        modeLab->setText(QCoreApplication::translate("Widget", "\350\247\246\345\217\221\346\250\241\345\274\217:", nullptr));
        sourceLab->setText(QCoreApplication::translate("Widget", "\350\247\246\345\217\221\346\272\220:", nullptr));
        encselectLab->setText(QCoreApplication::translate("Widget", "\347\274\226\347\240\201\345\231\250\351\200\211\346\213\251:", nullptr));
        encsourceALab->setText(QCoreApplication::translate("Widget", "\347\274\226\347\240\201\345\231\250\346\272\220A:", nullptr));
        encsourceBLab->setText(QCoreApplication::translate("Widget", "\347\274\226\347\240\201\345\231\250\346\272\220B:", nullptr));
        inputLab->setText(QCoreApplication::translate("Widget", "\345\217\230\351\242\221\345\231\250\350\276\223\345\205\245\346\272\220:", nullptr));
        heightlineEdit->setText(QString());
        lineEdit->setText(QString());
        selectCob->setItemText(0, QCoreApplication::translate("Widget", "\345\270\247\350\247\246\345\217\221", nullptr));
        selectCob->setItemText(1, QCoreApplication::translate("Widget", "\350\241\214\350\247\246\345\217\221", nullptr));

        modeCob->setItemText(0, QCoreApplication::translate("Widget", "\345\205\263\351\227\255", nullptr));
        modeCob->setItemText(1, QCoreApplication::translate("Widget", "\346\211\223\345\274\200", nullptr));

        sourceCob->setItemText(0, QCoreApplication::translate("Widget", "\345\217\230\351\242\221\345\231\250\350\247\246\345\217\221", nullptr));
        sourceCob->setItemText(1, QCoreApplication::translate("Widget", "\347\272\277\350\267\2570", nullptr));
        sourceCob->setItemText(2, QCoreApplication::translate("Widget", "\347\272\277\350\267\2572", nullptr));
        sourceCob->setItemText(3, QCoreApplication::translate("Widget", "\347\272\277\350\267\2573", nullptr));
        sourceCob->setItemText(4, QCoreApplication::translate("Widget", "\350\275\257\350\247\246\345\217\221", nullptr));

        encselectCob->setItemText(0, QCoreApplication::translate("Widget", "\347\274\226\347\240\201\345\231\2500", nullptr));

        encsourceACob->setItemText(0, QCoreApplication::translate("Widget", "\347\272\277\350\267\2570", nullptr));
        encsourceACob->setItemText(1, QCoreApplication::translate("Widget", "\347\272\277\350\267\2572", nullptr));
        encsourceACob->setItemText(2, QCoreApplication::translate("Widget", "\347\272\277\350\267\2573", nullptr));

        encsourceBCob->setItemText(0, QCoreApplication::translate("Widget", "\347\272\277\350\267\2570", nullptr));
        encsourceBCob->setItemText(1, QCoreApplication::translate("Widget", "\347\272\277\350\267\2572", nullptr));
        encsourceBCob->setItemText(2, QCoreApplication::translate("Widget", "\347\272\277\350\267\2573", nullptr));

        inputCob->setItemText(0, QCoreApplication::translate("Widget", "\347\272\277\350\267\2570", nullptr));
        inputCob->setItemText(1, QCoreApplication::translate("Widget", "\347\272\277\350\267\2572", nullptr));
        inputCob->setItemText(2, QCoreApplication::translate("Widget", "\347\272\277\350\267\2573", nullptr));
        inputCob->setItemText(3, QCoreApplication::translate("Widget", "\347\274\226\347\240\201\345\231\250\346\250\241\345\235\227", nullptr));

        numberLab->setText(QCoreApplication::translate("Widget", "\347\272\277\345\234\210\344\270\252\346\225\260:", nullptr));
        showLab->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H

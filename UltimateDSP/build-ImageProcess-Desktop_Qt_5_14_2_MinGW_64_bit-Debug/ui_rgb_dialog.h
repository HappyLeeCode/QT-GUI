/********************************************************************************
** Form generated from reading UI file 'rgb_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RGB_DIALOG_H
#define UI_RGB_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RGB_Dialog
{
public:
    QPushButton *Button_RGBCommit;
    QPushButton *Button_RGBCancel;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_R;
    QLineEdit *lineEdit_R;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_G;
    QLineEdit *lineEdit_G;
    QWidget *widget2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_B;
    QLineEdit *lineEdit_B;

    void setupUi(QDialog *RGB_Dialog)
    {
        if (RGB_Dialog->objectName().isEmpty())
            RGB_Dialog->setObjectName(QString::fromUtf8("RGB_Dialog"));
        RGB_Dialog->resize(400, 297);
        Button_RGBCommit = new QPushButton(RGB_Dialog);
        Button_RGBCommit->setObjectName(QString::fromUtf8("Button_RGBCommit"));
        Button_RGBCommit->setGeometry(QRect(80, 240, 93, 28));
        Button_RGBCancel = new QPushButton(RGB_Dialog);
        Button_RGBCancel->setObjectName(QString::fromUtf8("Button_RGBCancel"));
        Button_RGBCancel->setGeometry(QRect(220, 240, 93, 28));
        widget = new QWidget(RGB_Dialog);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(70, 50, 251, 31));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_R = new QLabel(widget);
        label_R->setObjectName(QString::fromUtf8("label_R"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(12);
        label_R->setFont(font);

        horizontalLayout->addWidget(label_R);

        lineEdit_R = new QLineEdit(widget);
        lineEdit_R->setObjectName(QString::fromUtf8("lineEdit_R"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font1.setPointSize(12);
        lineEdit_R->setFont(font1);
        lineEdit_R->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(lineEdit_R);

        widget1 = new QWidget(RGB_Dialog);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(70, 110, 251, 31));
        horizontalLayout_2 = new QHBoxLayout(widget1);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_G = new QLabel(widget1);
        label_G->setObjectName(QString::fromUtf8("label_G"));
        label_G->setFont(font);

        horizontalLayout_2->addWidget(label_G);

        lineEdit_G = new QLineEdit(widget1);
        lineEdit_G->setObjectName(QString::fromUtf8("lineEdit_G"));
        lineEdit_G->setFont(font1);
        lineEdit_G->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(lineEdit_G);

        widget2 = new QWidget(RGB_Dialog);
        widget2->setObjectName(QString::fromUtf8("widget2"));
        widget2->setGeometry(QRect(70, 170, 251, 31));
        horizontalLayout_3 = new QHBoxLayout(widget2);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_B = new QLabel(widget2);
        label_B->setObjectName(QString::fromUtf8("label_B"));
        label_B->setFont(font);

        horizontalLayout_3->addWidget(label_B);

        lineEdit_B = new QLineEdit(widget2);
        lineEdit_B->setObjectName(QString::fromUtf8("lineEdit_B"));
        lineEdit_B->setFont(font1);
        lineEdit_B->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(lineEdit_B);


        retranslateUi(RGB_Dialog);

        QMetaObject::connectSlotsByName(RGB_Dialog);
    } // setupUi

    void retranslateUi(QDialog *RGB_Dialog)
    {
        RGB_Dialog->setWindowTitle(QCoreApplication::translate("RGB_Dialog", "RGB\350\256\276\347\275\256", nullptr));
        Button_RGBCommit->setText(QCoreApplication::translate("RGB_Dialog", "\347\241\256\345\256\232", nullptr));
        Button_RGBCancel->setText(QCoreApplication::translate("RGB_Dialog", "\345\217\226\346\266\210", nullptr));
        label_R->setText(QCoreApplication::translate("RGB_Dialog", "R", nullptr));
        lineEdit_R->setText(QCoreApplication::translate("RGB_Dialog", "0", nullptr));
        label_G->setText(QCoreApplication::translate("RGB_Dialog", "G", nullptr));
        lineEdit_G->setText(QCoreApplication::translate("RGB_Dialog", "0", nullptr));
        label_B->setText(QCoreApplication::translate("RGB_Dialog", "B", nullptr));
        lineEdit_B->setText(QCoreApplication::translate("RGB_Dialog", "0", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RGB_Dialog: public Ui_RGB_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RGB_DIALOG_H

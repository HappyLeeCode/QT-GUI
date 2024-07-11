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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_1;
    QLabel *label_input;
    QLineEdit *lineEdit_input;
    QWidget *widget;
    QGridLayout *gridLayout;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QPushButton *pushButton_add;
    QPushButton *pushButton_del;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_sub;
    QPushButton *pushButton_sprt;
    QPushButton *pushButton_1;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_mul;
    QPushButton *pushButton_pow;
    QPushButton *pushButton_clear;
    QPushButton *pushButton_0;
    QPushButton *pushButton_point;
    QPushButton *pushButton_div;
    QPushButton *pushButton_equal;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_output;
    QLineEdit *lineEdit_output;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(652, 547);
        layoutWidget = new QWidget(Widget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(50, 30, 577, 52));
        horizontalLayout_1 = new QHBoxLayout(layoutWidget);
        horizontalLayout_1->setObjectName(QString::fromUtf8("horizontalLayout_1"));
        horizontalLayout_1->setContentsMargins(0, 0, 0, 0);
        label_input = new QLabel(layoutWidget);
        label_input->setObjectName(QString::fromUtf8("label_input"));
        label_input->setMinimumSize(QSize(60, 50));
        label_input->setMaximumSize(QSize(60, 50));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font.setPointSize(14);
        label_input->setFont(font);

        horizontalLayout_1->addWidget(label_input);

        lineEdit_input = new QLineEdit(layoutWidget);
        lineEdit_input->setObjectName(QString::fromUtf8("lineEdit_input"));
        lineEdit_input->setMinimumSize(QSize(400, 50));
        lineEdit_input->setMaximumSize(QSize(400, 50));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(14);
        lineEdit_input->setFont(font1);
        lineEdit_input->setLayoutDirection(Qt::LeftToRight);
        lineEdit_input->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_1->addWidget(lineEdit_input);

        widget = new QWidget(Widget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(60, 170, 526, 340));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_7 = new QPushButton(widget);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setMinimumSize(QSize(100, 80));
        pushButton_7->setMaximumSize(QSize(100, 80));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(11);
        pushButton_7->setFont(font2);

        gridLayout->addWidget(pushButton_7, 0, 0, 1, 1);

        pushButton_8 = new QPushButton(widget);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        pushButton_8->setMinimumSize(QSize(100, 80));
        pushButton_8->setMaximumSize(QSize(100, 80));
        pushButton_8->setFont(font2);

        gridLayout->addWidget(pushButton_8, 0, 1, 1, 1);

        pushButton_9 = new QPushButton(widget);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        pushButton_9->setMinimumSize(QSize(100, 80));
        pushButton_9->setMaximumSize(QSize(100, 80));
        pushButton_9->setFont(font2);

        gridLayout->addWidget(pushButton_9, 0, 2, 1, 1);

        pushButton_add = new QPushButton(widget);
        pushButton_add->setObjectName(QString::fromUtf8("pushButton_add"));
        pushButton_add->setMinimumSize(QSize(100, 80));
        pushButton_add->setMaximumSize(QSize(100, 80));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font3.setPointSize(11);
        font3.setBold(true);
        font3.setWeight(75);
        pushButton_add->setFont(font3);

        gridLayout->addWidget(pushButton_add, 0, 3, 1, 1);

        pushButton_del = new QPushButton(widget);
        pushButton_del->setObjectName(QString::fromUtf8("pushButton_del"));
        pushButton_del->setMinimumSize(QSize(100, 80));
        pushButton_del->setMaximumSize(QSize(100, 80));
        pushButton_del->setFont(font2);

        gridLayout->addWidget(pushButton_del, 0, 4, 1, 1);

        pushButton_4 = new QPushButton(widget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setMinimumSize(QSize(100, 80));
        pushButton_4->setMaximumSize(QSize(100, 80));
        pushButton_4->setFont(font2);

        gridLayout->addWidget(pushButton_4, 1, 0, 1, 1);

        pushButton_5 = new QPushButton(widget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setMinimumSize(QSize(100, 80));
        pushButton_5->setMaximumSize(QSize(100, 80));
        pushButton_5->setFont(font2);

        gridLayout->addWidget(pushButton_5, 1, 1, 1, 1);

        pushButton_6 = new QPushButton(widget);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setMinimumSize(QSize(100, 80));
        pushButton_6->setMaximumSize(QSize(100, 80));
        pushButton_6->setFont(font2);

        gridLayout->addWidget(pushButton_6, 1, 2, 1, 1);

        pushButton_sub = new QPushButton(widget);
        pushButton_sub->setObjectName(QString::fromUtf8("pushButton_sub"));
        pushButton_sub->setMinimumSize(QSize(100, 80));
        pushButton_sub->setMaximumSize(QSize(100, 80));
        pushButton_sub->setFont(font3);

        gridLayout->addWidget(pushButton_sub, 1, 3, 1, 1);

        pushButton_sprt = new QPushButton(widget);
        pushButton_sprt->setObjectName(QString::fromUtf8("pushButton_sprt"));
        pushButton_sprt->setMinimumSize(QSize(100, 80));
        pushButton_sprt->setMaximumSize(QSize(100, 80));
        pushButton_sprt->setFont(font2);

        gridLayout->addWidget(pushButton_sprt, 1, 4, 1, 1);

        pushButton_1 = new QPushButton(widget);
        pushButton_1->setObjectName(QString::fromUtf8("pushButton_1"));
        pushButton_1->setMinimumSize(QSize(100, 80));
        pushButton_1->setMaximumSize(QSize(100, 80));
        pushButton_1->setFont(font2);

        gridLayout->addWidget(pushButton_1, 2, 0, 1, 1);

        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(100, 80));
        pushButton_2->setMaximumSize(QSize(100, 80));
        pushButton_2->setFont(font2);

        gridLayout->addWidget(pushButton_2, 2, 1, 1, 1);

        pushButton_3 = new QPushButton(widget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setMinimumSize(QSize(100, 80));
        pushButton_3->setMaximumSize(QSize(100, 80));
        pushButton_3->setFont(font2);

        gridLayout->addWidget(pushButton_3, 2, 2, 1, 1);

        pushButton_mul = new QPushButton(widget);
        pushButton_mul->setObjectName(QString::fromUtf8("pushButton_mul"));
        pushButton_mul->setMinimumSize(QSize(100, 80));
        pushButton_mul->setMaximumSize(QSize(100, 80));
        pushButton_mul->setFont(font2);

        gridLayout->addWidget(pushButton_mul, 2, 3, 1, 1);

        pushButton_pow = new QPushButton(widget);
        pushButton_pow->setObjectName(QString::fromUtf8("pushButton_pow"));
        pushButton_pow->setMinimumSize(QSize(100, 80));
        pushButton_pow->setMaximumSize(QSize(100, 80));
        pushButton_pow->setFont(font2);

        gridLayout->addWidget(pushButton_pow, 2, 4, 1, 1);

        pushButton_clear = new QPushButton(widget);
        pushButton_clear->setObjectName(QString::fromUtf8("pushButton_clear"));
        pushButton_clear->setMinimumSize(QSize(100, 80));
        pushButton_clear->setMaximumSize(QSize(100, 80));
        pushButton_clear->setFont(font2);

        gridLayout->addWidget(pushButton_clear, 3, 0, 1, 1);

        pushButton_0 = new QPushButton(widget);
        pushButton_0->setObjectName(QString::fromUtf8("pushButton_0"));
        pushButton_0->setMinimumSize(QSize(100, 80));
        pushButton_0->setMaximumSize(QSize(100, 80));
        pushButton_0->setFont(font2);

        gridLayout->addWidget(pushButton_0, 3, 1, 1, 1);

        pushButton_point = new QPushButton(widget);
        pushButton_point->setObjectName(QString::fromUtf8("pushButton_point"));
        pushButton_point->setMinimumSize(QSize(100, 80));
        pushButton_point->setMaximumSize(QSize(100, 80));
        pushButton_point->setFont(font2);

        gridLayout->addWidget(pushButton_point, 3, 2, 1, 1);

        pushButton_div = new QPushButton(widget);
        pushButton_div->setObjectName(QString::fromUtf8("pushButton_div"));
        pushButton_div->setMinimumSize(QSize(100, 80));
        pushButton_div->setMaximumSize(QSize(100, 80));
        pushButton_div->setFont(font2);

        gridLayout->addWidget(pushButton_div, 3, 3, 1, 1);

        pushButton_equal = new QPushButton(widget);
        pushButton_equal->setObjectName(QString::fromUtf8("pushButton_equal"));
        pushButton_equal->setMinimumSize(QSize(100, 80));
        pushButton_equal->setMaximumSize(QSize(100, 80));
        pushButton_equal->setFont(font3);

        gridLayout->addWidget(pushButton_equal, 3, 4, 1, 1);

        widget1 = new QWidget(Widget);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(50, 100, 577, 52));
        horizontalLayout_2 = new QHBoxLayout(widget1);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_output = new QLabel(widget1);
        label_output->setObjectName(QString::fromUtf8("label_output"));
        label_output->setMinimumSize(QSize(60, 50));
        label_output->setMaximumSize(QSize(60, 50));
        label_output->setFont(font);

        horizontalLayout_2->addWidget(label_output);

        lineEdit_output = new QLineEdit(widget1);
        lineEdit_output->setObjectName(QString::fromUtf8("lineEdit_output"));
        lineEdit_output->setMinimumSize(QSize(400, 50));
        lineEdit_output->setMaximumSize(QSize(400, 50));
        lineEdit_output->setFont(font1);
        lineEdit_output->setLayoutDirection(Qt::LeftToRight);
        lineEdit_output->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(lineEdit_output);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        label_input->setText(QCoreApplication::translate("Widget", "\350\276\223\345\205\245\357\274\232", nullptr));
        pushButton_7->setText(QCoreApplication::translate("Widget", "7", nullptr));
        pushButton_8->setText(QCoreApplication::translate("Widget", "8", nullptr));
        pushButton_9->setText(QCoreApplication::translate("Widget", "9", nullptr));
        pushButton_add->setText(QCoreApplication::translate("Widget", "+", nullptr));
        pushButton_del->setText(QCoreApplication::translate("Widget", "Del", nullptr));
        pushButton_4->setText(QCoreApplication::translate("Widget", "4", nullptr));
        pushButton_5->setText(QCoreApplication::translate("Widget", "5", nullptr));
        pushButton_6->setText(QCoreApplication::translate("Widget", "6", nullptr));
        pushButton_sub->setText(QCoreApplication::translate("Widget", "-", nullptr));
        pushButton_sprt->setText(QCoreApplication::translate("Widget", "sqrt", nullptr));
        pushButton_1->setText(QCoreApplication::translate("Widget", "1", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Widget", "2", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Widget", "3", nullptr));
        pushButton_mul->setText(QCoreApplication::translate("Widget", "x", nullptr));
        pushButton_pow->setText(QCoreApplication::translate("Widget", "^", nullptr));
        pushButton_clear->setText(QCoreApplication::translate("Widget", "AC", nullptr));
        pushButton_0->setText(QCoreApplication::translate("Widget", "0", nullptr));
        pushButton_point->setText(QCoreApplication::translate("Widget", ".", nullptr));
        pushButton_div->setText(QCoreApplication::translate("Widget", "/", nullptr));
        pushButton_equal->setText(QCoreApplication::translate("Widget", "=", nullptr));
        label_output->setText(QCoreApplication::translate("Widget", "\350\276\223\345\207\272\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H

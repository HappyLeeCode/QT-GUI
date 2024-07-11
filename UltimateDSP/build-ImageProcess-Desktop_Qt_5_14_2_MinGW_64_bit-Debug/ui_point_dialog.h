/********************************************************************************
** Form generated from reading UI file 'point_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_POINT_DIALOG_H
#define UI_POINT_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_point_Dialog
{
public:
    QPushButton *Button_PointCancel;
    QLabel *label_end;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_end_x;
    QLineEdit *lineEdit_end_x;
    QLabel *label_end_y;
    QLineEdit *lineEdit_end_y;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label_start_x;
    QLineEdit *lineEdit_start_x;
    QLabel *label_start_y;
    QLineEdit *lineEdit_start_y;
    QPushButton *Button_PointCommit;
    QLabel *label_start;

    void setupUi(QDialog *point_Dialog)
    {
        if (point_Dialog->objectName().isEmpty())
            point_Dialog->setObjectName(QString::fromUtf8("point_Dialog"));
        point_Dialog->resize(643, 343);
        Button_PointCancel = new QPushButton(point_Dialog);
        Button_PointCancel->setObjectName(QString::fromUtf8("Button_PointCancel"));
        Button_PointCancel->setGeometry(QRect(380, 270, 93, 28));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        Button_PointCancel->setFont(font);
        label_end = new QLabel(point_Dialog);
        label_end->setObjectName(QString::fromUtf8("label_end"));
        label_end->setGeometry(QRect(40, 140, 151, 21));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font1.setPointSize(10);
        label_end->setFont(font1);
        layoutWidget = new QWidget(point_Dialog);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(130, 180, 394, 23));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_end_x = new QLabel(layoutWidget);
        label_end_x->setObjectName(QString::fromUtf8("label_end_x"));
        label_end_x->setFont(font);

        horizontalLayout_2->addWidget(label_end_x);

        lineEdit_end_x = new QLineEdit(layoutWidget);
        lineEdit_end_x->setObjectName(QString::fromUtf8("lineEdit_end_x"));
        lineEdit_end_x->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(lineEdit_end_x);

        label_end_y = new QLabel(layoutWidget);
        label_end_y->setObjectName(QString::fromUtf8("label_end_y"));
        label_end_y->setFont(font);

        horizontalLayout_2->addWidget(label_end_y);

        lineEdit_end_y = new QLineEdit(layoutWidget);
        lineEdit_end_y->setObjectName(QString::fromUtf8("lineEdit_end_y"));
        lineEdit_end_y->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(lineEdit_end_y);

        layoutWidget_2 = new QWidget(point_Dialog);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(130, 80, 394, 23));
        horizontalLayout = new QHBoxLayout(layoutWidget_2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_start_x = new QLabel(layoutWidget_2);
        label_start_x->setObjectName(QString::fromUtf8("label_start_x"));
        label_start_x->setFont(font);

        horizontalLayout->addWidget(label_start_x);

        lineEdit_start_x = new QLineEdit(layoutWidget_2);
        lineEdit_start_x->setObjectName(QString::fromUtf8("lineEdit_start_x"));
        lineEdit_start_x->setLayoutDirection(Qt::LeftToRight);
        lineEdit_start_x->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(lineEdit_start_x);

        label_start_y = new QLabel(layoutWidget_2);
        label_start_y->setObjectName(QString::fromUtf8("label_start_y"));
        label_start_y->setFont(font);

        horizontalLayout->addWidget(label_start_y);

        lineEdit_start_y = new QLineEdit(layoutWidget_2);
        lineEdit_start_y->setObjectName(QString::fromUtf8("lineEdit_start_y"));
        lineEdit_start_y->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(lineEdit_start_y);

        Button_PointCommit = new QPushButton(point_Dialog);
        Button_PointCommit->setObjectName(QString::fromUtf8("Button_PointCommit"));
        Button_PointCommit->setGeometry(QRect(210, 270, 93, 28));
        Button_PointCommit->setFont(font);
        label_start = new QLabel(point_Dialog);
        label_start->setObjectName(QString::fromUtf8("label_start"));
        label_start->setGeometry(QRect(40, 40, 151, 21));
        label_start->setFont(font1);

        retranslateUi(point_Dialog);

        QMetaObject::connectSlotsByName(point_Dialog);
    } // setupUi

    void retranslateUi(QDialog *point_Dialog)
    {
        point_Dialog->setWindowTitle(QCoreApplication::translate("point_Dialog", "\347\202\271\350\256\276\347\275\256", nullptr));
        Button_PointCancel->setText(QCoreApplication::translate("point_Dialog", "\345\217\226\346\266\210", nullptr));
        label_end->setText(QCoreApplication::translate("point_Dialog", "\347\273\210\347\202\271\345\235\220\346\240\207\357\274\210\345\217\263\344\270\213\347\202\271\357\274\211", nullptr));
        label_end_x->setText(QCoreApplication::translate("point_Dialog", "x:", nullptr));
        lineEdit_end_x->setText(QCoreApplication::translate("point_Dialog", "0", nullptr));
        label_end_y->setText(QCoreApplication::translate("point_Dialog", "y:", nullptr));
        lineEdit_end_y->setText(QCoreApplication::translate("point_Dialog", "0", nullptr));
        label_start_x->setText(QCoreApplication::translate("point_Dialog", "x:", nullptr));
        lineEdit_start_x->setText(QCoreApplication::translate("point_Dialog", "0", nullptr));
        label_start_y->setText(QCoreApplication::translate("point_Dialog", "y:", nullptr));
        lineEdit_start_y->setText(QCoreApplication::translate("point_Dialog", "0", nullptr));
        Button_PointCommit->setText(QCoreApplication::translate("point_Dialog", "\347\241\256\345\256\232", nullptr));
        label_start->setText(QCoreApplication::translate("point_Dialog", "\350\265\267\347\202\271\345\235\220\346\240\207\357\274\210\345\267\246\344\270\212\347\202\271\357\274\211", nullptr));
    } // retranslateUi

};

namespace Ui {
    class point_Dialog: public Ui_point_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POINT_DIALOG_H

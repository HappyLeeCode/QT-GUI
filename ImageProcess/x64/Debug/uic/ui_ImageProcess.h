/********************************************************************************
** Form generated from reading UI file 'ImageProcess.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMAGEPROCESS_H
#define UI_IMAGEPROCESS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ImageProcessClass
{
public:
    QWidget *centralWidget;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_image;
    QLabel *originalImageLabel;
    QLabel *transformLabel;
    QLabel *processedImageLabel;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_tips;
    QLabel *leftLabel;
    QLabel *middleLabel;
    QLabel *rightLabel;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ImageProcessClass)
    {
        if (ImageProcessClass->objectName().isEmpty())
            ImageProcessClass->setObjectName(QString::fromUtf8("ImageProcessClass"));
        ImageProcessClass->resize(1140, 650);
        ImageProcessClass->setMinimumSize(QSize(1140, 650));
        centralWidget = new QWidget(ImageProcessClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 50, 1096, 502));
        horizontalLayout_image = new QHBoxLayout(layoutWidget);
        horizontalLayout_image->setSpacing(6);
        horizontalLayout_image->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_image->setObjectName(QString::fromUtf8("horizontalLayout_image"));
        horizontalLayout_image->setContentsMargins(0, 0, 0, 0);
        originalImageLabel = new QLabel(layoutWidget);
        originalImageLabel->setObjectName(QString::fromUtf8("originalImageLabel"));
        originalImageLabel->setMinimumSize(QSize(500, 500));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221 Light"));
        font.setPointSize(12);
        originalImageLabel->setFont(font);
        originalImageLabel->setCursor(QCursor(Qt::ArrowCursor));
        originalImageLabel->setLayoutDirection(Qt::LeftToRight);
        originalImageLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout_image->addWidget(originalImageLabel);

        transformLabel = new QLabel(layoutWidget);
        transformLabel->setObjectName(QString::fromUtf8("transformLabel"));
        transformLabel->setMinimumSize(QSize(80, 80));
        transformLabel->setMaximumSize(QSize(80, 80));

        horizontalLayout_image->addWidget(transformLabel);

        processedImageLabel = new QLabel(layoutWidget);
        processedImageLabel->setObjectName(QString::fromUtf8("processedImageLabel"));
        processedImageLabel->setMinimumSize(QSize(500, 500));
        processedImageLabel->setFont(font);
        processedImageLabel->setCursor(QCursor(Qt::ArrowCursor));
        processedImageLabel->setLayoutDirection(Qt::LeftToRight);
        processedImageLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout_image->addWidget(processedImageLabel);

        layoutWidget1 = new QWidget(centralWidget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(20, 10, 1096, 32));
        horizontalLayout_tips = new QHBoxLayout(layoutWidget1);
        horizontalLayout_tips->setSpacing(6);
        horizontalLayout_tips->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_tips->setObjectName(QString::fromUtf8("horizontalLayout_tips"));
        horizontalLayout_tips->setContentsMargins(0, 0, 0, 0);
        leftLabel = new QLabel(layoutWidget1);
        leftLabel->setObjectName(QString::fromUtf8("leftLabel"));
        leftLabel->setMinimumSize(QSize(500, 30));
        leftLabel->setFont(font);
        leftLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout_tips->addWidget(leftLabel);

        middleLabel = new QLabel(layoutWidget1);
        middleLabel->setObjectName(QString::fromUtf8("middleLabel"));
        middleLabel->setMinimumSize(QSize(80, 30));

        horizontalLayout_tips->addWidget(middleLabel);

        rightLabel = new QLabel(layoutWidget1);
        rightLabel->setObjectName(QString::fromUtf8("rightLabel"));
        rightLabel->setMinimumSize(QSize(500, 30));
        rightLabel->setFont(font);
        rightLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout_tips->addWidget(rightLabel);

        ImageProcessClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ImageProcessClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1140, 26));
        ImageProcessClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ImageProcessClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        ImageProcessClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(ImageProcessClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        ImageProcessClass->setStatusBar(statusBar);

        retranslateUi(ImageProcessClass);

        QMetaObject::connectSlotsByName(ImageProcessClass);
    } // setupUi

    void retranslateUi(QMainWindow *ImageProcessClass)
    {
        ImageProcessClass->setWindowTitle(QCoreApplication::translate("ImageProcessClass", "ImageProcess", nullptr));
        originalImageLabel->setText(QCoreApplication::translate("ImageProcessClass", "\345\216\237\345\247\213\345\233\276\345\203\217\n"
"Original Image", nullptr));
        transformLabel->setText(QString());
        processedImageLabel->setText(QCoreApplication::translate("ImageProcessClass", "\346\225\210\346\236\234\345\261\225\347\244\272\n"
"Proceeed Image", nullptr));
        leftLabel->setText(QString());
        middleLabel->setText(QString());
        rightLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ImageProcessClass: public Ui_ImageProcessClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGEPROCESS_H

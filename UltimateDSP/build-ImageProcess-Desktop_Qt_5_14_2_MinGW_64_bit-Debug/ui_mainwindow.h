/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

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

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *originalImageLabel;
    QLabel *transformLabel;
    QLabel *processedImageLabel;
    QMenuBar *menubar;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1150, 620);
        MainWindow->setMinimumSize(QSize(1150, 620));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(30, 30, 1094, 502));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
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

        horizontalLayout->addWidget(originalImageLabel);

        transformLabel = new QLabel(layoutWidget);
        transformLabel->setObjectName(QString::fromUtf8("transformLabel"));
        transformLabel->setMinimumSize(QSize(80, 80));
        transformLabel->setMaximumSize(QSize(80, 80));

        horizontalLayout->addWidget(transformLabel);

        processedImageLabel = new QLabel(layoutWidget);
        processedImageLabel->setObjectName(QString::fromUtf8("processedImageLabel"));
        processedImageLabel->setMinimumSize(QSize(500, 500));
        processedImageLabel->setFont(font);
        processedImageLabel->setCursor(QCursor(Qt::ArrowCursor));
        processedImageLabel->setLayoutDirection(Qt::LeftToRight);
        processedImageLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(processedImageLabel);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1150, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        originalImageLabel->setText(QCoreApplication::translate("MainWindow", "\345\216\237\345\247\213\345\233\276\345\203\217\n"
"Original Image", nullptr));
        transformLabel->setText(QString());
        processedImageLabel->setText(QCoreApplication::translate("MainWindow", "\346\225\210\346\236\234\345\261\225\347\244\272\n"
"Proceeed Image", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

#pragma once
#pragma execution_character_set("utf-8")  //解决汉字编码问题


#include <QtWidgets/QMainWindow>
#include <QLabel>
#include <QFileDialog>
#include <QMessageBox>
#include <QImage>
#include <opencv2/opencv.hpp>

#include <QMouseEvent>        //处理鼠标时间（用于鼠标框选范围）
#include <QRubberBand>


#include <QDebug>

#include "ui_ImageProcess.h"

class ImageProcess : public QMainWindow
{
    Q_OBJECT

public:
    ImageProcess(QWidget *parent = nullptr);
    ~ImageProcess();

signals:
    void allImageSignal(cv::Mat originalImage);


private slots:
    void openFileActionSlot();
    void displayImageSlot(QLabel*label,const QString& filePath); //展示原始图像（信号）


    //最终显示图片函数，
    void displayImage(QLabel* label, const cv::Mat& image);
    // 传入的label为：
    //1.originnalImageLabel时，打印在原始图像区域
    //2.processedImageLabel时，打印在处理后的区域

    void allImageActionSlot();
    void selectImageActionSlot();

    cv::Mat histogramDraw(const cv::Mat& inputImage);

    //void openBmpActionSlot();
    
    //void displayImageSlot(QPoint, QPoint, QColor, QImage*);

    //void setPointSlot(QPoint StartPoint, QPoint EndPoint);
    //void setColorSlot(QColor color);

    //void pointSetActionSlot();
    //void RGBSetActionSlot();
    //void RegionPaint();

    //void saveFileAcitonSlot();
    //void exitActionSlot();

    //cv::Mat histogramActionSlot(const cv::Mat& inputImage);
    //void displayImageSlot(QLabel* label, const cv::Mat& image);
    //void his_equalizeActionSlot();

    //cv::Mat QImageTocvMatSlot();

protected:
    void mousePressEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;

private:
    Ui::ImageProcessClass ui;

    //菜单栏

   //新建
    QAction* newAction;

    //文件
    QMenu* fileMenu;
    QAction* newFileAction;
    QAction* openFileAction;
    QAction* saveFileAction;
    QAction* exitAction;

    //打开bmp图片
    QAction* openBmpAction;

    //直方图
    QMenu* histogramMenu;
    QAction* allImage;
    QAction* selectImage;
    QAction* his_equalizeAciton;

    //区域描绘
    QMenu* regionPaintMenu;
    QAction* pointSetAction;
    QAction* RGBSetAction;

    //帮助
    QMenu* helpMenu;

    //成员变量
    //ui.originalImageLabel(500x500)
    //ui.processdeImageLabel(500x500)
    cv::Mat originalImage;
    cv::Mat selectedRegionImage;

    //鼠标框选
    QPoint rubberBandStart;
    QRubberBand* currentRubberBand;

    //point_Dialog* point;
    //RGB_Dialog* rgb;

    static int mouse;      //在currentRubberBand != nullptr的前提下，mouse=0，不使用鼠标框选；mouse=1，使用鼠标框选
    static QPoint Start;
    static QPoint End;
    static QColor color;
};

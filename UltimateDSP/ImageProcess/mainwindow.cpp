#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    point=new point_Dialog();
    rgb=new RGB_Dialog();

    ui->transformLabel->setPixmap(QPixmap(":/myImage/image/transform.png"));
    ui->transformLabel->setScaledContents(true);

    newAction=new QAction("新建(&N)");

    fileMenu=new QMenu("文件(&F)");
    openFileAction=new QAction("打开(&O)");
    saveFileAction=new QAction("另存为(&S)");
    exitAction=new QAction("退出(&Q)");
    fileMenu->addAction(openFileAction);
    fileMenu->addAction(saveFileAction);
    fileMenu->addAction(exitAction);

    openBmpAction=new QAction("打开bmp图片(&B)");

    regionPaintMenu=new QMenu("区域描绘");
    pointSetAction=new QAction("区域框选(&P)");
    RGBSetAction=new QAction("RGB设置(&R)");
    regionPaintMenu->addAction(pointSetAction);
    regionPaintMenu->addAction(RGBSetAction);

    histogramAction=new QAction("直方图绘制(&D)");
    his_equalizeAciton=new QAction("直方图均衡(&E)");

    helpMenu=new QMenu("帮助(&H)");


    //将菜单添加到菜单栏里：
    ui->menubar->addAction(newAction);
    ui->menubar->addMenu(fileMenu);
    ui->menubar->addAction(openBmpAction);
    ui->menubar->addMenu(regionPaintMenu);
    ui->menubar->addAction(histogramAction);
    ui->menubar->addAction(his_equalizeAciton);
    ui->menubar->addMenu(helpMenu);


    //连接
    connect(newAction,&QAction::triggered,this,&MainWindow::newActionSlot);
    connect(openFileAction,&QAction::triggered,this,&MainWindow::openFileActionSlot);
    connect(openBmpAction,&QAction::triggered,this,&MainWindow::openBmpActionSlot);   //点击打开bmp图片
    connect(this,SIGNAL(displayImageSignal()),this,SLOT(displayImageSlot()));         //发送图片刷新请求，执行displayImageSlot

    connect(RGBSetAction,&QAction::triggered,this,&MainWindow::RGBSetActionSlot);
    connect(pointSetAction,&QAction::triggered,this,&MainWindow::pointSetActionSlot);
    connect(point,SIGNAL(resultSignal(QPoint,QPoint)),this,SLOT(setPointSlot(QPoint,QPoint)));
    connect(rgb,SIGNAL(resultSignal(QColor)),this,SLOT(setColorSlot(QColor)));

    connect(histogramAction,&QAction::triggered,this,&MainWindow::QImageTocvMatSlot);


}



MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::newActionSlot()
{
    ui->originalImageLabel->clear();
    ui->processedImageLabel->clear();
    this->setWindowTitle("新建图片处理");
}

void MainWindow::openFileActionSlot()
{
    QString fileName = QFileDialog::getOpenFileName(this, "打开一张图片",
                                                    QCoreApplication::applicationFilePath(),
                                                    "Images (*.bmp *jpg *png)");
    if(fileName.isEmpty())
    {
        QMessageBox::warning(this,"警告","请选择打开一张图片");
        return;
    }
    else
    {
        //qDebug()<< fileName ;
         image = new QImage(fileName);
         emit displayImageSignal();
    }
}

void MainWindow::openBmpActionSlot()
{
    QString fileName = QFileDialog::getOpenFileName(this, "打开一张图片",
                                                    QCoreApplication::applicationFilePath(),
                                                    "Images (*.bmp)");
    if(fileName.isEmpty())
    {
        QMessageBox::warning(this,"警告","请选择打开一张图片");
        return;
    }
    else
    {
        //qDebug()<< fileName ;
         image = new QImage(fileName);
         emit displayImageSignal();
    }
}

void MainWindow::displayImageSlot()
{
    ui->originalImageLabel->setPixmap(QPixmap::fromImage(*image));
    ui->originalImageLabel->resize(image->size());
}

void MainWindow::displayImageSlot(QPoint,QPoint,QColor,QImage*)
{
    ui->processedImageLabel->setPixmap(QPixmap::fromImage(*image));
    ui->processedImageLabel->resize(image->size());
}

void MainWindow::displayImageSlot(QLabel* label,const cv::Mat& image)
{
    if (image.empty()) {
        QMessageBox::warning(this, "Error", "Empty image!");
        return;
    }

    // 将opencv格式图片转换成Qt格式的图片
    QImage img = QImage((const unsigned char*)(image.data), image.cols, image.rows, image.step, QImage::Format_RGB888);

    ui->processedImageLabel->setPixmap(QPixmap::fromImage(img).scaled(label->size(), Qt::KeepAspectRatio));
    ui->processedImageLabel->setAlignment(Qt::AlignCenter);
}

void MainWindow::pointSetActionSlot()
{
    point->show();
}

void MainWindow::RGBSetActionSlot()
{
    rgb->show();
}

void MainWindow::RegionPaint()
{
    {
        QPoint StartPoint=this->Start;
        QPoint EndPoint=this->End;
        QColor color=this->color;
        // Qt 打开的 bmp、jpg 图像格式为 Format_RGB32，在内存中的顺序为 B G R 0
        //    打开的 png 图像的格式为 Format_ARGB32，在内存中的顺序为 B G R A
        unsigned char *scrdata = image->bits();
        int width = image->width();
        int height = image->height();
        int bytesPerLine = image->bytesPerLine();//图像每行字节对齐
        unsigned char *dstdata = new unsigned char[bytesPerLine*height];//存储处理后的数据
        int r = color.red();
        int g = color.green();
        int b = color.blue();
        for(int i=0;i<height;i++)
            for(int j=0;j<width;j++)
            {
                if((i>=StartPoint.x())&&i<EndPoint.x()&&
                        (j>=StartPoint.y())&&j<EndPoint.y())
                {
                    dstdata[i*bytesPerLine+j*4]  = b;
                    dstdata[i*bytesPerLine+j*4+1]= g;
                    dstdata[i*bytesPerLine+j*4+2]= r;
                }
                else{
                    dstdata[i*bytesPerLine+j*4]  = scrdata[0];
                    dstdata[i*bytesPerLine+j*4+1]= scrdata[1];
                    dstdata[i*bytesPerLine+j*4+2]= scrdata[2];
                }
                scrdata+=4;
            }
        image= new QImage(dstdata,width,height,bytesPerLine,QImage::Format_RGB32);
        displayImageSlot(Start,End,color,image);
    }

}

void MainWindow::setPointSlot(QPoint StartPoint,QPoint EndPoint)
{
    Start=StartPoint;
    End=EndPoint;
    RegionPaint();
}

void MainWindow::setColorSlot(QColor color)
{
    this->color=color;
    RegionPaint();
}

cv::Mat MainWindow::histogramActionSlot(const cv::Mat& inputImage)
// 图像处理函数 -> 最关键的函数 -> 展示直方图
{
    try {

        // 检查图像是否为空
        if (inputImage.empty()) {
            qDebug() << "Empty input image in processImage!";
            QMessageBox::warning(this,"警告","请选择打开一张图片");
            return cv::Mat();
        }

        // 确保输入图像是单通道的（灰度图像）
        cv::Mat grayImage;
        cv::cvtColor(inputImage, grayImage, cv::COLOR_BGR2GRAY);

        // 计算灰度直方图
        int histSize =256;
        float range[] = {0, 256 };
        const float* histRange ={range};
        cv::Mat hist;   // 将结果存储在hist中
        cv::calcHist(&grayImage, 1, 0, cv::Mat(), hist, 1, &histSize, &histRange, true, false);

        // 创建可用于可视化直方图的图像
        int hist_w = 300, hist_h = 200;
        int bin_w = cvRound((double)hist_w / histSize);
        cv::Mat histImage(hist_h, hist_w, CV_8UC3, cv::Scalar(255, 255, 255));

        // 将直方图归一化到可是范围
        cv::normalize(hist, hist, 0, histImage.rows, cv::NORM_MINMAX, -1, cv::Mat());

        // 在图像上绘制直方图
        for (int i = 1; i < histSize; i++) {
            cv::line(histImage, cv::Point(bin_w * (i - 1), hist_h - cvRound(hist.at<float>(i - 1))),
                cv::Point(bin_w * (i), hist_h - cvRound(hist.at<float>(i))),
                cv::Scalar(0, 0, 0), 2, 8, 0);
        }

        displayImageSlot(ui->processedImageLabel,histImage);
        return histImage;
    }
    catch (cv::Exception& e) {
        qDebug() << "OpenCV Exception in processImage: " << e.what();
        return cv::Mat();
    }
}


cv::Mat MainWindow::QImageTocvMatSlot()
{
    QImage &image=*(this->image);
    cv::Mat mat;
//    switch(image.format())
//    {
//    case QImage::Format_Grayscale8: //灰度图，每个像素点1个字节（8位）
//    case QImage::Format_Indexed8: //Mat构造：行数，列数，存储结构，数据，step每行多少字节
//                mat = cv::Mat(image.height(), image.width(), CV_8UC1, (void*)image.constBits(), image.bytesPerLine());
//    break;
//    case QImage::Format_ARGB32:
//    case QImage::Format_RGB32:
//    case
//    QImage::Format_ARGB32_Premultiplied:
                mat = cv::Mat(image.height(), image.width(), CV_8UC4, (void*)image.constBits(), image.bytesPerLine());
//    break;
//    case QImage::Format_RGB888: //RR,GG,BB字节顺序存储
//                mat = cv::Mat(image.height(), image.width(), CV_8UC3, (void*)image.constBits(), image.bytesPerLine());
//                cv::cvtColor(mat, mat, cv::COLOR_RGB2BGR); //opencv需要转为BGR的字节顺序
//        break;
//    }
    histogramActionSlot(mat);
}




//静态成员变量，类内声明，类外初始化
QPoint MainWindow:: Start=QPoint(0,0);
QPoint MainWindow:: End =QPoint(0,0);
QColor MainWindow:: color=QColor(0,0,0);

#include "ImageProcess.h"

ImageProcess::ImageProcess(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    setWindowTitle("图像处理软件v2.0");

    currentRubberBand = nullptr; //初始化，默认关闭鼠标框选功能

    // 所有区域合并
    QVBoxLayout* mainLayout = new QVBoxLayout();
    // mainLayout->addWidget(imagePathEdit);
    mainLayout->addLayout(ui.horizontalLayout_tips);
    mainLayout->addLayout(ui.horizontalLayout_image);

    //设置转换图标
    ui.transformLabel->setPixmap(QPixmap(":/ImageProcess/image/transform.png"));
    ui.transformLabel->setScaledContents(true);

    //创建菜单栏
    //1.文件
    fileMenu = new QMenu("文件(&F)");
    newFileAction = new QAction("新建(&N)");
    openFileAction = new QAction("打开(&O)");
    saveFileAction = new QAction("另存为(&S)");
    exitAction = new QAction("退出(&Q)");
    fileMenu->addAction(openFileAction);
    fileMenu->addAction(saveFileAction);
    fileMenu->addAction(saveFileAction);
    fileMenu->addAction(exitAction);
    //2.打开bmp图片
    openBmpAction = new QAction("打开bmp图片(&B)");
    //3.区域描绘
    regionPaintMenu = new QMenu("区域描绘");
    pointSetAction = new QAction("区域框选(&P)");
    RGBSetAction = new QAction("RGB设置(&R)");
    regionPaintMenu->addAction(pointSetAction);
    regionPaintMenu->addAction(RGBSetAction);
    //4.直方图
    histogramMenu = new QMenu("直方图绘制(&D)");
    allImage = new QAction("整幅图片");
    selectImage = new QAction("自定义框选");
    his_equalizeAciton = new QAction("直方图均衡(&E)");
    histogramMenu->addAction(allImage);
    histogramMenu->addAction(selectImage);
    //5.帮助
    helpMenu = new QMenu("帮助(&H)");

    //菜单栏合并
    ui.menuBar->addMenu(fileMenu);
    ui.menuBar->addAction(openBmpAction);
    ui.menuBar->addMenu(regionPaintMenu);
    ui.menuBar->addMenu(histogramMenu);
    ui.menuBar->addAction(his_equalizeAciton);
    ui.menuBar->addMenu(helpMenu);


    //连接
    connect(openFileAction,&QAction::triggered,this,&ImageProcess::openFileActionSlot);

    connect(allImage, &QAction::triggered, this, &ImageProcess::allImageActionSlot);
    connect(selectImage, &QAction::triggered, this, &ImageProcess::selectImageActionSlot);

}

ImageProcess::~ImageProcess()
{}


void ImageProcess::openFileActionSlot()
{
    QString imagePath = QFileDialog::getOpenFileName(this, "打开图片", "", "Images (*.png *.jpg *.bmp)");
    // imagePathEdit->setText(imagePath);

    // 展示原始图像
    displayImageSlot(ui.originalImageLabel, imagePath);

    // 定义为被鼠标选中的区域 -> 当前为一个没有像素的空矩阵
    //selectedRegionImage = cv::Mat();
}

void ImageProcess::displayImageSlot(QLabel* label, const QString& filePath)
{
    originalImage = cv::imread(filePath.toStdString()); //把图片转成cv::Mat格式
    if (originalImage.empty()) {
        QMessageBox::warning(this, "警告", "请选择打开一张图片");
        return;
    }
    displayImage(label, originalImage);
}

void ImageProcess::displayImage(QLabel* label, const cv::Mat& image)
{
    // 将opencv格式图片转换成Qt格式的图片
    QImage img = QImage((const unsigned char*)(image.data), image.cols, image.rows, image.step, QImage::Format_RGB888);
    label->setPixmap(QPixmap::fromImage(img).scaled(label->size(), Qt::KeepAspectRatio));
    label->setAlignment(Qt::AlignCenter);
}

void ImageProcess::allImageActionSlot()
{
    mouse = 0;//关闭鼠标框选功能

    if (originalImage.empty()) {
        QMessageBox::warning(this, "警告", "请先选择打开一张图片");
        return;
    }
    
    ui.leftLabel->setText("原始图像");
    ui.rightLabel->setText("整幅图片的灰度直方图");
    histogramDraw(originalImage);
}

void ImageProcess::selectImageActionSlot()
{
    mouse = 1;//启动鼠标框选功能
}

cv::Mat ImageProcess::histogramDraw(const cv::Mat& inputImage)
// 图像处理函数 -> 最关键的函数 -> 展示直方图
{
    try {
        // 检查图像是否为空
        if (inputImage.empty()) {
            qDebug() << "Empty input image in processImage!";
            return cv::Mat();
        }

        // 确保输入图像是单通道的（灰度图像）
        cv::Mat grayImage;
        cv::cvtColor(inputImage, grayImage, cv::COLOR_BGR2GRAY);

        // 计算灰度直方图
        int histSize = 256;
        float range[] = { 0, 256 };
        const float* histRange = { range };
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
        displayImage(ui.processedImageLabel, histImage);
        return histImage;
    }
    catch (cv::Exception& e) {
        qDebug() << "OpenCV Exception in processImage: " << e.what();
        return cv::Mat();
    }
}

void ImageProcess::mousePressEvent(QMouseEvent* event)
// 设置按压鼠标左键后的行为
{
    if (event->button() == Qt::LeftButton )
    {
        QPoint startPoint = event->pos();   // 记录起始点坐标
        //QPoint startPoint = originalImageLabel->mapFrom(this, event->pos());

        QRubberBand* rubberBand = new QRubberBand(QRubberBand::Rectangle, this);

        // 设置线的颜色
        QPalette palette;
        palette.setColor(QPalette::Highlight, Qt::red);  // 将矩形框的颜色设置为红色
        rubberBand->setPalette(palette);

        // 设置矩形框的形状为矩形
        rubberBand->setGeometry(QRect(startPoint, QSize()));

        // 显示矩形框
        if (mouse != 1)
            return;
        rubberBand->show();

        rubberBandStart = startPoint;
        currentRubberBand = rubberBand;
    }
}

void ImageProcess::mouseMoveEvent(QMouseEvent* event)
// 设置鼠标移动后的行为 -> 矩形框实时更新
{
    if (currentRubberBand) {
        if (mouse != 1)
            return;
        currentRubberBand->setGeometry(QRect(rubberBandStart, event->pos()).normalized());
    }
}

void ImageProcess::mouseReleaseEvent(QMouseEvent* event)
// 设置鼠标释放后的行为
{
    if (currentRubberBand) {
        currentRubberBand->hide();

        // 还原显示比例
        float ratio_x = ui.originalImageLabel->size().width() / originalImage.rows;
        float ratio_y = ui.originalImageLabel->size().height() / originalImage.cols;

        // 坐标点映射 -> 坐标点回归正常
        QPoint mappedStart = ui.originalImageLabel->mapFrom(this, rubberBandStart);
        QPoint mappedEnd = ui.originalImageLabel->mapFrom(this, event->pos());
        mappedStart.setX(mappedStart.x() / ratio_x); mappedStart.setY(mappedStart.y() / ratio_y);
        mappedEnd.setX(mappedEnd.x() / ratio_x); mappedEnd.setY(mappedEnd.y() / ratio_y);

        // 鼠标选中区域
        QRect selectedRect = QRect(mappedStart, mappedEnd).normalized();

        if (!selectedRect.isEmpty()) { // 如果当前选中区域不为空
            cv::Rect roi(selectedRect.x(), selectedRect.y(), selectedRect.width(), selectedRect.height());

            cv::Rect validRect = roi & cv::Rect(0, 0, originalImage.cols, originalImage.rows);

            if (validRect.area() > 0) {
                selectedRegionImage = originalImage(validRect).clone();
                ui.rightLabel->setText("所框选范围的灰度直方图");
                histogramDraw(selectedRegionImage);
            }
            else {
                // 处理越界的情况，可能打印一些信息或进行其他处理
                qDebug() << "Selected region is out of image bounds.";
            }
        }

        delete currentRubberBand;
        currentRubberBand = nullptr;
    }
}



//静态成员变量，类内声明，类外初始化
int ImageProcess::mouse = 0;
QPoint ImageProcess::Start = QPoint(0, 0);
QPoint ImageProcess::End = QPoint(0, 0);
QColor ImageProcess::color = QColor(0, 0, 0);
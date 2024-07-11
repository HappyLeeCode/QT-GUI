#include "ImageProcess.h"

ImageProcess::ImageProcess(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    setWindowTitle("ͼ�������v2.0");

    currentRubberBand = nullptr; //��ʼ����Ĭ�Ϲر�����ѡ����

    // ��������ϲ�
    QVBoxLayout* mainLayout = new QVBoxLayout();
    // mainLayout->addWidget(imagePathEdit);
    mainLayout->addLayout(ui.horizontalLayout_tips);
    mainLayout->addLayout(ui.horizontalLayout_image);

    //����ת��ͼ��
    ui.transformLabel->setPixmap(QPixmap(":/ImageProcess/image/transform.png"));
    ui.transformLabel->setScaledContents(true);

    //�����˵���
    //1.�ļ�
    fileMenu = new QMenu("�ļ�(&F)");
    newFileAction = new QAction("�½�(&N)");
    openFileAction = new QAction("��(&O)");
    saveFileAction = new QAction("���Ϊ(&S)");
    exitAction = new QAction("�˳�(&Q)");
    fileMenu->addAction(openFileAction);
    fileMenu->addAction(saveFileAction);
    fileMenu->addAction(saveFileAction);
    fileMenu->addAction(exitAction);
    //2.��bmpͼƬ
    openBmpAction = new QAction("��bmpͼƬ(&B)");
    //3.�������
    regionPaintMenu = new QMenu("�������");
    pointSetAction = new QAction("�����ѡ(&P)");
    RGBSetAction = new QAction("RGB����(&R)");
    regionPaintMenu->addAction(pointSetAction);
    regionPaintMenu->addAction(RGBSetAction);
    //4.ֱ��ͼ
    histogramMenu = new QMenu("ֱ��ͼ����(&D)");
    allImage = new QAction("����ͼƬ");
    selectImage = new QAction("�Զ����ѡ");
    his_equalizeAciton = new QAction("ֱ��ͼ����(&E)");
    histogramMenu->addAction(allImage);
    histogramMenu->addAction(selectImage);
    //5.����
    helpMenu = new QMenu("����(&H)");

    //�˵����ϲ�
    ui.menuBar->addMenu(fileMenu);
    ui.menuBar->addAction(openBmpAction);
    ui.menuBar->addMenu(regionPaintMenu);
    ui.menuBar->addMenu(histogramMenu);
    ui.menuBar->addAction(his_equalizeAciton);
    ui.menuBar->addMenu(helpMenu);


    //����
    connect(openFileAction,&QAction::triggered,this,&ImageProcess::openFileActionSlot);

    connect(allImage, &QAction::triggered, this, &ImageProcess::allImageActionSlot);
    connect(selectImage, &QAction::triggered, this, &ImageProcess::selectImageActionSlot);

}

ImageProcess::~ImageProcess()
{}


void ImageProcess::openFileActionSlot()
{
    QString imagePath = QFileDialog::getOpenFileName(this, "��ͼƬ", "", "Images (*.png *.jpg *.bmp)");
    // imagePathEdit->setText(imagePath);

    // չʾԭʼͼ��
    displayImageSlot(ui.originalImageLabel, imagePath);

    // ����Ϊ�����ѡ�е����� -> ��ǰΪһ��û�����صĿվ���
    //selectedRegionImage = cv::Mat();
}

void ImageProcess::displayImageSlot(QLabel* label, const QString& filePath)
{
    originalImage = cv::imread(filePath.toStdString()); //��ͼƬת��cv::Mat��ʽ
    if (originalImage.empty()) {
        QMessageBox::warning(this, "����", "��ѡ���һ��ͼƬ");
        return;
    }
    displayImage(label, originalImage);
}

void ImageProcess::displayImage(QLabel* label, const cv::Mat& image)
{
    // ��opencv��ʽͼƬת����Qt��ʽ��ͼƬ
    QImage img = QImage((const unsigned char*)(image.data), image.cols, image.rows, image.step, QImage::Format_RGB888);
    label->setPixmap(QPixmap::fromImage(img).scaled(label->size(), Qt::KeepAspectRatio));
    label->setAlignment(Qt::AlignCenter);
}

void ImageProcess::allImageActionSlot()
{
    mouse = 0;//�ر�����ѡ����

    if (originalImage.empty()) {
        QMessageBox::warning(this, "����", "����ѡ���һ��ͼƬ");
        return;
    }
    
    ui.leftLabel->setText("ԭʼͼ��");
    ui.rightLabel->setText("����ͼƬ�ĻҶ�ֱ��ͼ");
    histogramDraw(originalImage);
}

void ImageProcess::selectImageActionSlot()
{
    mouse = 1;//��������ѡ����
}

cv::Mat ImageProcess::histogramDraw(const cv::Mat& inputImage)
// ͼ������ -> ��ؼ��ĺ��� -> չʾֱ��ͼ
{
    try {
        // ���ͼ���Ƿ�Ϊ��
        if (inputImage.empty()) {
            qDebug() << "Empty input image in processImage!";
            return cv::Mat();
        }

        // ȷ������ͼ���ǵ�ͨ���ģ��Ҷ�ͼ��
        cv::Mat grayImage;
        cv::cvtColor(inputImage, grayImage, cv::COLOR_BGR2GRAY);

        // ����Ҷ�ֱ��ͼ
        int histSize = 256;
        float range[] = { 0, 256 };
        const float* histRange = { range };
        cv::Mat hist;   // ������洢��hist��
        cv::calcHist(&grayImage, 1, 0, cv::Mat(), hist, 1, &histSize, &histRange, true, false);

        // ���������ڿ��ӻ�ֱ��ͼ��ͼ��
        int hist_w = 300, hist_h = 200;
        int bin_w = cvRound((double)hist_w / histSize);
        cv::Mat histImage(hist_h, hist_w, CV_8UC3, cv::Scalar(255, 255, 255));

        // ��ֱ��ͼ��һ�������Ƿ�Χ
        cv::normalize(hist, hist, 0, histImage.rows, cv::NORM_MINMAX, -1, cv::Mat());

        // ��ͼ���ϻ���ֱ��ͼ
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
// ���ð�ѹ�����������Ϊ
{
    if (event->button() == Qt::LeftButton )
    {
        QPoint startPoint = event->pos();   // ��¼��ʼ������
        //QPoint startPoint = originalImageLabel->mapFrom(this, event->pos());

        QRubberBand* rubberBand = new QRubberBand(QRubberBand::Rectangle, this);

        // �����ߵ���ɫ
        QPalette palette;
        palette.setColor(QPalette::Highlight, Qt::red);  // �����ο����ɫ����Ϊ��ɫ
        rubberBand->setPalette(palette);

        // ���þ��ο����״Ϊ����
        rubberBand->setGeometry(QRect(startPoint, QSize()));

        // ��ʾ���ο�
        if (mouse != 1)
            return;
        rubberBand->show();

        rubberBandStart = startPoint;
        currentRubberBand = rubberBand;
    }
}

void ImageProcess::mouseMoveEvent(QMouseEvent* event)
// ��������ƶ������Ϊ -> ���ο�ʵʱ����
{
    if (currentRubberBand) {
        if (mouse != 1)
            return;
        currentRubberBand->setGeometry(QRect(rubberBandStart, event->pos()).normalized());
    }
}

void ImageProcess::mouseReleaseEvent(QMouseEvent* event)
// ��������ͷź����Ϊ
{
    if (currentRubberBand) {
        currentRubberBand->hide();

        // ��ԭ��ʾ����
        float ratio_x = ui.originalImageLabel->size().width() / originalImage.rows;
        float ratio_y = ui.originalImageLabel->size().height() / originalImage.cols;

        // �����ӳ�� -> �����ع�����
        QPoint mappedStart = ui.originalImageLabel->mapFrom(this, rubberBandStart);
        QPoint mappedEnd = ui.originalImageLabel->mapFrom(this, event->pos());
        mappedStart.setX(mappedStart.x() / ratio_x); mappedStart.setY(mappedStart.y() / ratio_y);
        mappedEnd.setX(mappedEnd.x() / ratio_x); mappedEnd.setY(mappedEnd.y() / ratio_y);

        // ���ѡ������
        QRect selectedRect = QRect(mappedStart, mappedEnd).normalized();

        if (!selectedRect.isEmpty()) { // �����ǰѡ������Ϊ��
            cv::Rect roi(selectedRect.x(), selectedRect.y(), selectedRect.width(), selectedRect.height());

            cv::Rect validRect = roi & cv::Rect(0, 0, originalImage.cols, originalImage.rows);

            if (validRect.area() > 0) {
                selectedRegionImage = originalImage(validRect).clone();
                ui.rightLabel->setText("����ѡ��Χ�ĻҶ�ֱ��ͼ");
                histogramDraw(selectedRegionImage);
            }
            else {
                // ����Խ�����������ܴ�ӡһЩ��Ϣ�������������
                qDebug() << "Selected region is out of image bounds.";
            }
        }

        delete currentRubberBand;
        currentRubberBand = nullptr;
    }
}



//��̬��Ա���������������������ʼ��
int ImageProcess::mouse = 0;
QPoint ImageProcess::Start = QPoint(0, 0);
QPoint ImageProcess::End = QPoint(0, 0);
QColor ImageProcess::color = QColor(0, 0, 0);
#pragma once
#pragma execution_character_set("utf-8")  //������ֱ�������


#include <QtWidgets/QMainWindow>
#include <QLabel>
#include <QFileDialog>
#include <QMessageBox>
#include <QImage>
#include <opencv2/opencv.hpp>

#include <QMouseEvent>        //�������ʱ�䣨��������ѡ��Χ��
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
    void displayImageSlot(QLabel*label,const QString& filePath); //չʾԭʼͼ���źţ�


    //������ʾͼƬ������
    void displayImage(QLabel* label, const cv::Mat& image);
    // �����labelΪ��
    //1.originnalImageLabelʱ����ӡ��ԭʼͼ������
    //2.processedImageLabelʱ����ӡ�ڴ���������

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

    //�˵���

   //�½�
    QAction* newAction;

    //�ļ�
    QMenu* fileMenu;
    QAction* newFileAction;
    QAction* openFileAction;
    QAction* saveFileAction;
    QAction* exitAction;

    //��bmpͼƬ
    QAction* openBmpAction;

    //ֱ��ͼ
    QMenu* histogramMenu;
    QAction* allImage;
    QAction* selectImage;
    QAction* his_equalizeAciton;

    //�������
    QMenu* regionPaintMenu;
    QAction* pointSetAction;
    QAction* RGBSetAction;

    //����
    QMenu* helpMenu;

    //��Ա����
    //ui.originalImageLabel(500x500)
    //ui.processdeImageLabel(500x500)
    cv::Mat originalImage;
    cv::Mat selectedRegionImage;

    //����ѡ
    QPoint rubberBandStart;
    QRubberBand* currentRubberBand;

    //point_Dialog* point;
    //RGB_Dialog* rgb;

    static int mouse;      //��currentRubberBand != nullptr��ǰ���£�mouse=0����ʹ������ѡ��mouse=1��ʹ������ѡ
    static QPoint Start;
    static QPoint End;
    static QColor color;
};

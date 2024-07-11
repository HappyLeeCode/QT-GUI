#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QMessageBox>
#include <QImage>
#include <opencv2/opencv.hpp>

#include <QDebug>      //本部分仅用于调试，如：查看文件路径

#include "point_dialog.h"  //包含子类 点设置的对话框
#include "rgb_dialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void displayImageSignal();


private slots:

    void newActionSlot();
    void openFileActionSlot();

    void openBmpActionSlot();
    void displayImageSlot();
    void displayImageSlot(QPoint,QPoint,QColor,QImage*);

    void setPointSlot(QPoint StartPoint,QPoint EndPoint);
    void setColorSlot(QColor color);

    void pointSetActionSlot();
    void RGBSetActionSlot();
    void RegionPaint();

//    void saveFileAcitonSlot();
//    void exitActionSlot();

    cv::Mat histogramActionSlot(const cv::Mat& inputImage);
    void displayImageSlot(QLabel* label,const cv::Mat& image);
//    void his_equalizeActionSlot();

    cv::Mat QImageTocvMatSlot();



private:
    Ui::MainWindow *ui;

 //菜单栏

    //新建
    QAction *newAction;

    //文件
    QMenu *fileMenu;
    QAction *openFileAction;
    QAction *saveFileAction;
    QAction *exitAction;

    //打开bmp图片
    QAction *openBmpAction;

    //直方图
    QAction *histogramAction;
    QAction *his_equalizeAciton;

    //区域描绘
    QMenu *regionPaintMenu;
    QAction *pointSetAction;
    QAction *RGBSetAction;

    //帮助
    QMenu *helpMenu;

 //成员变量
    QImage *image;
    point_Dialog *point;
    RGB_Dialog *rgb;

    static QPoint Start;
    static QPoint End;
    static QColor color;
};
#endif // MAINWINDOW_H

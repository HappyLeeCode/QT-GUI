#include "point_dialog.h"
#include "ui_point_dialog.h"

point_Dialog::point_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::point_Dialog)
{
    ui->setupUi(this);
}

point_Dialog::~point_Dialog()
{
    delete ui;
}

void point_Dialog::on_Button_PointCommit_clicked()
{
    int x1=ui->lineEdit_start_x->text().toInt();
    int y1=ui->lineEdit_start_y->text().toInt();
    int x2=ui->lineEdit_end_x->text().toInt();
    int y2=ui->lineEdit_end_y->text().toInt();
    QPoint startPoint = QPoint(x1,y1);
    QPoint endPoint = QPoint(x2,y2);
    emit resultSignal(startPoint,endPoint);
    this->hide();
}

void point_Dialog::on_Button_PointCancel_clicked()
{
    this->close();
}

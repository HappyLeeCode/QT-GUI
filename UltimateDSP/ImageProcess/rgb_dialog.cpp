#include "rgb_dialog.h"
#include "ui_rgb_dialog.h"

RGB_Dialog::RGB_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RGB_Dialog)
{
    ui->setupUi(this);
}

RGB_Dialog::~RGB_Dialog()
{
    delete ui;
}

void RGB_Dialog::on_Button_RGBCommit_clicked()
{
    int r=ui->lineEdit_R->text().toUInt();
    int g=ui->lineEdit_G->text().toUInt();
    int b=ui->lineEdit_B->text().toUInt();
    QColor color=QColor(r,g,b);
    emit resultSignal(color);
    this->hide();
}

void RGB_Dialog::on_Button_RGBCancel_clicked()
{
    this->close();
}

#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    this->setWindowIcon(QIcon("./app.ico"));

    this->setMaximumSize(660,540);
    this->setMinimumSize(660,540);
    this->setWindowTitle("Lee的计算器  v1.0");

    ui->pushButton_equal->setStyleSheet("background:blue");

    QMessageBox::information(this,"欢迎使用，Lee的计算器v1.0版本","友情提示：\n本版本计算器暂不支持负数，以及多重运算符混合计算！");  //this这个参数，在这里指的是父类的框
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_0_clicked()
{
    QString str = "0";
    input.append(str);
    ui->lineEdit_input->setText(input);
}

void Widget::on_pushButton_1_clicked()
{
    QString str = "1";
    input.append(str);
    ui->lineEdit_input->setText(input);
}

void Widget::on_pushButton_2_clicked()
{
    QString str = "2";
    input.append(str);
    ui->lineEdit_input->setText(input);
}

void Widget::on_pushButton_3_clicked()
{
    QString str = "3";
    input.append(str);
    ui->lineEdit_input->setText(input);
}

void Widget::on_pushButton_4_clicked()
{
    QString str = "4";
    input.append(str);
    ui->lineEdit_input->setText(input);
}

void Widget::on_pushButton_5_clicked()
{
    QString str = "5";
    input.append(str);
    ui->lineEdit_input->setText(input);
}

void Widget::on_pushButton_6_clicked()
{
    QString str = "6";
    input.append(str);
    ui->lineEdit_input->setText(input);
}

void Widget::on_pushButton_7_clicked()
{
    QString str = "7";
    input.append(str);
    ui->lineEdit_input->setText(input);
}

void Widget::on_pushButton_8_clicked()
{
    QString str = "8";
    input.append(str);
    ui->lineEdit_input->setText(input);
}

void Widget::on_pushButton_9_clicked()
{
    QString str = "9";
    input.append(str);
    ui->lineEdit_input->setText(input);
}

void Widget::on_pushButton_point_clicked()
{
    QString str = ".";
    input.append(str);
    ui->lineEdit_input->setText(input);
}

void Widget::on_pushButton_div_clicked()
{
    Operator='/';
    QString str=" / ";
    input.append(str);
    ui->lineEdit_input->setText(input);
}

void Widget::on_pushButton_mul_clicked()
{
    Operator='*';
    QString str=" * ";
    input.append(str);
    ui->lineEdit_input->setText(input);
}

void Widget::on_pushButton_sub_clicked()
{
    Operator='-';
    QString str=" - ";
    input.append(str);
    ui->lineEdit_input->setText(input);
}

void Widget::on_pushButton_add_clicked()
{
    Operator='+';
    QString str=" + ";
    input.append(str);
    ui->lineEdit_input->setText(input);
}

void Widget::on_pushButton_sprt_clicked()
{
    Operator='s';
    QString str=" ^(1/2) ";
    input.append(str);
    ui->lineEdit_input->setText(input);
}

void Widget::on_pushButton_pow_clicked()
{
    Operator='p';
    QString str=" ^ ";
    input.append(str);
    ui->lineEdit_input->setText(input);
}

void Widget::on_pushButton_clear_clicked()
{
    input.clear();
    ui->lineEdit_input->clear();
    ui->lineEdit_output->clear();
}

void Widget::on_pushButton_del_clicked()
{
    input.chop(1);
    ui->lineEdit_input->setText(input);
}

void Widget::on_pushButton_equal_clicked()
{
    arr[1]=0;
    ui->lineEdit_output->clear();

    QStringList Str_List = input.split(" ");
    //split指定空格为分隔符，组成数组Str_List

    Str_List[0]=Str_List[0].simplified(); //不仅去掉首尾的空格，还将中间连续的空格用一个空格代替；
    arr[0]=Str_List[0].toDouble();  //前面的数转成double型，放在arr[0]里

    Str_List[2]=Str_List[2].simplified();
    arr[1]=Str_List[2].toDouble();

    switch(Operator)
    {
        case '+':
            output = arr[0] + arr[1];
        break;

        case '-':
            output = arr[0] - arr[1];
        break;

        case '*':
            output = arr[0] * arr[1];
        break;

        case '/':
            if(arr[1]!=(float)0)
                output = arr[0] / arr[1];
            else
            {
                input=" 错误！除数不能为0，请按AC重新输入";
                ui->lineEdit_input->setText(input);
                output=0;
            }
        break;

         //sqrt
        case 's':
            if(arr[0]<0)
            {
                input=" 错误！被开方数不能为负数，请按AC重新输入";
                ui->lineEdit_input->setText(input);
                output=0;
            }
            else
            output = std::sqrt(arr[0]);
        break;

        //pow
        case 'p':
            output = pow(arr[0],arr[1]);
        break;

    default:
        break;

    }

    ui->lineEdit_output->setText(tr("%1").arg(output));
    input.clear();
}





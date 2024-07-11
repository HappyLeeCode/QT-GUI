#ifndef POINT_DIALOG_H
#define POINT_DIALOG_H

#include <QDialog>

namespace Ui {
class point_Dialog;
}

class point_Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit point_Dialog(QWidget *parent = nullptr);
    ~point_Dialog();

signals:
    void resultSignal(QPoint,QPoint);

private slots:
    void on_Button_PointCommit_clicked();

    void on_Button_PointCancel_clicked();

private:
    Ui::point_Dialog *ui;
};

#endif // POINT_DIALOG_H

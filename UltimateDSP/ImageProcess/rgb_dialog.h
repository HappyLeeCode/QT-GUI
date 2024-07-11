#ifndef RGB_DIALOG_H
#define RGB_DIALOG_H

#include <QDialog>

namespace Ui {
class RGB_Dialog;
}

class RGB_Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit RGB_Dialog(QWidget *parent = nullptr);
    ~RGB_Dialog();

signals:
    void resultSignal(QColor);

private slots:
    void on_Button_RGBCommit_clicked();

    void on_Button_RGBCancel_clicked();

private:
    Ui::RGB_Dialog *ui;
};

#endif // RGB_DIALOG_H

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    double x = ui->doubleSpinBox_weight->value();//метод  value, в х складыввем значение()вес..
    double y = ui->doubleSpinBox_high->value();

    if (x * y == 0){
        QMessageBox::information(this, "Ошибка", "Вы не заполнили все поля");
        return;
    }


    double weight = ui->doubleSpinBox_weight->value();
    double high = ui ->doubleSpinBox_high-> value();
    double result_B = 0;
    double result_J = 0;
    double result_H = 0;

    result_B = (0.47 * weight) + (0.267 * high) - 19.2;
    result_J = (1.1 * weight) - (128 * qPow(weight / high, 2));
    result_H = (0.3281 * weight) +(0.33929 * high) -29.5336;

    ui -> label_result_bur_m ->setText(QString::number(result_B));
    ui -> label_result_2_dsheims_m ->setText(QString::number(result_J));
    ui -> label_result_4_X_m -> setText(QString::number(result_H));
    double result_sr_m = (result_B + result_J + result_H)/3;
    ui -> label_result_sr_m ->setText(QString::number(result_sr_m));

    result_B = (0.252 * weight) + (0.473 * high) - 48.3;
    result_J = (0.29569 * weight) +(0.41813 * high) - 43.2933;
    result_H = (1.07 * weight) - (148 * qPow(weight / high, 2));

    double result_sr_w = (result_B + result_J + result_H)/3;
    ui -> label_bur_w ->setText(QString::number(result_B));
    ui -> label_result_3_Dshjemsw ->setText(QString::number(result_J));
    ui -> label_result_6_X_w -> setText(QString::number(result_H));
    ui -> label_result_sr_w -> setText(QString::number(result_sr_w));
}







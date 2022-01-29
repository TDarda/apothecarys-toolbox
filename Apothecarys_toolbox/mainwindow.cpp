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
    after_30_days = new After_30_days(this);
    after_30_days->show();
}


void MainWindow::on_pushButton_3_clicked()
{
    alcoCalc = new AlcoCalc(this);
    alcoCalc->show();
}


void MainWindow::on_pushButton_2_clicked()
{
    densityCalc = new DensityCalc(this);
    densityCalc->show();
}


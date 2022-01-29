#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "after_30_days.h"
#include "alcocalc.h"
#include "densitycalc.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    After_30_days *after_30_days;
    AlcoCalc * alcoCalc;
    DensityCalc * densityCalc;
};
#endif // MAINWINDOW_H

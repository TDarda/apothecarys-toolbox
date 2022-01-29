#ifndef DENSITYCALC_H
#define DENSITYCALC_H

#include <QDialog>

namespace Ui {
class DensityCalc;
}

class DensityCalc : public QDialog
{
    Q_OBJECT

public:
    explicit DensityCalc(QWidget *parent = nullptr);
    ~DensityCalc();

private slots:
    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_radioButton_3_clicked();

    void on_pushButton_clicked();

private:
    Ui::DensityCalc *ui;
};

#endif // DENSITYCALC_H

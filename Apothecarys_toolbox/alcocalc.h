#ifndef ALCOCALC_H
#define ALCOCALC_H

#include <QDialog>
#include <map>

namespace Ui {
class AlcoCalc;
}

class AlcoCalc : public QDialog
{
    Q_OBJECT

public:
    explicit AlcoCalc(QWidget *parent = nullptr);
    ~AlcoCalc();

private slots:
    void on_pushButton_clicked();

private:
    Ui::AlcoCalc *ui;
    std::map<int, double> AlcTable{{10, 8.01}, {20, 16.21}, {30, 24.61},
                                   {40, 33.3}, {50, 42.43}, {60, 52.09},
                                   {70, 62.39}, {80, 73.48}, {90, 85.66},
                                   {95, 92.41}, {96, 93.84}};


};

#endif // ALCOCALC_H

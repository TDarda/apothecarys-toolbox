#ifndef AFTER_30_DAYS_H
#define AFTER_30_DAYS_H

#include <QDialog>


namespace Ui {
class After_30_days;
}

class After_30_days : public QDialog
{
    Q_OBJECT

public:
    explicit After_30_days(QWidget *parent = nullptr);
    ~After_30_days();

private slots:
    void on_pushButton_clicked();

private:
    Ui::After_30_days *ui;
};

#endif // AFTER_30_DAYS_H

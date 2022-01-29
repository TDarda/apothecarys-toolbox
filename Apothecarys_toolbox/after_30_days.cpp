#include "after_30_days.h"
#include "ui_after_30_days.h"
#include <QMessageBox>


After_30_days::After_30_days(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::After_30_days)
{
    ui->setupUi(this);
    ui->dateEdit->setDate(QDate(2022,01,01));
}

After_30_days::~After_30_days()
{
    delete ui;
}

void After_30_days::on_pushButton_clicked()
{
    QString answer;
    auto issueDate = ui->dateEdit->date();
    double diffDate = issueDate.daysTo(QDate::currentDate());
    if(diffDate <= 30){answer = "It's OK!!";}
    else
    {

        double lengthOfTherapy = (ui->how_many_pac->text().toDouble() * ui->size_pac->text().toDouble())
                            /ui->dosage->text().toDouble();
        double daysLeftTherapy = lengthOfTherapy - diffDate;

        if(!(daysLeftTherapy < (ui->small_pac->text().toDouble() /  ui->dosage->text().toDouble())))
        {
            answer = "you can give ";
            double temp = daysLeftTherapy / (ui->size_pac->text().toDouble() / ui->dosage->text().toDouble());
            int givePack = temp;
            if(givePack > 0){answer += QString::number(givePack) + " packs of " + ui->size_pac->text() + " pieces"; }
            double rest = ui->size_pac->text().toDouble() * (temp - givePack);
            double giveSmallPack = rest / (ui->small_pac->text().toDouble() /  ui->dosage->text().toDouble());
            if(giveSmallPack > 0 and giveSmallPack < 1){giveSmallPack = 1;}
            if(givePack > 0 and giveSmallPack > 0){answer += "\n and " + QString::number(int(giveSmallPack)) + " packs of " + ui->small_pac->text() + " pieces";}
            else if(givePack < 1 and giveSmallPack > 0){answer += QString::number(giveSmallPack) + " packs of " + ui->small_pac->text() + " pieces"; }
        }
        else
        {
            answer = "you can't give anything";
        }
    }

    QMessageBox::about(this, "calculate", answer);
}


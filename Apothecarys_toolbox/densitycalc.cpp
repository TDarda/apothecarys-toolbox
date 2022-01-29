#include "densitycalc.h"
#include "ui_densitycalc.h"

DensityCalc::DensityCalc(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DensityCalc)
{
    ui->setupUi(this);
    ui->radioButton->setChecked(true);
    ui->dentsityEdit->setDisabled(true);
}

DensityCalc::~DensityCalc()
{
    delete ui;
}

void DensityCalc::on_radioButton_clicked()
{
    ui->dentsityEdit->setDisabled(true);
    ui->volumeEdit->setDisabled(false);
    ui->massEdit->setDisabled(false);
}


void DensityCalc::on_radioButton_2_clicked()
{
    ui->volumeEdit->setDisabled(true);
    ui->massEdit->setDisabled(false);
    ui->dentsityEdit->setDisabled(false);
}


void DensityCalc::on_radioButton_3_clicked()
{
    ui->massEdit->setDisabled(true);
    ui->volumeEdit->setDisabled(false);
    ui->dentsityEdit->setDisabled(false);
}


void DensityCalc::on_pushButton_clicked()
{
    double dentsity = ui->dentsityEdit->text().toDouble(),
           mass = ui->massEdit->text().toDouble(),
           volume = ui->volumeEdit->text().toDouble();

    if(ui->radioButton->isChecked()) //dentsity
    {
        dentsity = mass/volume;
        ui->dentsityEdit->setDisabled(false);
        ui->dentsityEdit->setText(QString::number(dentsity));
    }
    if(ui->radioButton_2->isChecked()) //volume
    {
        volume = mass / dentsity;
        ui->volumeEdit->setDisabled(false);
        ui->volumeEdit->setText(QString::number(volume));
    }
    if(ui->radioButton_3->isChecked()) //mass
    {
        mass = volume * dentsity;
        ui->massEdit->setDisabled(false);
        ui->massEdit->setText(QString::number(mass));
    }
}


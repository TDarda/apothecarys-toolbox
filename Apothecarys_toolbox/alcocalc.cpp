#include "alcocalc.h"
#include "ui_alcocalc.h"
#include <iterator>
#include <QMessageBox>

AlcoCalc::AlcoCalc(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AlcoCalc)
{
    ui->setupUi(this);
    for(auto it = AlcTable.begin(); it != AlcTable.end(); ++it )
    {
        QString alcVtoM = QString::number(it->first) + "°(v/v) - " + QString::number(it->second) + "%(m/m)";
        ui->desireBox->addItem(alcVtoM);
        ui->ownedBox->addItem(alcVtoM);
    }
}

AlcoCalc::~AlcoCalc()
{
    delete ui;
}

void AlcoCalc::on_pushButton_clicked()
{
    auto itDes = AlcTable.begin(), itOwn = AlcTable.begin();
    int posDes = ui->desireBox->currentIndex(), posOwn = ui->ownedBox->currentIndex();
    std::advance(itDes, posDes);
    std::advance(itOwn, posOwn);
    double desirePercent = itDes->second, ownedPercent = itOwn->second;

    double amountOfSol = ui->AmountSolEdit->text().toDouble();
    double amountOwnAlcToUse = (desirePercent * amountOfSol) / ownedPercent;
    double amountWaterToUse = amountOfSol - amountOwnAlcToUse;



    QMessageBox::about(this, "Calculation", "You must use " + QString::number(amountOwnAlcToUse)+
                       " grams of " + QString::number(itOwn->first)+"° alcohol, and " +
                       QString::number(amountWaterToUse) + " grams of water.");


}

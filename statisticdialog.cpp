#include "statisticdialog.h"
#include "ui_statisticdialog.h"
#include <QDate>

statisticDialog::statisticDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::statisticDialog)
{
    ui->setupUi(this);
    for(int i =2000; i<2020; i++){
        ui->comboBox->addItem(QString::number(i));

    }
}

statisticDialog::~statisticDialog()
{
    delete ui;
}

void statisticDialog::on_pushButton_clicked()
{


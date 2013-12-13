#include "changepass.h"
#include "ui_changepass.h"
#include <QMessageBox>

changepass::changepass(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::changepass)
{
    ui->setupUi(this);
    setWindowTitle("NA SOFTWARE");
}

changepass::~changepass()
{
    delete ui;
}

void changepass::on_pushButton_clicked()
{
    if(ui->lineEdit->text().size()>0 && ui->lineEdit_2->text().size()>0 && ui->lineEdit_3->text().size()>0){

    user=ui->lineEdit->text();
    pass=ui->lineEdit_2->text();
    newpass=ui->lineEdit_3->text();

    this->close();

}

    else{ QMessageBox::information(this, "ინფორმაცია", "ველები არ არის შევსებული");
}
}



void changepass::on_pushButton_2_clicked()
{
    this->close();
}

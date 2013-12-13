#include "changepass2.h"
#include "ui_changepass2.h"
#include <QMessageBox>

ChangePass2::ChangePass2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChangePass2)
{
    ui->setupUi(this);
}

ChangePass2::~ChangePass2()
{
    delete ui;
}

void ChangePass2::on_pushButton_clicked()
{
    if(ui->lineEdit->text().size()>0&&ui->lineEdit_2->text().size()>0&&ui->lineEdit_3->text().size()>0){
        name =ui->lineEdit->text();
        pass = ui->lineEdit_2->text();
        newpass = ui->lineEdit_3->text();
        this->close();

    }
    else{ QMessageBox::information(this,"ინფორმაცია", "ველები არ არის შევსებული");
}
}

void ChangePass2::on_pushButton_2_clicked()
{
    this->close();
}

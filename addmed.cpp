#include "addmed.h"
#include "ui_addmed.h"
#include <QFileDialog>

AddMed::AddMed(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddMed)
{
    ui->setupUi(this);
}

AddMed::~AddMed()
{
    delete ui;
}

void AddMed::on_pushButton_clicked()
{
    //ამოწმებს ცარიელია თუ არა რომელიმე ველი
    if(ui->lineEdit->text().size()>0 && ui->lineEdit_2->text().size()>0 && ui->lineEdit_3->text().size()>0
            && ui->lineEdit_4->text().size()>0 && ui->lineEdit_5->text().size()>0 && ui->lineEdit_6->text().size()>0 && ui->lineEdit_7->text().size()>0 && ui->lineEdit_8->text().size()>0){
        imageurl=ui->lineEdit_8->text();
            name = ui->lineEdit->text();
             lastname = ui->lineEdit_2->text();
             datebirthday = ui->lineEdit_3->text();
              address = ui->lineEdit_4->text();
            email = ui->lineEdit_5->text();
            phone = ui->lineEdit_6->text();
            diagnose = ui->lineEdit_7->text();


          this->close();

    }
    else {
        QMessageBox::information(this, "შეცდომა", "<font size=4>შეავსეთ ყველა ველი!</font>");
    }
}




void AddMed::on_pushButton_3_clicked()
{
    QString filename;
    filename=QFileDialog::getOpenFileName(this,"გახსნა");


    ui->lineEdit_8->setText(filename);
}

#include "authdialog2.h"
#include "ui_authdialog2.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlRecord>
#include <changepass2.h>


Authdialog2::Authdialog2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Authdialog2)
{
    ui->setupUi(this);
    login = QSqlDatabase::addDatabase("QSQLITE");
    login.setDatabaseName("");
    login.open();
    auth = false;
}

Authdialog2::~Authdialog2()
{
    delete ui;
    login.close();
}

void Authdialog2::on_pushButton_clicked()
{
    QString name,pass;
    name = ui->lineEdit->text();
    pass = ui->lineEdit_2->text();
    QSqlQuery qry(login);
    QString sql ="SELECT username, password FROM Users WHERE username='%1' AND password='%2'";
    if(qry.exec(sql.arg(name).arg(pass))){

        if(qry.next()){
            auth=true;
        }
        else{
            auth=false;
        }
        if(auth){
            this->close();
        }
     }
}
void Authdialog2::on_pushButton_2_clicked()
{
   ChangePass2 pas;
   pas.setm






}

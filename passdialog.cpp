#include "passdialog.h"
#include "ui_passdialog.h"
#include <QMessageBox>
#include <QSqlQuery>

passDialog::passDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::passDialog)
{
    ui->setupUi(this);
    setWindowTitle("ვისტამედი");
    login=QSqlDatabase::addDatabase("QSQLITE");
    login.setDatabaseName("C:/login");
    login.open();

}

passDialog::~passDialog()
{
    delete ui;
    login.close();
}

void passDialog::on_pushButton_clicked()
{

  QSqlQuery qry;
QString userr,pass,newpass;
userr= ui->lineEdit->text();
pass=ui->lineEdit_2->text();
newpass=ui->lineEdit_3->text();
QString sql="SELECT username,password,type FROM Users WHERE username='%1' AND password='%2' AND type='%3'";
if(qry.exec(sql.arg(userr).arg(pass).arg(newpass))){
    if(qry.next()){
        auth=true;
        QMessageBox::information(this,"ინფორმაცია","პაროლი დაემატა");

    }
    else auth=false;
}
if(auth){
    close();
}
}


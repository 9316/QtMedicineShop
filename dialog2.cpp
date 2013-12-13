#include "dialog2.h"
#include "ui_dialog2.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlRecord>

Dialog2::Dialog2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Dialog2)
{


ui->setupUi(this);
setWindowTitle("NA SOFTWARE");
log=QSqlDatabase::addDatabase("QSQLITE");
log.setDatabaseName("C:/login");
log.open();
auth=false;
}
Dialog2::~Dialog2()
{

delete ui;
log.close();
}

void Dialog2::on_pushButton_2_clicked()
{
QString user,pass2;
    user =ui->lineEdit->text() ; //ანიჭებს user სტრინგს ტექსტს ლაინედიტიტდან
    pass2= ui->lineEdit_2->text();
    QSqlQuery qry;
    QString sql = "SELECT username, password FROM Users WHERE username='%1' AND password='%2'";
      if(qry.exec(sql.arg(user)
                  .arg(pass2))){


    //მონიშნე სახელი პაროლი და ტიპი უზერ ცხრილიდან

        if(qry.next()){
            auth=true; //ავტორიზაცია წარმატებულია ბულ


        }
        else
            auth=false;
    }
    if(auth){
        this->close();

    }
    else if(ui->lineEdit->text().trimmed().isEmpty()){
        QMessageBox::warning(this,"ყურადღება","<font size=4>გთხოვთ შეიყვანოთ თქვენი სახელი და პაროლი</font>");
    }
    else{
        QMessageBox::warning(this,"ყურადღება","<font size=4>სახელი ან პაროლი არასწორია კიდევ სცადეთ</font>");
    }


}







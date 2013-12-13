#include "authdialog.h"
#include "ui_authdialog.h"
#include <QMessageBox>
#include <QDebug>
#include <QSqlQuery>
#include <passdialog.h>
#include <QSqlRecord>
#include <changepass.h>

#include <mainwindow.h>
authDialog::authDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::authDialog)
{
    ui->setupUi(this);
    setWindowTitle("NA SOFTWARE");
    log=QSqlDatabase::addDatabase("QSQLITE");
    log.setDatabaseName("C:/login");
    log.open();
    auth=false;

}
authDialog::~authDialog()
{
    delete ui;
   log.close();
}

void authDialog::on_pushButton_clicked()
{
    QString user,pass2;
        user = ui->lineEdit->text(); //ანიჭებს user სტრინგს ტექსტს ლაინედიტიტდან
        pass2= ui->lineEdit_2->text();
        QSqlQuery qry;
        QString sql = "SELECT username, password FROM Users WHERE username='%1' AND password='%2'";  //მონიშნე სახელი პაროლი და ტიპი უზერ ცხრილიდან
          if(qry.exec(sql.arg(user)
                      .arg(pass2))){




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



void authDialog::on_pushButton_2_clicked()
{

    changepass pass1;
    pass1.setModal(true);
    pass1.exec();
    if(pass1.newpass.size()!=0 && pass1.user.size()!=0 && pass1.pass.size()!=0 ){
    QSqlQuery qry(log);
    QString sql = "UPDATE Users SET password='%1' WHERE password='%2' AND username='%3'";


    if(qry.exec(sql.arg(pass1.newpass).arg(pass1.pass).arg(pass1.user))){
        QString sql2 = "SELECT * FROM Users WHERE password='%1' AND username='%2'";
        qry.exec(sql2.arg(pass1.newpass).arg(pass1.user));
                if(qry.next()){

                  QMessageBox::warning(this, "ყურადღება", "<font size=4>პაროლი შეიცვლა</font>");


                }
                else{
                    QMessageBox::warning(this,"ყურადღება", "<font size=4>დაფიქსირდა შეცდომა პაროლი არ შეცვლილა</font/>");
                }


     }
}

}




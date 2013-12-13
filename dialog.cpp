 #include "dialog.h"
#include "ui_dialog.h"
#include <QInputDialog>
#include <QDate>
#include <QtWebKit>
#include <mainwindow.h>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

}

Dialog::~Dialog()
{
    delete ui;
}
//იღებს მონაცემებს და აყენებს შესაბამის ლეიბლებზე
void Dialog::setLabels(QString name, QString lastname, QString datebirthday, QString address,QString email,QString phone,QString diagnose,QString date,QString imageurl, QString toDay){

     ui->labelName->setText("<b><font size=4>"+name + "</font></b>");
    ui->labelLastname->setText("<b><font size=4>"+lastname + "</font></b>");
    if(datebirthday==toDay){
        ui->labelDatebirhday->setText("<b><font size=4 color=red>"+datebirthday + "</font></b>");
    }
    else{
        ui->labelDatebirhday->setText("<b><font size=4>"+datebirthday + "</font></b>");
    }
    ui->labelAddress->setText("<b><font size=4>"+address + "</font></b>");
    ui->labelEmail->setText("<b><font size=4>"+email + "</font></b>");
     ui->labelPhone->setText("<b><font size=4>"+phone + "</font></b>");
      ui->labelDiagnose->setText("<b><font size=4>"+diagnose + "</font></b>");
      ui->label_9->setText("<b><font size=4>"+ date + "</font><b>");

  QUrl url(imageurl); //მისამართის ობიექტის შექმნა imgurl ცვლადით
  ui->webView->setUrl(QUrl::fromLocalFile(imageurl));
 


}
 //   ui->webView->setUrl(url); //ვებ მისამართის ჩატვირთვა
 //   p=price;
//   a=amount;


/*void Dialog::on_pushButton_clicked()
{
    SellDialog d; //გაყიდვის დიალოგური ფანრჯის გახსნა
    d.getInfo(a,p);
    d.setModal(true);
    d.exec();
}
*/


#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QInputDialog> //შესაყვანი ბრძანების ფანჯრის გამოჩენა
#include <authdialog.h>
#include <QHeaderView>
#include <addmed.h>
#include <QSqlRecord>
#include <QDateTime>
#include <QTime>
#include <statisticdialog.h>
#include <QDate>
#include <dialog2.h>
#include <persons.h>
#include <dialogcalendar.h>
#include <smtp.h>
#include <dialogcalculator.h>
#include <QTextCodec>
#include <QPrinter>
#include <QPrintDialog>
#include <QPainter>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

   authDialog login;
   login.setModal(true);
   login.exec();


    setWindowTitle("NA SOFTWARE");
 if(login.auth){
        ui->setupUi(this); //ეს ქმნის ინტერფრეიის xml კოდიდან

 }


    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/nika/desktop/medical");
    db.open();
 //   showMaximized(); გადიდება
QFont font;
font.setPointSize(10);
QHeaderView* headerView = new QHeaderView(Qt::Horizontal); //ფონტების დაყენება
headerView->setFont(font);

headerView->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding); //expanding - გაფართოებადი

ui->tableView->setHorizontalHeader(headerView);
menuBar()->setFont(font);






   model = new QSqlTableModel(this, db);  //სქლ-ის ცხრილის მოდელი
    model->setTable("med"); //მედ ცხრილის ამორცევა
    model->select(); //ცხრილი მონიშვნა
    model->setEditStrategy(QSqlTableModel::OnManualSubmit); //რედაქტირების მეთოდი (მექანიკური)
  model->removeColumn(0); //პირველი სვეტის წაშლა
 model->removeColumn(0);
    model->setHeaderData(0, Qt::Horizontal, tr("სახელი"));  //სვეტების სახელების დარქმევა
    model->setHeaderData(1, Qt::Horizontal, tr("გვარი"));
    model->setHeaderData(2, Qt::Horizontal, tr("დაბადების თარიღი"));
    model->setHeaderData(3, Qt::Horizontal, tr("მისამართი"));
    model->setHeaderData(4, Qt::Horizontal, tr("ელ.ფოსტა"));
    model->setHeaderData(5, Qt::Horizontal, tr("ტელ"));
    model->setHeaderData(6, Qt::Horizontal, tr("ანალიზი"));
    model->setHeaderData(7,Qt::Horizontal, tr("თარიღი"));
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows); //სტრიქონების ამორჩევის ამორჩევის მეთოდი
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection); //ამორჩევის მეთოდი (მხოლოდ ერთის ამორჩევა)
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers); //რედაქტირების შეზღუდვა პირდაპირ ცხრილიდან
    ui->tableView->setModel(model);
    this->showMaximized();
    ui->tableView->resizeColumnsToContents(); //ზომის დაყენება სვეტების შიგთავსის მიხედვით
    ui->tableView->resizeRowsToContents(); //სტრიქონების შიგთავსის მიხედვით
    ui->lineEdit->hide(); //ძებნის
    ui->label->hide();  //ძებნის
    ui->label_2->hide(); //ძებნის
    ui->lineEdit_2->hide(); //ძებნის
    ui->pushButton->hide(); //ძებნის
    ui->comboBox->hide();  //სტატისტიკის
    ui->comboBox_2->hide(); //სტატისტიკის
    ui->label_3->hide();
    ui->label_4->hide();
    ui->pushButton_2->hide();
    ui->label_5->hide();
    ui->listWidget->hide();
    ui->label_6->hide();
    ui->pushButton_3->hide();
    ui->lineEdit_3->hide();
    ui->lineEdit_4->hide();
    ui->lineEdit_5->hide();
    ui->lineEdit_6->hide();
    ui->lineEdit_7->hide();
    ui->textEdit->hide();
    ui->label_8->hide();
    ui->label_9->hide();
    ui->label_10->hide();
    ui->label_11->hide();
    ui->label_12->hide();
    ui->label_13->hide();
    showSearchToolbar = false;
    
    QDateTime date = QDateTime::currentDateTime();
    QString tdate=date.date().toString("dd/MM/yyyy");

    fullDate = tdate;
    qDebug()<<fullDate;
    calcBirthday();


 }


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionAdd_triggered(){
    QSqlQuery qry(db);

   QDateTime date=QDateTime::currentDateTime();
   QTime time=QTime::currentTime();
    AddMed addmed; //AddMed კლასის ობიექტი
    QString sql = "INSERT INTO med (imageurl,name,lastname,datebirthday,address,email,phone,diagnose,date)"
            "VALUES ('%1', '%2', '%3', '%4', '%5', '%6', '%7', '%8', '%9')"; //სქლ-ის ბრძანების სტრინგი

    addmed.setModal(true);
    addmed.exec(); //წამლის დამატების ფანჯრის გამოჩენა
  //  qDebug()<<addmed.imgUrl;
    QString tdate=date.date().toString("MMMM dd yyyy - ") + " %1 : %2";
    if(addmed.name.size()!=0 && addmed.lastname.size()!=0){ //ვამოწმებთ შევსებული იყო თუ არა სრულყოფილად დამატების დიალოგური ფანჯარა
    qry.exec(sql.arg(addmed.imageurl)//სქლ ბრძანების გაშვება შესაბამისი არგუმენტებით
             .arg(addmed.name)
             .arg(addmed.lastname)
             .arg(addmed.datebirthday)
             .arg(addmed.address)
             .arg(addmed.email)
           .arg(addmed.phone)
                  .arg(addmed.diagnose)
             .arg(tdate.arg(time.hour()).arg(time.minute())));//sql სტრინგს გადავცემთ tdate სტრინგს არგუმენტებით time.hour() და time.minute()
    QSqlRecord rec = model->record(); //სქლიდან დაბრუნებული ინფორმაციის ჩანაწერი
   model->setRecord(model->rowCount(),rec); //სქლ-ის მოდელში მონაცემის ჩამატება ჩანაწერის მიხედვით(rec)
    model->submitAll(); //ჩანაწერის დამტკიცება
    calcBirthday();

}
    else{
       QMessageBox::warning(this, "დაფიქსირდა შეცდომა", "<font size=4>ველები არ არის შევსებული</font> ");
   }
    
    

}

void MainWindow::calcBirthday(){
    QList<Persons> people;
    ui->listWidget->clear();
    people.clear();



    for(int i=0; i<ui->tableView->model()->rowCount(); i++){

            QString name= ui->tableView->model()->data(ui->tableView->model()->index(i,0)).toString();
            QString lastname = ui->tableView->model()->data(ui->tableView->model()->index(i,1)).toString();
            QString datebirthday = ui->tableView->model()->data(ui->tableView->model()->index(i,2)).toString();

            Persons p(name,lastname,datebirthday);
            people.append(p);

    }

    int day = QDate::currentDate().day();
        int month = QDate::currentDate().month();
        int count=0;

        for(int i=0; i<people.size(); i++){

            if(day==people.at(i).datebirthday.split("/").at(0).toInt() &&
                    month==people.at(i).datebirthday.split("/").at(1).toInt()){
                ui->listWidget->addItem(new QListWidgetItem());

                ui->listWidget->item(count)->setText(people.at(i).name + " " + people.at(i).lastname + "  "+people.at(i).datebirthday);
                                     count++;
                //ui->label_6->setText(ui->label_6->text() + " " + "დღეს დაბადაების აქვს"  + people.at(i).name + " " + people.at(i).lastname + " დაბადების დღე!");
            }
            else if((people.at(i).datebirthday.split("/").at(0).toInt()-day)<7 &&
                    (people.at(i).datebirthday.split("/").at(0).toInt()-day)>=1){
                //ui->label_6->setText( ui->label_6->text() + "უახლოესი დაბადების დღე აქვს " + people.at(i).name);
            }
        }


}



void MainWindow::on_actionDelete_triggered()

{


    QSqlQuery qry(db);
   int rowid = ui->tableView->selectionModel()->selectedIndexes().at(0).row(); //მონიშნული სტრიქონის ინდექსი
   QString str = "DELETE FROM med WHERE name='%1' AND lastname='%2'"; //სქლ ბრძანების სტრინგი (ამოშლა name-ის მიხედვით)
   // ცხრილის მოდელიდან იღებს ინფორმაციას, ცხრილის მოდელის ინდექსის მიხედვით და გადაყავს სტრინგში
   QString name = ui->tableView->model()->data(ui->tableView->model()->index(rowid,0)).toString();
   QString lastname = ui->tableView->model()->data(ui->tableView->model()->index(rowid,1)).toString();
    qry.exec(str.arg(name).arg(lastname));
    calcBirthday();
    ui->listWidget->clear();
    model->submitAll();
  
}




void MainWindow::on_actionSearch_triggered()
{
//    //ინფუთ დიალოგიდან getText მეთოდით შემოდის სიტყვა და იწერება სტრინგში
//    QString search = QInputDialog::getText(this,"ძებნა","<font size=4>შეიყვანეთ პაციენტის გვარი</font>",QLineEdit::Normal);
//    //შემდეგი ობიექტის საშუალებით ჩვენ გვექნება ახალი მოდელი რომელსაც ექნება გაფილტრვის(ძებნის) შესაძლებლობა
//    QSortFilterProxyModel *proxyModel = new QSortFilterProxyModel(this);
//    proxyModel->setSourceModel(model); //ძველი მოდელი მითითება
//    //რის მიხედვით უნდა მოხდეს ძებნა. ამ შემთხვევაში არ აქვს მნიშვნელობა დიდ და პატარა ასოს, ელოდება სტრინგს
//    proxyModel->setFilterRegExp(QRegExp(search, Qt::CaseInsensitive, QRegExp::FixedString));
//    proxyModel->setFilterKeyColumn(-1); //სვეტების შემოზღუდვა (გათიშულია)
//    ui->tableView->setModel(proxyModel); //ცხრილის ახალ მოდელზე დაფუძნება
//    ui->tableView->show(); //ახალი მოდელის გამოყენება
    if(!showSearchToolbar){      // თუ არ არის გამოჩენილი მაგ შემთხვევაში გამოჩენს
        ui->lineEdit->show();
        ui->lineEdit_2->show();
        ui->label->show();
        ui->label_2->show();
        ui->pushButton->show();
        showSearchToolbar=true;

    }
    else{
        ui->lineEdit->hide();
        ui->label->hide();
        ui->label_2->hide();
        ui->lineEdit_2->hide();
        ui->pushButton->hide();
        showSearchToolbar=false;
    }

}

void MainWindow::on_tableView_doubleClicked(const QModelIndex &index)
{
    //ცხრილის მოდელიდან იღებს ინფორმაციას, ცხრილის მოდელის ინდექსის მიხედვით და გადაყავს სტრინგში
    QString name = ui->tableView->model()->data(ui->tableView->model()->index(index.row(),0)).toString();
    QString lastname = ui->tableView->model()->data(ui->tableView->model()->index(index.row(),1)).toString();
    QString datebirthday = ui->tableView->model()->data(ui->tableView->model()->index(index.row(),2)).toString();
    QString address  = ui->tableView->model()->data(ui->tableView->model()->index(index.row(),3)).toString();
    QString email = ui->tableView->model()->data(ui->tableView->model()->index(index.row(),4)).toString();
    QString phone = ui->tableView->model()->data(ui->tableView->model()->index(index.row(),5)).toString();
    QString diagnose=ui->tableView->model()->data(ui->tableView->model()->index(index.row(),6)).toString();
    QString date = ui->tableView->model()->data(ui->tableView->model()->index(index.row(),7)).toString();
    QSqlQuery qry(db);
    QString imageurl;
    qry.prepare("SELECT name FROM med WHERE name=:name"); //სქლ ბრძანების მომზადება გამოყენებისათვის
    qry.bindValue(":name",name);//:name იცვლება ჩვენი სტრინგით name
    qry.exec(); //გაშვება
    qry.next(); //აუცილებელია გამოძახება რომ დააბრუნოს მნიშვნელობa
    Dialog showInfo; //ინფორმაციის დიალოგური ფანჯრის ობიექტის შექმნა
    imageurl=qry.value(0).toString();
    showInfo.setLabels(name,lastname,datebirthday,address,email,phone,diagnose,date,imageurl, fullDate); //ობიექტის დახმარებით გადავცემთ setlabel მეთოდის ცვლადებს
    showInfo.setModal(true);
    showInfo.exec();
}


void MainWindow::on_actionAbout_triggered()
{
    QMessageBox::information(this, "ინფორმაცია", "<font size=4>პროგრამა დაწერილია ნიკა ფანოზიშვილის  მიერ</font>");
}




void MainWindow::on_actionRefresh_triggered()
{
    ui->tableView->setModel(model);


        }



void MainWindow::on_actionExit_triggered()
{
    QMessageBox::StandardButton but;
    but=QMessageBox::question(this,"ინფორმაცია", "<font size=4>გსურთ პროგრამიდან გასვლა?</font>",
                              QMessageBox::Yes | QMessageBox::No);
    if(but==QMessageBox::Yes){
    QMessageBox::warning(this,"ინფორმაცია", "<font size=4>გისურვებთ წარმატებებს");
this->hide();
  MainWindow w;
  w.show();
this->show();
}
else QMessageBox::information(this,"ინფორმაცია","<font size=4>პროგრამა აგრძელებს მუშაობას</font>");



}

void MainWindow::on_pushButton_clicked()
{

    QString name =ui->lineEdit->text();
    QString lastname =ui->lineEdit_2->text();
    //შემდეგი ობიექტის საშუალებით ჩვენ გვექნება ახალი მოდელი რომელსაც ექნება გაფილტრვის(ძებნის) შესაძლებლობა
    QSortFilterProxyModel *proxyModel = new QSortFilterProxyModel(this);
    proxyModel->setSourceModel(model); //ძველი მოდელი მითითება
    QSortFilterProxyModel *proxyModel_2 = new QSortFilterProxyModel(this);
     proxyModel_2->setSourceModel(proxyModel);
    if(!ui->lineEdit->text().trimmed().isEmpty()){

    //რის მიხედვით უნდა მოხდეს ძებნა. ამ შემთხვევაში არ აქვს მნიშვნელობა დიდ და პატარა ასოს, ელოდება სტრინგს
    proxyModel->setFilterRegExp(QRegExp(name, Qt::CaseInsensitive, QRegExp::FixedString));
  // proxyModel->setFilterKeyColumn(-1); //სვეტების შემოზღუდვა (გათიშულია) //შეზღუდვა გათიშულია ძებნისთვის
    ui->tableView->setModel(proxyModel); //ცხრილის ახალ მოდელზე დაფუძნება
    ui->tableView->show();
    }
    if(!ui->lineEdit_2->text().trimmed().isEmpty()){                        //Caseinsensitive -ძებნის დროს ფუნქცია არაქცევს დიდ და პატარა ასოს

     proxyModel_2->setFilterRegExp(QRegExp(lastname,Qt::CaseInsensitive,QRegExp::FixedString)); //Qregexp - განაპიროებს თუ რის მიხედვით შეიძლება იყოს ძებნა ამ შემთხვევაში ხდება ძებნა სახელი გვარი მიხედვით როცა დიდ და პატარა ასოს არ ექცევა ყურადღება
          proxyModel_2->setFilterKeyColumn(-1);
     ui->tableView->setModel(proxyModel_2);
     ui->tableView->show();
    }

    if(ui->lineEdit->text().trimmed().isEmpty() && ui->lineEdit_2->text().trimmed().isEmpty()){

        QMessageBox::warning(this,"ყურადღება" ," ველები არ არის შევსებული ");
    }


}


void MainWindow::on_actionStatics_triggered()
{
    if(!showSearchToolbar){

        ui->label_3->show();
        ui->comboBox->show();
        ui->comboBox_2->show();
        ui->label_4->show();
        ui->pushButton_2->show();
        ui->label_5->show();
        showSearchToolbar=true;
    }
    else{

        ui->label_4->hide();
        ui->comboBox->hide();
        ui->comboBox_2->hide();
        ui->label_3->hide();
        ui->pushButton_2->hide();
        ui->label_5->hide();
        showSearchToolbar=false;
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    QString month,yers;
    month=ui->comboBox->itemText( ui->comboBox->currentIndex());
    yers=ui->comboBox_2->itemText(ui->comboBox_2->currentIndex());

//QSortFilterProxyModel ახალი ობიექტი რომელსაც ექნება გაფილტვრის შესაძლებლობა
    QSortFilterProxyModel *proxyModel_3 =new QSortFilterProxyModel(this);
    proxyModel_3->setSourceModel(model); //ძველი მოდელის მითითება
    QSortFilterProxyModel *proxyModel_4 = new QSortFilterProxyModel(this);
    proxyModel_4->setSourceModel(proxyModel_3);


        proxyModel_3->setFilterRegExp(QRegExp(month, Qt::CaseInsensitive ,QRegExp::FixedString));
        proxyModel_3->setFilterKeyColumn(-1);
        ui->tableView->setModel(proxyModel_3);
        ui->tableView->show();



        proxyModel_4->setFilterRegExp(QRegExp(yers, Qt::CaseInsensitive, QRegExp::FixedString));
        proxyModel_4->setFilterKeyColumn(-1);
        ui->tableView->setModel(proxyModel_4);
 ui->tableView->show();
        QString monthStat = month.left(month.length()-1); //გამოკლება 1 ით
        ui->label_5->setText("<b>"+ yers+ " წლის " +monthStat + "ში პაციენტთა რაოდენობაა  "  + QString::number(proxyModel_4->rowCount()) + "</b>");
    }
      //  if(ui->lineEdit_3->text().trimmed().isEmpty() && ui->lineEdit_4->text().trimmed().isEmpty()){
          //  QMessageBox::information(this,"ინფორმაცია", "ველები არ არის შევსებული");
      //  }
   // }


void MainWindow::on_action_triggered()
{
  DialogCalendar calendar;


    QList<Persons> people;
    for(int i=0; i<ui->tableView->model()->rowCount(); i++){

            QString name= ui->tableView->model()->data(ui->tableView->model()->index(i,0)).toString();
            QString lastname = ui->tableView->model()->data(ui->tableView->model()->index(i,1)).toString();
            QString datebirthday = ui->tableView->model()->data(ui->tableView->model()->index(i,2)).toString();
            Persons p(name,lastname,datebirthday);
            people.append(p);

    }
    calendar.setArray(people);
    calendar.setModal(true);
    calendar.exec();

}

void MainWindow::on_pushButton_3_clicked()   //Mail
{
   QEventLoop loop;
   QString mail1 = ui->lineEdit_3->text();
   QString pass = ui->lineEdit_4->text();
   QString name = ui->label_5->text();
   QString type = ui->lineEdit_6->text();
   QString heMail = ui->lineEdit_7->text();
   QString post = ui->textEdit->toPlainText();

   QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
   Smtp *smtp = new Smtp(mail1,pass,"smtp.gmail.com", 465);
   smtp->sendMail(name,heMail,type,post);
}

void MainWindow::on_action_2_triggered()  //კალკულატორის კლასის დიალოგური ფანჯრის გამოძახება
{
    DialogCalculator calc;
    calc.setModal(true);
    calc.exec();

}

void MainWindow::on_action_4_triggered()
{
    if(!showSearchToolbar){
        ui->listWidget->show();
        ui->label_6->show();
        showSearchToolbar=true;
    }
    else{
       ui->listWidget->hide();
       ui->label_6->hide();
       showSearchToolbar=false;
    }
}

void MainWindow::on_action_3_triggered()
{
    if(!showSearchToolbar){
        ui->pushButton_3->show();
        ui->lineEdit_3->show();
        ui->lineEdit_4->show();
        ui->lineEdit_5->show();
        ui->lineEdit_6->show();
        ui->lineEdit_7->show();
        ui->textEdit->show();
        ui->label_8->show();
        ui->label_9->show();
        ui->label_10->show();
        ui->label_11->show();
        ui->label_12->show();
        ui->label_13->show();
        showSearchToolbar=true;
    }
    else{
        ui->pushButton_3->hide();
        ui->lineEdit_3->hide();
        ui->lineEdit_4->hide();
        ui->lineEdit_5->hide();
        ui->lineEdit_6->hide();
        ui->lineEdit_7->hide();
        ui->textEdit->hide();
        ui->label_8->hide();
        ui->label_9->hide();
        ui->label_10->hide();
        ui->label_11->hide();
        ui->label_12->hide();
        ui->label_13->hide();
        showSearchToolbar=false;
    }
}



void MainWindow::on_action_5_triggered()
{
    bool b;

    if(b){
       int i =0;
    QString line = QInputDialog::getText(this,"ფაილი","შეიყვანეთ ფაილის სახელი" ,QLineEdit::Normal);
    QPrinter printer(QPrinter::HighResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName("C:/Users/nika/Desktop/"+line+".pdf");

    QString name = ui->tableView->model()->data(ui->tableView->model()->index(i,0)).toString();
    QString last = ui->tableView->model()->data(ui->tableView->model()->index(i,1)).toString();
    QString datebirthday = ui->tableView->model()->data(ui->tableView->model()->index(i,2)).toString();
    QString addresss = ui->tableView->model()->data(ui->tableView->model()->index(i,3)).toString();
    QString email = ui->tableView->model()->data(ui->tableView->model()->index(i,4)).toString();
    QString phone = ui->tableView->model()->data(ui->tableView->model()->index(i,5)).toString();
    QString analyze = ui->tableView->model()->data(ui->tableView->model()->index(i,6)).toString();
    QString date =ui->tableView->model()->data(ui->tableView->model()->index(i,7)).toString();
    i++;

    QPainter painter;
    painter.begin(&printer);
    QModelIndex index;
    int rows = model->rowCount(index);
    int columns = model->columnCount(index);
    double xscale = printer.pageRect().width();

    double yscale = printer.pageRect().height();
    double scale = qMin(xscale, yscale);
    QRect required = QRect();
    QRect r = QRect(100, 100, scale, yscale);
    painter.drawRect(r);//
    painter.drawText(r, Qt::TextWordWrap, name +",   "+ last +",   "+ datebirthday + ",   " + addresss + ",   " + email + ",   " + phone + ",   " + analyze + ",   " + date);
    QModelIndex parent = QModelIndex();
    painter.save();
   QStyleOptionViewItem option;


   const int ItemSize = 250;
    float x = ItemSize /2;
    for (int printRow = 0; printRow < rows; ++printRow) {
    float y = ItemSize /250;
    for (int column = 0; column < columns; ++column) {
    option.rect = QRect(int(x), int(y), ItemSize, ItemSize);
    ui->tableView->itemDelegate()->paint(&painter, option, model->index(printRow, column, parent));
    x = x + 250;
    }
    y = y + 250;
    }

     painter.restore();
     painter.end();
    QMessageBox::information(this,"ინფორმაცია", line + " ფაილი შეიქმნა PDF-ფორმატში");
    }
    else{ QMessageBox::warning(this,"შეცდომა", "ფაილი არ შექმნილა");
    }
}

#include "dialogcalendar.h"
#include "ui_dialogcalendar.h"
#include <QTextCharFormat>
#include <QMessageBox>

#include <QStringList>

DialogCalendar::DialogCalendar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogCalendar)
{
    ui->setupUi(this);

}

DialogCalendar::~DialogCalendar()
{
    delete ui;
}
void DialogCalendar::setArray(QList<Persons> people){

    QTextCharFormat text;
    text.setBackground(Qt::red);
    for(int i=0; i<people.size(); i++){
        QStringList list =  people.at(i).datebirthday.split("/");
ui->calendarWidget->setDateTextFormat(QDate(QDate::currentDate().year(),list.at(1).toInt(),list.at(0).toInt()),text);
    }

}



#include "dialogemail.h"
#include "ui_dialogemail.h"
#include <QtWebKit>
#include <QtCore>

DialogEmail::DialogEmail(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogEmail)
{
    ui->setupUi(this);
    //ui->webView->load(QUrl("https://e.mail.ru/compose/"));

}

DialogEmail::~DialogEmail()
{
    delete ui;
}

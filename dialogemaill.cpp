#include "dialogemaill.h"
#include "ui_dialogemaill.h"
#include <QtWebKit>
#include <QtGui>
#include <QtCore>ialogemaill::Dialogemaill(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialogemaill)
{
    ui->setupUi(this);
    ui->webView->setUrl(QUrl("https://vk.com"));
}

Dialogemaill::~Dialogemaill()
{
    delete ui;
}

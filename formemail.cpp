#include "formemail.h"
#include "ui_formemail.h"

FormEmail::FormEmail(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormEmail)
{
    ui->setupUi(this);
}

FormEmail::~FormEmail()
{
    delete ui;
}

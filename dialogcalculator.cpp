#include "dialogcalculator.h"
#include "ui_dialogcalculator.h"
#include <QtCore>
#include <QtGui>

DialogCalculator::DialogCalculator(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogCalculator)
{
    ui->setupUi(this);
    setWindowTitle("კალკულატორი");
}

DialogCalculator::~DialogCalculator()
{
    delete ui;
}

void DialogCalculator::on_pushButton_clicked()
{
    ui->plainTextEdit->setPlainText(ui->plainTextEdit->toPlainText() + "1");
}


void DialogCalculator::on_pushButton_2_clicked()
{
    ui->plainTextEdit->setPlainText(ui->plainTextEdit->toPlainText()+ "2");
}

void DialogCalculator::on_pushButton_3_clicked()
{
    ui->plainTextEdit->setPlainText(ui->plainTextEdit->toPlainText() + "3");
}

void DialogCalculator::on_pushButton_4_clicked()
{
    ui->plainTextEdit->setPlainText(ui->plainTextEdit->toPlainText() + "4");
}

void DialogCalculator::on_pushButton_5_clicked()
{
    ui->plainTextEdit->setPlainText(ui->plainTextEdit->toPlainText() + "5");
}

void DialogCalculator::on_pushButton_6_clicked()
{
    ui->plainTextEdit->setPlainText(ui->plainTextEdit->toPlainText() + "6");
}

void DialogCalculator::on_pushButton_7_clicked()
{
    ui->plainTextEdit->setPlainText(ui->plainTextEdit->toPlainText() + "7");
}

void DialogCalculator::on_pushButton_8_clicked()
{
    ui->plainTextEdit->setPlainText(ui->plainTextEdit->toPlainText() + "8");
}

void DialogCalculator::on_pushButton_9_clicked()
{
    ui->plainTextEdit->setPlainText(ui->plainTextEdit->toPlainText()  + "9");
}


void DialogCalculator::on_pushButton_14_clicked()
{
    ui->plainTextEdit->setPlainText(ui->plainTextEdit->toPlainText()  + "+");
}


void DialogCalculator::on_pushButton_15_clicked()
{
    ui->plainTextEdit->setPlainText(ui->plainTextEdit->toPlainText() +  "-");
}


void DialogCalculator::on_pushButton_16_clicked()
{
    ui->plainTextEdit->setPlainText(ui->plainTextEdit->toPlainText()  + "*");
}


void DialogCalculator::on_pushButton_17_clicked()
{
    ui->plainTextEdit->setPlainText(ui->plainTextEdit->toPlainText() + "/");
}
void DialogCalculator::on_pushButton_12_clicked()
{
 tempStr = ui->plainTextEdit->toPlainText();

 for(int i=0; i<tempStr.size(); i++){
     if(tempStr [i]=='+')
         op="+";
     else if(tempStr[i]=='-')
         op="-";
     else if(tempStr[i]=='*')
         op="*";
     else if(tempStr[i]=='/')
         op='/';
 }

 if(op=="+"){
     QStringList nums = tempStr.split("+");
     num1=nums[0].toDouble();
     num2=nums[1].toDouble();
     result=num1+num2;
     ui->plainTextEdit->setPlainText(QString::number(result));
 }
 else if(op=="-"){
     QStringList nums =tempStr.split("-");
     num1 =nums[0].toDouble();
     num2=nums[1].toDouble();
     result=num1-num2;
     ui->plainTextEdit->setPlainText(QString::number(result));
 }
 else if(op=="*"){
     QStringList nums = tempStr.split("*");
     num1=nums[0].toDouble();
     num2=nums[1].toDouble();
     result=num1*num2;
     ui->plainTextEdit->setPlainText(QString::number(result));


}

 else if(op=="/"){
     QStringList nums = tempStr.split("/");
     num1=nums[0].toDouble();
     num2=nums[1].toDouble();
     result=num1*num2;
     ui->plainTextEdit->setPlainText(QString::number(result));


}
}

void DialogCalculator::on_pushButton_13_clicked()
{
    result=num1=num2=0;
  ui->plainTextEdit->clear();
}

void DialogCalculator::on_pushButton_10_clicked()
{
    if(ui->plainTextEdit->toPlainText().trimmed().isEmpty()){
        ui->plainTextEdit->setPlainText("0.");
    }
    else{
        ui->plainTextEdit->setPlainText(ui->plainTextEdit->toPlainText()+".");
    }
}

void DialogCalculator::on_pushButton_11_clicked()
{
    if( ui->plainTextEdit->toPlainText()!="0"){
        ui->plainTextEdit->setPlainText(ui->plainTextEdit->toPlainText()+"0");
    }
}

void DialogCalculator::keyPressEvent(QKeyEvent *key)
{

        switch (key->key()) {
            case Qt::Key_Return: on_pushButton_12_clicked();
                break;
            case Qt::Key_0: on_pushButton_11_clicked();
                break;
            case Qt::Key_1: on_pushButton_clicked();
                break;
            case Qt::Key_2: on_pushButton_2_clicked();
                break;
            case Qt::Key_3: on_pushButton_3_clicked();
               break;
            case Qt::Key_4: on_pushButton_4_clicked();
               break;
            case Qt::Key_5: on_pushButton_5_clicked();
               break;
            case Qt::Key_6: on_pushButton_6_clicked();
               break;
            case Qt::Key_7: on_pushButton_7_clicked();
                break;
            case Qt::Key_8: on_pushButton_8_clicked();
                break;
            case Qt::Key_9: on_pushButton_9_clicked();
                break;
            case Qt::Key_Comma: on_pushButton_10_clicked();
                 break;
            case Qt::Key_Plus: on_pushButton_14_clicked();
                 break;
            case Qt::Key_Minus: on_pushButton_15_clicked();
                break;
            case Qt::Key_Slash: on_pushButton_17_clicked();
                break;
            case Qt::Key_Asterisk: on_pushButton_16_clicked();
                break;
            case Qt::Key_Backspace: on_pushButton_13_clicked();
                break;
            default:
                break;
        }
    }







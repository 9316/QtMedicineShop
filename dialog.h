#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <selldialog.h>


namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
    void setLabels(QString name, QString lastname, QString datebirthday, QString address,QString email, QString phone,QString diagnose,QString date,QString imageurl, QString toDay);


    
private slots:




private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H

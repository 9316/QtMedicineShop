#ifndef ADDMED_H
#define ADDMED_H

#include <QDialog>
#include <QMessageBox>

namespace Ui {
class AddMed;
}

class AddMed : public QDialog
{
    Q_OBJECT
    
public:
    explicit AddMed(QWidget *parent = 0);
    ~AddMed();
    QString name,lastname,datebirthday,address,email,phone,diagnose,imageurl;
    
private slots:
  //  void on_pushButton_clicked();

    void on_pushButton_clicked();

   // void on_pushButton_2_clicked();

    //void on_toolButton_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::AddMed *ui;
};

#endif // ADDMED_H

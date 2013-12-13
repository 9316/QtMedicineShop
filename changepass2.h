#ifndef CHANGEPASS2_H
#define CHANGEPASS2_H

#include <QWidget>

namespace Ui {
class ChangePass2;
}

class ChangePass2 : public QWidget
{
    Q_OBJECT
    
public:
    explicit ChangePass2(QWidget *parent = 0);
    ~ChangePass2();
    QString name,pass,newpass;
    
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::ChangePass2 *ui;
};

#endif // CHANGEPASS2_H

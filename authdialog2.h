#ifndef AUTHDIALOG2_H
#define AUTHDIALOG2_H

#include <QWidget>
#include <QtSql>


namespace Ui {
class Authdialog2;
}

class Authdialog2 : public QWidget
{
    Q_OBJECT
    
public:
    explicit Authdialog2(QWidget *parent = 0);
    ~Authdialog2();
    bool auth;
    QSqlDatabase login;
    
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Authdialog2 *ui;
};

#endif // AUTHDIALOG2_H

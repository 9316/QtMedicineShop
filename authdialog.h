#ifndef AUTHDIALOG_H
#define AUTHDIALOG_H

#include <QDialog>
#include <QSql>
#include <QSqlDatabase>

namespace Ui {
class authDialog;
}

class authDialog : public QDialog
{
    Q_OBJECT

public:
    explicit authDialog(QWidget *parent = 0);
    ~authDialog();
    bool auth;
    QSqlDatabase log;


private slots:
    void on_pushButton_clicked();








    void on_pushButton_2_clicked();

private:
    Ui::authDialog *ui;
};

#endif // AUTHDIALOG_H

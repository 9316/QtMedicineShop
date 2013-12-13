#ifndef PASSDIALOG_H
#define PASSDIALOG_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSql>

namespace Ui {
class passDialog;
}

class passDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit passDialog(QWidget *parent = 0);
    ~passDialog();
    bool auth;
    QSqlDatabase login;


    
private slots:
    void on_pushButton_clicked();

private:
    Ui::passDialog *ui;
};

#endif // PASSDIALOG_H

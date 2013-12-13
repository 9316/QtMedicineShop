#ifndef DIALOG2_H
#define DIALOG2_H

#include <QWidget>
#include <QtSql>

namespace Ui {
class Dialog2;
}

class Dialog2 : public QWidget
{
    Q_OBJECT
    
public:
    explicit Dialog2(QWidget *parent = 0);
    ~Dialog2();
    bool auth;
    QSqlDatabase log;
    
private slots:
    void on_pushButton_2_clicked();

private:
    Ui::Dialog2 *ui;
};

#endif // DIALOG2_H

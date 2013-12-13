#ifndef STATISTICDIALOG_H
#define STATISTICDIALOG_H

#include <QDialog>
#include <QDate>

namespace Ui {
class statisticDialog;
}

class statisticDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit statisticDialog(QWidget *parent = 0);
    ~statisticDialog();
    int dateCount;
    
private slots:
    void on_pushButton_clicked();

private:
    Ui::statisticDialog *ui;
};

#endif // STATISTICDIALOG_H

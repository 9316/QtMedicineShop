#ifndef DIALOGCALCULATOR_H
#define DIALOGCALCULATOR_H

#include <QDialog>
#include <QKeyEvent>
#include <QtCore>

namespace Ui {
class DialogCalculator;
}

class DialogCalculator : public QDialog
{
    Q_OBJECT

public:
    explicit DialogCalculator(QWidget *parent = 0);
    ~DialogCalculator();
    double num1,num2,result;
    QString op;
    QString tempStr;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

    void keyPressEvent(QKeyEvent *key);

private:
    Ui::DialogCalculator *ui;
};

#endif // DIALOGCALCULATOR_H

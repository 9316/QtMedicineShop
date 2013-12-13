#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QDebug>
#include <addmed.h>
#include <dialog.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QSqlDatabase db;
    QSqlTableModel *model;
    void noEdit();
    bool showSearchToolbar;
    QString fullDate;
    void calcBirthday();




private slots:
    void on_actionAdd_triggered();



    void on_actionSearch_triggered();

    void on_tableView_doubleClicked(const QModelIndex &index);

    void on_actionAbout_triggered();

 void on_pushButton_clicked();

 void on_pushButton_2_clicked();

 void on_actionDelete_triggered();

 void on_actionRefresh_triggered();

 void on_actionStatics_triggered();

 void on_actionExit_triggered();

 void on_action_triggered();

 void on_pushButton_3_clicked();

 void on_action_2_triggered();

 void on_action_4_triggered();

 void on_action_3_triggered();

 void on_action_5_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

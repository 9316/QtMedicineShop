#ifndef DIALOGCALENDAR_H
#define DIALOGCALENDAR_H

#include <QDialog>
#include <persons.h>

namespace Ui {
class DialogCalendar;
}

class DialogCalendar : public QDialog
{
    Q_OBJECT
    
public:
    explicit DialogCalendar(QWidget *parent = 0);
    ~DialogCalendar();
    void setArray(QList<Persons> );
private:
    Ui::DialogCalendar *ui;
};

#endif // DIALOGCALENDAR_H

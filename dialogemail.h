#ifndef DIALOGEMAIL_H
#define DIALOGEMAIL_H

#include <QDialog>

namespace Ui {
class DialogEmail;
}

class DialogEmail : public QDialog
{
    Q_OBJECT
    
public:
    explicit DialogEmail(QWidget *parent = 0);
    ~DialogEmail();
    
private:
    Ui::DialogEmail *ui;
};

#endif // DIALOGEMAIL_H

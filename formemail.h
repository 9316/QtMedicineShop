#ifndef FORMEMAIL_H
#define FORMEMAIL_H

#include <QWidget>

namespace Ui {
class FormEmail;
}

class FormEmail : public QWidget
{
    Q_OBJECT
    
public:
    explicit FormEmail(QWidget *parent = 0);
    ~FormEmail();
    
private:
    Ui::FormEmail *ui;
};

#endif // FORMEMAIL_H

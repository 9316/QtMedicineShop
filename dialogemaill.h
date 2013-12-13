#ifndef DIALOGEMAILL_H
#define DIALOGEMAILL_H

#include <QDialog>

namespace Ui {
class Dialogemaill;
}

class Dialogemaill : public QDialog
{
    Q_OBJECT
    
public:
    explicit Dialogemaill(QWidget *parent = 0);
    ~Dialogemaill();
    
private:
    Ui::Dialogemaill *ui;
};

#endif // DIALOGEMAILL_H

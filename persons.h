#ifndef PERSONS_H
#define PERSONS_H

#include <QtCore>
#include <QString>

class Persons
{
public:
    Persons(QString name, QString lastname, QString datebirthday);
    QString name,lastname,datebirthday;
};

#endif // PERSONS_H

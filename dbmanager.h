#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QSqlDatabase>
#include <QVariantList>
#include <userdata.h>

class DBManager
{
public:
    DBManager();

    virtual void connectToDataBase() = 0;
    virtual QSqlDatabase getDB() = 0;
};

#endif // DBMANAGER_H


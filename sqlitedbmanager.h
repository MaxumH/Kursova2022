#ifndef DATABASE_H
#define DATABASE_H

#include <QSqlDatabase>
#include <QVariantList>
#include <dbmanager.h>
#include <userdata.h>

#define DATABASE_HOSTNAME   "ExampleDataBase"
#define DATABASE_NAME       "db.db"

#define TABLE_EXAMPLE                                   "users"
#define TABLE_EXAMPLE_LASTNAME                          "last_name"
#define TABLE_EXAMPLE_INCOME                            "income"
#define TABLE_EXAMPLE_NUMBER_OF_REGISTERED              "number_of_registered"
#define TABLE_EXAMPLE_RESIDENTIAL_COMMUNAL_SERVICES     "residential_communal_services"
#define TABLE_EXAMPLE_MANDATORY_PAYMENT                 "mandatory_payment"
#define TABLE_EXAMPLE_SUBSIDY                           "subsidy"


class SqliteDBManager : public DBManager {

public:
    static SqliteDBManager* getInstance();
    void connectToDataBase();
    QSqlDatabase getDB();

private:
    QSqlDatabase db;

private:

    static SqliteDBManager* instance;
    SqliteDBManager();
    bool openDataBase();
    void closeDataBase();
};



#endif // DATABASE_H


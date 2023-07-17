#include "sqlitedbmanager.h"
#include <userdata.h>

#include <QObject>
#include <QSqlQuery>
#include <QSqlError>
#include <QFile>
#include <QDate>
#include <QDebug>


SqliteDBManager::SqliteDBManager()
{

}
SqliteDBManager* SqliteDBManager::instance = nullptr;

SqliteDBManager* SqliteDBManager::getInstance()
{
    if(instance == nullptr){
        instance = new SqliteDBManager();
    }
    return instance;
}
void SqliteDBManager::connectToDataBase()
{

        this->openDataBase();
 }

QSqlDatabase SqliteDBManager::getDB()
{
    return db;
}


bool SqliteDBManager::openDataBase()
{

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("db.db");
    if(db.open()){
        return true;
    } else
        return false;
}


void SqliteDBManager::closeDataBase()
{
    db.close();
}





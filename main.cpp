#include "mainwindow.h"
#include "dbmanager.h"
#include "sqlitedbmanager.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DBManager *db = SqliteDBManager::getInstance();
    MainWindow w;
    w.show();
    return a.exec();
}

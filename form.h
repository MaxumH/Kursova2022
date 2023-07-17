#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include<QSqlTableModel>
#include <QDialog>
#include <dbmanager.h>
#include "sqlitedbmanager.h"
#define TABLE_NAME "users"


QT_BEGIN_NAMESPACE
namespace Ui { class Form; }
QT_END_NAMESPACE
class QSqlTableModel;
class DBManager;

class Form : public QWidget
{
    Q_OBJECT

public:
    ~Form();
    explicit Form(QWidget *parent = nullptr);

private:
    Ui::Form *ui;
    QSqlQuery *query;
    QSqlTableModel *model;
    DBManager *dbmanager;
    int row;

private slots:
    void on_tableView_clicked(const QModelIndex &index);
    void on_addObject_clicked();
    void on_removeObject_clicked();
};
#endif // FORM_H

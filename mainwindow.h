#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include<dbmanager.h>
#include <sqlitedbmanager.h>
#include <form.h>
#define cost_of_living 2294
#define procent 0.15

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include<QSqlTableModel>
#include <QDialog>
#include<QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
class QSqlTableModel;
class DBManager;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_go_to_database_form_clicked();

    void on_Calculation_clicked();

private:
    DBManager *dbmanager;
    Ui::MainWindow *ui;
    Form *form;
    QSqlQuery *query;
    QSqlTableModel *model;

};
#endif // MAINWINDOW_H

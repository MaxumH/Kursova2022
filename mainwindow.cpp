#include "mainwindow.h"
#include <dbmanager.h>
#include <sqlitedbmanager.h>
#include "ui_mainwindow.h"
#include<form.h>
#include <QDebug>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)

{
    ui->setupUi(this);

    dbmanager = SqliteDBManager::getInstance();
    dbmanager->connectToDataBase();
}

MainWindow::~MainWindow()

{
    delete ui;
}


void MainWindow::on_go_to_database_form_clicked()
{
   form=new Form;
   form->show();
}
void MainWindow::on_Calculation_clicked()
{
     QSqlQuery query = QSqlQuery(dbmanager->getDB());

    query.prepare("INSERT INTO " TABLE_NAME " (last_name, income,number_of_registered,residential_communal_services,mandatory_payment,subsidy,street)"
                  "VALUES (?, ?,?,?,?,?,?)");
    QString str1 = ui->LastName->text();
    int str2 = ui->Income->text().toInt();
    int str3 = ui->Number_of_registered->text().toInt();
    int str4 = ui->Residential_communal_services->text().toInt();
    float Mandatory_payment=(((((ui->Income->text().toDouble()/ui->Number_of_registered->text().toDouble())/cost_of_living)/2)*procent)*ui->Income->text().toInt());
    ui->Mandatory_payment->setText(QString::number(Mandatory_payment));
    float subsidy = ui->Residential_communal_services->text().toDouble() - ui->Mandatory_payment->text().toDouble();
    if (subsidy < 0) subsidy = 0;
    ui->Subsidy->setText(QString::number(subsidy));
    QString str5 = ui->street->text();

    query.addBindValue(str1);
    query.addBindValue(str2);
    query.addBindValue(str3);
    query.addBindValue(str4);
    query.addBindValue(Mandatory_payment);
    query.addBindValue(subsidy);
    query.addBindValue(str5);
    if(subsidy>0)
    {

       QMessageBox *message = new QMessageBox(this);
       message->setText("Ви можете звернутися до управлiння соцiального захисту населення\n за мiсцем реєстрації за житловою субсидією у розмірі.\nРозмір вашої субсидії: " + QString::number(subsidy));

       message->show();
    }
    else
    {
        QMessageBox *message = new QMessageBox(this);
        message->setText("Нажаль, виходячи з введених Вами даних, на житлову субсидію Ви права не маєте.\nРозмір вашої субсидії: " + QString::number(subsidy));

        message->show();
    }
    if(!query.exec()){
        qDebug() << query.lastError().text();
        qDebug() << query.lastQuery();
    }
}


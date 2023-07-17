#include "form.h"
#include "ui_form.h"
Form::Form(QWidget *parent)
    :QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
    dbmanager = SqliteDBManager::getInstance();
    dbmanager->connectToDataBase();

       model = new QSqlTableModel(this,dbmanager->getDB());
       model->setTable(TABLE_NAME);
       model->select();
       model->setHeaderData(1,Qt::Horizontal,"Прізвище",Qt::DisplayRole);
       model->setHeaderData(2,Qt::Horizontal,"Загальний заробіток сім'ї ",Qt::DisplayRole);
       model->setHeaderData(3,Qt::Horizontal,"Кількість жильців ",Qt::DisplayRole);
       model->setHeaderData(4,Qt::Horizontal,"Сума місячних нарахувань за послуги ЖКГ ",Qt::DisplayRole);
       model->setHeaderData(5,Qt::Horizontal,"Обов'язковий платіж ",Qt::DisplayRole);
       model->setHeaderData(6,Qt::Horizontal," Субсидія ",Qt::DisplayRole);
       model->setHeaderData(7,Qt::Horizontal," Вулиця ",Qt::DisplayRole);

        ui->tableView->setModel(model);
        ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
        ui->tableView->setColumnHidden(0,true);
        ui->tableView->setSortingEnabled(true);


}

Form::~Form()
{
    delete ui;
}
void Form::on_tableView_clicked(const QModelIndex &index)
{
     row = index.row();
}


void Form::on_addObject_clicked()
{
     model->insertRow(model->rowCount());
}


void Form::on_removeObject_clicked()
{
    model->removeRow(row);
    model->select();
}


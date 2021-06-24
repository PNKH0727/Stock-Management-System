#include "updateitems.h"
#include "ui_updateitems.h"
#include <QMessageBox>

Updateitems::Updateitems(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Updateitems)
{
    ui->setupUi(this);
}

Updateitems::~Updateitems()
{
    delete ui;
}

void Updateitems::on_pushButton_clicked()
{
    //connect to the database

    Login conn;
    QString id,status,sellingprice;

    id=ui->txtId->text();
    status=ui->cmbStatus->currentText();
    sellingprice=ui->txtSellingPrice->text();

    if(!conn.connOpen())
    {
        qDebug()<<"failed to open the database";
        return;
    }

    conn.connOpen();
    QSqlQuery qry;

    //update data of employeeInfoo table

    qry.prepare("update items set Id='"+id+"', Status='"+status+"', SellingPrice='"+sellingprice+"' where Id='"+id+"'");

    if(qry.exec())
    {
        QMessageBox::critical(this,tr("Update"),tr("Data are Updated"));
        conn.connClose();
    }
    else
    {
        QMessageBox::critical(this,tr("error::"),qry.lastError().text());
    }
}


void Updateitems::on_btnload_clicked()
{
    Login conn;
    QSqlQueryModel  * modal = new QSqlQueryModel();
    QSqlQueryModel * tableModel = new QSqlQueryModel();

    conn.connOpen();
    QSqlQuery* qry=new QSqlQuery(conn.mydb);

    //load data of employeeInfoo table

    qry->prepare("select * from items");

    qry->exec();
    modal->setQuery(*qry);
    tableModel->setQuery(*qry);
    ui->tableView->setModel(modal);


    conn.connClose();
    qDebug() <<(modal->rowCount());


}

void Updateitems::on_tableView_activated(const QModelIndex &index)
{
    //double click tableView and display data on QLineEdit

    QString val=ui->tableView->model()->data(index).toString();

    Login conn;
    if(!conn.connOpen()){

        qDebug()<<"Failed to open the database";
    }

    conn.connOpen();
    QSqlQuery qry;
    qry.prepare("select * from items where Id='"+val+"' or Name='"+val+"'");

    if(qry.exec())
    {
        while(qry.next())
        {
            ui->txtId->setText(qry.value(0).toString());


        }
        conn.connClose();
    }
    else
    {
        QMessageBox::critical(this,tr("error::"),qry.lastError().text());
    }
}

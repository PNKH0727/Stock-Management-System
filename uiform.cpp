#include "uiform.h"
#include "ui_uiform.h"
#include "additems.h"
#include "updateitems.h"
#include "firstform.h"
#include "deleteitems.h"


Uiform::Uiform(QWidget *parent) : // Produt details Form but it has Add/Update/Delete buttons
    QDialog(parent),
    ui(new Ui::Uiform)
{
    ui->setupUi(this);
}

Uiform::~Uiform()
{
    delete ui;
}

void Uiform::on_btnAddItem_clicked()
{
    //goto the Add items form (additems.ui)

    Additems additems;
    additems.setModal(true);
    additems.exec();

}

void Uiform::on_btnUpdateItem_clicked()
{
    //goto the Update items form (updateitems.ui)

    Updateitems updateitems;
    updateitems.setModal(true);
    updateitems.exec();



}

void Uiform::on_btnFindItem_clicked()
{
    //connect to the database

    Login conn;

    //click the find items button then show details of product items


    QSqlQueryModel  * modal = new QSqlQueryModel();
    QSqlQueryModel * tableModel = new QSqlQueryModel();

    conn.connOpen();
    QSqlQuery* qry=new QSqlQuery(conn.mydb);

    //Display all details of items tables

    qry->prepare("select * from items");

    qry->exec();
    modal->setQuery(*qry);
    tableModel->setQuery(*qry);
    ui->tableView->setModel(modal);


    conn.connClose();
    qDebug() <<(modal->rowCount());

}


void Uiform::on_btnDeleteItem_clicked()
{
    //goto the Delete items form (deleteitems.ui)

    Deleteitems deleteitems;
    deleteitems.setModal(true);
    deleteitems.exec();
}



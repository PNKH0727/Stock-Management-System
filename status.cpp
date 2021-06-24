#include "status.h"
#include "ui_status.h"
#include <QMessageBox>

Status::Status(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Status)
{
    ui->setupUi(this);
}

Status::~Status()
{
    delete ui;
}

void Status::on_btnAvailable_clicked()
{
    //connect to the database
    Login conn;
    QSqlQueryModel  * modal = new QSqlQueryModel();
    QSqlQueryModel * tableModel = new QSqlQueryModel();

    conn.connOpen();
    QSqlQuery* qry=new QSqlQuery(conn.mydb);

    //Display only available items

    qry->prepare("select * from items where Status='Available'");

    qry->exec();
    modal->setQuery(*qry);
    tableModel->setQuery(*qry);
    ui->tableView->setModel(modal);

    conn.connClose();
    qDebug() <<(modal->rowCount());

}

void Status::on_btnExpired_clicked()
{
    //connect to the database
    Login conn;
    QSqlQueryModel  * modal = new QSqlQueryModel();
    QSqlQueryModel * tableModel = new QSqlQueryModel();

    conn.connOpen();
    QSqlQuery* qry=new QSqlQuery(conn.mydb);

    //Display only Expired items

    qry->prepare("select * from items where Status='Expired'");

    qry->exec();
    modal->setQuery(*qry);
    tableModel->setQuery(*qry);
    ui->tableView->setModel(modal);

    conn.connClose();
    qDebug() <<(modal->rowCount());

}

void Status::on_btnSold_clicked()
{
    //connect to the database
    Login conn;
    QSqlQueryModel  * modal = new QSqlQueryModel();
    QSqlQueryModel * tableModel = new QSqlQueryModel();

    conn.connOpen();
    QSqlQuery* qry=new QSqlQuery(conn.mydb);

    //Display only Sold items

    qry->prepare("select * from items where Status='Sold'");

    qry->exec();
    modal->setQuery(*qry);
    tableModel->setQuery(*qry);
    ui->tableView->setModel(modal);

    conn.connClose();
    qDebug() <<(modal->rowCount());

}

void Status::on_btnReturn_clicked()
{
    //connect to the database
    Login conn;

    QSqlQueryModel  * modal = new QSqlQueryModel();
    QSqlQueryModel * tableModel = new QSqlQueryModel();

    conn.connOpen();
    QSqlQuery* qry=new QSqlQuery(conn.mydb);

    //Display only Return items

    qry->prepare("select * from items where Status='Return'");

    qry->exec();
    modal->setQuery(*qry);
    tableModel->setQuery(*qry);
    ui->tableView->setModel(modal);

    conn.connClose();
    qDebug() <<(modal->rowCount());

}

void Status::on_btnSpoiled_clicked()
{
    //connect to the database
    Login conn;
    QSqlQueryModel  * modal = new QSqlQueryModel();
    QSqlQueryModel * tableModel = new QSqlQueryModel();

    conn.connOpen();
    QSqlQuery* qry=new QSqlQuery(conn.mydb);

    //Display only Spoiled items

    qry->prepare("select * from items where Status='Spoiled'");

    qry->exec();
    modal->setQuery(*qry);
    tableModel->setQuery(*qry);
    ui->tableView->setModel(modal);

    conn.connClose();
    qDebug() <<(modal->rowCount());

}

#include "users.h"
#include "ui_users.h"
#include <QMessageBox>

Users::Users(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Users)
{
    ui->setupUi(this);
}

Users::~Users()
{
    delete ui;
}

void Users::on_btnsave_clicked()
{

    //connect to the database

    Login conn;

    QString eid,name,username,age,password ;

    //extract values from ui

    eid=ui->lineEdit_eid->text();
    name=ui->lineEdit_name->text();
    username=ui->lineEdit_username->text();
    age=ui->lineEdit_age->text();
    password=ui->lineEdit_password->text();


    if(!conn.connOpen())
    {
        qDebug()<<"failed to open the database";
        return;
    }

    conn.connOpen();
    QSqlQuery qry;

    //insert user details to the employeeInfo table


    qry.prepare("insert into employeeInfo (emId,name,username,age,password) values ('"+eid+"', '"+name+"', '"+username+"','"+age+"','"+password+"')");


    if(qry.exec())
    {
        QMessageBox::critical(this,tr("Save"),tr("Data are added"));
        conn.connClose();
    }
    else
    {
        QMessageBox::critical(this,tr("error::"),qry.lastError().text());
    }

}

void Users::on_btnupdate_clicked()
{

    Login conn;

    QString eid,name,username,age,password ;

    eid=ui->lineEdit_eid->text();
    name=ui->lineEdit_name->text();
    username=ui->lineEdit_username->text();
    age=ui->lineEdit_age->text();
    password=ui->lineEdit_password->text();

    if(!conn.connOpen())
    {
        qDebug()<<"failed to open the database";
        return;
    }

    conn.connOpen();
    QSqlQuery qry;

    //update data from employeeInfoo table

    qry.prepare("update employeeInfo set emId='"+eid+"', name='"+name+"', username='"+username+"', age='"+age+"' , password='"+password+"' where emId='"+eid+"'");

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

void Users::on_btndelete_clicked()
{
    Login conn;

    QString eid ;
    eid=ui->lineEdit_eid->text();


    if(!conn.connOpen())
    {
        qDebug()<<"failed to open the database";
        return;
    }

    conn.connOpen();
    QSqlQuery qry;

    //dele user details from employeeinfoo


    qry.prepare("Delete from employeeInfo where emId='"+eid+"'");

    if(qry.exec())
    {
        QMessageBox::critical(this,tr("Delete"),tr("Data are Deleted"));
        conn.connClose();
    }
    else
    {
        QMessageBox::critical(this,tr("error::"),qry.lastError().text());
    }
}

void Users::on_btnload_clicked()
{

    //connect to the database
    Login conn;
    QSqlQueryModel  * modal = new QSqlQueryModel();
    QSqlQueryModel * tableModel = new QSqlQueryModel();

    conn.connOpen();
    QSqlQuery* qry=new QSqlQuery(conn.mydb);

    qry->prepare("select * from employeeInfo");

    qry->exec();
    modal->setQuery(*qry);
    tableModel->setQuery(*qry);

    // click User Details button and display data on tableView


    ui->tableView->setModel(modal);

    conn.connClose();
    qDebug() <<(modal->rowCount());
}

void Users::on_tableView_activated(const QModelIndex &index)
{
    QString val=ui->tableView->model()->data(index).toString();

    Login conn;
    if(!conn.connOpen()){

        qDebug()<<"Failed to open the database";
    }

    conn.connOpen();
    QSqlQuery qry;

    //click emId or name on tableView and display data in QlineEdit


    qry.prepare("select * from employeeInfo where emId='"+val+"' or name='"+val+"'");

    if(qry.exec())
    {
        while(qry.next())
        {
            ui->lineEdit_eid->setText(qry.value(0).toString());
            ui->lineEdit_name->setText(qry.value(1).toString());
            ui->lineEdit_username->setText(qry.value(2).toString());
            ui->lineEdit_age->setText(qry.value(3).toString());
            ui->lineEdit_password->setText(qry.value(4).toString());
        }
        conn.connClose();
    }
    else
    {
        QMessageBox::critical(this,tr("error::"),qry.lastError().text());
    }
}



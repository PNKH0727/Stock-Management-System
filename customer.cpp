#include "customer.h"
#include "ui_customer.h"
#include "QMessageBox"

Customer::Customer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Customer)
{
    ui->setupUi(this);
}

Customer::~Customer()
{
    delete ui;
}

void Customer::on_btnsave_clicked()
{
    //connect to the database
    Login conn;

    QString cid,fname,lname,tel,email ;

    //extract text from ui

    cid=ui->lineEdit_cid->text();
    fname=ui->lineEdit_fname->text();
    lname=ui->lineEdit_lname->text();
    tel=ui->lineEdit_tel->text();
    email=ui->lineEdit_email->text();


    if(!conn.connOpen())
    {
        qDebug()<<"failed to open the database";
        return;
    }

    // database connection open and adding customer details

    conn.connOpen();
    QSqlQuery qry;
    qry.prepare("insert into customer (Id,firstname,lastname,tel,email) values ('"+cid+"', '"+fname+"', '"+lname+"','"+tel+"','"+email+"')");


    if(qry.exec())
    {
        QMessageBox::critical(this,tr("Save"),tr("Data are added"));

        //colse database
        conn.connClose();

        //clear text values
        ui->lineEdit_cid->setText("");
        ui->lineEdit_fname->setText("");
        ui->lineEdit_lname->setText("");
        ui->lineEdit_tel->setText("");
        ui->lineEdit_email->setText("");

    }
    else
    {
        QMessageBox::critical(this,tr("error::"),qry.lastError().text());
    }

}

void Customer::on_btndelete_clicked()
{
    //connect to the database

    Login conn;

    QString cid ;
    cid=ui->lineEdit_cid->text();


    if(!conn.connOpen())
    {
        qDebug()<<"failed to open the database";
        return;
    }

    conn.connOpen();
    QSqlQuery qry;

    //delete cutomer details when enter id number
    //Or double click Id number in tableview and display it on QLineEdit the click button data is deleted


    qry.prepare("Delete from customer where Id='"+cid+"'");

    if(qry.exec())
    {
        QMessageBox::critical(this,tr("Delete"),tr("Data are Deleted"));
        conn.connClose();

        //clear data
        ui->lineEdit_cid->setText("");
        ui->lineEdit_fname->setText("");
        ui->lineEdit_lname->setText("");
        ui->lineEdit_tel->setText("");
        ui->lineEdit_email->setText("");
    }
    else
    {
        QMessageBox::critical(this,tr("error::"),qry.lastError().text());
    }




}

void Customer::on_btnupdate_clicked()
{
    Login conn;

    QString cid,fname,lname,tel,email ;

    cid=ui->lineEdit_cid->text();
    fname=ui->lineEdit_fname->text();
    lname=ui->lineEdit_lname->text();
    tel=ui->lineEdit_tel->text();
    email=ui->lineEdit_email->text();


    if(!conn.connOpen())
    {
        qDebug()<<"failed to open the database";
        return;
    }

    conn.connOpen();
    QSqlQuery qry;

    //update data relevant to the id number
    qry.prepare("update customer set Id='"+cid+"', firstname='"+fname+"', lastname='"+lname+"', tel='"+tel+"' , email='"+email+"' where Id='"+cid+"'");

    if(qry.exec())
    {
        QMessageBox::critical(this,tr("Update"),tr("Data are Updated"));
        //clear values
        ui->lineEdit_cid->setText("");
        ui->lineEdit_fname->setText("");
        ui->lineEdit_lname->setText("");
        ui->lineEdit_tel->setText("");
        ui->lineEdit_email->setText("");
        conn.connClose();

    }
    else
    {
       QMessageBox::critical(this,tr("error::"),qry.lastError().text());
    }

}

void Customer::on_tableView_activated(const QModelIndex &index)
{

    //double click id or firstname column in table

    QString val=ui->tableView->model()->data(index).toString();

    Login conn;
    if(!conn.connOpen()){

        qDebug()<<"Failed to open the database";
    }

    conn.connOpen();
    QSqlQuery qry;
    qry.prepare("select * from customer where Id='"+val+"' or firstname='"+val+"'");

    if(qry.exec())
    {

        // display all details on QlineEdit

        while(qry.next())
        {
            ui->lineEdit_cid->setText(qry.value(0).toString());
            ui->lineEdit_fname->setText(qry.value(1).toString());
            ui->lineEdit_lname->setText(qry.value(2).toString());
            ui->lineEdit_tel->setText(qry.value(3).toString());
            ui->lineEdit_email->setText(qry.value(4).toString());
        }
        conn.connClose();
    }
    else
    {
        QMessageBox::critical(this,tr("error::"),qry.lastError().text());
    }

}

void Customer::on_btnload_clicked()
{
    //connect to the database and click load button display all customer details on tableView

    Login conn;
    QSqlQueryModel  * modal = new QSqlQueryModel();
    QSqlQueryModel * tableModel = new QSqlQueryModel();

    conn.connOpen();
    QSqlQuery* qry=new QSqlQuery(conn.mydb);

    //select database from customer table on database(sbs.db)

    qry->prepare("select * from customer");

    qry->exec();
    modal->setQuery(*qry);
    tableModel->setQuery(*qry);
    ui->tableView->setModel(modal);

    conn.connClose();
    qDebug() <<(modal->rowCount());

}

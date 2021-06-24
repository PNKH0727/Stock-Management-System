#include "registernew.h"
#include "ui_registernew.h"
#include "firstform.h"
#include <QMessageBox>

Registernew::Registernew(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Registernew)
{
    ui->setupUi(this);
}

Registernew::~Registernew()
{
    delete ui;
}



void Registernew::on_btnregister_clicked()
{
    //Connect to database and register users
    Login conn;

    //extract text from ui
    QString eid,name,username,age,password ;
    eid=ui->lineEdit_eid->text();
    name=ui->lineEdit_name->text();
    username=ui->lineEdit_username->text();
    age=ui->lineEdit_age->text();
    password=ui->lineEdit_password->text();


    //check database open/ close
    if(!conn.connOpen())
    {
        qDebug()<<"failed to open the database";
        return;
    }

    //open database and store data to database

    conn.connOpen();
    QSqlQuery qry;
    qry.prepare("insert into employeeInfo (emId,name,username,age,password) values ('"+eid+"', '"+name+"', '"+username+"', '"+age+"', '"+password+"')");

    //If the data is stored in the database, the message box shows that the data is being saved
    if(qry.exec())
    {
        QMessageBox::critical(this,tr("Save"),tr("Welcome! Registered as new member"));

        //hide register form and invole stock Management system

        this->hide();
        Firstform firstform;
        firstform.setModal(true);
        firstform.exec();
        conn.connClose();
    }

    //Error message
    else
    {
        QMessageBox::critical(this,tr("error::"),qry.lastError().text());
    }
}

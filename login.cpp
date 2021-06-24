#include "login.h"
#include "ui_login.h"
#include "registernew.h"
#include "firstform.h"



Login::Login(QWidget *parent)
    : QMainWindow(parent) //Main window
    , ui(new Ui::Login)
{
    ui->setupUi(this);

}

Login::~Login()
{
    delete ui;
}


void Login::on_btnLogin_clicked()
{

    //Connect to database and login as a user

    //extract text from ui

    QString username , password ;
    username=ui->lineEdit_Username->text();
    password=ui->lineEdit_Password->text();

    //Check database open/close

    if(!connOpen())
    {
        qDebug()<<"failed to open the database";
        return;
    }

    // check password and username from employeInfoo table

    connOpen();
    QSqlQuery qry;
    qry.prepare("select * from employeeInfo where username='"+username+"'and password='"+password+"'");


    if(qry.exec())
    {
        int count=0;
        while(qry.next())
        {
            count++;
        }

        //username and password , both are correct
        if(count==1){
            ui->label->setText("Username and password is correct");

            //close database
            connClose();

            //hide login form and move to Stock management system
            this->hide();
            Firstform firstform;
            firstform.setModal(true);
            firstform.exec();

        }
        //duplicate username and paasword are entering
        if(count>1){
            ui->label->setText("duplicate username and password");}

        //username and password are not correct
        if(count<1){
            ui->label->setText("Username and password is not correct");}
    }





}

void Login::on_btnRegister_clicked()
{
    // hide login form and go to Register form (registernew.ui)
    this->hide();
    Registernew registernew;
    registernew.setModal(true);
    registernew.exec();

}

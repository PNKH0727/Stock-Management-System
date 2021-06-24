#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>

#include "registernew.h"
#include "uiform.h"


namespace Ui {
class Login;
}

class Login : public QMainWindow
{
    Q_OBJECT
public:
    QSqlDatabase mydb;

    //close the database

    void connClose()
    {
        mydb.close();
        mydb.removeDatabase(QSqlDatabase::defaultConnection);
    }

    //check if the database is connected or not

    bool connOpen()
    {
        mydb=QSqlDatabase::addDatabase("QSQLITE");
        mydb.setDatabaseName("E:/3rd Year/1st sem/C++/Stock_Management_System/SMS/sbs.db");

        if(!mydb.open())
        {
            qDebug()<<("Failed to open the database");
            return false;
        }
        else{
            qDebug()<<("Connected..");
            return true ;
        }
    }
public:
    explicit Login(QWidget *parent = 0);
    ~Login();

private slots:
    void on_btnLogin_clicked();

    void on_btnRegister_clicked();

private:
    Ui::Login *ui;

};
#endif // LOGIN_H

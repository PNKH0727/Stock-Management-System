#include "additems.h"
#include "ui_additems.h"
#include <QMessageBox>

Additems::Additems(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Additems)
{
    ui->setupUi(this);
}

Additems::~Additems()
{
    delete ui;
}

void Additems::on_btnAdd_clicked()
{
    //connect to the database
    Login conn;

    QString id,name,quantity,status,dop,dos,sellingprice,purchaseprice ;

    //extract values from ui
    id = ui->txtId->text();
    name = ui->txtName->text();
    quantity = ui->txtQuantity->text();
    status= ui->cmbStatus->currentText();
    dop = ui->txtDOP->text();
    dos = ui->txtDOS->text();
    sellingprice = ui->txtSellingPrice->text();
    purchaseprice = ui->txtPurchasePrice->text();


    //check if there is table
    if(!conn.connOpen())
    {
        qDebug()<<"failed to open the database";
        return;
    }

    conn.connOpen();
    QSqlQuery qry;

    //add items to the items table


    qry.prepare("insert into items (Id,Name, Quantity, Status, DOP, DOS, SellingPrice, PurchasePrice) values ('"+id+"','"+name+"', '"+quantity+"', '"+status+"', '"+dop+"', '"+dos+"', '"+sellingprice+"', '"+purchaseprice+"')");


    if(qry.exec())
    {
        QMessageBox::critical(this,tr("Added Item"),tr("Data are added"));
        conn.connClose();

        //clear values

        ui->txtId->setText("");
        ui->txtName->setText("");
        ui->txtQuantity->setText("");
        ui->txtDOP->setText("");
        ui->txtDOS->setText("");
        ui->txtSellingPrice->setText("");
        ui->txtPurchasePrice->setText("");


    }
    else
    {
        QMessageBox::critical(this,tr("error::"),qry.lastError().text());
    }
}



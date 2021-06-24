#include "deleteitems.h"
#include "ui_deleteitems.h"
#include <QMessageBox>

Deleteitems::Deleteitems(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Deleteitems)
{
    ui->setupUi(this);

}

Deleteitems::~Deleteitems()
{
    delete ui;
}

void Deleteitems::on_btndelete_clicked()
{
    //connect to the database
    Login conn;

    //extract text from ui or data come from tableView

    QString eid ;
    eid=ui->lineEdit_eid->text();


    if(!conn.connOpen())
    {
        qDebug()<<"failed to open the database";
        return;
    }

    conn.connOpen();
    QSqlQuery qry;

    //select relevent data and delete data column

    qry.prepare("Delete from items where Id='"+eid+"'");

    if(qry.exec())
    {
        ui->lineEdit_eid->setText("");
        QMessageBox::critical(this,tr("Delete"),tr("Data are Deleted"));
        conn.connClose();


    }
    else
    {
        QMessageBox::critical(this,tr("error::"),qry.lastError().text());
    }
}

void Deleteitems::on_btnFind_clicked()
{
    //connect to the database
    Login conn;

    //extract text from ui
    QString sValue = ui->txtValue->text();

    // select relevent redio button and chack thata data then review that data on table
    // Or select relevant redio button and enter data value into QLineEdit then show whole data column

    QString sCriteriaColum = "";

    if(ui->rdoId->isChecked())
        sCriteriaColum="Id";
    else if (ui->rdoName->isChecked())
        sCriteriaColum="Name";
    else if (ui->rdoQuantity->isChecked())
        sCriteriaColum="Quantity";
    else if (ui->rdoSellingPrice->isChecked())
        sCriteriaColum = "SellingPrice";
    else
        sCriteriaColum = "Name";
     QSqlQueryModel  * modal = new QSqlQueryModel();
     QSqlQueryModel * tableModel = new QSqlQueryModel();


     conn.connOpen();
     QSqlQuery* qry=new QSqlQuery(conn.mydb);

     //search that data from database and display on table

     qry->prepare("select * from items where " +sCriteriaColum+" like '%" + sValue + "%' ");

     qry->exec();
     modal->setQuery(*qry);
     tableModel->setQuery(*qry);
     ui->tableView->setModel(modal);

     conn.connClose();

     //clear data
     ui->txtValue->setText("");
     qDebug() <<(modal->rowCount());


}

void Deleteitems::on_tableView_activated(const QModelIndex &index)
{
    // double click relevat id number of data and show QlineEdit


    QString val=ui->tableView->model()->data(index).toString();

    Login conn;
    if(!conn.connOpen()){

        qDebug()<<"Failed to open the database";
    }

    conn.connOpen();
    QSqlQuery qry;
    qry.prepare("select * from items where Id='"+val+"'");

    if(qry.exec())
    {
        while(qry.next())
        {
            //disply data on QLineEdit

            ui->lineEdit_eid->setText(qry.value(0).toString());

        }
        conn.connClose();
    }
    else
    {
        QMessageBox::critical(this,tr("error::"),qry.lastError().text());
    }

}

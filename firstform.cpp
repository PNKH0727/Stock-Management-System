#include "firstform.h"
#include "ui_firstform.h"
#include "uiform.h"
#include "users.h"
#include "customer.h"
#include "status.h"

Firstform::Firstform(QWidget *parent) : // Main Ui form of Stock Management System
    QDialog(parent),
    ui(new Ui::Firstform)
{
    ui->setupUi(this);
}

Firstform::~Firstform()
{
    delete ui;
}

void Firstform::on_btnProduct_clicked()
{
    // goto the Product Details form (uiform.ui) and it has add/update/delete buttons and display already product items details

    Uiform uiform;
    uiform.setModal(true);
    uiform.exec();

}


void Firstform::on_btnUsers_clicked()
{
    //goto the users details form (users.ui) and It has add/update/delete buttons and display already users details

    Users users;
    users.setModal(true);
    users.exec();
}

void Firstform::on_btnCustomer_clicked()
{
    //goto the customer details form (customer.ui) and It also has add/update/delete buttons and display already customer details

    Customer customer;
    customer.setModal(true);
    customer.exec();

}

void Firstform::on_btnStaus_clicked()
{
    //goto the items status form (status.ui) and can see separately statues of items
    Status status;
    status.setModal(true);
    status.exec();
}

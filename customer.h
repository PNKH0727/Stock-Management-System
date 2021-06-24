#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <QDialog>
#include "login.h"

namespace Ui {
class Customer;
}

class Customer : public QDialog
{
    Q_OBJECT

public:
    explicit Customer(QWidget *parent = nullptr);
    ~Customer();

private slots:
    void on_btnsave_clicked();

    void on_btndelete_clicked();

    void on_btnupdate_clicked();

    void on_tableView_activated(const QModelIndex &index);

    void on_btnload_clicked();

private:
    Ui::Customer *ui;
};

#endif // CUSTOMER_H

#ifndef FIRSTFORM_H
#define FIRSTFORM_H

#include <QDialog>
#include "login.h"
#include "additems.h"


namespace Ui {
class Firstform;
}

class Firstform : public QDialog
{
    Q_OBJECT

public:
    explicit Firstform(QWidget *parent = nullptr);
    ~Firstform();

private slots:
    void on_btnProduct_clicked();

    //void on_btnCategory_clicked();

    void on_btnUsers_clicked();

    void on_btnCustomer_clicked();

    void on_btnStaus_clicked();

private:
    Ui::Firstform *ui;
};

#endif // FIRSTFORM_H

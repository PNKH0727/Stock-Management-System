#ifndef ADDITEMS_H
#define ADDITEMS_H

#include <QDialog>
#include "login.h"

namespace Ui {
class Additems;
}

class Additems : public QDialog
{
    Q_OBJECT

public:
    explicit Additems(QWidget *parent = nullptr);
    ~Additems();

private slots:
    void on_btnAdd_clicked();

    //void on_btnClear_clicked();

private:
    Ui::Additems *ui;
};

#endif // ADDITEMS_H

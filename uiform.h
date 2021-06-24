#ifndef UIFORM_H
#define UIFORM_H

#include <QDialog>
#include "login.h"
#include "additems.h"

namespace Ui {
class Uiform;
}

class Uiform : public QDialog
{
    Q_OBJECT

public:
    explicit Uiform(QWidget *parent = nullptr);
    ~Uiform();

private slots:
    void on_btnAddItem_clicked();

    void on_btnUpdateItem_clicked();

    void on_btnFindItem_clicked();

    //void on_btnExpiredItems_clicked();

    //void on_btnAvailableItems_clicked();

    void on_btnDeleteItem_clicked();

    //void on_btnReport_clicked();

private:
    Ui::Uiform *ui;
    //Additems *additems;

};

#endif // UIFORM_H

#ifndef DELETEITEMS_H
#define DELETEITEMS_H

#include <QDialog>
#include "login.h"

namespace Ui {
class Deleteitems;
}

class Deleteitems : public QDialog
{
    Q_OBJECT

public:
    explicit Deleteitems(QWidget *parent = nullptr);
    ~Deleteitems();

private slots:
    void on_btndelete_clicked();

    void on_btnFind_clicked();

    void on_tableView_activated(const QModelIndex &index);

private:
    Ui::Deleteitems *ui;
};

#endif // DELETEITEMS_H

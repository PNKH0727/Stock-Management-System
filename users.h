#ifndef USERS_H
#define USERS_H

#include <QDialog>
#include "login.h"

namespace Ui {
class Users;
}

class Users : public QDialog
{
    Q_OBJECT

public:
    explicit Users(QWidget *parent = nullptr);
    ~Users();

private slots:
    void on_btnsave_clicked();

    void on_btnupdate_clicked();

    void on_btndelete_clicked();

    void on_btnload_clicked();

    void on_tableView_activated(const QModelIndex &index);

    //void on_comboBox_currentIndexChanged(const QString &arg1);

private:
    Ui::Users *ui;
};

#endif // USERS_H

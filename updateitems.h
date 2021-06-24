#ifndef UPDATEITEMS_H
#define UPDATEITEMS_H

#include <QDialog>
#include "login.h"

namespace Ui {
class Updateitems;
}

class Updateitems : public QDialog
{
    Q_OBJECT

public:
    explicit Updateitems(QWidget *parent = nullptr);
    ~Updateitems();

private slots:
    void on_pushButton_clicked();

    void on_tableView_activated(const QModelIndex &index);

    void on_btnload_clicked();

private:
    Ui::Updateitems *ui;
};

#endif // UPDATEITEMS_H

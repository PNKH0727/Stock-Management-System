#ifndef STATUS_H
#define STATUS_H

#include <QDialog>
#include "login.h"

namespace Ui {
class Status;
}

class Status : public QDialog
{
    Q_OBJECT

public:
    explicit Status(QWidget *parent = nullptr);
    ~Status();

private slots:
    void on_btnAvailable_clicked();

    void on_btnExpired_clicked();

    void on_btnSold_clicked();

    void on_btnReturn_clicked();

    void on_btnSpoiled_clicked();

private:
    Ui::Status *ui;
};

#endif // STATUS_H

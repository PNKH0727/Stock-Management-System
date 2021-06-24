#ifndef REGISTERNEW_H
#define REGISTERNEW_H

#include <QDialog>
#include "firstform.h"

namespace Ui {
class Registernew;
}

class Registernew : public QDialog
{
    Q_OBJECT

public:
    explicit Registernew(QWidget *parent = nullptr);
    ~Registernew();

private slots:
    void on_btnregister_clicked();

private:
    Ui::Registernew *ui;
};

#endif // REGISTERNEW_H

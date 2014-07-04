#include "errorvaldialog.h"
#include "ui_errorvaldialog.h"

ErrorValDialog::ErrorValDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ErrorValDialog)
{
    ui->setupUi(this);
}

ErrorValDialog::~ErrorValDialog()
{
    delete ui;
}

void ErrorValDialog::on_pushButton_clicked()
{
    this->close();
}

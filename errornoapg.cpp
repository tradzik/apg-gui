#include "errornoapg.h"
#include "ui_errornoapg.h"
#include "cstdlib"
ErrorNoApg::ErrorNoApg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ErrorNoApg)
{
    ui->setupUi(this);

}

ErrorNoApg::~ErrorNoApg()
{
    delete ui;
}

void ErrorNoApg::on_pushButton_clicked()
{
    std::exit(0);
}

void ErrorNoApg::on_ErrorNoApg_destroyed()
{
    ui->label->setText("Destroying...");
    std::exit(0);
}

#ifndef ERRORNOAPG_H
#define ERRORNOAPG_H

#include <QDialog>

namespace Ui {
class ErrorNoApg;
}

class ErrorNoApg : public QDialog
{
    Q_OBJECT

public:
    explicit ErrorNoApg(QWidget *parent = 0);
    ~ErrorNoApg();

private slots:
    void on_pushButton_clicked();

    void on_ErrorNoApg_destroyed();

private:
    Ui::ErrorNoApg *ui;
};

#endif // ERRORNOAPG_H

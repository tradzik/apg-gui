#ifndef ERRORVALDIALOG_H
#define ERRORVALDIALOG_H

#include <QDialog>

namespace Ui {
class ErrorValDialog;
}

class ErrorValDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ErrorValDialog(QWidget *parent = 0);
    ~ErrorValDialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::ErrorValDialog *ui;
};

#endif // ERRORVALDIALOG_H

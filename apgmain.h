#ifndef APGMAIN_H
#define APGMAIN_H

#include <QMainWindow>

namespace Ui {
class APGMain;
}

class APGMain : public QMainWindow
{
    Q_OBJECT

public:
    explicit APGMain(QWidget *parent = 0);
    ~APGMain();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_comboBox_currentIndexChanged(const QString &arg1);

private:
    Ui::APGMain *ui;
};

#endif // APGMAIN_H

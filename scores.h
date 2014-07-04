#ifndef SCORES_H
#define SCORES_H

#include <QDialog>
#include "iostream"
#include "string"
namespace Ui {
class Scores;
}

class Scores : public QDialog
{
    Q_OBJECT

public:
    explicit Scores(QWidget *parent = 0, int nk=1, int mk=8, int xk=8, int ak=0, QString modesk = "", QString excludek ="", QString saltk = "");
    ~Scores();
    std::string exec(char* cmd);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Scores *ui;
};

#endif // SCORES_H

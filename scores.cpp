#include "scores.h"
#include "cstdio"
#include "ui_scores.h"
#include "cstdlib"
#include "iostream"
#include "string"
int n,m,sx,a;
QString mode, exclude, salt;


std::string Scores::exec(char* cmd) {
    FILE* pipe = popen(cmd, "r");
    if (!pipe) return "ERROR";
    char buffer[128];
    std::string result = "";
    while(!feof(pipe)) {
        if(fgets(buffer, 128, pipe) != NULL)
            result += buffer;
    }
    pclose(pipe);
    return result;
}


Scores::Scores(QWidget *parent, int nk, int mk, int xk, int ak, QString modesk, QString excludek, QString saltk) :
    QDialog(parent),
    ui(new Ui::Scores)
{
    ui->setupUi(this);
    ui->progressBar->setValue(5);
    n = nk;
    m = mk;
    a = ak;
    mode = modesk;
    sx = xk;
    exclude = excludek;
    salt = saltk;
    ui->progressBar->setValue(15);
    std::string wyniki = std::string("apg -q -n ") + std::to_string(n) + " -m " + std::to_string(m) + " -x " + std::to_string(sx) + " -a " + std::to_string(a);
    if(exclude != "") wyniki+=" -E " + exclude.toStdString();
    if(a==1)wyniki += " -M " + mode.toStdString();
    if(salt!="") wyniki += " -c " + salt.toStdString();
    char *cstr = new char[wyniki.length() + 1];
    strcpy(cstr, wyniki.c_str());
    ui->progressBar->setValue(25);
    std::string result = exec(cstr);
    ui->progressBar->setValue(100);
    ui->plainTextEdit->setPlainText(QString::fromStdString(result));
}

Scores::~Scores()
{
    delete ui;
}

void Scores::on_pushButton_clicked()
{
    this->close();
}

void Scores::on_pushButton_2_clicked()
{
    std::string wyniki = std::string("apg -q -n ") + std::to_string(n) + " -m " + std::to_string(m) + " -x " + std::to_string(sx) + " -a " + std::to_string(a);
    if(exclude != "") wyniki+=" -E " + exclude.toStdString();
    if(a==1)wyniki += " -M " + mode.toStdString();
    if(salt!="") wyniki += " -c " + salt.toStdString();
    char *cstr = new char[wyniki.length() + 1];
    strcpy(cstr, wyniki.c_str());
    std::string result = exec(cstr);
    ui->plainTextEdit->setPlainText(QString::fromStdString(result));
}

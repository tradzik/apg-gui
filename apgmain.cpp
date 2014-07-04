#include "apgmain.h"
#include "ui_apgmain.h"
#include "stdlib.h"
#include "QRegExp"
#include "errornoapg.h"
#include "errorvaldialog.h"
#include "iostream"
#include "string"
#include "scores.h"
#include "cstdio"


APGMain::APGMain(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::APGMain)
{
    ui->setupUi(this);
    setWindowFlags(Qt::WindowStaysOnTopHint);
        FILE *file;
        if (file = fopen("/usr/bin/apg", "r"))
        {
            fclose(file);

        }
        else
        {
            ErrorNoApg *errnao = new ErrorNoApg(this);
            ui->pushButton_2->setEnabled(false);
            errnao->show();
        }


    ui->lineEdit->setMaxLength(3);
    ui->lineEdit_2->setMaxLength(3);
    ui->lineEdit_3->setMaxLength(2);
    ui->lineEdit_5->setMaxLength(16);
    ui->comboBox_2->setEnabled(false);
    ui->comboBox_3->setEnabled(false);
    ui->comboBox_4->setEnabled(false);
    ui->comboBox_5->setEnabled(false);
}

APGMain::~APGMain()
{
    delete ui;
}

void APGMain::on_pushButton_clicked()
{
    //Exit-button
    std::exit(0);
}

void APGMain::on_pushButton_2_clicked()
{
    //Generate-button
    bool temp = true;
    QString tempStr = ui->lineEdit->text();
    int minlength = tempStr.toInt(&temp);
    if(temp&&minlength>0&&minlength<129)
    {
        tempStr = ui->lineEdit_2->text();
        int maxlength = tempStr.toInt(&temp);
        if(temp&&maxlength>0&&maxlength<129)
        {
            tempStr = ui->lineEdit_3->text();
            int amount = tempStr.toInt(&temp);
            if(temp&&amount>0&&amount<65)
            {
                int mode = 0;
                QString salt,ex;
                if(ui->comboBox->currentText() == "random password generation (more secure)") mode = 1;
                if(ui->lineEdit_5->text()=="")  salt = "";
                else salt = ui->lineEdit_5->text();
                if(ui->lineEdit_4->text()=="") ex = "";
                else ex = ui->lineEdit_4->text();
                QString modes = "";
                if(mode==1)
                {
                    if(ui->comboBox_2->currentText() == "must") modes.append("S");
                    if(ui->comboBox_2->currentText() == "should") modes.append("s");
                    if(ui->comboBox_3->currentText() == "must") modes.append("N");
                    if(ui->comboBox_3->currentText() == "should") modes.append("n");
                    if(ui->comboBox_4->currentText() == "must") modes.append("C");
                    if(ui->comboBox_4->currentText() == "should") modes.append("c");
                    if(ui->comboBox_5->currentText() == "must") modes.append("L");
                    if(ui->comboBox_5->currentText() == "should") modes.append("l");
                    if(modes == "") modes = "sncl";
                }
                Scores *scrs = new Scores(this, amount, minlength, maxlength, mode, modes, ex, salt);
                scrs->show();
            }
            else
            {
                ErrorValDialog* errorval = new ErrorValDialog(this);
                errorval->show();
                return;
            }
        }
        else
        {
            ErrorValDialog* errorval = new ErrorValDialog(this);
            errorval->show();
            return;
        }
    }
    else
    {
        ErrorValDialog* errorval = new ErrorValDialog(this);
        errorval->show();
        return;
    }
}

void APGMain::on_comboBox_currentIndexChanged(const QString &arg1)
{
    if(arg1 == "random password generation (more secure)")
    {
        ui->comboBox_2->setEnabled(true);
        ui->comboBox_3->setEnabled(true);
        ui->comboBox_4->setEnabled(true);
        ui->comboBox_5->setEnabled(true);
    }

    else
    {
        ui->comboBox_2->setEnabled(false);
        ui->comboBox_3->setEnabled(false);
        ui->comboBox_4->setEnabled(false);
        ui->comboBox_5->setEnabled(false);
    }

}

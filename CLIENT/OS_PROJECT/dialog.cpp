#include "dialog.h"
#include "ui_dialog.h"

#define N 3 //кількість допустимих матюків

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
    std::ofstream out;
    out.open("users_list.txt",std::ios_base::app);
    std::string login = ui->textEdit->toPlainText().toStdString();
    std::string password = ui->textEdit_2->toPlainText().toStdString();
    out<<login<<" "<<password<<" "<<N<<'\n';
    QMessageBox msg;
    msg.setText("Successfully !");
    msg.exec();

    _sleep(1500);
    this->close();

}

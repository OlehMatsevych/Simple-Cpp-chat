#include "mainwindow.h"
#include "ui_mainwindow.h"

const quint16 PORT = 3000;
#define  IP   "127.0.0.1"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    ui->stackedWidget->setCurrentIndex(1);
    mSocket = new QTcpSocket(this);
    connect(mSocket, &QTcpSocket::readyRead, [&]()
    {
        QTextStream T(mSocket);
        auto text = T.readAll();
        QString A = ui->label->text();
        ui->label->setText(A+'\n'+text);
    });
}

void MainWindow::on_pushButton_clicked()        //надсилаання
{
    QTextStream T(mSocket);
    T<<ui->lineEdit_2->text()<<": "<<ui->lineEdit->text();
    mSocket->flush();
    ui->lineEdit->clear();
}

void MainWindow::on_pushButton_2_clicked()      // підключення
{
    std::ifstream users;
    users.open("users_list.txt");
    std::string Users ;

    std::string login = ui->lineEdit_2->text().toStdString();
    std::string password = ui->lineEdit_3->text().toStdString();

    if (users.is_open())
    {
        while (getline(users, Users))
        {}
    }

    if(Users.find((login+" "+password))!= std::string::npos)
    {
        QMessageBox msg;
        msg.setText("Successfully !");
        msg.exec();
    }
    else
    {
        Dialog A;
        A.exec();

    }

    ui->stackedWidget->setCurrentIndex(0);
    mSocket->connectToHost
            ("192.168.0.104", PORT);
}

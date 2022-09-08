#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->login_username->setPlaceholderText("Username");
    ui->login_password->setPlaceholderText("Password");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_2_clicked()
{
    ui->StackedWidget->setCurrentIndex(0);
}


void MainWindow::on_pushButton_3_clicked()
{
    ui->StackedWidget->setCurrentIndex(1);
}


void MainWindow::on_pushButton_4_clicked()
{
    ui->StackedWidget->setCurrentIndex(2);
}


#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName("db.bit.io");
    db.setDatabaseName("ToxicJuice23/Messager");
    db.setUserName("ToxicJuice23");
    db.setPassword("v2_3tyfT_Mesyw2r6NcdEmTuijS5Vpvj");
    db.open();
    database = QSqlDatabase::database("Messager");
    ui->setupUi(this);
    ui->login_username->setPlaceholderText("Nom d'utilisateur");
    ui->login_password->setPlaceholderText("Mot de passe");
    ui->register_username->setPlaceholderText("Nom d'utilisateur");
    ui->register_password->setPlaceholderText("Mot de passe");
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
    if (logged_in) {
        ui->StackedWidget->setCurrentIndex(2);
    } else {
        QMessageBox error_message;
        error_message.critical(0, "Erreurr", "S.V.P. se connecter avant d'accéder la page d'acceuil.");
        error_message.setFixedSize(500, 200);
    }
}


void MainWindow::on_login_submit_clicked()
{
    string username = ui->login_username->text().toStdString();
    string password = ui->login_password->text().toStdString();
    QSqlQuery user;
    user.exec(("SELECT * FROM users WHERE username = '" + username + "'").c_str());
    while(user.next()) {
        string db_username = user.value(0).toString().toStdString();
        string db_password = user.value(1).toString().toStdString();
        if (username == db_username && password == db_password) {
            ui->StackedWidget->setCurrentIndex(2);
            logged_in = true;
            break;
        }
    }
    QMessageBox error_message;
    error_message.critical(0, "Erreurr", "Le nom d'utilisateur ou le mot de passe est incorrect.");
    error_message.setFixedSize(500, 200);
}


void MainWindow::on_pushButton_clicked()
{
    string username = ui->register_username->text().toStdString();
    string password = ui->register_password->text().toStdString();
    if (username.length() < 8) {
        QMessageBox error_message;
        error_message.critical(0, "Erreurr", "Le nom d'utilisateur doit être plus long que 8 charactères.");
        error_message.setFixedSize(500, 200);
        return;
    } else if (password.length() < 6) {
        QMessageBox error_message;
        error_message.critical(0, "Erreurr", "Le mot de passe doit être plus long que 6 charactères.");
        error_message.setFixedSize(500, 200);
        return;
    }
    QSqlQuery user;
    user.exec(("INSERT INTO users (username, password, messager_password) VALUES('" + username + "', '" + password + "'," + to_string(0) + ")").c_str());
    database.commit();
    logged_in = true;
    ui->StackedWidget->setCurrentIndex(2); // WHEN UR BACK ADD THAT U CAN INSERT IN DB
}


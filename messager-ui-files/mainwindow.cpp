#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "encoder.cpp"
#include <QSizePolicy>

void clearLayout(QLayout *layout) {
    if (layout == NULL)
        return;
    QLayoutItem *item;
    while((item = layout->takeAt(0))) {
        if (item->layout()) {
            clearLayout(item->layout());
            delete item->layout();
        }
        if (item->widget()) {
           delete item->widget();
        }
        delete item;
    }
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    db = QSqlDatabase::addDatabase("QPSQL");
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

void MainWindow::open_homepage() {
    db.open();
    clearLayout(ui->verticalLayout_2);
    vector<string> conversations;
    vector<string> other_people;
    QSqlQuery get_convos;
    get_convos.exec(("SELECT sender, recipient FROM messages "
                     "WHERE sender = '" + current_username + "' OR recipient = '" + current_username + "'" + " ORDER BY time_sent DESC").c_str());
    while (get_convos.next()) {
        string sender = get_convos.value(0).toString().toStdString();
        string recipient = get_convos.value(1).toString().toStdString();
        // true if the username isn't the sender and is not already inside conversations DEBUG THIS NEXT
        if (std::find(conversations.begin(), conversations.end(), current_username) == conversations.end()) {
            if (sender == current_username) {
                conversations.push_back(recipient);
            } else {
                conversations.push_back(sender);
            }
        }
    }
    // itterate through conversations
    int index;
    for (string conversation : conversations) {
        QPushButton * conversation_button = new QPushButton(("\n" + conversation + "\n").c_str(), ui->conversations);
        conversation_button->setStyleSheet("border:1px solid black;");
        ui->verticalLayout_2->addWidget(conversation_button);
        index++;
    }
    ui->verticalLayout_2->addStretch();
    ui->StackedWidget->setCurrentIndex(2);
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
        open_homepage();
    } else {
        QMessageBox error_message;
        error_message.critical(0, "Erreurr", "S.V.P. se connecter avant d'accéder la page d'acceuil.");
        error_message.setFixedSize(500, 200);
    }
}


void MainWindow::on_login_submit_clicked()
{
    // reopen database if its closed
    db.open();
    string username = ui->login_username->text().toStdString();
    string password = ui->login_password->text().toStdString();
    QSqlQuery user;
    user.exec(("SELECT * FROM users WHERE username = '" + username + "'").c_str());
    while(user.next()) {
        string db_username = user.value(0).toString().toStdString();
        string db_password = Encoder->translate(user.value(1).toString().toStdString());
        if (username == db_username && password == db_password) {
            current_username = username;
            open_homepage();
            ui->login_username->setText("");
            ui->login_password->setText("");
            logged_in = true;
            return;
        }
    }
    QMessageBox error_message;
    error_message.critical(0, "Erreurr", "Le nom d'utilisateur ou le mot de passe est incorrect.");
    error_message.setFixedSize(500, 200);
}

void MainWindow::on_register_submit_clicked()
{
    // reopen database if its closed
    db.open();
    // get a list of all usernames to make sure the username isnt already there
    vector<string> all_usernames = {};
    QSqlQuery get_usernames;
    get_usernames.exec("SELECT username FROM users;");
    while (get_usernames.next()) {
        all_usernames.push_back(get_usernames.value(0).toString().toStdString());
    }
    // get user input for username and password and did some error handling too
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
    } else if (std::find(all_usernames.begin(), all_usernames.end(), username) != all_usernames.end()) {
        QMessageBox error_message;
        error_message.critical(0, "Erreurr", "Le nom d'utilisateur est deja utilisé.");
        error_message.setFixedSize(500, 200);
        return;
    }
    // if all conditions were matched then you upload the data to database :)
    string encoded_password = Encoder->encode(password);
    QSqlQuery user;
    user.exec(("INSERT INTO users (username, password, messager_score) VALUES('" + username + "', '" + encoded_password + "'," + to_string(0) + ")").c_str());
    database.commit();
    logged_in = true;
    current_username = username;
    open_homepage();
    ui->register_username->setText("");
    ui->register_password->setText("");
}


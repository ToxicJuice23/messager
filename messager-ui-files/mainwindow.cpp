#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "encoder.cpp"

void MainWindow::clearLayout(QLayout *layout) {
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

void MainWindow::contactClicked() {
    if (!db.isOpen()) {
        db.open();
    }
    // get the other user's username by getting the button text
    QPushButton * button = dynamic_cast<QPushButton*>(sender());
    string other_user = button->text().toStdString();
    QSqlQuery get_convo;
    get_convo.exec(("SELECT sender, message FROM messages WHERE sender = '" + current_username + "'" + " AND recipient = '" + other_user + "' OR recipient = '" + current_username + "' AND sender = '" + other_user + "' ORDER BY time_sent ASC").c_str());
    string messages;
    while (get_convo.next()) {
        if (get_convo.at() != get_convo.size() - 1) {
            messages.append(get_convo.value(0).toString().toStdString() + ": " + get_convo.value(1).toString().toStdString() + "\n\n");
        } else {
            messages.append(get_convo.value(0).toString().toStdString() + ": " + get_convo.value(1).toString().toStdString());
        }
    }
    selected_user = other_user;
    ui->contact_button->setText(other_user.c_str());
    ui->messages_container->setText(messages.c_str());
}

void MainWindow::newConversation() {
    bool ok;
    string other_name = QInputDialog::getText(this, tr("Dialogue"), tr("Entrer un nouveau contacte:"), QLineEdit::Normal, tr("example_username"), &ok).toStdString();
    // reopen database if its closed
    if (db.isOpen()) db.open();
    // get a list of all usernames to make sure the username isnt already there
    vector<string> all_usernames = {};
    QSqlQuery get_usernames;
    get_usernames.exec("SELECT username FROM users;");
    while (get_usernames.next()) {
        all_usernames.push_back(get_usernames.value(0).toString().toStdString());
    }
    if (std::find(all_usernames.begin(), all_usernames.end(), other_name) != all_usernames.end()) {
        QSqlQuery creer_conversation;
        creer_conversation.exec(("INSERT INTO messages (sender, recipient, message, time_sent) VALUES ('" + current_username + "', '" + other_name + "', 'Début de la conversation', now()::timestamp)").c_str());
        open_homepage();
    } else {
        QMessageBox error_message;
        error_message.critical(0, "Erreur", "L'utilisateur n'existe pas.");
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
    ui->message_input->setPlaceholderText("Messager");
    ui->login_username->setFocus();
    ui->messages_container->setWordWrap(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::open_homepage() {
    if (!db.isOpen()) db.open();
    ui->messages_container->setText("");
    clearLayout(ui->verticalLayout_2);
    vector<string> conversations;
    QSqlQuery get_convos;
    get_convos.exec(("SELECT sender, recipient FROM messages WHERE sender = '" + current_username + "' OR recipient = '" + current_username + "'" + " ORDER BY time_sent DESC").c_str());
    while (get_convos.next()) {
        string sender = get_convos.value(0).toString().toStdString();
        string recipient = get_convos.value(1).toString().toStdString();
        string other_person;
        if (sender == current_username) {
            other_person = recipient;
        } else {
            other_person = sender;
        }
        // true if the username isn't the sender and is not already inside conversations DEBUG THIS NEXT
        if (std::find(conversations.begin(), conversations.end(), other_person) == conversations.end()) {
            conversations.push_back(other_person);
        }
    }
    // itterate through conversations
    int index;
    for (string conversation : conversations) {
        conversation_button = new QPushButton(conversation.c_str(), ui->conversations);
        conversation_button->setStyleSheet("border:1px solid black; padding-top: 20px; padding-bottom: 20px;");
        ui->verticalLayout_2->addWidget(conversation_button);
        // ADD CLICKABILLITY
        QObject::connect(conversation_button, SIGNAL(clicked()), this, SLOT(contactClicked()));
        index++;
    }
    QPushButton * new_convo = new QPushButton("Nouvelle Conversation", ui->conversations);
    new_convo->setStyleSheet("border:1px solid black; padding-top: 20px; padding-bottom: 20px;");
    ui->verticalLayout_2->addWidget(new_convo);
    QPushButton::connect(new_convo, SIGNAL(clicked()), this, SLOT(newConversation()));
    ui->verticalLayout_2->addStretch();
    ui->contact_button->setText("Aucune conversation de séléctionné");
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
    current_username = "";
    // reopen database if its closed
    if (!db.isOpen()) db.open();
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
    current_username = "";
    // reopen database if its closed
    if (db.isOpen()) db.open();
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


void MainWindow::on_login_username_returnPressed()
{
    ui->login_password->setFocus();
}


void MainWindow::on_login_password_returnPressed()
{
    on_login_submit_clicked();
}


void MainWindow::on_register_username_returnPressed()
{
    ui->register_password->setFocus();
}


void MainWindow::on_register_password_returnPressed()
{
    on_register_submit_clicked();
}

void MainWindow::refresh_m_and_c() {
    // refresh messages
    string other_user = selected_user;
    QSqlQuery get_convo;
    get_convo.exec(("SELECT sender, message FROM messages WHERE sender = '" + current_username + "'" + " AND recipient = '" + other_user + "' OR recipient = '" + current_username + "' AND sender = '" + other_user + "' ORDER BY time_sent ASC").c_str());
    string messages;
    while (get_convo.next()) {
        if (get_convo.at() != get_convo.size() - 1) {
            messages.append(get_convo.value(0).toString().toStdString() + ": " + get_convo.value(1).toString().toStdString() + "\n\n");
        } else {
            messages.append(get_convo.value(0).toString().toStdString() + ": " + get_convo.value(1).toString().toStdString());
        }
    }
    ui->messages_container->setText(messages.c_str());
    ui->scrollArea_2->verticalScrollBar()->setSliderPosition(ui->messages_container->height());
    // refresh contacts
    clearLayout(ui->verticalLayout_2);
    vector<string> conversations;
    QSqlQuery get_convos;
    get_convos.exec(("SELECT sender, recipient FROM messages WHERE sender = '" + current_username + "' OR recipient = '" + current_username + "'" + " ORDER BY time_sent DESC").c_str());
    while (get_convos.next()) {
        string sender = get_convos.value(0).toString().toStdString();
        string recipient = get_convos.value(1).toString().toStdString();
        string other_person;
        if (sender == current_username) {
            other_person = recipient;
        } else {
            other_person = sender;
        }
        // true if the username isn't the sender and is not already inside conversations DEBUG THIS NEXT
        if (std::find(conversations.begin(), conversations.end(), other_person) == conversations.end()) {
            conversations.push_back(other_person);
        }
    }
    // itterate through conversations
    int index;
    for (string conversation : conversations) {
        conversation_button = new QPushButton(conversation.c_str(), ui->conversations);
        conversation_button->setStyleSheet("border:1px solid black; padding-top: 20px; padding-bottom: 20px;");
        ui->verticalLayout_2->addWidget(conversation_button);
        // ADD CLICKABILLITY
        QObject::connect(conversation_button, SIGNAL(clicked()), this, SLOT(contactClicked()));
        index++;
    }
    QPushButton * new_convo = new QPushButton("Nouvelle Conversation", ui->conversations);
    new_convo->setStyleSheet("border:1px solid black; padding-top: 20px; padding-bottom: 20px;");
    ui->verticalLayout_2->addWidget(new_convo);
    QPushButton::connect(new_convo, SIGNAL(clicked()), this, SLOT(newConversation()));
    ui->verticalLayout_2->addStretch();
}

void MainWindow::on_send_message_clicked()
{
    if (!db.isOpen()) {
        db.open();
    }
    string message = ui->message_input->text().toStdString();
    ui->message_input->setText("");
    QSqlQuery send_message;
    send_message.exec(("INSERT INTO messages (sender, recipient, message, time_sent)"
                       "VALUES ('" + current_username + "', '" + selected_user + "', '" + message + "', now()::timestamp)").c_str());
    db.commit();
    // get the other user's username by getting the button text
    string other_user = selected_user;
    QSqlQuery get_convo;
    get_convo.exec(("SELECT sender, message FROM messages WHERE sender = '" + current_username + "'" + " AND recipient = '" + other_user + "' OR recipient = '" + current_username + "' AND sender = '" + other_user + "' ORDER BY time_sent ASC").c_str());
    string messages;
    while (get_convo.next()) {
        if (get_convo.at() != get_convo.size() - 1) {
            messages.append(get_convo.value(0).toString().toStdString() + ": " + get_convo.value(1).toString().toStdString() + "\n\n");
        } else {
            messages.append(get_convo.value(0).toString().toStdString() + ": " + get_convo.value(1).toString().toStdString());
        }
    }
    ui->messages_container->setText(messages.c_str());
    ui->scrollArea_2->verticalScrollBar()->setSliderPosition(ui->messages_container->height());
    QSqlQuery incr;
    incr.exec(("UPDATE users "
               "SET messager_score = messager_score + 1 "
               "WHERE username = '" + current_username + "' "
               "AND username = '" + selected_user + "'").c_str());
    cout << "UPDATE users "
            "SET messager_score = messager_score + 1 "
            "WHERE username = '" + current_username + "' "
            "AND username = '" + selected_user + "'";
    db.commit();
    ui->message_input->setFocus();
    ui->scrollArea_2->verticalScrollBar()->setSliderPosition(ui->messages_container->height());
}


void MainWindow::on_message_input_returnPressed()
{
    on_send_message_clicked();
}


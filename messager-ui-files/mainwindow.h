#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QScrollBar>
#include <QMessageBox>
#include <QSizePolicy>
#include <QInputDialog>
#include <QDir>
#include <iostream>
#include <vector>
#include <algorithm>
#include <thread>
using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    string current_username = "";
    string selected_user = "";
    void clearLayout(QLayout *layout);
    bool logged_in = false;
    QPushButton * conversation_button;
    QSqlDatabase db;
    QSqlDatabase database;

    void open_homepage();
    // refresh messages and contacts, takes no arguments
    void refresh_m_and_c();
private slots:
    void contactClicked();

    void newConversation();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_login_submit_clicked();

    void on_register_submit_clicked();

    void on_login_username_returnPressed();

    void on_login_password_returnPressed();

    void on_register_username_returnPressed();

    void on_register_password_returnPressed();

    void on_send_message_clicked();

    void on_message_input_returnPressed();
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H

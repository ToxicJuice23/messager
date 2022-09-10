#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>
#include <iostream>
#include <vector>
#include <algorithm>
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
    bool logged_in = false;
    QSqlDatabase db;
    QSqlDatabase database;
    string current_username = "";
    void open_homepage();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_login_submit_clicked();

    void on_register_submit_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H

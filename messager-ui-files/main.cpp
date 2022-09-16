#include "mainwindow.h"
#include <QApplication>

void refresh_messages(MainWindow w) {
    /*
    while (true) {
        if (selected_user != "" && current_username != "") {
            w.refresh_m_and_c();
        }
    }
    */
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    w.setWindowIcon(QIcon("Messager.png"));
    w.setWindowTitle("Messager");
    //thread refresh_(refresh_messages);
    int a_result = a.exec();
    //refresh_.join();
    return a_result;
}

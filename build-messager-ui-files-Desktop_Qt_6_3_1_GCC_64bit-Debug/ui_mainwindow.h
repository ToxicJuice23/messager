/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QFrame *frame;
    QGridLayout *gridLayout_3;
    QPushButton *pushButton_2;
    QPushButton *pushButton_4;
    QPushButton *pushButton_3;
    QSpacerItem *horizontalSpacer_5;
    QStackedWidget *StackedWidget;
    QWidget *Login;
    QGridLayout *gridLayout_2;
    QSpacerItem *horizontalSpacer;
    QLineEdit *login_username;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer;
    QPushButton *login_submit;
    QLineEdit *login_password;
    QLabel *login_title;
    QLabel *used_as_spacer_1;
    QWidget *Register;
    QGridLayout *gridLayout_5;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *register_submit;
    QSpacerItem *horizontalSpacer_9;
    QLineEdit *register_password;
    QSpacerItem *horizontalSpacer_7;
    QLabel *register_title;
    QLabel *used_as_spacer_2;
    QSpacerItem *horizontalSpacer_8;
    QLineEdit *register_username;
    QSpacerItem *verticalSpacer_2;
    QWidget *Homepage;
    QGridLayout *gridLayout_4;
    QScrollArea *scrollArea;
    QWidget *conversations;
    QVBoxLayout *verticalLayout_2;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setStyleSheet(QString::fromUtf8("background-color: 7bae37"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        frame = new QFrame(centralwidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setStyleSheet(QString::fromUtf8("background-color: #7bae37; text-decoration: underline;"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_3 = new QGridLayout(frame);
        gridLayout_3->setSpacing(0);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        pushButton_2 = new QPushButton(frame);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setStyleSheet(QString::fromUtf8("border: 0px transparent; padding: 5px;"));

        gridLayout_3->addWidget(pushButton_2, 0, 0, 1, 1);

        pushButton_4 = new QPushButton(frame);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setStyleSheet(QString::fromUtf8("border: 0px transparent; padding: 5px;"));

        gridLayout_3->addWidget(pushButton_4, 0, 2, 1, 1);

        pushButton_3 = new QPushButton(frame);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setStyleSheet(QString::fromUtf8("border: 0px transparent; padding: 5px;"));

        gridLayout_3->addWidget(pushButton_3, 0, 1, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_5, 0, 3, 1, 1);


        verticalLayout->addWidget(frame);

        StackedWidget = new QStackedWidget(centralwidget);
        StackedWidget->setObjectName(QString::fromUtf8("StackedWidget"));
        Login = new QWidget();
        Login->setObjectName(QString::fromUtf8("Login"));
        Login->setStyleSheet(QString::fromUtf8("background-color: #EEEEEE;"));
        gridLayout_2 = new QGridLayout(Login);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 3, 3, 2, 1);

        login_username = new QLineEdit(Login);
        login_username->setObjectName(QString::fromUtf8("login_username"));

        gridLayout_2->addWidget(login_username, 3, 1, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_4, 1, 3, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_3, 1, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 3, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 7, 2, 1, 1);

        login_submit = new QPushButton(Login);
        login_submit->setObjectName(QString::fromUtf8("login_submit"));

        gridLayout_2->addWidget(login_submit, 4, 2, 1, 1);

        login_password = new QLineEdit(Login);
        login_password->setObjectName(QString::fromUtf8("login_password"));
        login_password->setEchoMode(QLineEdit::Password);

        gridLayout_2->addWidget(login_password, 4, 1, 1, 1);

        login_title = new QLabel(Login);
        login_title->setObjectName(QString::fromUtf8("login_title"));
        QFont font;
        font.setPointSize(20);
        login_title->setFont(font);
        login_title->setAlignment(Qt::AlignHCenter|Qt::AlignTop);

        gridLayout_2->addWidget(login_title, 1, 1, 1, 2);

        used_as_spacer_1 = new QLabel(Login);
        used_as_spacer_1->setObjectName(QString::fromUtf8("used_as_spacer_1"));

        gridLayout_2->addWidget(used_as_spacer_1, 2, 1, 1, 1);

        StackedWidget->addWidget(Login);
        Register = new QWidget();
        Register->setObjectName(QString::fromUtf8("Register"));
        Register->setStyleSheet(QString::fromUtf8("background-color: #EEEEEE;"));
        gridLayout_5 = new QGridLayout(Register);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_6, 0, 4, 1, 1);

        register_submit = new QPushButton(Register);
        register_submit->setObjectName(QString::fromUtf8("register_submit"));

        gridLayout_5->addWidget(register_submit, 3, 7, 1, 1);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_9, 3, 4, 1, 1);

        register_password = new QLineEdit(Register);
        register_password->setObjectName(QString::fromUtf8("register_password"));
        register_password->setEchoMode(QLineEdit::Password);

        gridLayout_5->addWidget(register_password, 3, 6, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_7, 0, 8, 1, 1);

        register_title = new QLabel(Register);
        register_title->setObjectName(QString::fromUtf8("register_title"));
        register_title->setFont(font);
        register_title->setAlignment(Qt::AlignHCenter|Qt::AlignTop);

        gridLayout_5->addWidget(register_title, 0, 6, 1, 2);

        used_as_spacer_2 = new QLabel(Register);
        used_as_spacer_2->setObjectName(QString::fromUtf8("used_as_spacer_2"));

        gridLayout_5->addWidget(used_as_spacer_2, 1, 6, 1, 1);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_8, 3, 8, 1, 1);

        register_username = new QLineEdit(Register);
        register_username->setObjectName(QString::fromUtf8("register_username"));

        gridLayout_5->addWidget(register_username, 2, 6, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_5->addItem(verticalSpacer_2, 4, 6, 1, 1);

        StackedWidget->addWidget(Register);
        Homepage = new QWidget();
        Homepage->setObjectName(QString::fromUtf8("Homepage"));
        Homepage->setStyleSheet(QString::fromUtf8("background-color: #74bd20; text-align: left;"));
        gridLayout_4 = new QGridLayout(Homepage);
        gridLayout_4->setSpacing(0);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        scrollArea = new QScrollArea(Homepage);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setStyleSheet(QString::fromUtf8("background-color: #74bd20; text-align: left; border: 0;"));
        scrollArea->setWidgetResizable(true);
        conversations = new QWidget();
        conversations->setObjectName(QString::fromUtf8("conversations"));
        conversations->setGeometry(QRect(0, 0, 400, 571));
        conversations->setStyleSheet(QString::fromUtf8("padding: 5px;"));
        verticalLayout_2 = new QVBoxLayout(conversations);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        scrollArea->setWidget(conversations);

        gridLayout_4->addWidget(scrollArea, 0, 0, 1, 1);

        scrollArea_2 = new QScrollArea(Homepage);
        scrollArea_2->setObjectName(QString::fromUtf8("scrollArea_2"));
        scrollArea_2->setStyleSheet(QString::fromUtf8("background-color: white;"));
        scrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 398, 569));
        scrollArea_2->setWidget(scrollAreaWidgetContents);

        gridLayout_4->addWidget(scrollArea_2, 0, 1, 2, 1);

        StackedWidget->addWidget(Homepage);

        verticalLayout->addWidget(StackedWidget);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        StackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Connecter", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "Page D'acceuil", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "Enregistrer", nullptr));
        login_submit->setText(QCoreApplication::translate("MainWindow", "Soumettre", nullptr));
        login_title->setText(QCoreApplication::translate("MainWindow", "Connecter", nullptr));
        used_as_spacer_1->setText(QString());
        register_submit->setText(QCoreApplication::translate("MainWindow", "Soumettre", nullptr));
        register_title->setText(QCoreApplication::translate("MainWindow", " Enregistrer ", nullptr));
        used_as_spacer_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

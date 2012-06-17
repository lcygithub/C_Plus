/********************************************************************************
** Form generated from reading UI file 'user.ui'
**
** Created: Fri Jun 15 22:19:41 2012
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USER_H
#define UI_USER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_user
{
public:
    QWidget *centralwidget;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *usrLabel;
    QLineEdit *usrLineEdit;
    QLabel *pwdLabel;
    QLineEdit *pwdLineEdit;
    QWidget *widget1;
    QGridLayout *gridLayout_2;
    QPushButton *registerButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *loginButton;
    QPushButton *cancelButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *user)
    {
        if (user->objectName().isEmpty())
            user->setObjectName(QString::fromUtf8("user"));
        user->resize(800, 600);
        centralwidget = new QWidget(user);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(110, 120, 421, 161));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        usrLabel = new QLabel(widget);
        usrLabel->setObjectName(QString::fromUtf8("usrLabel"));

        gridLayout->addWidget(usrLabel, 0, 0, 1, 1);

        usrLineEdit = new QLineEdit(widget);
        usrLineEdit->setObjectName(QString::fromUtf8("usrLineEdit"));
        usrLineEdit->setEnabled(true);
        usrLineEdit->setMouseTracking(true);
        usrLineEdit->setFrame(true);
        usrLineEdit->setReadOnly(true);

        gridLayout->addWidget(usrLineEdit, 0, 1, 1, 1);

        pwdLabel = new QLabel(widget);
        pwdLabel->setObjectName(QString::fromUtf8("pwdLabel"));

        gridLayout->addWidget(pwdLabel, 1, 0, 1, 1);

        pwdLineEdit = new QLineEdit(widget);
        pwdLineEdit->setObjectName(QString::fromUtf8("pwdLineEdit"));

        gridLayout->addWidget(pwdLineEdit, 1, 1, 1, 1);

        widget1 = new QWidget(centralwidget);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(110, 290, 421, 81));
        gridLayout_2 = new QGridLayout(widget1);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        registerButton = new QPushButton(widget1);
        registerButton->setObjectName(QString::fromUtf8("registerButton"));

        gridLayout_2->addWidget(registerButton, 0, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 0, 1, 1, 1);

        loginButton = new QPushButton(widget1);
        loginButton->setObjectName(QString::fromUtf8("loginButton"));

        gridLayout_2->addWidget(loginButton, 0, 2, 1, 1);

        cancelButton = new QPushButton(widget1);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));

        gridLayout_2->addWidget(cancelButton, 0, 3, 1, 1);

        user->setCentralWidget(centralwidget);
        menubar = new QMenuBar(user);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 25));
        user->setMenuBar(menubar);
        statusbar = new QStatusBar(user);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        user->setStatusBar(statusbar);

        retranslateUi(user);

        QMetaObject::connectSlotsByName(user);
    } // setupUi

    void retranslateUi(QMainWindow *user)
    {
        user->setWindowTitle(QApplication::translate("user", "MainWindow", 0, QApplication::UnicodeUTF8));
        usrLabel->setText(QApplication::translate("user", "\347\224\250\346\210\267\345\220\215", 0, QApplication::UnicodeUTF8));
        usrLineEdit->setText(QString());
        pwdLabel->setText(QApplication::translate("user", "\345\257\206   \347\240\201", 0, QApplication::UnicodeUTF8));
        registerButton->setText(QApplication::translate("user", "\346\263\250\345\206\214", 0, QApplication::UnicodeUTF8));
        loginButton->setText(QApplication::translate("user", "\347\231\273\345\275\225", 0, QApplication::UnicodeUTF8));
        cancelButton->setText(QApplication::translate("user", "\351\200\200\345\207\272", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class user: public Ui_user {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USER_H

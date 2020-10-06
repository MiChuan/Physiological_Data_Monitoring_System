/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_login
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QLineEdit *password;
    QLabel *label_2;
    QLineEdit *username;
    QLabel *label;
    QPushButton *login_btn;

    void setupUi(QDialog *login)
    {
        if (login->objectName().isEmpty())
            login->setObjectName(QStringLiteral("login"));
        login->resize(394, 200);
        gridLayoutWidget = new QWidget(login);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 10, 371, 180));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        password = new QLineEdit(gridLayoutWidget);
        password->setObjectName(QStringLiteral("password"));

        gridLayout->addWidget(password, 2, 1, 1, 1);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        username = new QLineEdit(gridLayoutWidget);
        username->setObjectName(QStringLiteral("username"));

        gridLayout->addWidget(username, 1, 1, 1, 1);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 0, 1, 1, 1);

        login_btn = new QPushButton(gridLayoutWidget);
        login_btn->setObjectName(QStringLiteral("login_btn"));

        gridLayout->addWidget(login_btn, 3, 1, 1, 1);


        retranslateUi(login);

        QMetaObject::connectSlotsByName(login);
    } // setupUi

    void retranslateUi(QDialog *login)
    {
        login->setWindowTitle(QApplication::translate("login", "Dialog", nullptr));
        label_3->setText(QApplication::translate("login", "\345\257\206\347\240\201", nullptr));
#ifndef QT_NO_STATUSTIP
        password->setStatusTip(QApplication::translate("login", "\350\257\267\350\276\223\345\205\245\345\257\206\347\240\201", nullptr));
#endif // QT_NO_STATUSTIP
        label_2->setText(QApplication::translate("login", "\347\224\250\346\210\267\345\220\215", nullptr));
#ifndef QT_NO_STATUSTIP
        username->setStatusTip(QApplication::translate("login", "\350\257\267\350\276\223\345\205\245\347\224\250\346\210\267\345\220\215", nullptr));
#endif // QT_NO_STATUSTIP
        label->setText(QApplication::translate("login", "\346\254\242\350\277\216\344\275\277\347\224\250\347\224\237\347\220\206\346\225\260\346\215\256\347\233\221\346\265\213\347\263\273\347\273\237", nullptr));
#ifndef QT_NO_STATUSTIP
        login_btn->setStatusTip(QApplication::translate("login", "\347\231\273\345\275\225\346\214\211\351\222\256", nullptr));
#endif // QT_NO_STATUSTIP
        login_btn->setText(QApplication::translate("login", "\347\231\273\345\275\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class login: public Ui_login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H

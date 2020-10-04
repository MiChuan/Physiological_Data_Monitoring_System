/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *about;
    QWidget *centralWidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;
    QMenuBar *menuBar;
    QMenu *menu;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(566, 208);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/images/\344\277\241\346\201\257\345\210\206\346\236\220.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        about = new QAction(MainWindow);
        about->setObjectName(QStringLiteral("about"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/new/prefix1/images/help.png"), QSize(), QIcon::Normal, QIcon::Off);
        about->setIcon(icon1);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayoutWidget = new QWidget(centralWidget);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 10, 541, 141));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_3 = new QPushButton(horizontalLayoutWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        horizontalLayout->addWidget(pushButton_3);

        pushButton_2 = new QPushButton(horizontalLayoutWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 566, 26));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menu->addAction(about);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\345\237\272\344\272\216MQTT\347\232\204\347\224\237\347\220\206\346\225\260\346\215\256\347\233\221\346\265\213\347\263\273\347\273\237", nullptr));
        about->setText(QApplication::translate("MainWindow", "\345\205\263\344\272\216", nullptr));
#ifndef QT_NO_STATUSTIP
        about->setStatusTip(QApplication::translate("MainWindow", "\345\205\263\344\272\216\347\263\273\347\273\237\347\232\204\344\277\241\346\201\257", nullptr));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_STATUSTIP
        pushButton_3->setStatusTip(QApplication::translate("MainWindow", "\347\273\230\345\210\266\344\270\200\345\221\250\345\206\205\346\225\260\346\215\256\346\233\262\347\272\277", nullptr));
#endif // QT_NO_STATUSTIP
        pushButton_3->setText(QApplication::translate("MainWindow", "\346\225\260\346\215\256\346\233\262\347\272\277", nullptr));
#ifndef QT_NO_STATUSTIP
        pushButton_2->setStatusTip(QApplication::translate("MainWindow", "\346\240\271\346\215\256\344\270\200\345\221\250\345\206\205\347\224\237\347\220\206\346\225\260\346\215\256\345\210\206\346\236\220\350\272\253\344\275\223\347\212\266\345\206\265", nullptr));
#endif // QT_NO_STATUSTIP
        pushButton_2->setText(QApplication::translate("MainWindow", "\346\225\260\346\215\256\345\210\206\346\236\220", nullptr));
        menu->setTitle(QApplication::translate("MainWindow", "\345\270\256\345\212\251", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

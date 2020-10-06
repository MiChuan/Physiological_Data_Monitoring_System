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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *about;
    QAction *login;
    QAction *logout;
    QAction *dataAnalyze;
    QAction *draw;
    QAction *mainpage;
    QWidget *centralWidget;
    QStackedWidget *stackedWidget;
    QMenuBar *menuBar;
    QMenu *help;
    QMenu *setting;
    QMenu *menu;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(722, 371);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/images/\344\277\241\346\201\257\345\210\206\346\236\220.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        about = new QAction(MainWindow);
        about->setObjectName(QStringLiteral("about"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/new/prefix1/images/help.png"), QSize(), QIcon::Normal, QIcon::Off);
        about->setIcon(icon1);
        login = new QAction(MainWindow);
        login->setObjectName(QStringLiteral("login"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/new/prefix1/images/login.png"), QSize(), QIcon::Normal, QIcon::Off);
        login->setIcon(icon2);
        logout = new QAction(MainWindow);
        logout->setObjectName(QStringLiteral("logout"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/new/prefix1/images/logout.png"), QSize(), QIcon::Normal, QIcon::Off);
        logout->setIcon(icon3);
        dataAnalyze = new QAction(MainWindow);
        dataAnalyze->setObjectName(QStringLiteral("dataAnalyze"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/new/prefix1/images/dataanalyze.png"), QSize(), QIcon::Normal, QIcon::Off);
        dataAnalyze->setIcon(icon4);
        draw = new QAction(MainWindow);
        draw->setObjectName(QStringLiteral("draw"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/new/prefix1/images/draw.png"), QSize(), QIcon::Normal, QIcon::Off);
        draw->setIcon(icon5);
        mainpage = new QAction(MainWindow);
        mainpage->setObjectName(QStringLiteral("mainpage"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/new/prefix1/images/main.png"), QSize(), QIcon::Normal, QIcon::Off);
        mainpage->setIcon(icon6);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 4, 721, 301));
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(10);
        stackedWidget->setFont(font);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 722, 26));
        help = new QMenu(menuBar);
        help->setObjectName(QStringLiteral("help"));
        setting = new QMenu(menuBar);
        setting->setObjectName(QStringLiteral("setting"));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(setting->menuAction());
        menuBar->addAction(menu->menuAction());
        menuBar->addAction(help->menuAction());
        help->addAction(about);
        setting->addAction(login);
        setting->addAction(logout);
        setting->addAction(mainpage);
        menu->addAction(dataAnalyze);
        menu->addAction(draw);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\345\237\272\344\272\216MQTT\347\232\204\347\224\237\347\220\206\346\225\260\346\215\256\347\233\221\346\265\213\347\263\273\347\273\237", nullptr));
        about->setText(QApplication::translate("MainWindow", "\345\205\263\344\272\216", nullptr));
#ifndef QT_NO_STATUSTIP
        about->setStatusTip(QApplication::translate("MainWindow", "\345\205\263\344\272\216\347\263\273\347\273\237\347\232\204\344\277\241\346\201\257", nullptr));
#endif // QT_NO_STATUSTIP
        login->setText(QApplication::translate("MainWindow", "\347\231\273\345\275\225", nullptr));
#ifndef QT_NO_STATUSTIP
        login->setStatusTip(QApplication::translate("MainWindow", "\347\231\273\345\275\225\347\224\237\347\220\206\346\225\260\346\215\256\347\233\221\346\265\213\347\263\273\347\273\237", nullptr));
#endif // QT_NO_STATUSTIP
        logout->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272", nullptr));
#ifndef QT_NO_STATUSTIP
        logout->setStatusTip(QApplication::translate("MainWindow", "\351\200\200\345\207\272\347\224\237\347\220\206\346\225\260\346\215\256\347\233\221\346\265\213\347\263\273\347\273\237", nullptr));
#endif // QT_NO_STATUSTIP
        dataAnalyze->setText(QApplication::translate("MainWindow", "\346\225\260\346\215\256\345\210\206\346\236\220", nullptr));
#ifndef QT_NO_STATUSTIP
        dataAnalyze->setStatusTip(QApplication::translate("MainWindow", "\346\240\271\346\215\256\347\224\237\347\220\206\346\225\260\346\215\256\345\210\206\346\236\220\345\201\245\345\272\267\347\212\266\345\206\265", nullptr));
#endif // QT_NO_STATUSTIP
        draw->setText(QApplication::translate("MainWindow", "\346\233\262\347\272\277\347\273\230\345\210\266", nullptr));
#ifndef QT_NO_STATUSTIP
        draw->setStatusTip(QApplication::translate("MainWindow", "\347\273\230\345\210\266\347\224\237\347\220\206\346\225\260\346\215\256\346\233\262\347\272\277", nullptr));
#endif // QT_NO_STATUSTIP
        mainpage->setText(QApplication::translate("MainWindow", "\346\230\276\347\244\272\344\270\273\351\241\265", nullptr));
#ifndef QT_NO_STATUSTIP
        mainpage->setStatusTip(QApplication::translate("MainWindow", "\346\230\276\347\244\272\347\263\273\347\273\237\344\270\273\351\241\265", nullptr));
#endif // QT_NO_STATUSTIP
        help->setTitle(QApplication::translate("MainWindow", "\345\270\256\345\212\251", nullptr));
        setting->setTitle(QApplication::translate("MainWindow", "\347\263\273\347\273\237\350\256\276\347\275\256", nullptr));
        menu->setTitle(QApplication::translate("MainWindow", "\347\263\273\347\273\237\345\212\237\350\203\275", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

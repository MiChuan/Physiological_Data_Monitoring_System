/********************************************************************************
** Form generated from reading UI file 'analyze.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ANALYZE_H
#define UI_ANALYZE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Analyze
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QTextBrowser *textBrowser;
    QTableView *tableView;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *analyze_btn;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;

    void setupUi(QWidget *Analyze)
    {
        if (Analyze->objectName().isEmpty())
            Analyze->setObjectName(QStringLiteral("Analyze"));
        Analyze->resize(720, 300);
        horizontalLayoutWidget = new QWidget(Analyze);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(20, 10, 681, 231));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        textBrowser = new QTextBrowser(horizontalLayoutWidget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));

        horizontalLayout->addWidget(textBrowser);

        tableView = new QTableView(horizontalLayoutWidget);
        tableView->setObjectName(QStringLiteral("tableView"));

        horizontalLayout->addWidget(tableView);

        horizontalLayoutWidget_2 = new QWidget(Analyze);
        horizontalLayoutWidget_2->setObjectName(QStringLiteral("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(100, 250, 521, 31));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        analyze_btn = new QPushButton(horizontalLayoutWidget_2);
        analyze_btn->setObjectName(QStringLiteral("analyze_btn"));

        horizontalLayout_2->addWidget(analyze_btn);

        pushButton = new QPushButton(horizontalLayoutWidget_2);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout_2->addWidget(pushButton);

        pushButton_2 = new QPushButton(horizontalLayoutWidget_2);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout_2->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(horizontalLayoutWidget_2);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        horizontalLayout_2->addWidget(pushButton_3);


        retranslateUi(Analyze);

        QMetaObject::connectSlotsByName(Analyze);
    } // setupUi

    void retranslateUi(QWidget *Analyze)
    {
        Analyze->setWindowTitle(QApplication::translate("Analyze", "Form", nullptr));
        analyze_btn->setText(QApplication::translate("Analyze", "\345\210\206\346\236\220\346\225\260\346\215\256", nullptr));
        pushButton->setText(QApplication::translate("Analyze", "\346\237\245\347\234\213\344\275\223\346\270\251\346\225\260\346\215\256", nullptr));
        pushButton_2->setText(QApplication::translate("Analyze", "\346\237\245\347\234\213\345\277\203\347\216\207\346\225\260\346\215\256", nullptr));
        pushButton_3->setText(QApplication::translate("Analyze", "\346\237\245\347\234\213\350\241\200\345\216\213\346\225\260\346\215\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Analyze: public Ui_Analyze {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ANALYZE_H

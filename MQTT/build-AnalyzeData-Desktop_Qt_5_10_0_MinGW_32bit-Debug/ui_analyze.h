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
    QTextBrowser *analyzeResult;
    QTableView *viewData;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *analyze_btn;
    QPushButton *temp_btn;
    QPushButton *heart_btn;
    QPushButton *blood_btn;

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
        analyzeResult = new QTextBrowser(horizontalLayoutWidget);
        analyzeResult->setObjectName(QStringLiteral("analyzeResult"));

        horizontalLayout->addWidget(analyzeResult);

        viewData = new QTableView(horizontalLayoutWidget);
        viewData->setObjectName(QStringLiteral("viewData"));

        horizontalLayout->addWidget(viewData);

        horizontalLayoutWidget_2 = new QWidget(Analyze);
        horizontalLayoutWidget_2->setObjectName(QStringLiteral("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(100, 250, 521, 31));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        analyze_btn = new QPushButton(horizontalLayoutWidget_2);
        analyze_btn->setObjectName(QStringLiteral("analyze_btn"));

        horizontalLayout_2->addWidget(analyze_btn);

        temp_btn = new QPushButton(horizontalLayoutWidget_2);
        temp_btn->setObjectName(QStringLiteral("temp_btn"));

        horizontalLayout_2->addWidget(temp_btn);

        heart_btn = new QPushButton(horizontalLayoutWidget_2);
        heart_btn->setObjectName(QStringLiteral("heart_btn"));

        horizontalLayout_2->addWidget(heart_btn);

        blood_btn = new QPushButton(horizontalLayoutWidget_2);
        blood_btn->setObjectName(QStringLiteral("blood_btn"));

        horizontalLayout_2->addWidget(blood_btn);


        retranslateUi(Analyze);

        QMetaObject::connectSlotsByName(Analyze);
    } // setupUi

    void retranslateUi(QWidget *Analyze)
    {
        Analyze->setWindowTitle(QApplication::translate("Analyze", "Form", nullptr));
        analyze_btn->setText(QApplication::translate("Analyze", "\345\210\206\346\236\220\346\225\260\346\215\256", nullptr));
        temp_btn->setText(QApplication::translate("Analyze", "\346\237\245\347\234\213\344\275\223\346\270\251\346\225\260\346\215\256", nullptr));
        heart_btn->setText(QApplication::translate("Analyze", "\346\237\245\347\234\213\345\277\203\347\216\207\346\225\260\346\215\256", nullptr));
        blood_btn->setText(QApplication::translate("Analyze", "\346\237\245\347\234\213\350\241\200\345\216\213\346\225\260\346\215\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Analyze: public Ui_Analyze {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ANALYZE_H

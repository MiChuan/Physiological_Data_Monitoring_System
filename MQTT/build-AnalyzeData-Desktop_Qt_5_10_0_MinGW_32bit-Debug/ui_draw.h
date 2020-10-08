/********************************************************************************
** Form generated from reading UI file 'draw.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DRAW_H
#define UI_DRAW_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Draw
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *temperature_btn;
    QPushButton *heartrate_btn;
    QPushButton *blood_btn;
    QWidget *horizontalLayoutWidget_4;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QDateTimeEdit *begin_time;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QDateTimeEdit *end_time;
    QLabel *status;

    void setupUi(QWidget *Draw)
    {
        if (Draw->objectName().isEmpty())
            Draw->setObjectName(QStringLiteral("Draw"));
        Draw->resize(720, 300);
        horizontalLayoutWidget = new QWidget(Draw);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(150, 210, 431, 31));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        temperature_btn = new QPushButton(horizontalLayoutWidget);
        temperature_btn->setObjectName(QStringLiteral("temperature_btn"));

        horizontalLayout->addWidget(temperature_btn);

        heartrate_btn = new QPushButton(horizontalLayoutWidget);
        heartrate_btn->setObjectName(QStringLiteral("heartrate_btn"));

        horizontalLayout->addWidget(heartrate_btn);

        blood_btn = new QPushButton(horizontalLayoutWidget);
        blood_btn->setObjectName(QStringLiteral("blood_btn"));

        horizontalLayout->addWidget(blood_btn);

        horizontalLayoutWidget_4 = new QWidget(Draw);
        horizontalLayoutWidget_4->setObjectName(QStringLiteral("horizontalLayoutWidget_4"));
        horizontalLayoutWidget_4->setGeometry(QRect(100, 50, 501, 101));
        horizontalLayout_4 = new QHBoxLayout(horizontalLayoutWidget_4);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(horizontalLayoutWidget_4);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label);

        begin_time = new QDateTimeEdit(horizontalLayoutWidget_4);
        begin_time->setObjectName(QStringLiteral("begin_time"));
        begin_time->setMaximumDate(QDate(2021, 12, 31));
        begin_time->setMinimumDate(QDate(2019, 1, 14));
        begin_time->setCurrentSection(QDateTimeEdit::YearSection);

        horizontalLayout_2->addWidget(begin_time);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_2 = new QLabel(horizontalLayoutWidget_4);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_2);

        end_time = new QDateTimeEdit(horizontalLayoutWidget_4);
        end_time->setObjectName(QStringLiteral("end_time"));
        end_time->setMaximumDate(QDate(2021, 12, 31));
        end_time->setMinimumDate(QDate(2019, 1, 1));
        end_time->setCurrentSection(QDateTimeEdit::YearSection);

        horizontalLayout_3->addWidget(end_time);


        verticalLayout->addLayout(horizontalLayout_3);


        horizontalLayout_4->addLayout(verticalLayout);

        status = new QLabel(horizontalLayoutWidget_4);
        status->setObjectName(QStringLiteral("status"));
        status->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(status);


        retranslateUi(Draw);

        QMetaObject::connectSlotsByName(Draw);
    } // setupUi

    void retranslateUi(QWidget *Draw)
    {
        Draw->setWindowTitle(QApplication::translate("Draw", "Form", nullptr));
        temperature_btn->setText(QApplication::translate("Draw", "\346\230\276\347\244\272\346\270\251\345\272\246", nullptr));
        heartrate_btn->setText(QApplication::translate("Draw", "\346\230\276\347\244\272\345\277\203\347\216\207", nullptr));
        blood_btn->setText(QApplication::translate("Draw", "\346\230\276\347\244\272\350\241\200\345\216\213", nullptr));
        label->setText(QApplication::translate("Draw", "\345\274\200\345\247\213\346\227\266\351\227\264", nullptr));
        begin_time->setDisplayFormat(QApplication::translate("Draw", "yyyy-MM-dd HH:mm:ss", nullptr));
        label_2->setText(QApplication::translate("Draw", "\347\273\223\346\235\237\346\227\266\351\227\264", nullptr));
        end_time->setDisplayFormat(QApplication::translate("Draw", "yyyy-MM-dd HH:mm:ss", nullptr));
        status->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Draw: public Ui_Draw {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DRAW_H

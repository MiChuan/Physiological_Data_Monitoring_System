/********************************************************************************
** Form generated from reading UI file 'draw.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DRAW_H
#define UI_DRAW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>
#include <qchartview.h>

QT_BEGIN_NAMESPACE

class Ui_Draw
{
public:
    QChartView *widget;

    void setupUi(QWidget *Draw)
    {
        if (Draw->objectName().isEmpty())
            Draw->setObjectName(QStringLiteral("Draw"));
        Draw->resize(720, 300);
        widget = new QChartView(Draw);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(0, 0, 720, 300));

        retranslateUi(Draw);

        QMetaObject::connectSlotsByName(Draw);
    } // setupUi

    void retranslateUi(QWidget *Draw)
    {
        Draw->setWindowTitle(QApplication::translate("Draw", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Draw: public Ui_Draw {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DRAW_H

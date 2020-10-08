#ifndef DRAW_H
#define DRAW_H

#include <QtCharts>
QT_CHARTS_USE_NAMESPACE
#include <QWidget>
#include "chart.h"
#include "chartview.h"
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCore/QtMath>
#include <QtCore/QRandomGenerator>
#include <QtCharts/QLineSeries>
#include <QtCharts/QValueAxis>
#include "tools/dbhelper.h"

namespace Ui {
class Draw;
}

class Draw : public QWidget
{
    Q_OBJECT

public:
    explicit Draw(QWidget *parent = 0);
    ~Draw();

private slots:
    void on_temperature_btn_clicked();

    void on_heartrate_btn_clicked();

    void on_blood_btn_clicked();

private:
    Ui::Draw *ui;
};

#endif // DRAW_H

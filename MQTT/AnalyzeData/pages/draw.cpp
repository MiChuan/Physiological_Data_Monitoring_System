#include "draw.h"
#include "ui_draw.h"

Draw::Draw(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Draw)
{
    ui->setupUi(this);
    QChart* chart = new QChart();//构建一个QChart对象
    QLineSeries *series = new QLineSeries();//构建一个折线系列对象并初始化
    for (quint32 i = 0; i < 100; i++) {
        series->append(i, sin(0.6f*i));
    }
    chart->addSeries(series);
    chart->createDefaultAxes();        // 基于已添加到图表的 series 来创建默认的坐标轴
    ui->widget->setChart(chart);
}

Draw::~Draw()
{
    delete ui;
}

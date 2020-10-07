#include "draw.h"
#include "ui_draw.h"

Draw::Draw(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Draw)
{
    ui->setupUi(this);

}

Draw::~Draw()
{
    delete ui;
}

/**
 * @brief Draw::on_temperature_btn_clicked
 * 显示温度
 */
void Draw::on_temperature_btn_clicked()
{
    QSplineSeries *series = new QSplineSeries();//创建曲线系列
    series->setName("spline");
    QDateTime xValue;//添加点
    xValue.setDate(QDate::fromString("2012-01-18","yyyy-MM-dd"));
    //xValue.setDate(QDate(2012, 1 , 18));
    xValue.setTime(QTime::fromString("09:21:15","hh:mm:ss"));
    //xValue.setTime(QTime(9, 34));
    qreal yValue = 36.5;
    series->append(xValue.toMSecsSinceEpoch(), yValue);

    xValue.setDate(QDate(2013, 5 , 11));
    xValue.setTime(QTime(23, 14));
    yValue = 37.1;
    series->append(xValue.toMSecsSinceEpoch(), yValue);

    xValue.setDate(QDate(2013, 9 , 12));
    xValue.setTime(QTime(14, 14));
    yValue = 36.8;
    series->append(xValue.toMSecsSinceEpoch(), yValue);

    Chart *chart = new Chart();//创建图表对象
    chart->legend()->hide();//隐藏图例
    chart->setAnimationOptions(QChart::SeriesAnimations);//设置动画效果
    chart->addSeries(series);//添加系列到图表
    chart->setTitle("体温表");

    //chart->createDefaultAxes();//创建默认坐标轴
    QDateTimeAxis *axisX = new QDateTimeAxis;//创建日期时间坐标轴
    axisX->setTickCount(10);//刻度数
    axisX->setFormat("yyyy-MM-dd hh:mm:ss");
    axisX->setTitleText("Date");
    chart->addAxis(axisX, Qt::AlignBottom);//底部
    series->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis;
    axisY->setLabelFormat("%.1f");//输入浮点型数据
    axisY->setTitleText("体温/℃");
    chart->addAxis(axisY, Qt::AlignLeft);//左边
    series->attachAxis(axisY);

    chart->axes(Qt::Vertical).first()->setRange(36, 42);//设置值范围

    ChartView *chartView = new ChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);//设置抗锯齿
    chartView->resize(721,201);//设置大小
    chartView->setAlignment(Qt::AlignCenter);//设置居中
    chartView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);//设置滚动条
    chartView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    chartView->grabGesture(Qt::PanGesture);//捕捉鼠标动作
    chartView->grabGesture(Qt::PinchGesture);
    chartView->show();
}

/**
 * @brief Draw::on_heartrate_btn_clicked
 * 显示心率
 */
void Draw::on_heartrate_btn_clicked()
{

}

/**
 * @brief Draw::on_blood_btn_clicked
 * 显示血压
 */
void Draw::on_blood_btn_clicked()
{

}

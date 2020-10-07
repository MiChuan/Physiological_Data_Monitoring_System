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
    series->append(0, 36.5);//添加点
    series->append(2, 36.6);
    series->append(3, 36.8);
    series->append(7, 36.8);
    series->append(10, 36.5);
    *series << QPointF(11, 36.7) << QPointF(13, 36.8) <<
               QPointF(17, 36.6) << QPointF(18, 36.5) ;

    Chart *chart = new Chart();//创建图表对象
    chart->legend()->hide();//隐藏图例
    chart->setAnimationOptions(QChart::SeriesAnimations);//设置动画效果
    chart->addSeries(series);//添加系列到图表
    chart->setTitle("体温表");
    chart->createDefaultAxes();//创建默认坐标轴
    chart->axes(Qt::Vertical).first()->setRange(0, 42);//设置值范围
    chart->axes(Qt::Vertical).first()->setTitleText("体温/℃");//设置Y轴标题
    chart->axes(Qt::Horizontal).first()->setTitleText("日期时间");//设置X轴标题

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

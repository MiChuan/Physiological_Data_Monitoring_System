#include "draw.h"
#include "ui_draw.h"
#include <QDebug>
#include <QSqlQuery>

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
    qreal yValue;

    DBHelper *helper = DBHelper::getInstance();
    QSqlQuery query;
    helper->openDatabase();//链接数据库

    QString begin = ui->begin_time->text();
    QString end = ui->end_time->text();
    QString sql = QString("SELECT * FROM temperature_data WHERE savetime BETWEEN '%1' AND '%2';").arg(begin).arg(end);

    //SELECT * FROM temperature_data WHERE savetime BETWEEN '2020-10-08 16:24:27' AND '2020-10-08 16:27:17'
    query.prepare(sql);
    query.exec();
    while(query.next()){
         double temperature = query.value("temperature").toDouble();
         QString datetimetmp = query.value("savetime").toString();
         QStringList values = datetimetmp.split(QLatin1Char('T'));
         QString datetime = values[0] + " " + values[1];
         qDebug()<<datetime<<", "<<temperature<<endl;
         if(temperature > 37.3){
             ui->status->setText("发烧");
             ui->status->setStyleSheet("background-color: rgb(255, 255, 255);font-size:60px;color:red");
         } else{
             ui->status->setText("正常");
             ui->status->setStyleSheet("background-color: rgb(255, 255, 255);font-size:60px;color:green");
         }

         xValue.setDate(QDate::fromString(values[0],"yyyy-MM-dd"));//设置日期
         xValue.setTime(QTime::fromString(values[1],"hh:mm:ss"));//设置时间
         yValue = temperature;
         series->append(xValue.toMSecsSinceEpoch(), yValue);
    }

    helper->closeDatabase();//关闭数据库

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

    chart->axes(Qt::Vertical).first()->setRange(35, 42);//设置值范围

    ChartView *chartView = new ChartView(chart);
    QIcon icon(":/new/prefix1/images/体温.png");
    chartView->setWindowIcon(icon);//设置窗口图标
    chartView->setWindowTitle("体温曲线");//设置窗口标题
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
    QSplineSeries *series = new QSplineSeries();//创建曲线系列
    series->setName("spline");
    QDateTime xValue;//添加点
    qreal yValue;

    DBHelper *helper = DBHelper::getInstance();
    QSqlQuery query;
    helper->openDatabase();//链接数据库

    QString begin = ui->begin_time->text();
    QString end = ui->end_time->text();
    QString sql = QString("SELECT * FROM heartrate_data WHERE savetime BETWEEN '%1' AND '%2';").arg(begin).arg(end);

    //SELECT * FROM heartrate_data WHERE savetime BETWEEN '2020-10-08 16:24:27' AND '2020-10-08 16:27:17'
    query.prepare(sql);
    query.exec();
    while(query.next()){
         double heartrate = query.value("heartrate").toDouble();
         QString datetimetmp = query.value("savetime").toString();
         QStringList values = datetimetmp.split(QLatin1Char('T'));
         QString datetime = values[0] + " " + values[1];
         qDebug()<<datetime<<", "<<heartrate<<endl;
         if(heartrate > 100){
             ui->status->setText("过快");
             ui->status->setStyleSheet("background-color: rgb(255, 255, 255);font-size:60px;color:red");
         } else if(heartrate < 60){
             ui->status->setText("过慢");
             ui->status->setStyleSheet("background-color: rgb(255, 255, 255);font-size:60px;color:blue");
         } else{
             ui->status->setText("正常");
             ui->status->setStyleSheet("background-color: rgb(255, 255, 255);font-size:60px;color:green");
         }

         xValue.setDate(QDate::fromString(values[0],"yyyy-MM-dd"));//设置日期
         xValue.setTime(QTime::fromString(values[1],"hh:mm:ss"));//设置时间
         yValue = heartrate;
         series->append(xValue.toMSecsSinceEpoch(), yValue);
    }

    helper->closeDatabase();//关闭数据库

    Chart *chart = new Chart();//创建图表对象
    chart->legend()->hide();//隐藏图例
    chart->setAnimationOptions(QChart::SeriesAnimations);//设置动画效果
    chart->addSeries(series);//添加系列到图表
    chart->setTitle("心率表");

    //chart->createDefaultAxes();//创建默认坐标轴
    QDateTimeAxis *axisX = new QDateTimeAxis;//创建日期时间坐标轴
    axisX->setTickCount(10);//刻度数
    axisX->setFormat("yyyy-MM-dd hh:mm:ss");
    axisX->setTitleText("Date");
    chart->addAxis(axisX, Qt::AlignBottom);//底部
    series->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis;
    axisY->setLabelFormat("%f");//输入浮点型数据
    axisY->setTitleText("心率(次/分)");
    chart->addAxis(axisY, Qt::AlignLeft);//左边
    series->attachAxis(axisY);

    chart->axes(Qt::Vertical).first()->setRange(30, 160);//设置值范围

    ChartView *chartView = new ChartView(chart);
    QIcon icon(":/new/prefix1/images/i-心率.png");
    chartView->setWindowIcon(icon);//设置窗口图标
    chartView->setWindowTitle("心率曲线");//设置窗口标题
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
 * @brief Draw::on_blood_btn_clicked
 * 显示血压
 */
void Draw::on_blood_btn_clicked()
{

}

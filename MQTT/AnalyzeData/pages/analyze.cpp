#include "analyze.h"
#include "ui_analyze.h"
#include <QSqlQuery>
#include <QModelIndex>
#include <QDebug>
#include <QString>
#include <QMessageBox>
#include "timeeditdelegate.h"

Analyze::Analyze(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Analyze)
{
    ui->setupUi(this);
    model = new QSqlQueryModel(ui->viewData);/**将数据模型与QTableView绑定**/
    ui->viewData->setEditTriggers(QAbstractItemView::NoEditTriggers);//只读
    ui->viewData->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//列宽等宽自适应
}

Analyze::~Analyze()
{
    delete ui;
}

void Analyze::on_analyze_btn_clicked()
{
    DBHelper *helper = DBHelper::getInstance();
    QSqlQuery query;
    helper->openDatabase();//链接数据库

    QString tips = "发烧时间:\n";
    QString sql = "SELECT * FROM temperature_data WHERE temperature > 37.3;";
    query.prepare(sql);
    query.exec();
    while(query.next()){
        double temperature = query.value("temperature").toDouble();
        QString datetimetmp = query.value("savetime").toString();
        QStringList values = datetimetmp.split(QLatin1Char('T'));
        QString datetime = values[0] + " " + values[1];
        qDebug()<<datetime<<", "<<temperature<<endl;
        tips = tips + " " + datetime + "\n";
    }

    tips = tips + " " + "心率过快时间:" + "\n";
    sql = "SELECT * FROM heartrate_data WHERE heartrate > 100;";
    query.prepare(sql);
    query.exec();
    while(query.next()){
        double heartrate = query.value("heartrate").toDouble();
        QString datetimetmp = query.value("savetime").toString();
        QStringList values = datetimetmp.split(QLatin1Char('T'));
        QString datetime = values[0] + " " + values[1];
        qDebug()<<datetime<<", "<<heartrate<<endl;
        tips = tips + " " + datetime + "\n";
    }
    tips = tips + " " + "心率过慢时间:" + "\n";
    sql = "SELECT * FROM heartrate_data WHERE heartrate < 60;";
    query.prepare(sql);
    query.exec();
    while(query.next()){
        double heartrate = query.value("heartrate").toDouble();
        QString datetimetmp = query.value("savetime").toString();
        QStringList values = datetimetmp.split(QLatin1Char('T'));
        QString datetime = values[0] + " " + values[1];
        qDebug()<<datetime<<", "<<heartrate<<endl;
        tips = tips + datetime + "\n";
    }

    tips = tips + " " + "高血压时间:" + "\n";
    sql = "SELECT * FROM bloodpressure_data WHERE SBP > 140 OR DBP > 90;";
    query.prepare(sql);
    query.exec();
    while(query.next()){
        double SBP = query.value("SBP").toDouble();
        double DBP = query.value("DBP").toDouble();
        QString datetimetmp = query.value("savetime").toString();
        QStringList values = datetimetmp.split(QLatin1Char('T'));
        QString datetime = values[0] + " " + values[1];
        qDebug()<<datetime<<", "<<SBP<<", "<<DBP<<endl;
        tips = tips + " " + datetime + "\n";
    }

    helper->closeDatabase();//关闭数据库

    ui->analyzeResult->setText(tips);
}

void Analyze::on_temp_btn_clicked()
{
    DBHelper *helper =  DBHelper::getInstance();
    helper->openDatabase();

    QSqlQuery query;
    bool ret = query.exec("select * from temperature_data;");
    while(query.next()){
        qDebug() << query.value(0).toString() << "|"
                 << query.value(1).toString();
    }
    if(ret){
        qDebug()<<"select from temperature_data success";
    } else {
        qDebug()<<query.lastError().text();
    }

    ui->viewData->setItemDelegateForColumn(0, new TimeEditDelegate("yyyy-MM-dd hh:mm:ss"));//设置日期格式
    model->setQuery("select savetime as '采集时间',"
                    "temperature as '体温'"
                    " from temperature_data;");
    ui->viewData->setModel(model);
}

void Analyze::on_heart_btn_clicked()
{
    DBHelper *helper =  DBHelper::getInstance();
    helper->openDatabase();

    QSqlQuery query;
    bool ret = query.exec("select * from heartrate_data;");
    while(query.next()){
        qDebug() << query.value(0).toString() << "|"
                 << query.value(1).toString();
    }
    if(ret){
        qDebug()<<"select from heartrate_data success";
    } else {
        qDebug()<<query.lastError().text();
    }

    ui->viewData->setItemDelegateForColumn(0, new TimeEditDelegate("yyyy-MM-dd hh:mm:ss"));//设置日期格式
    model->setQuery("select savetime as '采集时间',"
                    "heartrate as '心率'"
                    " from heartrate_data;");
    ui->viewData->setModel(model);
}

void Analyze::on_blood_btn_clicked()
{
    DBHelper *helper =  DBHelper::getInstance();
    helper->openDatabase();

    QSqlQuery query;
    bool ret = query.exec("select * from bloodpressure_data;");
    while(query.next()){
        qDebug() << query.value(0).toString() << "|"
                 << query.value(1).toString() << "|"
                 << query.value(2).toString();
    }
    if(ret){
        qDebug()<<"select from bloodpressure_data success";
    } else {
        qDebug()<<query.lastError().text();
    }
    ui->viewData->setItemDelegateForColumn(0, new TimeEditDelegate("yyyy-MM-dd hh:mm:ss"));//设置日期格式
    model->setQuery("select savetime as '采集时间',"
                    "SBP as '收缩压',"
                    "DBP as '舒张压'"
                    " from bloodpressure_data;");
    ui->viewData->setModel(model);
}

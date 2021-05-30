/**
 * Author:huhan
 * Email:huhan_h@163.com
 * GitHub:https://github.com/MiChuan
 */
#include "analyze.h"
#include "ui_analyze.h"
#include <QSqlQuery>
#include <QModelIndex>
#include <QDebug>
#include <QString>
#include <QMessageBox>
#include <QDateTime>
#include "timeeditdelegate.h"
#include "tools/zsmtp.h"

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
    bool SendEmailFlag = false;
    bool IsFever = false;
    bool IsQuick = false;
    bool IsSLow = false;
    bool IsHigh = false;
    helper->openDatabase();//链接数据库

    QString tips = "发烧时间:\n";
    QString sql = "SELECT * FROM temperature_data WHERE temperature > 37.3;";
    query.prepare(sql);
    query.exec();
    while(query.next()){
        SendEmailFlag = true;
        IsFever = true;
        double temperature = query.value("temperature").toDouble();
        QString datetimetmp = query.value("savetime").toString();
        QStringList values = datetimetmp.split(QLatin1Char('T'));
        QString datetime = values[0] + " " + values[1];
        qDebug()<<datetime<<", "<<temperature<<endl;
        tips = tips + " " + datetime + "\n";
    }
    if(IsFever == true){
        tips = tips + "健康建议:\n"
               "1.利用湿抹布和酒精擦拭额头和手臂降温。\n"
               "2.在医生的指导下吃一些退烧药和消炎药。\n"
               "3.多喝热水，增加自身酶的活性，更好的杀毒。\n";
    }

    tips = tips + " " + "\n心率过快时间:" + "\n";
    sql = "SELECT * FROM heartrate_data WHERE heartrate > 100;";
    query.prepare(sql);
    query.exec();
    int count = 0;
    while(query.next()){
        SendEmailFlag = true;
        IsQuick = true;
        ++count;
        double heartrate = query.value("heartrate").toDouble();
        QString datetimetmp = query.value("savetime").toString();
        QStringList values = datetimetmp.split(QLatin1Char('T'));
        QString datetime = values[0] + " " + values[1];
        qDebug()<<datetime<<", "<<heartrate<<endl;
        tips = tips + " " + datetime + "\n";
    }
    if(IsQuick == true){
        if(count > 5) tips = tips + "健康建议:\n"
                      "心率长时间过速，可能有病理性问题，请及时就医。\n";
    }
    tips = tips + " " + "\n心率过慢时间:" + "\n";
    sql = "SELECT * FROM heartrate_data WHERE heartrate < 60;";
    query.prepare(sql);
    query.exec();
    count = 0;
    while(query.next()){
        SendEmailFlag = true;
        IsSLow = true;
        ++count;
        double heartrate = query.value("heartrate").toDouble();
        QString datetimetmp = query.value("savetime").toString();
        QStringList values = datetimetmp.split(QLatin1Char('T'));
        QString datetime = values[0] + " " + values[1];
        qDebug()<<datetime<<", "<<heartrate<<endl;
        tips = tips + datetime + "\n";
    }
    if(IsSLow == true){
        if(count > 5) tips = tips + "健康建议:\n"
                      "心率长时间过慢，可能有病理性问题，请及时就医。\n";
    }

    tips = tips + " " + "\n高血压时间:" + "\n";
    sql = "SELECT * FROM bloodpressure_data WHERE SBP > 140 OR DBP > 90;";
    query.prepare(sql);
    query.exec();
    while(query.next()){
        SendEmailFlag = true;
        IsHigh = true;
        double SBP = query.value("SBP").toDouble();
        double DBP = query.value("DBP").toDouble();
        QString datetimetmp = query.value("savetime").toString();
        QStringList values = datetimetmp.split(QLatin1Char('T'));
        QString datetime = values[0] + " " + values[1];
        qDebug()<<datetime<<", "<<SBP<<", "<<DBP<<endl;
        tips = tips + " " + datetime + "\n";
    }
    if(IsHigh == true){
        tips = tips + "健康建议:\n"
                      "1.注意防暑降温，多食用蔬菜水果，上火了要喝凉茶降火。\n"
                      "2.坚持进行锻炼，锻炼不要过度，选择适合自己的运动。\n"
                      "3.注意每天适量饮食，每餐不要吃得过饱。\n"
                      "4.限制食用盐的用量，日常还需要注意多喝点水。\n";
    }

    helper->closeDatabase();//关闭数据库

    ui->analyzeResult->setText(tips);
    if(SendEmailFlag == true){//查询到异常数据，发送邮件
        QDateTime current_date_time =QDateTime::currentDateTime();
        QString current_date = current_date_time.toString("yyyy.MM.dd hh:mm:ss ddd");
        QString Subject = current_date + " 分析异常数据";
        ZSmtp *smtp = new ZSmtp;//创建邮件发送对象
        connect(smtp, SIGNAL(disconnected()), smtp, SLOT(deleteLater()));	//发送完毕自行销毁
        //smtp->sendEmail("huhan_h@163.com", "邮箱SMTP服务授权码", "huhan_h@163.com", Subject, tips);
        smtp->sendEmail("huhan_h@163.com", "邮箱SMTP服务授权码", "huhan_h@qq.com", Subject, tips);
    }
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

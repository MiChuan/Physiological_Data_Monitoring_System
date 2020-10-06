#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->testConnection();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::testConnection()
{
    DBHelper *helper = DBHelper::getInstance();
    QSqlQuery query;
    helper->openDatabase();//链接数据库

    query.prepare("select * from test;");
    query.exec();
    while(query.next()){
         QString id = query.value("mytest").toString();
         QString value = query.value("myvalue").toString();
         QString datetime = query.value("mydatetime").toString();
         qDebug()<<id<<", "<<value<<", "<<datetime;
    }
    helper->closeDatabase();
}


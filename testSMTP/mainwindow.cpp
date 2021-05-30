/**
 * Author:huhan
 * Email:huhan_h@163.com
 * GitHub:https://github.com/MiChuan
 */
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "zsmtp.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ZSmtp *smtp = new ZSmtp;//默认是qq邮箱服务器，想用别的服务器就 new ZSmtp(Smtp服务器地址)
    connect(smtp, SIGNAL(disconnected()), smtp, SLOT(deleteLater()));	//发送完毕自行销毁
    smtp->sendEmail("发送邮箱号", "邮箱SMTP服务授权码", "接收邮箱号", "标题", "内容");
}

MainWindow::~MainWindow()
{
    delete ui;
}

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QHBoxLayout>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(this->width(), this->height()); //禁止拖动窗口
    this->setWindowFlags(windowFlags()&~Qt::WindowMaximizeButtonHint); // 禁止最大化按钮
    this->handConnect();
}

MainWindow::~MainWindow()
{
    delete ui;
}

/**
 * @brief MainWindow::handConnect
 * 连接槽函数
 */
void MainWindow::handConnect()
{
    connect(ui->about,SIGNAL(triggered(bool)),this,SLOT(About()));
}

//窗口关闭响应事件
void MainWindow::closeEvent(QCloseEvent *event)
{
    QMessageBox message;
    message.setStandardButtons(QMessageBox::Yes|QMessageBox::No);
    message.setWindowTitle(tr("温馨提示"));
    message.setIcon(QMessageBox::Warning);
    message.setText(tr("您确定要退出吗？"));
    if (message.exec()==QMessageBox::Yes)
    {
        //DB_Close();
    }
    else
    {
        event->ignore();
    }
}

/**
 * @brief MainWindow::About
 * 关于按钮点击事件
 */
void MainWindow::About()
{
    QString text = tr("软件版本:%1\r\n作者:%2\r\n描述:%3")
            .arg(CURRENT_VERSION)
            .arg(tr("huhan_h@163.com"))
            .arg(tr("基于MQTT通信协议，利用MySQL进行数据保存，利用Qt Charts进行数据分析的生理数据监测系统"));
    QMessageBox::information(this,tr("帮助"),text,QMessageBox::Yes);
}

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
    ui->logout->setDisabled(true);//未登陆禁用退出功能
    ui->stackedWidget->setCurrentIndex(0);

    this->IsLogin = false;

    this->handConnect();
    this->addWidgets();
}

MainWindow::~MainWindow()
{
    delete ui;
}

/**
 * @brief MainWindow::addWidgets
 * 添加子页面
 */
void MainWindow::addWidgets()
{
    Welcome *welcome = new Welcome(this);
    ui->stackedWidget->addWidget(welcome);//0

}

/**
 * @brief MainWindow::handConnect
 * 连接槽函数
 */
void MainWindow::handConnect()
{
    connect(ui->about,SIGNAL(triggered(bool)),this,SLOT(About()));
    connect(ui->login,SIGNAL(triggered(bool)),this,SLOT(LoginSys()));
    connect(ui->logout,SIGNAL(triggered(bool)),this,SLOT(ExitSys()));
    connect(ui->mainpage,SIGNAL(triggered(bool)),this,SLOT(viewMainPage()));
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
 * @brief MainWindow::CheckLogin
 * @return 如果已经登陆返回ture,否则false
 * 监测是否登陆
 */
bool MainWindow::CheckLogin()
{
    if(!IsLogin)
        QMessageBox::warning(this,tr("提示"),tr("您尚未登录，无权操作，请先登录！"),QMessageBox::Yes);
    return IsLogin;
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

/**
 * @brief MainWindow::LoginSys
 *登陆按钮点击事件
 */
void MainWindow::LoginSys()
{
    login *loginpage = new login(this,&IsLogin);
    loginpage->setWindowTitle("用户登录");
    //loginpage->show();
    loginpage->exec();
    if(this->IsLogin == true)
    {
        ui->statusBar->showMessage(tr("登录成功"));
        ui->login->setDisabled(true);
        ui->logout->setEnabled(true);
    }
    else
    {
        ui->statusBar->showMessage(tr("登录失败"));
    }
    delete loginpage;
}

/**
 * @brief MainWindow::ExitSys
 * 退出按钮点击事件
 */
void MainWindow::ExitSys()
{
    this->IsLogin = false;
    ui->login->setEnabled(true);
    ui->logout->setDisabled(true);
    ui->statusBar->showMessage(tr("退出登录"));
    ui->stackedWidget->setCurrentIndex(0);
}

/**
 * @brief MainWindow::viewMainPage
 * 显示welcome页面
 */
void MainWindow::viewMainPage()
{
    ui->stackedWidget->setCurrentIndex(0);
    ui->statusBar->showMessage("返回到主页");
}

#include "login.h"
#include "ui_login.h"
#include <QMessageBox>

login::login(QWidget *parent,bool *IsLogin) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    this->setFixedSize(this->width(), this->height()); //禁止拖动窗口
    this->setWindowFlags(windowFlags()&~Qt::WindowMaximizeButtonHint); // 禁止最大化按钮
    ui->password->setEchoMode(QLineEdit::Password);//密码输入框设置
    QWidget::setTabOrder(ui->username, ui->password);
    QWidget::setTabOrder(ui->password, ui->login_btn);
    this->LogStatus = IsLogin;
    this->user = account->readConfig("/account/first_account");
    this->pwd = account->readConfig("/password/first_password");
    //this->user = "huhan";
    //this->pwd = "123456";
}

login::~login()
{
    delete ui;
}

/**
 * @brief login::on_login_btn_clicked
 * 登陆按钮点击事件
 */
void login::on_login_btn_clicked()
{
    /*用户名密码不为空*/
    if(ui->username->text().isEmpty()){
        QMessageBox::critical(this,"警告","请输入用户名后再登录");
        return;
    }
    if(ui->password->text().isEmpty()){
        QMessageBox::critical(this,"警告","请输入密码后再登录");
        return;
    }
    QString inputName = ui->username->text();
    QString inputPwd = account->GetMD5String(ui->password->text());

    /*用户存在*/
    if(inputName != this->user){
        QMessageBox::critical(this,"警告","用户不存在");
        return;
    }

    /*检查密码*/
    if(inputPwd != this->pwd){
         QMessageBox::critical(this,"警告","密码错误");
         return;
    }

    *(this->LogStatus) = true;
    //this->hide();
    this->close();
    return;
}

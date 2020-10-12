#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include "tools/useraccount.h"

namespace Ui {
class login;
}

class login : public QDialog
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = 0,bool *IsLogin = nullptr);
    ~login();

private slots:
    void on_login_btn_clicked();

private:
    Ui::login *ui;
    QString user;
    QString pwd;
    bool *LogStatus;
    userAccount *account = new userAccount();
};

#endif // LOGIN_H

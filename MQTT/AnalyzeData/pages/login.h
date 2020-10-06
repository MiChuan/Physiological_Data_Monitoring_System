#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>

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
    QString user = "huhan";
    QString pwd = "123456";
    bool *LogStatus;
};

#endif // LOGIN_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCloseEvent>
#include <QLabel>
#include <QDebug>

#define CURRENT_VERSION "基于MQTT的生理数据监测系统 V1.0"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void handConnect();//信号插槽连接

private slots:
    void About(); //关于

protected:
    void closeEvent(QCloseEvent *event); //窗口关闭时调用

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

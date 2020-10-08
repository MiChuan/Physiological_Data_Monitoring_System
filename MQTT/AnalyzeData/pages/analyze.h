#ifndef ANALYZE_H
#define ANALYZE_H

#include <QWidget>
#include <QDialog>
#include <QStandardItemModel>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QHeaderView>
#include <QThread>
#include <QDateTime>
#include <QTimer>
#include "tools/dbhelper.h"

namespace Ui {
class Analyze;
}

class Analyze : public QWidget
{
    Q_OBJECT

public:
    explicit Analyze(QWidget *parent = 0);
    ~Analyze();

private slots:
    void on_analyze_btn_clicked();

    void on_temp_btn_clicked();

    void on_heart_btn_clicked();

    void on_blood_btn_clicked();

private:
    Ui::Analyze *ui;
    QSqlQueryModel *model;
};

#endif // ANALYZE_H

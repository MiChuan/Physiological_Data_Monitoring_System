#ifndef DRAW_H
#define DRAW_H

#include <QtCharts>
QT_CHARTS_USE_NAMESPACE
#include <QWidget>

namespace Ui {
class Draw;
}

class Draw : public QWidget
{
    Q_OBJECT

public:
    explicit Draw(QWidget *parent = 0);
    ~Draw();

private:
    Ui::Draw *ui;
};

#endif // DRAW_H

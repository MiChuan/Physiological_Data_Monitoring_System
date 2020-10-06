#ifndef ANALYZE_H
#define ANALYZE_H

#include <QWidget>

namespace Ui {
class Analyze;
}

class Analyze : public QWidget
{
    Q_OBJECT

public:
    explicit Analyze(QWidget *parent = 0);
    ~Analyze();

private:
    Ui::Analyze *ui;
};

#endif // ANALYZE_H

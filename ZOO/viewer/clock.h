#ifndef CLOCK_H
#define CLOCK_H

#include <QWidget>
#include <QLabel>
#include <QTime>
#include <QVBoxLayout>
#include <QTimer>
#include <QFont>

class DigitalClock : public QWidget
{
    Q_OBJECT

public:
    DigitalClock(QWidget *parent = nullptr);

private slots:
    void addTime();

private:
    QLabel *label;
    QTime time;
};

#endif
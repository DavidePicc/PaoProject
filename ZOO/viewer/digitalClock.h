#ifndef DIGITALCLOCK_H
#define DIGITALCLOCK_H

#include <QWidget>
#include <QLabel>
#include <QTime>
#include <QVBoxLayout>
#include <QTimer>
#include <QFont>

#include "../src/clock.h"

class DigitalClock : public QWidget
{
    Q_OBJECT

public:
    DigitalClock(QWidget *parent = nullptr);
    QString getTime() const;
    void setTime(const QTime& newTime);

private slots:
    void updateDisplay();

private:
    QLabel *label;
    Clock clock;
};

#endif
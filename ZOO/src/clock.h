#ifndef CLOCK_H
#define CLOCK_H

#include <QTime>

class Clock {
public:
    Clock();
    Clock(int h, int m);
    void addTime();
    QString getTimeString() const;

private:
    QTime time;
};

#endif

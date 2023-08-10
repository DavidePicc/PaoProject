#ifndef CLOCK_H
#define CLOCK_H

#include <QTime>

class Clock {
public:
    Clock();
    void addTime();
    QString getTimeString() const;

private:
    QTime time;
};

#endif

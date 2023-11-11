#ifndef CLOCK_H
#define CLOCK_H

#include <QDateTime>

class Clock {
public:
    Clock();
    Clock(const QDateTime& newDateTime);
    void addTime();
    QString getDateTimeString() const;
    void setDateTime(const QDateTime& newDateTime);

private:
    QDateTime dateTime;
};

#endif
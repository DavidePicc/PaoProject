#include "clock.h"

Clock::Clock() : dateTime(QDateTime::currentDateTime()) {}

Clock::Clock(const QDateTime& newDateTime) : dateTime(newDateTime) {}

void Clock::addTime() {
    dateTime = dateTime.addSecs(120);
}

QString Clock::getDateTimeString() const {
    return dateTime.toString("dd - MM - yyyy  hh:mm");
}

void Clock::setDateTime(const QDateTime& newDateTime) {
    dateTime = newDateTime;
}
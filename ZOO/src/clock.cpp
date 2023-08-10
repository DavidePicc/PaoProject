#include "clock.h"

Clock::Clock() : time(QTime(7, 0)) {}

void Clock::addTime() {
    time = time.addSecs(120);
}

QString Clock::getTimeString() const {
    return time.toString("hh:mm");
}
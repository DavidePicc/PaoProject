#include "digitalClock.h"

DigitalClock::DigitalClock(QWidget *parent) : QWidget(parent){
    label = new QLabel(this);

    QFont font;
    font.setBold(true);
    label->setFont(font);
    label->setStyleSheet("QLabel { color : black; font-size : 24px; border: 1px solid black; border-radius: 10px; background-color: rgba(0, 0, 0, 50);}");
    label->setAlignment(Qt::AlignCenter);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(label);
    setLayout(layout);

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateDisplay()));
    timer->start(1000);  // Aggiorna ogni secondo

    updateDisplay();  // Aggiorna subito l'orologio all'avvio

    setWindowTitle("Digital Clock");
    resize(280, 60);

    this->move(600, 30);
}

QString DigitalClock::getTime() const{
    return clock.getDateTimeString();
}

void DigitalClock::updateDisplay(){
    clock.addTime();
    QString text = clock.getDateTimeString();
    label->setText(text);
}

void DigitalClock::setTime(const QDateTime& newDateTime){
    clock.setDateTime(newDateTime);
}
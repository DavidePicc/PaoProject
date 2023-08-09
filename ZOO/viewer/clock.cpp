#include "clock.h"

DigitalClock::DigitalClock(QWidget *parent, int h, int min) : QWidget(parent), time(QTime(h, min)), paused(0) //L'orario parte dalle 7:00 grazie all'ultimo parametro
{
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
    connect(timer, SIGNAL(timeout()), this, SLOT(addTime()));
    timer->start(1000);

    addTime();

    setWindowTitle("Digital Clock");
    resize(150, 60); // Potrebbe essere necessario regolare la dimensione in base al tuo font

    this->move(600, 25);
}


void DigitalClock::setPausa(bool val){
    paused = val;
}

void DigitalClock::setTime(int h, int min) {
    time = QTime(h, min);
}

int DigitalClock::getH() const{
    return time.hour();
}

int DigitalClock::getMin() const{
    return time.minute();
}


void DigitalClock::addTime()
{
    if(!paused){
        time = time.addSecs(120); //Aggiungo al gioco 120 secondi ogni secondo reale cosìcchè il tempo sia più fluido
        QString text = time.toString("hh:mm");
        label->setText(text);
    }
}


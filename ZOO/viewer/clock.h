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
    DigitalClock(QWidget *parent = nullptr, int h=7, int min=0);
    void setPausa(bool val);
    void setTime(int h, int min);
    int getH() const;
    int getMin() const;

private slots:
    void addTime();

private:
    QLabel *label;
    QTime time;
    bool paused; //Se = 1 il timer si ferma -> usato per pausa
};

#endif

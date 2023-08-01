#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPixmap>
#include <QScreen>
#include <QGuiApplication>
#include <QPushButton>
#include "clock.h"


class GameWidget : public QWidget {
    Q_OBJECT

public:
    GameWidget(QWidget *parent = nullptr);
    QPushButton* createButton(int x, int y);
};

#endif // GAMEWIDGET_H
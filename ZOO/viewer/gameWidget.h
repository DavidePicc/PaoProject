#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPixmap>
#include <QScreen>
#include <QGuiApplication>
#include <QPushButton>
#include <QDialog>
#include <QListWidget>
#include <QListWidgetItem>
#include <QHBoxLayout>

#include "clock.h"
#include "../src/Animal.h"
#include "../src/Coccodrillo.h"
#include "../src/Giraffa.h"
#include "../src/Leone.h"
#include "../src/Pavone.h"
#include "../src/Struzzo.h"
#include "../src/Tartaruga.h"


class GameWidget : public QWidget {
    Q_OBJECT

public:
    GameWidget(QWidget *parent = nullptr);
    QPushButton* createButton(int x, int y);

public slots:
    void chooseAnimal();
    void handleItemClicked(QListWidgetItem *item);

private:
    Animal* animal;
};


#endif // GAMEWIDGET_H
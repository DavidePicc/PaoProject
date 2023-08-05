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
#include <QProgressBar>
#include <QScrollArea>

#include "clock.h"
#include "../src/Animal.h"
#include "../src/Coccodrillo.h"
#include "../src/Giraffa.h"
#include "../src/Leone.h"
#include "../src/Pavone.h"
#include "../src/Struzzo.h"
#include "../src/Tartaruga.h"
#include "../src/Container.h"


class GameWidget : public QWidget {
    Q_OBJECT
private:
    //Variabili di gioco: soldi e recinti
    unsigned int soldi;
    DLrecinto<Leone> leoni;
    DLrecinto<Coccodrillo> coccodrilli;
    DLrecinto<Pavone> pavoni;
    DLrecinto<Tartaruga> tartarughe;
    DLrecinto<Struzzo> struzzi;
    DLrecinto<Giraffa> giraffe;

public:
    GameWidget(QWidget *parent = nullptr);

    template <typename T>
    QPushButton* createButton(int x, int y, std::string animale, DLrecinto<T>& recinto);

    template <typename T>
    void seeAnimals(const DLrecinto<T>& recinto,  QProgressBar* healthBar);

public slots:
    void animalDetails(Animal& a);
    void addAnimal();
    void giveFood(QProgressBar* healthBar);

};


#endif // GAMEWIDGET_H

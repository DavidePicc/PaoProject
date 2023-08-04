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

    // definizione di seeAnimals come un metodo template all'interno della classe
    template <typename T>
    void seeAnimals(const DLrecinto<T>& recinto);

public slots:
    //void addAnimal();
    //void giveFood();

};


#endif // GAMEWIDGET_H
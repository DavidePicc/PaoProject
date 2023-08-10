#ifndef GAMEMODEL_H
#define GAMEMODEL_H

#include "../src/Animal.h"
#include "../src/Coccodrillo.h"
#include "../src/Giraffa.h"
#include "../src/Leone.h"
#include "../src/Pavone.h"
#include "../src/Struzzo.h"
#include "../src/Tartaruga.h"
#include "../src/Container.h"
#include "clock.h"

class GameModel {
private:
    unsigned int soldi;
    //Clock clock;
    DLrecinto leoni;
    DLrecinto coccodrilli;
    DLrecinto pavoni;
    DLrecinto tartarughe;
    DLrecinto struzzi;
    DLrecinto giraffe;

public:
    GameModel();
    unsigned int getSoldi() const;
    DLrecinto& getLeoni();
    DLrecinto& getCoccodrilli();
    DLrecinto& getPavoni();
    DLrecinto& getTartarughe();
    DLrecinto& getStruzzi();
    DLrecinto& getGiraffe();
    void addAnimal(DLrecinto& recinto);
    void giveFood(DLrecinto& recinto, unsigned int perc);
    bool enoughMoney(DLrecinto& recinto, unsigned int perc);
    void updateSoldi();
};

#endif 
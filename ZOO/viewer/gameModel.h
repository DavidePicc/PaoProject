#ifndef GAMEMODEL_H
#define GAMEMODEL_H

#include "../src/Animal.h"
#include "../dataManager/dataManager.h"


class GameModel {
private:
    unsigned int soldi;
    DLrecinto leoni;
    DLrecinto coccodrilli;
    DLrecinto pavoni;
    DLrecinto tartarughe;
    DLrecinto struzzi;
    DLrecinto giraffe;

public:
    GameModel();
    void setSoldi(unsigned int i);
    unsigned int getSoldi() const;
    DLrecinto& getLeoni();
    DLrecinto& getCoccodrilli();
    DLrecinto& getPavoni();
    DLrecinto& getTartarughe();
    DLrecinto& getStruzzi();
    DLrecinto& getGiraffe();
    void addAnimal(DLrecinto& recinto);
    void addAnimal(DLrecinto& recinto, std::shared_ptr<Animal> a);
    void giveFood(DLrecinto& recinto, unsigned int perc);
    bool enoughMoney(DLrecinto& recinto, unsigned int perc);
    void updateSoldi();

};

#endif 
#include "../dataManager/dataManager.h"
#include "gameModel.h"

GameModel::GameModel() : soldi(100) {}

void GameModel::setSoldi(unsigned int i){
    soldi = i;
}

unsigned int GameModel::getSoldi() const {
    return soldi;
}

DLrecinto& GameModel::getLeoni() {
    return leoni;
}

DLrecinto& GameModel::getCoccodrilli() {
    return coccodrilli;
}

DLrecinto& GameModel::getPavoni() {
    return pavoni;
}

DLrecinto& GameModel::getTartarughe() {
    return tartarughe;
}

DLrecinto& GameModel::getStruzzi() {
    return struzzi;
}

DLrecinto& GameModel::getGiraffe() {
    return giraffe;
}

void GameModel::addAnimal(DLrecinto& recinto) {
    std::shared_ptr<Animal> a;
    unsigned int sizeRecinto = recinto.getSize();

    if (&recinto == &leoni)
        a = std::make_shared<Leone>(sizeRecinto);
    else if (&recinto == &coccodrilli)
        a = std::make_shared<Coccodrillo>(sizeRecinto);
    else if (&recinto == &pavoni)
        a = std::make_shared<Pavone>(sizeRecinto);
    else if (&recinto == &tartarughe)
        a = std::make_shared<Tartaruga>(sizeRecinto);
    else if (&recinto == &struzzi)
        a = std::make_shared<Struzzo>(sizeRecinto);
    else if (&recinto == &giraffe)
        a = std::make_shared<Giraffa>(sizeRecinto);
    else
        throw("Errore 1\n");

    recinto.insert(a);
    soldi -= (*a).getCosto();
}

void GameModel::addAnimal(DLrecinto& recinto, std::shared_ptr<Animal> a) {
    recinto.insert(a);
}

void GameModel::giveFood(DLrecinto& recinto, unsigned int perc) {
    soldi -= recinto.moneyTo(perc);
    recinto.setVita(perc);
}

bool GameModel::enoughMoney(DLrecinto& recinto, unsigned int perc){
    return getSoldi() < recinto.moneyTo(perc) || recinto.getVita() >= perc ? 1 : 0;
}

void GameModel::updateSoldi() {
    soldi += (leoni.makeMoney()+ leoni.makeMoney() +  coccodrilli.makeMoney() + pavoni.makeMoney() + tartarughe.makeMoney() + struzzi.makeMoney() + giraffe.makeMoney())/20;
}
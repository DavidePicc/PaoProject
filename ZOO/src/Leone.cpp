#include "Leone.h"

/*Coccodrillo::Coccodrillo(int eta, const char sesso, float peso, std::string cibo, float lunghezza, int numero_denti)
    : Animal(setNome(), setDescrizione(), eta, sesso, peso, new Carnivoro(cibo)), lunghezza(lunghezza), numero_denti(numero_denti) {}*/

Leone::Leone(int eta, const char sesso, float peso, std::string cibo, int rug, bool crin)
        :Animal(setNome(), setDescrizione(), eta, sesso, peso, new Carnivoro(cibo)), ruggito(rug), criniera(crin){}


std::string Leone::emettereVerso() const {
        return "Ruggito!";
}

const std::string Leone::setNome(){
    static unsigned int num = 1;
    return "Leone " + std::to_string(num);
}

std::string Leone::setDescrizione(){
    return "Il leone è un possente felino appartenente alla famiglia dei leoni e noto come il re della giungla. È uno dei più grandi carnivori terrestri esistenti e si distingue per la sua possente struttura fisica, la criniera caratteristica e l'imponente presenza.";
}
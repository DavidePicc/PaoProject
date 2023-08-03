#include "Leone.h"
#include "generate.h"

Leone::Leone()
    : Animal(setNome(), setDescrizione(), comodo::generaNumeroCasuale(5, 20), comodo::setSesso(), comodo::generaNumeroCasuale(130, 180), new Carnivoro("Carne")), ruggito(comodo::generaNumeroCasuale(50, 110)), criniera(comodo::generaNumeroCasuale(0, 1) == 1 ? 1 : 0) {}

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
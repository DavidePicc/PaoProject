#include <iostream>
#include "Pavone.h"



Pavone::Pavone(int eta, const char sesso, float peso, std::string cibo, float raggioRuota)
    : Animal(setNome(), setDescrizione(), eta, sesso, peso, new Carnivoro(cibo)), raggioRuota(raggioRuota) {}
    

std::string Pavone::emettereVerso() const{
    return "eeee-ow!\n";
}

const std::string setNome(){
    static unsigned int num;
    return "Pavone " + std::to_string(num);
}

static std::string setDescrizione(){
    return "l pavone reale o pavone blu, anche noto come pavone indiano, è un uccello appartenente alla famiglia dei Fasianidi.";
}

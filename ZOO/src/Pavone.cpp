#include <iostream>
#include "Pavone.h"
#include "generate.h"

Pavone::Pavone()
    :Animal(setNome(), setDescrizione(), comodo::generaNumeroCasuale(5, 15), comodo::setSesso(), comodo::generaNumeroCasuale(3, 6), new Onnivoro("Frutta")), raggioRuota(sesso=='M' ? comodo::generaNumeroCasuale(30, 150) : 0) {}

Pavone::Pavone(int eta, const char sesso, float peso, std::string cibo, float raggioRuota)
    : Animal(setNome(), setDescrizione(), eta, sesso, peso, new Carnivoro(cibo)), raggioRuota(raggioRuota) {}
    

std::string Pavone::emettereVerso() const{
    return "eeee-ow!\n";
}

const std::string Pavone::setNome(){
    static unsigned int num = 1;
    return "Pavone " + std::to_string(num);
}

std::string Pavone::setDescrizione(){
    return "Il pavone reale o pavone blu, anche noto come pavone indiano, è un uccello appartenente alla famiglia dei Fasianidi.";
}

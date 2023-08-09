#include <iostream>
#include "Pavone.h"
#include "generate.h"

Pavone::Pavone()
    :Animal(setNome(), setDescrizione(), comodo::generaNumeroCasuale(5, 15), comodo::setSesso(), comodo::generaNumeroCasuale(3, 6), new Onnivoro("Frutta"), 2), raggioRuota(sesso=='M' ? comodo::generaNumeroCasuale(30, 150) : 0) {}   

Pavone::Pavone(const std::string& name, std::string description, int age, const char sex, float weight, const Alimentazione* type, unsigned int value,
               float raggio)
    : Animal(name, description, age, sex, weight, type, value), raggioRuota(raggio) {}

std::string Pavone::emettereVerso() const {
    return "eeee-ow!";
}

void Pavone::setRaggioRuota(float raggio) {
    raggioRuota = raggio;
}

float Pavone::getRaggioRuota() const {
    return raggioRuota;
}

std::string Pavone::SfoggiaRuota() const{
    if((sesso=='M' || sesso=='m') && raggioRuota>0){
        return "Il pavone ha sfoggiato una ruota di raggio:" + std::to_string(raggioRuota);
    }else{ return "Il pavone non ha una ruota";}
}

const std::string Pavone::setNome(){
    static unsigned int num = 0;    
    num ++;
    return "Pavone " + std::to_string(num);
}

std::string Pavone::setDescrizione(){
    return "Il pavone reale o pavone blu, anche noto come pavone indiano, è un uccello appartenente alla famiglia dei Fasianidi.";
}

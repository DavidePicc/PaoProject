#include <iostream>
#include "Tartaruga.h"
#include "generate.h"

Tartaruga::Tartaruga()
    : Animal(setNome(), setDescrizione(), comodo::generaNumeroCasuale(10, 90), comodo::setSesso(), comodo::generaNumeroCasuale(10, 30), new Erbivoro("Erba"), 4){
    misura.x = comodo::generaNumeroCasuale(30.0, 90.0);
    misura.y = comodo::generaNumeroCasuale(60.0, 130.0);
}

Tartaruga::Tartaruga(const std::string& name, std::string description, int age, const char sex, float weight, const Alimentazione* type, unsigned int value,
                     float X, float Y)
    : Animal(name, description, age, sex, weight, type, value), misura({X, Y}) {}

std::string Tartaruga::emettereVerso() const {
    return "La tartaruga non emette versi";
}

void Tartaruga::setMisura(float X, float Y) {
    misura.x = X;
    misura.y = Y;
}

Dim_Guscio Tartaruga::getMisura() const {
    return misura;
}

std::string Tartaruga::siNasconde() const{
    return "La tartaruga si è nascosta dentro un guscio di:" + misura.x + " e " + misura.y ;
}

const std::string Tartaruga::setNome(){
    static unsigned int num = 0;
    num ++;
    return "Tartaruga " + std::to_string(num);
}

std::string Tartaruga::setDescrizione(){
    return "Le testuggini delle Galapagos sono le tartarughe terrestri più grandi al mondo, con una lunghezza del carapace che si aggira attorno ai 150 centimetri ed un peso che può raggiungere i 300 kg. ";
}

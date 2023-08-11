#include <iostream>
#include "Struzzo.h"
#include "generate.h"

Struzzo::Struzzo()
    :Animal(setNome(), setDescrizione(), comodo::generaNumeroCasuale(5, 60), comodo::setSesso(), comodo::generaNumeroCasuale(70, 130), new Onnivoro("Erba"), 8), velocitamax(comodo::generaNumeroCasuale(30, 70)) {}

Struzzo::Struzzo(const std::string& name, std::string description, int age, const char sex, float weight, const Alimentazione* type, unsigned int value,
                 float velo)
    : Animal(name, description, age, sex, weight, type, value), velocitamax(velo) {}

std::string Struzzo::emettereVerso() const {
    return "Grugnito!";
}

void Struzzo::setVelocitaMax(float velo) {
    velocitamax = velo;
}

float Struzzo::getVelocitaMax() const {
    return velocitamax;
}

std::string Struzzo::corre() const{
    return "lo struzzo sta correndo ad una velocità di: " + std::to_string(velocitamax);
}

std::string Struzzo::nascondeTesta() const{
    return "lo struzzo ha nascosto la testa";
}

const std::string Struzzo::setNome(){
    static unsigned int num = 0;
    num ++;
    return "Struzzo " + std::to_string(num);
}

std::string Struzzo::setDescrizione(){
    return "Lo struzzo comune semplicemente struzzo, è una grande specie di uccello incapace di volare originario delle vaste savane dell'Africa.";
}

#include "Struzzo.h"

Struzzo::Struzzo(unsigned int sizeRecinto)
    :Animal(setNome(sizeRecinto), setDescrizione(), comodo::generaNumeroCasuale(5, 60), comodo::setSesso(), comodo::generaNumeroCasuale(70.0, 130.0), new Onnivoro("Erba"), 8), velocitamax(comodo::generaNumeroCasuale(30, 70)) {}

Struzzo::Struzzo(const std::string& name, int age, const char sex, float weight, const Alimentazione* type, float velo)
    : Animal(name, setDescrizione(), age, sex, weight, type, 8), velocitamax(velo) {}


void Struzzo::setVelocitaMax(float velo) {
    velocitamax = velo;
}

float Struzzo::getVelocitaMax() const {
    return velocitamax;
}

std::string Struzzo::corre() const{    
    std::ostringstream stream;
    stream << std::fixed << std::setprecision(2) << velocitamax;
    return "Lo struzzo sta correndo ad una velocità di: " + stream.str() + " chilometri all'ora";
}

std::string Struzzo::nascondeTesta() const{
    return "Lo struzzo ha nascosto la testa";
}

const std::string Struzzo::setNome(unsigned int sizeRecinto){
    return "Struzzo " + std::to_string(sizeRecinto + 1);
}

std::string Struzzo::setDescrizione(){
    return "Lo struzzo comune semplicemente struzzo, è una grande specie di uccello incapace di volare originario delle vaste savane dell'Africa.";
}

std::string Struzzo::getInfo() const {
    // Limita il numero di cifre decimali a 2
    std::ostringstream stream;
    stream << std::fixed << std::setprecision(2) << velocitamax;
    
    return Animal::getInfo() + "\nVelocita':\t" + stream.str() + " km/h";
}
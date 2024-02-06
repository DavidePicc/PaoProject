#include "Tartaruga.h"

Tartaruga::Tartaruga(unsigned int sizeRecinto)
    : Animal(setNome(sizeRecinto), setDescrizione(), comodo::generaNumeroCasuale(10, 90), comodo::setSesso(), comodo::generaNumeroCasuale(10.0, 30.0), new Erbivoro("Erba"), 4){
    misura.x = comodo::generaNumeroCasuale(30.0, 90.0);
    misura.y = comodo::generaNumeroCasuale(60.0, 130.0);
}

Tartaruga::Tartaruga(const std::string& name, int age, const char sex, float weight, const Alimentazione* type, float X, float Y)
    : Animal(name, setDescrizione(), age, sex, weight, type, 4), misura({X, Y}) {}


void Tartaruga::setMisura(float X, float Y) {
    misura.x = X;
    misura.y = Y;
}

Dim_Guscio Tartaruga::getMisura() const {
    return misura;
}

float Tartaruga::getMisuraX() const{
    return misura.x;
}

float Tartaruga::getMisuraY() const{
    return misura.y;
}

std::string Tartaruga::siNasconde() const{
    std::ostringstream misuraXStream, misuraYStream;
    misuraXStream << std::fixed << std::setprecision(2) << misura.x;
    misuraYStream << std::fixed << std::setprecision(2) << misura.y;

    return "La tartaruga si è nascosta dentro al suo guscio di dimensioni: " + misuraXStream.str() + " cm per  " + misuraYStream.str() + " cm";
}

const std::string Tartaruga::setNome(unsigned int sizeRecinto){
    return "Tartaruga " + std::to_string(sizeRecinto + 1);
}

std::string Tartaruga::setDescrizione(){
    return "Le testuggini delle Galapagos sono le tartarughe terrestri più grandi al mondo, con una lunghezza del carapace che si aggira attorno ai 150 centimetri ed un peso che può raggiungere i 300 kg. ";
}

std::string Tartaruga::getInfo() const {
    // Limita il numero di cifre decimali a 2 per le dimensioni del guscio
    std::ostringstream misuraXStream, misuraYStream;
    misuraXStream << std::fixed << std::setprecision(2) << misura.x;
    misuraYStream << std::fixed << std::setprecision(2) << misura.y;

    return Animal::getInfo() + "\nGuscio:\t\t" + misuraXStream.str() + " x " + misuraYStream.str() + " cm";
}

void Tartaruga::accept(animalVisitor& v){
    v.visitTartaruga(*this);
}
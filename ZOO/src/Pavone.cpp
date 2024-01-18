#include "Pavone.h"

Pavone::Pavone(unsigned int sizeRecinto)
    :Animal(setNome(sizeRecinto), setDescrizione(), comodo::generaNumeroCasuale(5, 15), comodo::setSesso(), comodo::generaNumeroCasuale(3.0, 6.0), new Onnivoro("Frutta"), 2), raggioRuota(sesso=='M' ? comodo::generaNumeroCasuale(30, 150) : 0) {}   

Pavone::Pavone(const std::string& name, int age, const char sex, float weight, const Alimentazione* type, float raggio)
    : Animal(name, setDescrizione(), age, sex, weight, type, 2), raggioRuota(raggio) {}

void Pavone::setRaggioRuota(float raggio) {
    raggioRuota = raggio;
}

float Pavone::getRaggioRuota() const {
    return raggioRuota;
}

std::string Pavone::SfoggiaRuota() const{
    if((sesso=='M' || sesso=='m') && raggioRuota > 0){
        std::ostringstream oss;
        oss << std::fixed << std::setprecision(2); // Imposta il formato a due cifre decimali
        oss << "Il pavone ha sfoggiato una ruota di raggio: " << raggioRuota << " cm\n";
        return oss.str();
    }
    else 
        return "Il pavone non ha una ruota in quanto femmina";
}

const std::string Pavone::setNome(unsigned int sizeRecinto){
    return "Pavone " + std::to_string(sizeRecinto + 1);
}

std::string Pavone::setDescrizione(){
    return "Il pavone reale o pavone blu, anche noto come pavone indiano, è un uccello appartenente alla famiglia dei Fasianidi.";
}

std::string Pavone::getInfo() const {
    // Limita il numero di cifre decimali a 2 per il raggio della ruota
    std::ostringstream raggioRuotaStream;
    raggioRuotaStream << std::fixed << std::setprecision(2) << raggioRuota;

    return Animal::getInfo() + "\nRaggio ruota:\t" + raggioRuotaStream.str() + " cm";
}
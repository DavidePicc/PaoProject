#include "Leone.h"

Leone::Leone(unsigned int sizeRecinto)
    : Animal(setNome(sizeRecinto), setDescrizione(), comodo::generaNumeroCasuale(5, 20), comodo::setSesso(), comodo::generaNumeroCasuale(130, 180), new Carnivoro("Carne"), 10), ruggito(comodo::generaNumeroCasuale(50, 110)) {}

Leone::Leone(const std::string& name, int age, const char sex, float weight, const Alimentazione* type, int rug)
    : Animal(name, setDescrizione(), age, sex, weight, type, 10), ruggito(rug) {}


void Leone::setRuggito(int rug) {
    ruggito = rug;
}

int Leone::getRuggito() const {
    return ruggito;
}

std::string Leone::getDescrizioneRuggito() const {
    return "Il leone " + nome + " ha ruggito con una potenza di " + std::to_string(ruggito) + " decibel";
}

const std::string Leone::setNome(unsigned int sizeRecinto){
    return "Leone " + std::to_string(sizeRecinto + 1);
}

std::string Leone::setDescrizione(){
    return "Il leone è un possente felino appartenente alla famiglia dei leoni e noto come il re della giungla. È uno dei più grandi carnivori terrestri esistenti e si distingue per la sua possente struttura fisica, la criniera caratteristica e l'imponente presenza.";
}

std::string Leone::getInfo() const {
    // Limita il numero di cifre decimali a 2 per il ruggito
    std::ostringstream ruggitoStream;
    ruggitoStream << std::fixed << std::setprecision(2) << ruggito;

    return Animal::getInfo() + "\nRuggito\t\t" + ruggitoStream.str() + " db";
}

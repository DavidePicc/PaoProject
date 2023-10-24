#include "Leone.h"
#include "generate.h"

Leone::Leone()
    : Animal(setNome(), setDescrizione(), comodo::generaNumeroCasuale(5, 20), comodo::setSesso(), comodo::generaNumeroCasuale(130, 180), new Carnivoro("Carne"), 10), ruggito(comodo::generaNumeroCasuale(50, 110)), criniera(comodo::generaNumeroCasuale(0, 1) == 1 ? 1 : 0) {}

Leone::Leone(const std::string& name, int age, const char sex, float weight, const Alimentazione* type, int rug, bool cri)
    : Animal(name, setDescrizione(), age, sex, weight, type, 10), ruggito(rug), criniera(cri) {}

std::string Leone::emettereVerso() const {
    return "Ruggito!";
}

void Leone::setRuggito(int rug) {
    ruggito = rug;
}

int Leone::getRuggito() const {
    return ruggito;
}

void Leone::setCriniera(bool cri) {
    criniera = cri;
}

bool Leone::hasCriniera() const {
    return criniera;
}

const std::string Leone::setNome(){
    static unsigned int num = 0;
    num++;
    return "Leone " + std::to_string(num);
}

std::string Leone::setDescrizione(){
    return "Il leone è un possente felino appartenente alla famiglia dei leoni e noto come il re della giungla. È uno dei più grandi carnivori terrestri esistenti e si distingue per la sua possente struttura fisica, la criniera caratteristica e l'imponente presenza.";
}

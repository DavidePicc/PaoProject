#include "Giraffa.h"

Giraffa::Giraffa(unsigned int sizeRecinto)
    : Animal(setNome(sizeRecinto), setDescrizione(), comodo::generaNumeroCasuale(10, 25), comodo::setSesso(), comodo::generaNumeroCasuale(700.0, 1100.0), new Erbivoro("Foglie"), 7), LunghezzaCollo(comodo::generaNumeroCasuale(2.0, 2.5)), Altezza(comodo::generaNumeroCasuale(4.0, 6.0)) {}


Giraffa::Giraffa(const std::string& name, int age, const char sex, float weight, const Alimentazione* type, float lungcollo, float altezza)
    : Animal(name, setDescrizione(), age, sex, weight, type, 7), LunghezzaCollo(lungcollo), Altezza(altezza) {}
    

void Giraffa::setLunghezzaCollo(float lungcollo) {
    LunghezzaCollo = lungcollo;
}

float Giraffa::getLunghezzaCollo() const {
    return LunghezzaCollo;
}

void Giraffa::setAltezza(float height) {
    Altezza = height;
}

float Giraffa::getAltezza() const {
    return Altezza;
}

const std::string Giraffa::setNome(unsigned int sizeRecinto){
    return "Giraffa " + std::to_string(sizeRecinto + 1);
}

std::string Giraffa::setDescrizione(){
    return "La giraffa è un genere di mammifero artiodattilo. Originaria dell'Africa, è il più alto animale terrestre, nonché il più grande ruminante esistente.";
}

std::string Giraffa::SiAlza() const{
    std::ostringstream colloStream, altezzaStream;
    colloStream << std::fixed << std::setprecision(2) << LunghezzaCollo;
    altezzaStream << std::fixed << std::setprecision(2) << Altezza;

    return "La giraffa si è alzata ed ha un altezza di: " + colloStream.str() + " mt ed un collo lungo " + altezzaStream.str() + " mt";
}

std::string Giraffa::getInfo() const {
    // Limita il numero di cifre decimali a 2 per la lunghezza del collo e l'altezza
    std::ostringstream colloStream, altezzaStream;
    colloStream << std::fixed << std::setprecision(2) << LunghezzaCollo;
    altezzaStream << std::fixed << std::setprecision(2) << Altezza;

    return Animal::getInfo() +
            "\nLunghezza collo:\t" + colloStream.str() + " mt" +
            "\nAltezza:\t\t" + altezzaStream.str() + " mt";
}

void Giraffa::accept(animalVisitor& v){
    v.visitGiraffa(*this);
}
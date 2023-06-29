#include "Coccodrillo.h"
#include <iostream>

int main(int argc, char *argv[]){
    //Prova coccodrillo
    /*Coccodrillo::Coccodrillo(const std::string& nome, int eta, const char sesso, float peso, std::string cibo, float lunghezza, int numero_denti)
    : Animal(setNome(), setDescrizione(), eta, sesso, peso, new Carnivoro(cibo)), lunghezza(lunghezza), numero_denti(numero_denti) {}*/
    std::string nome = "Nessie";
    int eta = 10;
    char sesso = 'F';
    float peso = 500.0;
    std::string ciboPreferito = "carne";
    float lunghezza = 5.5;
    int numeroDenti = 80;

    Coccodrillo c1(eta, sesso, peso, ciboPreferito, lunghezza, numeroDenti);
    std::cout << c1.nome << c1.emettereVerso() << c1.numero_denti << c1.getName();
}
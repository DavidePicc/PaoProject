#include "Coccodrillo.h"
#include <iostream>

int main(int argc, char *argv[]){
    std::string nome = "Nessie";
    int eta = 10;
    char sesso = 'F';
    float peso = 500.0;
    std::string ciboPreferito = "carne";
    std::string descrizione = "Un coccodrillo gigante";
    float lunghezza = 5.5;
    int numeroDenti = 80;

    Coccodrillo c1(nome, eta, sesso, peso, ciboPreferito, descrizione, lunghezza, numeroDenti);
    //std::cout << c1.descrizione;
}
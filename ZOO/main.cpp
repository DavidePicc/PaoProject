#include "Coccodrillo.h"
#include "Leone.h"
#include <iostream>

int main(int argc, char *argv[]){
    //Prova coccodrillo
    {
        std::string nome = "Nessie";
        int eta = 10;
        char sesso = 'F';
        float peso = 500.0;
        std::string ciboPreferito = "carne";
        float lunghezza = 5.5;
        int numeroDenti = 80;

        Coccodrillo c1(eta, sesso, peso, ciboPreferito, lunghezza, numeroDenti);
        std::cout << c1.nome << " " << c1.emettereVerso() << " " << c1.numero_denti << " " << c1.getName() << std::endl;
    }

    //Prova leone
    {
        Leone leone(5, 'M', 150.5, "carne", 10, true);
        std::cout << leone.getName() << std::endl;
    }
}
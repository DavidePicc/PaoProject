#include <iostream>
#include <random>
#include "Animal.h"



// Funzione templattizzata per generare un numero casuale compreso tra min e max (assumendo il primo sia min ed il secondo max)
template <typename T>
T generaNumeroCasuale(T min, T max) {
std::random_device rd;                      // Genera un seme casuale
std::mt19937 gen(rd());                     // Generatore di numeri casuali
std::uniform_real_distribution<T> dist(min, max); // Distribuzione uniforme tra min e max
return dist(gen);                           // Genera e restituisce un numero casuale
}

float setLunghezza(){
    return generaNumeroCasuale<int>(4, 7);
}

int setDenti(){
    return generaNumeroCasuale<int>(60, 70);
}

int setEta(){
    return generaNumeroCasuale<int>(10, 80);
}

class Coccodrillo : public Animal {
private:
float lunghezza;
int numero_denti;

public:
    Coccodrillo(const std::string& nome, 
            int eta, 
            const char sesso, 
            float peso, 
            const std::string& cibo_preferito, 
            std::string& descrizione, 
            float lunghezza, 
            int numero_denti): Animal(nome, eta, sesso, peso, cibo_preferito, descrizione), lunghezza(setLunghezza()), numero_denti(setDenti()) {}


    std::string getName() const { 
        return "Coccodrillo"; 
    }

    void emettereVerso() const override {
       std::cout << "Grrrr!" << std::endl;
    }
};
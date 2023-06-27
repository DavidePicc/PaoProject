#include <iostream>
#include <random>
#include "Coccodrillo.h"

//DECIDERE SE I METODI SET TENERLI DENTRO LA CLASSE O SPOSTARLI FUORI

// Funzione templattizzata per generare un numero casuale compreso tra min e max (assumendo il primo sia min ed il secondo max)
template <typename T>
T generaNumeroCasuale(T min, T max) {
std::random_device rd;                      // Genera un seme casuale
std::mt19937 gen(rd());                     // Generatore di numeri casuali
std::uniform_real_distribution<T> dist(min, max); // Distribuzione uniforme tra min e max
return dist(gen);                           // Genera e restituisce un numero casuale
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
            int numero_denti): Animal(setNome(), setEta(), setSesso(), setPeso(), setCiboPreferito(), setDescrizione()), lunghezza(setLunghezza()), numero_denti(setDenti()) {}

    static const std::string& setNome(){//Dangling reference ?
        static unsigned int num;
        return "Coccodrillo " + std::to_string(num);
    }

    int setEta(){
        return generaNumeroCasuale<int>(10, 80);
    }

    const char setSesso(){
        generaNumeroCasuale<int>(0, 1)==0 ? 'M' : 'F';
    }

    float setPeso(){
        return generaNumeroCasuale<float>(200.0, 900.0);
    }

    const std::string setCiboPreferito(){
        return "Carne";
    }

    std::string& setDescrizione(){//Dangling reference ?
        std::string a = "Nome: " + nome + "\nEta: " + std::to_string(eta) + "\nSesso: " + sesso + "\nPeso: " + std::to_string(peso) + "\nCibo preferito: " + /*cibo_preferito*/ + "\nLunghezza: " + std::to_string(lunghezza) + "\nNumero denti: " + std::to_string(numero_denti); //Non si resce ad accedere ai membri privati della classe base
        return a;
    }

    float setLunghezza(){
        return generaNumeroCasuale<int>(4, 7);
    }

    int setDenti(){
        return generaNumeroCasuale<int>(60, 70);
    }

    std::string getName() const { 
        return nome; 
    }

    std::string emettereVerso() const override {
       return "Grrrr!\n";
    }
};
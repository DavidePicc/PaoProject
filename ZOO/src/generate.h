#include <string>
#include <random>

namespace comodo{
    // Funzione templettizzata per generare un numero casuale compreso tra min e max (assumendo il primo sia min ed il secondo max)
    //Dovuta definire nel file .h per problemi di linking
    template <typename T>
    T generaNumeroCasuale(T min, T max) {
        std::random_device rd;                      // Genera un seme casuale
        std::mt19937 gen(rd());                     // Generatore di numeri casuali
        std::uniform_real_distribution<double> dist(min, max); // Distribuzione uniforme tra min e max -> double
        return static_cast<T>(dist(gen)); 
    }

    //Funzione per generare il sesso dell'animale
    char setSesso();
}
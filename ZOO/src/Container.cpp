#include "Container.h"

class Vettore {
private:
    Animal* array;//array che contera gli animali
    int size;

public:
    // Costruttore di default
    Vettore() : array(nullptr), size(0) {}
    // Costruttore con size specificata
    Vettore(int size) : array(new Animal[size]), size(size) {}

    // copia profonda
    Vettore(const Vettore& other) : array(new Animal[other.size]), size(other.size) {
        for (int i = 0; i < size; i++) {
            array[i] = other.array[i];
        }
    }

    // Distruttore profondo
    ~Vettore() {
        delete[] array;
    }

    // Assegnazione profonda di un vettore di animali ad un altro
    Vettore& operator=(const Vettore& other) {
        if (this != &other) {
            delete[] array;
            array = new Animal[other.size];
            size = other.size;
            for (int i = 0; i < size; i++) {
                array[i] = other.array[i];
            }
        }
        return *this;
    }

    // se volessi mettere gli animali di due gabbie in una unica più grande
    void Unite(const Vettore& other) {
        int newSize = size + other.size;
        Animal* newArray = new Animal[newSize];
        for (int i = 0; i < size; i++) {
            newArray[i] = array[i];
        }
        for (int i = 0; i < other.size; i++) {
            newArray[size + i] = other.array[i];
        }
        delete[] array;
        array = newArray;
        size = newSize;
    }

    // Overloading OUTPUT
    friend std::ostream& operator<<(std::ostream& os, const Vettore& v) {
        for (int i = 0; i < v.size; i++) {
            os << v.array[i].getName() << " ";
        }
        return os;
    }

    // Overloading di []
    Animal& operator[](int index) {
        return array[index];
    }
};

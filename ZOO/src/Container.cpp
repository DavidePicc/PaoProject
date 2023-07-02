#include <iostream>


template<typename T>
class Vettore {
private:
    T* array; // Array che conterrà gli oggetti di tipo T
    int size;

public:
    // Costruttore default
    Vettore() : array(nullptr), size(0) {}
    // Costruttore con size specificata
    Vettore(int size) : array(new T[size]), size(size) {}

    // Copia profonda
    Vettore(const Vettore& other) : array(new T[other.size]), size(other.size) {
        for (int i = 0; i < size; i++) {
            array[i] = other.array[i];
        }
    }

    // Distruttore profondo
    ~Vettore() {
        delete[] array;
    }

    // Assegnazione profonda di un vettore di oggetti T ad un altro
    Vettore& operator=(const Vettore& other) {
        if (this != &other) {
            delete[] array;
            array = new T[other.size];
            size = other.size;
            for (int i = 0; i < size; i++) {
                array[i] = other.array[i];
            }
        }
        return *this;
    }

    // Se volessi mettere gli oggetti di due vettori in uno unico più grande
    void Unite(const Vettore& other) {
        int newSize = size + other.size;
        T* newArray = new T[newSize];
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
    T& operator[](int index) {
        return array[index];
    }
};

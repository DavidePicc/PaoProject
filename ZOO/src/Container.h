#ifndef DLRECINTO_H
#define DLRECINTO_H

#include <memory>
#include "Animal.h"

class DLrecinto {
private:
    struct Node {
        std::shared_ptr<Animal> data; //Puntatori smart
        Node* prev;
        Node* next;

        Node(const std::shared_ptr<Animal>& value) : data(value), prev(nullptr), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    size_t size;
    unsigned int vita;

public:
    DLrecinto() : head(nullptr), tail(nullptr), size(0), vita(100) {}

    ~DLrecinto() {
        clear();
    }

    void insert(std::shared_ptr<Animal> value) {
        Node* newNode = new Node(value);
        if (size == 0) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        size++;
    }

    bool IsThere(const std::shared_ptr<Animal> value) const { //ricerca di un oggetto specifico per vedere se c'è dentro ad un recinto, bisogna definire meglio l'operatore di ugualianza in animal
        Node* currentNode = head;
        while (currentNode) {
            if (currentNode->data == value) {
                return true;
            }
            currentNode = currentNode->next;
        }
        return false;
    }
    
    std::shared_ptr<Animal> find(const std::string& string) const {//ricerca in base al nome visto che è unico
        Node* currentNode = head;
        while (currentNode) {
            if(currentNode->data->getName() == string) {
                return currentNode->data; // puntatore all'oggetto trovato
            }
            currentNode = currentNode->next;
        }
        return nullptr; // nullptr se non è stato trovato
    }

    void remove(const std::shared_ptr<Animal>& value) {
        Node* currentNode = head;
        while (currentNode) {
            if (currentNode->data == value) {
                if (currentNode->prev) {
                    currentNode->prev->next = currentNode->next;
                } else {
                    head = currentNode->next;
                }

                if (currentNode->next) {
                    currentNode->next->prev = currentNode->prev;
                } else {
                    tail = currentNode->prev;
                }

                delete currentNode;
                size--;
                return;
            }
            currentNode = currentNode->next;
        }
    }
    
    std::shared_ptr<Animal> operator[](size_t index) const {//Navigazione come array
        if (index >= size) {
            throw std::out_of_range("Index out of range");
        }

        Node* currentNode = head;
        for (size_t i = 0; i < index; i++) {
            currentNode = currentNode->next;
        }

        return currentNode->data;
    }

    void clear() {
        Node* currentNode = head;
        while (currentNode) {
            Node* nextNode = currentNode->next;
            delete currentNode;
            currentNode = nextNode;
        }
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    //Inutilizzata
    /*std::string print() const {
        Node* currentNode = head;
        while (currentNode) {
            std::cout << currentNode->data << " ";
            currentNode = currentNode->next;
        }
        std::cout << std::endl;
    }*/

    size_t getSize() const {
        return size;
    }
//metodi per vita
    unsigned int getVita() const {
        return vita;
    }

    void setVita(unsigned int newVita) {
        vita = newVita;
    }

    void modificavita(int amount) {
        int newVita = static_cast<int>(vita) + amount;
        newVita = std::max(0, newVita); //gestione sotto zero
        newVita = std::min(100, newVita); // gestione oltre 100
        vita = static_cast<unsigned int>(newVita);
    }

};

#endif // DLRECINTO_H

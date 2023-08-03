#ifndef DLRECINTO_H
#define DLRECINTO_H

#include <iostream>

template <typename T>
class DLrecinto {
private:
    struct Node {
        T data;
        Node* prev;
        Node* next;

        Node(const T& value) : data(value), prev(nullptr), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    size_t size;

public:
    DLrecinto() : head(nullptr), tail(nullptr), size(0) {}

    ~DLrecinto() {
        clear();
    }

    void insert(const T& value) {
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

    bool IsThere(const T& value) const { //ricerca di un oggetto specifico per vedere se c'è dentro ad un recinto, bisogna definire meglio l'operatore di ugualianza in animal
        Node* currentNode = head;
        while (currentNode) {
            if (currentNode->data == value) {
                return true;
            }
            currentNode = currentNode->next;
        }
        return false;
    }
    
    T* find(const std::string& string) const {//ricerca in base al nome visto che è unico
        Node* currentNode = head;
        while (currentNode) {
        	
            if (currentNode->data.getName() == string) {
            	std::cout<<"trovato"<<std::endl;
                return &(currentNode->data); // puntatore all'oggetto trovato
            }
            currentNode = currentNode->next;
        }
        std::cout<<"non trovato"<<std::endl;
        return nullptr; // nullptr se non è stato trovato
    }

    void remove(const T& value) {
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
    
    T& operator[](size_t index) const {//Navigazione come array
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

    void print() const {
        Node* currentNode = head;
        while (currentNode) {
            std::cout << currentNode->data << " ";
            currentNode = currentNode->next;
        }
        std::cout << std::endl;
    }

    size_t getSize() const {
        return size;
    }
};

#endif // DLRECINTO_H
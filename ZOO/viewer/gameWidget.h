#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPixmap>
#include <QScreen>
#include <QGuiApplication>
#include <QPushButton>
#include <QDialog>
#include <QListWidget>
#include <QListWidgetItem>
#include <QHBoxLayout>

#include "clock.h"
#include "../src/Animal.h"
#include "../src/Coccodrillo.h"
#include "../src/Giraffa.h"
#include "../src/Leone.h"
#include "../src/Pavone.h"
#include "../src/Struzzo.h"
#include "../src/Tartaruga.h"
#include "../src/Container.h"


class GameWidget : public QWidget {
    Q_OBJECT
private:
    //Variabili di gioco: soldi e recinti
    unsigned int soldi;
    DLrecinto<Leone> leoni;
    DLrecinto<Coccodrillo> coccodrilli;
    DLrecinto<Pavone> pavoni;
    DLrecinto<Tartaruga> tartarughe;
    DLrecinto<Struzzo> struzzi;
    DLrecinto<Giraffa> giraffe;

public:
    GameWidget(QWidget *parent = nullptr);

    template <typename T>
    QPushButton* createButton(int x, int y, std::string animale, DLrecinto<T>& recinto);

    // definizione di seeAnimals come un metodo template all'interno della classe
    template <typename T>
    void seeAnimals(const DLrecinto<T>& recinto) {
        QDialog *dialog = new QDialog(this);
        dialog->setWindowTitle("Recinto");
        QListWidget *listWidget = new QListWidget(dialog);

        //Aggiungo bottone Aggiungi animale
        QPushButton *addButton = new QPushButton("Aggiungi Animale", dialog); // Crea il bottone
        addButton->setStyleSheet("color: black; background-color: #D3D3D3;"); // Modifica lo stile del bottone
        addButton->setFixedHeight(50); // Imposta l'altezza fissa
        addButton->setCursor(Qt::PointingHandCursor);

        //Aggiungo bottone Sfama
        QPushButton *foodButton = new QPushButton("Sfama", dialog); // Crea il bottone
        foodButton->setStyleSheet("color: black; background-color: #D3D3D3;"); // Modifica lo stile del bottone
        foodButton->setFixedHeight(50); // Imposta l'altezza fissa
        foodButton->setCursor(Qt::PointingHandCursor);

        QHBoxLayout *buttonLayout = new QHBoxLayout(); // Crea un nuovo layout orizzontale
        buttonLayout->addWidget(addButton); // Aggiunge il primo bottone al layout orizzontale
        buttonLayout->addWidget(foodButton); // Aggiunge il secondo bottone al layout orizzontale

        QVBoxLayout *layout = new QVBoxLayout(dialog);
        layout->addWidget(listWidget);
        layout->addLayout(buttonLayout); // Aggiunge il layout orizzontale al layout verticale

        // Connetti il segnale del bottone al tuo slot personalizzato
        //connect(addButton, &QPushButton::clicked, this, &YourClass::addAnimal);
        //connect(foodButton, &QPushButton::clicked, this, &YourClass::giveFood);


        if(recinto.getSize() == 0){
            QListWidgetItem *item = new QListWidgetItem(QString::fromStdString("Gabbia vuota"));
            QFont font;
            font.setPointSize(20); // Imposta la dimensione del testo a 14
            font.setBold(true); // Rende il testo in grassetto
            item->setFont(font);
            item->setTextAlignment(Qt::AlignCenter);

            listWidget->addItem(item);
        }

        for(unsigned int i=0; i<recinto.getSize(); i++){
            QListWidgetItem *item = new QListWidgetItem(QString::fromStdString(recinto[i].getName())); //Altri parametri
            listWidget->addItem(item);
        }

        dialog->exec(); 
    }

public slots:
    //void addAnimal();
    //void giveFood();

};


#endif // GAMEWIDGET_H
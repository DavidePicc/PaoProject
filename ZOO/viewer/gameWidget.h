#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QApplication>
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
#include <QProgressBar>
#include <QScrollArea>
#include <QMessageBox>
#include <QKeyEvent>

#include "clock.h"
#include "../src/Animal.h"
#include "../src/Coccodrillo.h"
#include "../src/Giraffa.h"
#include "../src/Leone.h"
#include "../src/Pavone.h"
#include "../src/Struzzo.h"
#include "../src/Tartaruga.h"
#include "../src/Container.h"
#include "viewer/mainMenu.h"


class GameWidget : public QWidget {
    Q_OBJECT
private:
    //Variabili di gioco: soldi e recinti
    unsigned int soldi;
    DLrecinto leoni;
    DLrecinto coccodrilli;
    DLrecinto pavoni;
    DLrecinto tartarughe;
    DLrecinto struzzi;
    DLrecinto giraffe;

public:
    GameWidget(QWidget *parent = nullptr);
    QPushButton* createButton(int x, int y, std::string animale, DLrecinto& recinto);
    void seeAnimals(DLrecinto& recinto,  QProgressBar* healthBar);
    void keyPressEvent(QKeyEvent *event) override;
    

public slots:
    void animalDetails(Animal& a);
    void addAnimal(DLrecinto& recinto);
    void giveFood(DLrecinto& recinto, QProgressBar* healthBar);

};


#endif // GAMEWIDGET_H

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
#include <QInputDialog>
#include <QFile>


#include "gameModel.h"
#include "digitalClock.h"
#include "mainMenu.h"
#include "../dataManager/dataManager.h"

//SPLITTER
#include <QSplitter>

class GameWidget : public QWidget {
    Q_OBJECT
private:
    GameModel gameModel;
    DigitalClock clock;

    //BOX
    // Crea la finestra principale
    QWidget *mainWidget = new QWidget(this);//serve il this!
    QHBoxLayout *mainLayout = new QHBoxLayout(mainWidget);

    // Crea un widget a destra vuoto
    QLabel *emptyLabel = new QLabel(mainWidget);
    
    // Crea un widget a sinistra per l'immagine di sfondo
    QLabel *backgroundLabel = new QLabel(mainWidget);
    //BOX

public:
    GameWidget();
    GameWidget(std::string filename);
    void visualizer();
    void createButton(int x, int y, std::string animale, DLrecinto& recinto);
    void seeAnimals(DLrecinto& recinto, QProgressBar* healthBar, size_t numAnimali);
    void keyPressEvent(QKeyEvent *event) override;

    friend void readDatiRecinto(QXmlStreamReader& xmlReader, GameModel& gameModel, std::string animali);

public slots:
    void animalDetails(Animal& a);
    void foodSlot(DLrecinto& recinto, QProgressBar *healthBar);
};

#endif 

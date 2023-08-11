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

class GameWidget : public QWidget {
    Q_OBJECT
private:
    GameModel gameModel;
    DigitalClock clock;

public:
    GameWidget();
    GameWidget(std::string filename);
    void visualizer();
    QPushButton* createButton(int x, int y, std::string animale, DLrecinto& recinto);
    void seeAnimals(DLrecinto& recinto, QProgressBar* healthBar);
    void keyPressEvent(QKeyEvent *event) override;

    friend void readDatiRecinto(QXmlStreamReader& xmlReader, GameModel& gameModel, std::string animali);

public slots:
    void animalDetails(Animal& a);
    void foodSlot(DLrecinto& recinto, QProgressBar *healthBar);
};

#endif 
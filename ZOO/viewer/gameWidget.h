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

#include "gameModel.h"
#include "clock.h"
#include "mainMenu.h"

class GameWidget : public QWidget {
    Q_OBJECT
private:
    GameModel gameModel;

public:
    GameWidget(QWidget *parent = nullptr);
    QPushButton* createButton(int x, int y, std::string animale, DLrecinto& recinto);
    void seeAnimals(DLrecinto& recinto, QProgressBar* healthBar);
    void keyPressEvent(QKeyEvent *event) override;

public slots:
    void animalDetails(Animal& a);
    void foodSlot(DLrecinto& recinto, QProgressBar *healthBar);
};

#endif 
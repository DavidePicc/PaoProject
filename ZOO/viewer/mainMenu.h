#ifndef MAINMENU_H
#define MAINMENU_H

#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QPixmap>
#include <QDir>
#include <QFileInfoList>
#include <QDialog>

#include "gameWidget.h"

class MainMenu : public QWidget {
    Q_OBJECT
    public:
        MainMenu(QWidget *parent = nullptr);

    private:
        void setupLayout();
        QVBoxLayout *mainLayout;
        QLabel *titleLabel;
        QHBoxLayout *buttonsLayout;
        QPushButton *nuovaPartita;
        QPushButton *caricaPartita;

    private slots: // Qui aggiungiamo i nostri slot
        void handleNewGameButton();
        void handleLoadGameButton();
};


#endif

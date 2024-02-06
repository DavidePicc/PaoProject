#ifndef DATAMANAGER_H
#define DATAMANAGER_H

#include <QString>
#include <QMap>
#include <QFile>
#include <QXmlStreamWriter>
#include <QXmlStreamReader>
#include <QDebug>
#include <QMessageBox>
#include <QDir>

#include "../src/Coccodrillo.h"
#include "../src/Giraffa.h"
#include "../src/Leone.h"
#include "../src/Pavone.h"
#include "../src/Struzzo.h"
#include "../src/Tartaruga.h"
#include "../src/Container.h"

#include "../src/Container.h"
#include "../viewer/gameModel.h"

class GameModel;

class DataManager {
public:
    //Funzioni di scrittura
    static bool writeData(const std::string nome, GameModel& gameModel, QString time);
    static bool writeDatiRecinto(const std::string animali, const DLrecinto& recinto, QXmlStreamWriter* xmlWriter);
    
    
    //Funzioni  di lettura
    static bool readData(const std::string& nome, GameModel& gameModel, QString& time);
    static void readZOO(QXmlStreamReader& xmlReader, GameModel& gameModel, QString& time);
    static void readDatiRecinto(QXmlStreamReader& xmlReader, GameModel& gameModel, std::string animali);
    
    //Funzione per saltare righe fino ad un determinato attributo
    static void jumpTo(QXmlStreamReader& xmlReader, std::string tag);
};

#endif // DATAMANAGER_H

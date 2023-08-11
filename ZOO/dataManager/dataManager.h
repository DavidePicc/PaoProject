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


#include "../src/Container.h"
#include "../viewer/gameModel.h"

class GameModel;

class DataManager {
public:
    //Funzioni di scrittura
    static bool writeData(const std::string nome, GameModel& gameModel, QString time);
    static bool writeDatiRecinto(const std::string animali, const DLrecinto& recinto, QXmlStreamWriter* xmlWriter);
    /*static bool writeDatiAnimale(const Leone&, QXmlStreamWriter* xmlWriter);
    static bool writeDatiAnimale(const Coccodrillo&, QXmlStreamWriter* xmlWriter);
    static bool writeDatiAnimale(const Pavone&, QXmlStreamWriter* xmlWriter);
    static bool writeDatiAnimale(const Tartaruga&, QXmlStreamWriter* xmlWriter);
    static bool writeDatiAnimale(const Struzzo&, QXmlStreamWriter* xmlWriter);
    static bool writeDatiAnimale(const Giraffa&, QXmlStreamWriter* xmlWriter);*/
    
    
    //Funzioni  di lettura
    static bool readData(const std::string& nome, GameModel& gameModel, QString& time);
    static void readZOO(QXmlStreamReader& xmlReader, GameModel& gameModel, QString& time);
    static void readDatiRecinto(QXmlStreamReader& xmlReader, GameModel& gameModel, std::string animali);
};

#endif // DATAMANAGER_H

#ifndef DATAMANAGER_H
#define DATAMANAGER_H

#include <QString>
#include <QMap>
#include <QFile>
#include <QXmlStreamWriter>
#include <QXmlStreamReader>
#include <QDebug>
#include <QMessageBox>

#include "../src/Container.h"
#include "../viewer/gameModel.h"

class DataManager {
public:
    //Funzioni di scrittura
    static bool writeData(const std::string nome, GameModel& gameModel);
    static bool writeDatiRecinto(std::string animali, const DLrecinto& recinto, QXmlStreamWriter* xmlWriter);
    static bool writeDatiAnimale(const Leone&, QXmlStreamWriter* xmlWriter);
    static bool writeDatiAnimale(const Coccodrillo&, QXmlStreamWriter* xmlWriter);
    static bool writeDatiAnimale(const Pavone&, QXmlStreamWriter* xmlWriter);
    static bool writeDatiAnimale(const Tartaruga&, QXmlStreamWriter* xmlWriter);
    static bool writeDatiAnimale(const Struzzo&, QXmlStreamWriter* xmlWriter);
    static bool writeDatiAnimale(const Giraffa&, QXmlStreamWriter* xmlWriter);
    
    
    //Funzioni  di lettura
    static bool readData(const std::string& nome, unsigned int& soldi, DLrecinto& leoni, DLrecinto& coccodrilli, DLrecinto& pavoni, DLrecinto& tartarughe, DLrecinto& struzzi, DLrecinto& giraffe);
    static bool readDatiRecinto(const std::string& animali, DLrecinto& recinto, QXmlStreamReader* xmlReader);
};

#endif // DATAMANAGER_H

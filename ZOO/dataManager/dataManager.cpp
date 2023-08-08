#include "dataManager.h"
#include <QFile>
#include <QXmlStreamWriter>
#include <QXmlStreamReader>
#include <QDebug>

//Costruttore
DataManager::DataManager(const QString &filePath) : filePath(filePath) {}


unsigned int soldi;
    DLrecinto leoni;
    DLrecinto coccodrilli;
    DLrecinto pavoni;
    DLrecinto tartarughe;
    DLrecinto struzzi;
    DLrecinto giraffe;

//Funzione per scrivere dati
bool DataManager::writeData(const unsigned int soldi, const DLrecinto leoni, const DLrecinto coccodrilli, const DLrecinto pavoni , const DLrecinto tartarughe, const DLrecinto struzzi, const DLrecinto giraffe) {
    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly)) {
        qWarning() << "Non è possibile aprire il file per la scrittura:" << filePath;
        return false;
    }

    QXmlStreamWriter xmlWriter(&file);
    xmlWriter.setAutoFormatting(true);
    
    xmlWriter.writeStartDocument();
    xmlWriter.writeStartElement("utente");

    for (auto it = data.cbegin(); it != data.cend(); ++it) {
        xmlWriter.writeTextElement(it.key(), it.value());
    }

    xmlWriter.writeEndElement();
    xmlWriter.writeEndDocument();

    file.close();
    return true;
}



//Funzione per leggere dati
QMap<QString, QString> DataManager::readData() {
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly)) {
        qWarning() << "Non è possibile aprire il file per la lettura:" << filePath;
        return {};
    }

    QMap<QString, QString> data;
    QXmlStreamReader xmlReader(&file);

    while (!xmlReader.atEnd()) {
        if (xmlReader.readNextStartElement()) {
            if (xmlReader.name() == "utente") {
                while (xmlReader.readNextStartElement()) {
                    data[xmlReader.name().toString()] = xmlReader.readElementText();
                }
            }
        }
    }

    if (xmlReader.hasError()) {
        qWarning() << "Errore durante la lettura del file XML:" << xmlReader.errorString();
    }

    file.close();
    return data;
}
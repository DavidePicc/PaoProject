#include "dataManager.h"
#include "../viewer/gameModel.h"

//SCRITTURA
//Funzione per scrivere dati
bool DataManager::writeData(const std::string nome, GameModel& gameModel, QString time) {
    QDir dir("savedFile");
    if(!dir.exists()){
        if(!QDir().mkdir("savedFile")){
            qWarning() << "Error creating directory at path:" << dir.absolutePath();
            return false;
        }
    }

    //Creo percorso file
    QString filePath = QString::fromStdString("savedFile/" + nome + ".xml");
    QFile file(filePath);

    if (!file.open(QIODevice::WriteOnly)) {
        qWarning() << "Non è possibile aprire il file per la scrittura:" << filePath;
        qWarning() << "Errore:" << file.errorString();
        return false;
    }

    QXmlStreamWriter xmlWriter(&file);
    xmlWriter.setAutoFormatting(true);
    
    xmlWriter.writeStartDocument();
    xmlWriter.writeStartElement("ZOO");

    xmlWriter.writeTextElement("soldi", QString::number(gameModel.getSoldi()));
    
    xmlWriter.writeStartElement("clock");
    xmlWriter.writeTextElement("Time", QString(time));
    xmlWriter.writeEndElement();

    if(writeDatiRecinto("leoni", gameModel.getLeoni(), &xmlWriter) == 0 || writeDatiRecinto("coccodrilli", gameModel.getCoccodrilli(), &xmlWriter) == 0 || writeDatiRecinto("pavoni", gameModel.getPavoni(), &xmlWriter) == 0 || writeDatiRecinto("tartarughe", gameModel.getTartarughe(), &xmlWriter) == 0 || writeDatiRecinto("struzzi", gameModel.getStruzzi(), &xmlWriter) == 0 || writeDatiRecinto("giraffe", gameModel.getGiraffe(), &xmlWriter) == 0){
        file.remove();// Se errori, elimino tutto il file
        return 0;
    }


    xmlWriter.writeEndElement();
    xmlWriter.writeEndDocument();

    file.close();
    return true;
}

//Funzione di aiuto per scrivere dati di un singolo recinto
bool DataManager::writeDatiRecinto(const std::string animali, const DLrecinto& recinto, QXmlStreamWriter* xmlWriter){
    xmlWriter->writeStartElement(QString::fromStdString(animali));
    xmlWriter->writeTextElement("vita", QString::number(recinto.getVita()));
    if(recinto.getSize() > 0){
        xmlWriter->writeTextElement("descrizione", QString::fromStdString((*recinto[0]).getDescrizione()));
        xmlWriter->writeTextElement("costo", QString::number((*recinto[0]).getCosto()));
        for(size_t i = 0; i<recinto.getSize(); i++){
            xmlWriter->writeStartElement(QString::fromStdString((*recinto[i]).getName()));
            xmlWriter->writeTextElement("nome", QString::fromStdString((*recinto[i]).getName()));
            xmlWriter->writeTextElement("eta", QString::number((*recinto[i]).getEta()));
            xmlWriter->writeTextElement("sesso", QString((*recinto[i]).getSex()));
            xmlWriter->writeTextElement("peso", QString::number((*recinto[i]).getPeso(), 'f'));
            xmlWriter->writeTextElement("cibo", QString::fromStdString((*recinto[i]).getTipo()->getCiboPreferito()));

            //writeDatiAnimale(recinto.getObject(i), xmlWriter);

            //Converto il puntatore in nel suo oggetto appropriato
            if (animali == "leoni") {
                xmlWriter->writeTextElement("ruggito", QString::number((*(std::dynamic_pointer_cast<Leone>(recinto[i]))).getRuggito()));
                xmlWriter->writeTextElement("criniera", (*(std::dynamic_pointer_cast<Leone>(recinto[i]))).hasCriniera() ? "1" : "0");
            } else if (animali == "coccodrillo") {
                xmlWriter->writeTextElement("lunghezza", QString::number((*(std::dynamic_pointer_cast<Coccodrillo>(recinto[i]))).getLunghezza(), 'f'));
                xmlWriter->writeTextElement("numeroDenti", QString::number((*(std::dynamic_pointer_cast<Coccodrillo>(recinto[i]))).getNumeroDenti()));
            } else if (animali == "pavoni") {
                xmlWriter->writeTextElement("raggioRuota", QString::number((*(std::dynamic_pointer_cast<Pavone>(recinto[i]))).getRaggioRuota(), 'f'));
            } else if (animali == "tartarughe") {
                xmlWriter->writeTextElement("misuraGuscioX", QString::number((*(std::dynamic_pointer_cast<Tartaruga>(recinto[i]))).getMisuraX(), 'f'));
                xmlWriter->writeTextElement("misuraGuscioY", QString::number((*(std::dynamic_pointer_cast<Tartaruga>(recinto[i]))).getMisuraY(), 'f'));
            } else if (animali == "struzzi") {
                xmlWriter->writeTextElement("velocita", QString::number((*(std::dynamic_pointer_cast<Struzzo>(recinto[i]))).getVelocitaMax(), 'f'));
            } else if (animali == "giraffe") {
                xmlWriter->writeTextElement("lunghezzaCollo", QString::number((*(std::dynamic_pointer_cast<Giraffa>(recinto[i]))).getLunghezzaCollo(), 'f'));
                xmlWriter->writeTextElement("altezza", QString::number((*(std::dynamic_pointer_cast<Giraffa>(recinto[i]))).getAltezza(), 'f'));
            }


            xmlWriter->writeEndElement();

            if(xmlWriter->hasError())
                return false;
        }
    }
    
    xmlWriter->writeEndElement();

    if(xmlWriter->hasError())
        return false;

    return true;
}

#include <iostream>/////////////////////////////////

//LETTURA
//Funzione per leggere dati
bool DataManager::readData(const std::string& nome, GameModel& gameModel, QString& time) {
    QString filePath = QString::fromStdString("savedFile/" + nome);
    QFile file(filePath);

    if (!file.open(QIODevice::ReadOnly)) {
        qWarning() << "Non è possibile aprire il file per la lettura:" << filePath;
        qWarning() << "Errore:" << file.errorString();
        return false;
    }

    QXmlStreamReader xmlReader(&file);

    std::cout << "A\n";

    while (!xmlReader.atEnd() && !xmlReader.hasError()) {
        QXmlStreamReader::TokenType token = xmlReader.readNext();
        
        if (token == QXmlStreamReader::StartDocument) {
            continue;
        }

        if (token == QXmlStreamReader::StartElement) {
            if (xmlReader.name() == QStringLiteral("ZOO")) {
                readZOO(xmlReader, gameModel, time);
                std::cout << "B\n";
            }
        }
    }

    file.close();

    if (xmlReader.hasError()) {
        qWarning() << "Errore nella lettura del file XML:" << xmlReader.errorString();
        return false;
    }

    return true;
}

void DataManager::readZOO(QXmlStreamReader& xmlReader, GameModel& gameModel, QString& time) {
    while (!(xmlReader.tokenType() == QXmlStreamReader::EndElement && xmlReader.name() == QStringLiteral("ZOO"))) { //Finchè non arrivo alla fine di ZOO
        if (xmlReader.tokenType() == QXmlStreamReader::StartElement) {
            if (xmlReader.name() == QStringLiteral("soldi")) {
                std::cout << "C - " << xmlReader.readElementText().toInt() << " \n";
                gameModel.setSoldi(xmlReader.readElementText().toInt());
            } else if (xmlReader.name() == QStringLiteral("Time")) {
                std::cout << "D " << xmlReader.readElementText().toStdString() << "\n";
                time = xmlReader.readElementText();
            } else if(xmlReader.name() == QStringLiteral("leoni") || xmlReader.name() == QStringLiteral("coccodrilli") || xmlReader.name() == QStringLiteral("pavoni") || xmlReader.name() == QStringLiteral("tartarughe") || xmlReader.name() == QStringLiteral("struzzi") || xmlReader.name() == QStringLiteral("giraffe")) {
                std::cout << "E\n";
                readDatiRecinto(xmlReader, gameModel, xmlReader.name().toString().toStdString());
                std::cout << "F\n";
            }
        }
        xmlReader.readNext();
    }
}

void DataManager::readDatiRecinto(QXmlStreamReader& xmlReader, GameModel& gameModel, std::string animali) {
    bool vuoto = false;
    std::string nome, cibo, descrizione;
    char sesso;
    unsigned int costo;
    int eta;
    float peso;

    //Leggo la vita
    xmlReader.readNext();
    unsigned int vita = xmlReader.readElementText().toInt();
    xmlReader.readNext();
std::cout << "G\n";
    //Se non c'è neanche un animale ritorno
    if(xmlReader.tokenType() == QXmlStreamReader::EndElement)
        vuoto = true;
    else{
        std::cout << "H\n";
        //Prendo gli attributi comuni a tutti gli animali, poi dentro all'if prendo gli attrbuti specifici
        descrizione = xmlReader.readElementText().toStdString();
        xmlReader.readNext();
        costo = xmlReader.readElementText().toInt();
        xmlReader.readNext();
        xmlReader.readNext();
        while(!(xmlReader.tokenType() == QXmlStreamReader::EndElement && xmlReader.name() == QString::fromStdString(animali))){
            //xmlReader.readNext();
            nome = xmlReader.readElementText().toStdString();
            xmlReader.readNext();
            eta = xmlReader.readElementText().toInt();
            xmlReader.readNext();
            sesso = xmlReader.readElementText().toStdString()[0];
            xmlReader.readNext();
            peso = xmlReader.readElementText().toFloat();
            xmlReader.readNext();
            cibo = xmlReader.readElementText().toStdString();
            xmlReader.readNext();
            std::cout << "I\n";

            if (animali == "leoni") {
                if(vuoto)
                    gameModel.getLeoni().setVita(vita);
                else{
                    unsigned int ruggito = xmlReader.readElementText().toInt();
                    xmlReader.readNext();
                    bool criniera = (xmlReader.readElementText().toLower() == "true");
                    const Alimentazione* tipo = new Carnivoro(cibo);

                    gameModel.getLeoni().insert(std::make_shared<Leone>(nome, descrizione, eta, sesso, peso, tipo, costo, ruggito, criniera));
                }
            } else if (animali == "coccodrillo") {
                if(vuoto)
                    gameModel.getCoccodrilli().setVita(vita);
                else{
                    float lunghezza = xmlReader.readElementText().toFloat();
                    xmlReader.readNext();
                    int denti = xmlReader.readElementText().toInt();
                    const Alimentazione* tipo = new Carnivoro(cibo);

                    gameModel.getCoccodrilli().insert(std::make_shared<Coccodrillo>(nome, descrizione, eta, sesso, peso, tipo, costo, lunghezza, denti));
                }
            } else if (animali == "pavoni") {
                if(vuoto)
                    gameModel.getPavoni().setVita(vita);
                else{
                    float ruota = xmlReader.readElementText().toFloat();
                    xmlReader.readNext();
                    const Alimentazione* tipo = new Onnivoro(cibo);

                    gameModel.getPavoni().insert(std::make_shared<Pavone>(nome, descrizione, eta, sesso, peso, tipo, costo, ruota));
                }
            } else if (animali == "tartarughe") {
                if(vuoto)
                    gameModel.getTartarughe().setVita(vita);
                else{
                    float guscioX = xmlReader.readElementText().toFloat();
                    xmlReader.readNext();
                    float guscioY = xmlReader.readElementText().toFloat();
                    const Alimentazione* tipo = new Erbivoro(cibo);

                    gameModel.getTartarughe().insert(std::make_shared<Tartaruga>(nome, descrizione, eta, sesso, peso, tipo, costo, guscioX, guscioY));
                }
            } else if (animali == "struzzi") {
                if(vuoto)
                    gameModel.getStruzzi().setVita(vita);
                else{
                    float velocita = xmlReader.readElementText().toFloat();
                    const Alimentazione* tipo = new Onnivoro(cibo);

                    gameModel.getStruzzi().insert(std::make_shared<Struzzo>(nome, descrizione, eta, sesso, peso, tipo, costo, velocita));
                }
            } else if (animali == "giraffe") {
                if(vuoto)
                    gameModel.getGiraffe().setVita(vita);
                else{
                    float collo = xmlReader.readElementText().toFloat();
                    xmlReader.readNext();
                    float altezza = xmlReader.readElementText().toFloat();
                    const Alimentazione* tipo = new Erbivoro(cibo);

                    gameModel.getGiraffe().insert(std::make_shared<Giraffa>(nome, descrizione, eta, sesso, peso, tipo, costo, collo, altezza));
                }
            }
            xmlReader.readNext();
            
        }
        
    }

    
}

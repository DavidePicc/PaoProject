#include "dataManager.h"
#include "../viewer/gameModel.h"

#include <iostream>/////////////////////////////////


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
    
    xmlWriter.writeTextElement("clock", QString(time));

    if(writeDatiRecinto("leoni", gameModel.getLeoni(), &xmlWriter) == 0 || writeDatiRecinto("coccodrilli", gameModel.getCoccodrilli(), &xmlWriter) == 0 || writeDatiRecinto("pavoni", gameModel.getPavoni(), &xmlWriter) == 0 || writeDatiRecinto("tartarughe", gameModel.getTartarughe(), &xmlWriter) == 0 || writeDatiRecinto("struzzi", gameModel.getStruzzi(), &xmlWriter) == 0 || writeDatiRecinto("giraffe", gameModel.getGiraffe(), &xmlWriter) == 0){
        //file.remove();// Se errori, elimino tutto il file
        return false;
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
    xmlWriter->writeTextElement("numero", QString::number(static_cast<int>(recinto.getSize())));
    
    if(recinto.getSize() > 0){
        for(size_t i = 0; i<recinto.getSize(); i++){
            xmlWriter->writeStartElement(QString::fromStdString(animali + std::to_string(i)));
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
            } else if (animali == "coccodrilli") {
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

    while (!xmlReader.atEnd() && !xmlReader.hasError()) {
        QXmlStreamReader::TokenType token = xmlReader.readNext();
        
        if (token == QXmlStreamReader::StartDocument) {//Serve per saltare alla prossima iterazione del while (quindi andare alla prossima riga finchè non trova <ZOO>)
            continue;
        }

        if (token == QXmlStreamReader::StartElement && xmlReader.name() == QStringLiteral("ZOO")){
            readZOO(xmlReader, gameModel, time);
            break;
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
    
    jumpTo(xmlReader, "soldi");
    gameModel.setSoldi(xmlReader.readElementText().toInt());

    jumpTo(xmlReader, "clock");
    time = xmlReader.readElementText();
        
    readDatiRecinto(xmlReader, gameModel, "leoni");
    readDatiRecinto(xmlReader, gameModel, "coccodrilli");
    readDatiRecinto(xmlReader, gameModel, "pavoni");
    readDatiRecinto(xmlReader, gameModel, "tartarughe");
    readDatiRecinto(xmlReader, gameModel, "struzzi");
    readDatiRecinto(xmlReader, gameModel, "giraffe");
        
}

void DataManager::readDatiRecinto(QXmlStreamReader& xmlReader, GameModel& gameModel, std::string animali) {
    std::string nome, cibo, descrizione;
    char sesso;
    unsigned int costo;
    int eta;
    float peso;

    //Mi posiziono sull'animale giusto
    jumpTo(xmlReader, animali);

    //Mi posiziono e leggo la vita
    jumpTo(xmlReader, "vita");
    unsigned int vita = xmlReader.readElementText().toInt();

    //Setto la vita del recinto indipendentemente da quanti animali ci sono
    if (animali == "leoni")
        gameModel.getLeoni().setVita(vita);
    else if (animali == "coccodrilli")
        gameModel.getCoccodrilli().setVita(vita);
    else if (animali == "pavoni")
        gameModel.getPavoni().setVita(vita);
    else if (animali == "tartarughe")
        gameModel.getTartarughe().setVita(vita);
    else if (animali == "struzzi")
        gameModel.getStruzzi().setVita(vita);
    else if (animali == "giraffe")
        gameModel.getGiraffe().setVita(vita);

    //Mi posiziono e leggo il numero di animali
    jumpTo(xmlReader, "numero");
    unsigned int numero = 0;
    numero = xmlReader.readElementText().toInt();

    //Se 0 animali non devo aggiungerne
    if(numero <= 0)
        return;

    //Prendo gli attributi comuni a tutti gli animali, poi dentro all'if prendo gli attrbuti specifici
    for (unsigned int i = 0; i < numero; i++) {
        QString currentAnimalTag = QString::fromStdString(animali + std::to_string(i));
        jumpTo(xmlReader, currentAnimalTag.toStdString());

        jumpTo(xmlReader, "nome");
        nome = xmlReader.readElementText().toStdString();

        jumpTo(xmlReader, "eta");
        eta = xmlReader.readElementText().toInt();
        
        jumpTo(xmlReader, "sesso");
        sesso = xmlReader.readElementText().toStdString()[0];

        jumpTo(xmlReader, "peso");
        peso = xmlReader.readElementText().toFloat();

        jumpTo(xmlReader, "cibo");
        cibo = xmlReader.readElementText().toStdString();

        if (animali == "leoni") {
            unsigned int ruggito = xmlReader.readElementText().toInt();
            bool criniera = (xmlReader.readElementText().toStdString() == "1");
            const Alimentazione* tipo = new Carnivoro(cibo);

            gameModel.getLeoni().insert(std::make_shared<Leone>(nome, descrizione, eta, sesso, peso, tipo, costo, ruggito, criniera));
        } else if (animali == "coccodrilli") {
            float lunghezza = xmlReader.readElementText().toFloat();
            int denti = xmlReader.readElementText().toInt();
            const Alimentazione* tipo = new Carnivoro(cibo);

            gameModel.getCoccodrilli().insert(std::make_shared<Coccodrillo>(nome, descrizione, eta, sesso, peso, tipo, costo, lunghezza, denti));
        } else if (animali == "pavoni") {
            float ruota = xmlReader.readElementText().toFloat();
            const Alimentazione* tipo = new Onnivoro(cibo);

            gameModel.getPavoni().insert(std::make_shared<Pavone>(nome, descrizione, eta, sesso, peso, tipo, costo, ruota));
        } else if (animali == "tartarughe") {
            float guscioX = xmlReader.readElementText().toFloat();
            float guscioY = xmlReader.readElementText().toFloat();
            const Alimentazione* tipo = new Erbivoro(cibo);

            gameModel.getTartarughe().insert(std::make_shared<Tartaruga>(nome, descrizione, eta, sesso, peso, tipo, costo, guscioX, guscioY));
        } else if (animali == "struzzi") {
            float velocita = xmlReader.readElementText().toFloat();
            const Alimentazione* tipo = new Onnivoro(cibo);

            gameModel.getStruzzi().insert(std::make_shared<Struzzo>(nome, descrizione, eta, sesso, peso, tipo, costo, velocita));
        } else if (animali == "giraffe") {
            float collo = xmlReader.readElementText().toFloat();
            float altezza = xmlReader.readElementText().toFloat();
            const Alimentazione* tipo = new Erbivoro(cibo);

            gameModel.getGiraffe().insert(std::make_shared<Giraffa>(nome, descrizione, eta, sesso, peso, tipo, costo, collo, altezza));
        }
    }
}    


void DataManager::jumpTo(QXmlStreamReader& xmlReader, std::string tag) {
    while (!xmlReader.atEnd()) {
        if (xmlReader.tokenType() == QXmlStreamReader::StartElement && xmlReader.name() == QString::fromStdString(tag))
            break;
        xmlReader.readNext();
    }
}

#include "dataManager.h"


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
        for(size_t i = 0; i<recinto.getSize(); i++){
            xmlWriter->writeStartElement(QString::fromStdString((*recinto[i]).getName()));
            xmlWriter->writeTextElement("nome", QString::fromStdString((*recinto[i]).getName()));
            xmlWriter->writeTextElement("eta", QString::number((*recinto[i]).getEta()));
            xmlWriter->writeTextElement("peso", QString::number((*recinto[i]).getPeso(), 'f'));
            xmlWriter->writeTextElement("cibo", QString::fromStdString((*recinto[i]).getTipo()->getCiboPreferito()));

            //writeDatiAnimale(recinto.getObject(i), xmlWriter);

            //Converto il puntatore in nel suo oggetto appropriato
            if (animali == "leoni") {
                xmlWriter->writeTextElement("ruggito", QString::number((*(std::dynamic_pointer_cast<Leone>(recinto[i]))).getRuggito()));
                xmlWriter->writeTextElement("criniera", (*(std::dynamic_pointer_cast<Leone>(recinto[i]))).hasCriniera() ? "1" : "0");
            } else if (animali == "coccodrillo") {
                xmlWriter->writeTextElement("lunghezza", QString::number((*(std::dynamic_pointer_cast<Coccodrillo>(recinto[i]))).getLunghezza(), 'f'));
                xmlWriter->writeTextElement("numeroDenti", QString::number((*(std::dynamic_pointer_cast<Coccodrillo>(recinto[i]))).getNumeroDenti(), 'f'));
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

/*bool DataManager::writeDatiAnimale(const Leone& l, QXmlStreamWriter* xmlWriter){
    xmlWriter->writeTextElement("ruggito", QString::number(l.getRuggito()));
    xmlWriter->writeTextElement("criniera", l.hasCriniera() ? "1" : "0");
}

bool DataManager::writeDatiAnimale(const Coccodrillo& c, QXmlStreamWriter* xmlWriter){
    xmlWriter->writeTextElement("lunghezza", QString::number(c.getLunghezza(), 'f'));
    xmlWriter->writeTextElement("numeroDenti", QString::number(c.getNumeroDenti()));
}

bool DataManager::writeDatiAnimale(const Pavone& p, QXmlStreamWriter* xmlWriter){
    xmlWriter->writeTextElement("raggioRuota", QString::number(p.getRaggioRuota(), 'f'));
}

bool DataManager::writeDatiAnimale(const Tartaruga& t, QXmlStreamWriter* xmlWriter){
    xmlWriter->writeTextElement("misuraGuscioX", QString::number(t.getMisuraX(), 'f'));
    xmlWriter->writeTextElement("misuraGuscioY", QString::number(t.getMisuraY(), 'f'));
}

bool DataManager::writeDatiAnimale(const Struzzo& s, QXmlStreamWriter* xmlWriter){
    xmlWriter->writeTextElement("velocita", QString::number(s.getVelocitaMax(), 'f'));
}

bool DataManager::writeDatiAnimale(const Giraffa& g, QXmlStreamWriter* xmlWriter){
    xmlWriter->writeTextElement("lunghezzaCollo", QString::number(g.getLunghezzaCollo(), 'f'));
    xmlWriter->writeTextElement("altezza", QString::number(g.getAltezza(), 'f'));
}*/




//Funzione per leggere dati
bool DataManager::readData(const std::string& nome, unsigned int& soldi, DLrecinto& leoni, DLrecinto& coccodrilli, DLrecinto& pavoni, DLrecinto& tartarughe, DLrecinto& struzzi, DLrecinto& giraffe) {
    QString filePath = QString::fromStdString("savedFile/" + nome + ".xml");
    QFile file(filePath);

    if (!file.open(QIODevice::ReadOnly)) {
        qWarning() << "Non è possibile aprire il file per la lettura:" << filePath;
        return false;
    }

    QXmlStreamReader xmlReader(&file);

    while (!xmlReader.atEnd()) {
        if (xmlReader.readNextStartElement()) {
            if (xmlReader.name() == QString::fromStdString("ZOO")) {
                while (xmlReader.readNextStartElement()) {
                    if (xmlReader.name() == QString::fromStdString("soldi")) {
                        soldi = xmlReader.readElementText().toUInt();
                    } else {
                        // Chiamata alla tua funzione readDatiRecinto
                        DLrecinto recinto;
                        if(readDatiRecinto(xmlReader.name().toString().toStdString(), recinto, &xmlReader)){
                            // qui assegna recinto alla variabile corrispondente in base al nome
                        } else {
                            file.close();
                            return false;
                        }
                    }
                }
            }
        }
    }

    if (xmlReader.hasError()) {
        qWarning() << "Errore durante la lettura del file XML:" << xmlReader.errorString();
    }

    file.close();
    return true;
}
//Funzione di aiuto per leggere dati di un singolo recinto
bool DataManager::readDatiRecinto(const std::string& animali, DLrecinto& recinto, QXmlStreamReader* xmlReader){
    if (xmlReader->name() == QString::fromStdString(animali)) {
        while (xmlReader->readNextStartElement()) {
            if (xmlReader->name() == QString::fromStdString("vita")) {
                recinto.setVita(xmlReader->readElementText().toInt());
            } else {
                // Qui dovresti leggere le altre informazioni dell'animale, come eta, peso, ecc.
            }

            if(xmlReader->hasError()){
                return false;
            }
        }
    }
    return true;
}

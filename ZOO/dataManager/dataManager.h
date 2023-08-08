#ifndef DATAMANAGER_H
#define DATAMANAGER_H

#include <QString>
#include <QMap>

#include "../src/Container.h"

class DataManager {
public:
    DataManager(const QString &filePath);
    bool writeData(const QMap<QString, QString> &data);
    QMap<QString, QString> readData();

private:
    QString filePath;
};

#endif // DATAMANAGER_H

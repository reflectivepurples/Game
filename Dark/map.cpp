#include "map.h"
#include <QFile>
#include <QDebug>
#include "iostream"

Map::Map(int level)
{
    loadLevelFromFile(level);
}

Map::~Map()
{

}

void Map::loadLevelFromFile(int level)
{
    QString fileName(":/Levels/Level_" + QString::number(level) + ".txt");
    QFile file(fileName);

    if (!file.open(QIODevice::ReadOnly))
    {
        qDebug() << "Unable to open file";
    }
    else
    {
        QString line;
        while(!file.atEnd())
        {
            // Get one line from the text and remove possible "\r\n"
            line = file.readLine().trimmed();
            levelLayout_.push_back(line);
        }
    }
    file.close();
}

vector<QString> *Map::giveLevelLayout()
{
    return &levelLayout_;
}

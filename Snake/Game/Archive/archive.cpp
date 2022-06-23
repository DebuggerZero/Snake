#include "archive.h"

Archive::Archive() {

}

Archive::Archive(QString gameName)
{
    _gameName = gameName;
}

Archive::~Archive()
{

}

QString Archive::getGameName()
{
    return _gameName;
}

void Archive::setGameName(QString name)
{
    _gameName = name;
}

void Archive::setStartTime(QDateTime startTime)
{
    _startTime = startTime;
}

void Archive::setEndTime(QDateTime endTime)
{
    _endTime = endTime;
    _gameTime += _startTime.msecsTo(_endTime);
    _number++;
}

int Archive::getBestScore()
{
    return _bestScore;
}

void Archive::setBestScore(int bestScore)
{
    _bestScore = bestScore;
}

int Archive::getNumber()
{
    return _number;
}

long Archive::getGameTime()
{
    return _gameTime;
}

void Archive::writeGameStorage()
{
    QString fullPath = PATH + "Game/" + _gameName;
    createDir("Game/" + _gameName + "/");
    QFile file(fullPath + "/data.txt");
    file.open(QIODevice::WriteOnly);
    QTextStream textStream(&file);
    textStream.setEncoding(QStringConverter::Utf8);

    textStream << "name:" << _gameName << Qt::endl;
    textStream << "bestScore:" << QString::number(_bestScore) << Qt::endl;
    textStream << "number:" << QString::number(_number) << Qt::endl;
    textStream << "gameTime:" << QString::number(_gameTime) << Qt::endl;

    file.close();
}

void Archive::readGameStorage()
{
    QString fullPath = PATH + "Game/" + _gameName;
    createDir("Game/" + _gameName + "/");
    QFile file(fullPath + "/data.txt");
    if (!file.exists()) {
        _bestScore = 0;
        _number = 0;
        _gameTime = 0;
        file.close();
        return;
    }
    file.open(QIODevice::ReadOnly);
    QTextStream textStream(&file);
    textStream.setEncoding(QStringConverter::Utf8);

    while (!textStream.atEnd()) {
        QString str = textStream.readLine();
        QStringList list = str.split(":");
        if (list[0] == "name")
            _gameName = list[1];
        else if (list[0] == "bestScore")
            _bestScore = list[1].toInt();
        else if (list[0] == "number")
            _number = list[1].toInt();
        else if (list[0] == "gameTime")
            _gameTime = list[1].toLong();
    }

    file.close();
}

void Archive::createDir(QString path)
{
    QDir dir(PATH + path);
    if (!dir.exists()) {
        dir.mkpath(PATH + path);
    }
}

#ifndef ARCHIVE_H
#define ARCHIVE_H

#include <QString>
#include <QTime>
#include <QDateTime>
#include <QFile>
#include <QDir>

class Archive
{
public:
    Archive();

    Archive(QString gameName);

    ~Archive();

    QString getGameName();

    void setGameName(QString name);

    void setStartTime(QDateTime startTime);

    void setEndTime(QDateTime endTime);

    int getBestScore();

    void setBestScore(int bestScore);

    int getNumber();

    long getGameTime();

    void writeGameStorage();

    void readGameStorage();

private:

    QString _gameName;
    QDateTime _startTime;
    QDateTime _endTime;
    int _bestScore;
    int _number;
    long _gameTime;

    const QString PATH = "C:/MyGame/";

    void createDir(QString path);
};

#endif // ARCHIVE_H

#include "playlist.h"

#include <QFile>
#include <QTextStream>

Playlist::Playlist()
{
    for (int i = 1; i < 11; i++)
    {
        QString filePath = "C:\\Users\\Stephan Alves Dias\\Desktop\\MP3-Player\\MP3-Player\\mp3Tags\\song" + QString::number(i) + ".txt";
        this->loadSongInfo(filePath);
    }
}

void Playlist::loadSongInfo(const QString& filePath)
{
    Song song;
    QFile file(filePath);

    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream in(&file);
        while (!in.atEnd())
        {
            QString line = in.readLine();
            if (line.startsWith("Title:"))
            {
                song.title = line.mid(7).trimmed();
            }
            else if (line.startsWith("Author:"))
            {
                song.author = line.mid(8).trimmed();
            }
            else if (line.startsWith("Genre:"))
            {
                song.genre = line.mid(6).trimmed();
            }
            else if (line.startsWith("Playtime:"))
            {
                song.playtime = line.mid(10).trimmed();
            }
        }
        file.close();
    }
    else
    {
        //qDebug() << "Failed to open file:" << file.errorString();
    }

    songList.push_back(song);
}

QVector<Song> Playlist::getPlaylist() const
{
    return songList;
}

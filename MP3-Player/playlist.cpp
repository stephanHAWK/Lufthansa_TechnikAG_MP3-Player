#include "playlist.h"

#include <QFile>
#include <QTextStream>

Playlist::Playlist() {}

Playlist::~Playlist()
{
    this->songList.clear();
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

void Playlist::removeSong(int index)
{
    if (index >= 0 && index < songList.size())
    {
        songList.erase(songList.begin() + index);
    }
}

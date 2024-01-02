#include "playlist.h"

#include <QFile>
#include <QTextStream>
#include <QFile>
#include <QTextStream>
#include <QFileDialog>

Playlist::Playlist() {}

Playlist::~Playlist() {}

void Playlist::loadSongInfo(QString& filePath)
{
    getFilesData(filePath);
}

void Playlist::addDirectory()
{
    QString folderPath = QFileDialog::getExistingDirectory(nullptr, "Select Folder", QDir::homePath());

    if (!folderPath.isEmpty())
    {
        QDir folder(folderPath);
        QStringList filters;

        // only text files
        filters << "*.txt";

        QFileInfoList fileList = folder.entryInfoList(filters, QDir::Files);

        foreach (const QFileInfo &fileName, fileList)
        {
            getFilesData(fileName.filePath());
        }
    }
}

void Playlist::addSong()
{
    QStringList fileList = QFileDialog::getOpenFileNames(nullptr, "Select File", QString(), "Text Files (*.txt)");

    foreach (const QString &fileName, fileList)
    {
        getFilesData(fileName);
    }
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

void Playlist::getFilesData(QString filePath)
{
    Song song;

    if (!filePath.isEmpty())
    {
        // load file and add the song from the file to the playlist
        QFile file(filePath);

        if (file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            QTextStream in(&file);

            // important to read umlauts (ÜÄÖüäö...)
            in.setCodec("UTF-8");

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

            songList.push_back(song);
            file.close();
        }
        else
        {

        }
    }
}

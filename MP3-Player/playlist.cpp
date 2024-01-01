#include "playlist.h"

#include <QFile>
#include <QTextStream>
#include <QFile>
#include <QTextStream>
#include <QFileDialog>

Playlist::Playlist() {}

Playlist::~Playlist()
{
    //this->songList.clear();
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

void Playlist::addDirectory()
{
    Song song;
    QString folderPath = QFileDialog::getExistingDirectory(nullptr, "Ordner auswählen", QDir::homePath());

    if (!folderPath.isEmpty())
    {
        QDir folder(folderPath);
        QStringList filters;
        filters << "*.txt"; // Nur Textdateien

        QFileInfoList fileList = folder.entryInfoList(filters, QDir::Files);

        foreach (const QFileInfo &fileName, fileList)
        {
            QString filePath = fileName.filePath();

            if (!filePath.isEmpty())
            {
                // Hier kannst du die Datei einlesen und die Playlist aktualisieren
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
                    // Hier kannst du die Playlist weiterverarbeiten (z.B., indem du sie an eine Playlist-Klasse übergibst)
                    // playlist enthält jetzt die Zeilen aus der ausgewählten Textdatei
                    //QMessageBox::information(this, "Erfolg", "Playlist erfolgreich geladen!");
                }
                else
                {
                    //QMessageBox::warning(this, "Fehler", "Fehler beim Öffnen der Datei");
                }
                songList.push_back(song);
            }
        }
    }
}

void Playlist::addSong()
{
    Song song;
    QStringList fileList = QFileDialog::getOpenFileNames(nullptr, "Datei auswählen", QString(), "Textdateien (*.txt)");

    foreach (const QString &fileName, fileList)
    {
        if (!fileName.isEmpty())
        {
            // Hier kannst du die Datei einlesen und die Playlist aktualisieren
            QFile file(fileName);

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
                // Hier kannst du die Playlist weiterverarbeiten (z.B., indem du sie an eine Playlist-Klasse übergibst)
                // playlist enthält jetzt die Zeilen aus der ausgewählten Textdatei
                //QMessageBox::information(this, "Erfolg", "Playlist erfolgreich geladen!");
            }
            else
            {
                //QMessageBox::warning(this, "Fehler", "Fehler beim Öffnen der Datei");
            }
            songList.push_back(song);
        }
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

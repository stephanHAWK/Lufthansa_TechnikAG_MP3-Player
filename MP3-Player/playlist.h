#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <QMainWindow>

struct Song
{
    QString title;
    QString author;
    QString genre;
    QString playtime;
};


class Playlist
{
public:
    Playlist();
    ~Playlist();

    QVector<Song> getPlaylist() const;
    void loadSongInfo(const QString& filePath);
    void addDirectory();
    void addSong();
    void deleteSong();
    void removeSong(int index);

private:
    QVector<Song> songList;
};

#endif // PLAYLIST_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>
#include <QTimer>
#include <QTableWidgetItem>
#include <QString>
#include <QTime>
#include <QRandomGenerator>

#include "playlist.h"


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_play_clicked();
    void playSong();
    void on_pushButton_shuffle_clicked();
    void on_pushButton_previousSong_clicked();
    void onDoubleClickTimerTimeout();
    void on_pushButton_nextSong_clicked();
    void nextSong();
    void on_pushButton_repeat_clicked();
    void on_pushButton_volume_clicked();
    void on_pushButton_fullscreen_clicked();
    void showNormalized();
    void setVolumeIcon(int position);
    void on_horizontalSlider_volumeLevel_valueChanged(int value);
    void handleHorizontalHeaderClicked(int logicalIndex);
    void loadData();
    void tableWidget_setItemsFlags();
    void handleItemEntered(QTableWidgetItem* item);
    void on_tableWidget_itemClicked(QTableWidgetItem *item);
    void on_tableWidget_itemDoubleClicked(QTableWidgetItem *item);
    void playNewSong();
    void on_horizontalSlider_songProgress_valueChanged(int value);
    void on_horizontalSlider_volumeLevel_sliderPressed();
    void on_horizontalSlider_volumeLevel_sliderReleased();
    void on_horizontalSlider_songProgress_sliderPressed();
    void on_horizontalSlider_songProgress_sliderReleased();

private:
    Ui::MainWindow *ui;

    bool songPaused = false;
    bool soundMuted = false;
    bool shuffleOn = false;
    bool repeatOn = true;
    bool repeatOn_onlySong = false;
    bool fullscreen = false;
    bool titleSorted = false;
    bool authorSorted = false;
    bool genreSorted = false;
    bool playtimeSorted = false;
    bool shuffleOn_beginSongList = false;
    bool shuffleOn_previousSong = false;

    int windowHeight;
    int windowWidth;
    int volumePosition;
    int shuffleOn_songIndex = 0;

    Playlist playlist;

    QTimer *timerLongName = nullptr;
    QTimer *timerPassedPlaytime = nullptr;
    QTimer *timerDoubleClick_previousSong = nullptr;

    QTableWidgetItem *item_selectedSong = nullptr;

    QVector<QString> shuffleSongList;
};
#endif // MAINWINDOW_H

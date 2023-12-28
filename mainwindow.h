#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>
#include <QTimer>
#include <QTableWidgetItem>
#include <QString>

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

    void on_pushButton_shuffle_clicked();

    void on_pushButton_previousSong_clicked();

    void on_pushButton_nextSong_clicked();

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

private:
    Ui::MainWindow *ui;

    bool songPaused = false;
    bool soundMuted = false;
    bool fullscreen = false;
    bool titleSorted = false;
    bool authorSorted = false;
    bool genreSorted = false;
    bool playtimeSorted = false;

    int windowHeight;
    int windowWidth;
    int volumePosition;

    Playlist playlist;
    // Member variable to hold the timer
    QTimer *timer = nullptr;
    QTableWidgetItem *item_selectedSong;
};
#endif // MAINWINDOW_H

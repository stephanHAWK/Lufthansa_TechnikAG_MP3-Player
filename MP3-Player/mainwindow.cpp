#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // add text to the buttons when the mouse is over the buttons
    ui->pushButton_addDirectory->setToolTip("add all songs from directory");
    ui->pushButton_addSongToQueue->setToolTip("add a song to the queue");
    ui->pushButton_addSong->setToolTip("add songs");
    ui->pushButton_removeSong->setToolTip("remove selected song");

    // set the central widget layout -> verticalLayout_mp3PlayerLayout expands with the size from centralwidget
    ui->centralwidget->setLayout(ui->verticalLayout_mp3PlayerLayout);

    // connect sectionClicked signal to the handleHorizontalHeaderClicked
    connect(ui->tableWidget->horizontalHeader(), &QHeaderView::sectionClicked, this, &MainWindow::handleHorizontalHeaderClicked);
    // connect itemEntered signal to handleItemEntered
    connect(ui->tableWidget, &QTableWidget::itemEntered, this, &MainWindow::handleItemEntered);

    // set column width from the tableWidget
    // Title
    ui->tableWidget->setColumnWidth(0, 180);
    // Author
    ui->tableWidget->setColumnWidth(1, 180);
    // Genre
    ui->tableWidget->setColumnWidth(2, 150);
    // Playtime
    ui->tableWidget->setColumnWidth(3, 80);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_addDirectory_clicked()
{
    // add the songs from a directory to the playlist
    playlist.addDirectory();

    // filling tableWidget with data
    loadData();
}

void MainWindow::on_pushButton_addSongToQueue_clicked()
{
    if (item_clickedSong != nullptr)
    {
        songQueue.append(item_clickedSong->text());
        queueOn = true;
    }
}

void MainWindow::on_pushButton_addSong_clicked()
{
    playlist.addSong();
    loadData();
}

void MainWindow::on_pushButton_removeSong_clicked()
{
    // only when a item in tableWidget was clicked
    if (item_clickedSong != nullptr)
    {
        playlist.removeSong(item_clickedSong->row());

        // only when a item in tableWidget was selected (yellow highlighted)
        if (item_selectedSong != nullptr)
        {
            // the playing song is also the clicked song (who gets removed)
            if (item_clickedSong->text() == item_selectedSong->text())
            {
                setOldSelectedCellTransparent();
                ui->horizontalSlider_songProgress->setSliderPosition(0);
            }
        }

        loadData();

        // only if the timerPassedPlaytime was initialized
        if (timerPassedPlaytime != nullptr)
        {
            // pause the timer for playing music
            if (timerPassedPlaytime->isActive())
            {
                timerPassedPlaytime->stop();
            }
        }

        ui->pushButton_play->setStyleSheet("QPushButton {"
                                           "border-image: url(:/icons/icons/play.png);"
                                           "background-color: transparent;"
                                           "}"
                                           "QPushButton:hover {"
                                           "border-image: url(:/icons/icons/playHover.png);"
                                           "}"
                                           );

        songPaused = false;


        // disable songProgress slider when there is no item (song) in tableWidget
        bool flag = ui->tableWidget->item(0,0)->text().isNull();

        // the cell is empty
        if (flag)
        {
            ui->horizontalSlider_songProgress->setDisabled(true);
        }


        item_clickedSong = nullptr;
    }
}


// filling tableWidget with data
void MainWindow::loadData()
{
    // set the number of rows to the number of songs in the playlist
    ui->tableWidget->setRowCount(playlist.getPlaylist().size());

    // filling the items with the information of the different songs
    for (int row = 0; row < playlist.getPlaylist().size(); row++)
    {
        ui->tableWidget->setItem(row, 0, new QTableWidgetItem(playlist.getPlaylist().at(row).title));
        ui->tableWidget->setItem(row, 1, new QTableWidgetItem(playlist.getPlaylist().at(row).author));
        ui->tableWidget->setItem(row, 2, new QTableWidgetItem(playlist.getPlaylist().at(row).genre));
        ui->tableWidget->setItem(row, 3, new QTableWidgetItem(playlist.getPlaylist().at(row).playtime));
    }

    // set the flags for the items (not editable)
    tableWidget_setItemsFlags();
}


void MainWindow::on_horizontalSlider_songProgress_valueChanged(int value)
{
    // calculate the time in hours, minutes and seconds
    int hours = value / 3600;
    int minutes = (value % 3600) / 60;
    int seconds = value % 60;

    // set the calculated time in the right format for label_timePassed (hh:mm:ss)
    ui->label_timePassed->setText(QString("%1:%2:%3").arg(hours, 2, 10, QChar('0')).arg(minutes, 2, 10, QChar('0')).arg(seconds, 2, 10, QChar('0')));
    ui->horizontalSlider_songProgress->setValue(value);
}

void MainWindow::on_horizontalSlider_songProgress_sliderPressed()
{
    if (item_selectedSong != nullptr)
    {
        ui->horizontalSlider_songProgress->setStyleSheet("QSlider::groove:horizontal"
                                                         "{"
                                                         "border: 1px solid black;"
                                                         "background: white;"
                                                         "height: 20px;"
                                                         "border-radius: 5px;"
                                                         "}"

                                                         "QSlider::handle:horizontal"
                                                         "{"
                                                         "background: transparent;"
                                                         "background-image: url(:/icons/icons/airplaneHover.png);"
                                                         "border: none;"
                                                         "background-repeat: no-repeat;"
                                                         "width: 40px;"
                                                         "height: 40px;"
                                                         "margin: -2px 0;"
                                                         "}"

                                                         "QSlider::handle:horizontal:hover"
                                                         "{"
                                                         "    background-image: url(:/icons/icons/airplaneHover.png);"
                                                         "}"

                                                         "QSlider::add-page:horizontal {"
                                                         "background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #ccd3df, stop:1 #b3bdcf);"
                                                         "border: none;"
                                                         "border-radius: 5px;"
                                                         "}"
                                                         "QSlider::sub-page:horizontal {"
                                                         "background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 white, stop:1 #f9ba00);"
                                                         "border: none;"
                                                         "border-radius: 5px;"
                                                         "}"
                                                         );
    }
    else
    {
        ui->horizontalSlider_songProgress->setDisabled(true);
    }
}

void MainWindow::on_horizontalSlider_songProgress_sliderReleased()
{
    ui->horizontalSlider_songProgress->setStyleSheet("QSlider::groove:horizontal"
                                                     "{"
                                                     "border: 1px solid black;"
                                                     "background: white;"
                                                     "height: 20px;"
                                                     "border-radius: 5px;"
                                                     "}"

                                                     "QSlider::handle:horizontal"
                                                     "{"
                                                     "background: transparent;"
                                                     "background-image: url(:/icons/icons/airplane.png);"
                                                     "border: none;"
                                                     "background-repeat: no-repeat;"
                                                     "width: 40px;"
                                                     "height: 40px;"
                                                     "margin: -2px 0;"
                                                     "}"

                                                     "QSlider::handle:horizontal:hover"
                                                     "{"
                                                     "    background-image: url(:/icons/icons/airplaneHover.png);"
                                                     "}"

                                                     "QSlider::add-page:horizontal {"
                                                     "background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #ccd3df, stop:1 #b3bdcf);"
                                                     "border: none;"
                                                     "border-radius: 5px;"
                                                     "}"

                                                     "QSlider::sub-page:horizontal {"
                                                     "background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 white, stop:1 #00235f);"
                                                     "border: none;"
                                                     "border-radius: 5px;"
                                                     "}"
                                                     );
}

void MainWindow::on_horizontalSlider_volumeLevel_valueChanged(int value)
{
    setVolumeIcon(value);
}

void MainWindow::on_horizontalSlider_volumeLevel_sliderPressed()
{
    ui->horizontalSlider_volumeLevel->setStyleSheet("QSlider::groove:horizontal"
                                                    "{"
                                                    "border: 1px solid black;"
                                                    "background: white;"
                                                    "height: 20px;"
                                                    "border-radius: 5px;"
                                                    "}"

                                                    "QSlider::handle:horizontal"
                                                    "{"
                                                    "background: transparent;"
                                                    "background-image: url(:/icons/icons/airplaneHover.png);"
                                                    "border: none;"
                                                    "background-repeat: no-repeat;"
                                                    "width: 40px;"
                                                    "height: 40px;"
                                                    "margin: -2px 0;"
                                                    "}"

                                                    "QSlider::handle:horizontal:hover"
                                                    "{"
                                                    "    background-image: url(:/icons/icons/airplaneHover.png);"
                                                    "}"

                                                    "QSlider::add-page:horizontal {"
                                                    "background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #ccd3df, stop:1 #b3bdcf); "
                                                    "border: none;"
                                                    "border-radius: 5px;"
                                                    "}"

                                                    "QSlider::sub-page:horizontal {"
                                                    "background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 white, stop:1 #f9ba00);"
                                                    "border: none;"
                                                    "border-radius: 5px;"
                                                    "}"
                                                    );
}

void MainWindow::on_horizontalSlider_volumeLevel_sliderReleased()
{
    ui->horizontalSlider_volumeLevel->setStyleSheet("QSlider::groove:horizontal"
        "{"
            "border: 1px solid black;"
            "background: white;"
            "height: 20px;"
            "border-radius: 5px;"
        "}"

        "QSlider::handle:horizontal"
        "{"
            "background: transparent;"
            "background-image: url(:/icons/icons/airplane.png);"
            "border: none;"
            "background-repeat: no-repeat;"
            "width: 40px;"
            "height: 40px;"
            "margin: -2px 0;"
        "}"

        "QSlider::handle:horizontal:hover"
        "{"
        "    background-image: url(:/icons/icons/airplaneHover.png);"
        "}"

        /* "right side from handle" */
        "QSlider::add-page:horizontal"
        "{"
            "background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #ccd3df, stop:1 #b3bdcf);"
            "border: none;"
            "border-radius: 5px;"
        "}"

        /* "left side from handle" */
        "QSlider::sub-page:horizontal"
        "{"
            "background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 white, stop:1 #00235f);"
            "border: none;"
            "border-radius: 5px;"
        "}"

    );
}

void MainWindow::setVolumeIcon(int position)
{
    // make sure that the image gets the right icon for each volume position

    if (position > 70)
    {
        ui->pushButton_volume->setStyleSheet("QPushButton {"
                                             "border-image: url(:/icons/icons/volumeHigh.png);"
                                             "background-color: transparent;"
                                             "}"
                                             "QPushButton:hover {"
                                             "border-image: url(:/icons/icons/volumeHighHover.png);"
                                             "}"
                                             );
    }
    else if (position == 0)
    {
        ui->pushButton_volume->setStyleSheet("QPushButton {"
                                             "border-image: url(:/icons/icons/volumeMute.png);"
                                             "background-color: transparent;"
                                             "}"
                                             "QPushButton:hover {"
                                             "border-image: url(:/icons/icons/volumeMuteHover.png);"
                                             "}"
                                             );
    }
    else
    {
        ui->pushButton_volume->setStyleSheet("QPushButton {"
                                             "border-image: url(:/icons/icons/volumeLow.png);"
                                             "background-color: transparent;"
                                             "}"
                                             "QPushButton:hover {"
                                             "border-image: url(:/icons/icons/volumeLowHover.png);"
                                             "}"
                                             );
    }
}


void MainWindow::on_pushButton_fullscreen_clicked()
{
    if (fullscreen == false)
    {
        // save the current size of the window
        windowWidth = width();
        windowHeight = height();

        showFullScreen();

        // action for the menubar
        // close action
        QAction *exitAction = new QAction(QIcon(":/icons/icons/closeWindow.png"), tr("close"), this);
        connect(exitAction, &QAction::triggered, qApp, &QApplication::quit);

        // restore action
        QAction *restoreAction = new QAction(QIcon(":/icons/icons/restoreWindow.png"), tr("restore"), this);
        connect(restoreAction, &QAction::triggered, this, &MainWindow::showNormalized);

        // minimize action
        QAction *minimizeAction = new QAction(QIcon(":/icons/icons/minimizeWindow.png"), tr("minimize"), this);
        connect(minimizeAction, &QAction::triggered, this, &QMainWindow::showMinimized);

        // adding actions to the menubar
        ui->menubar->addAction(exitAction);
        ui->menubar->addAction(restoreAction);
        ui->menubar->addAction(minimizeAction);

        fullscreen = true;
    }
    else
    {
        // set window back to the original size
        showNormalized();
        fullscreen = false;
    }
}

void MainWindow::showNormalized()
{
    // set window back to the original size
    showNormal();
    resize(windowWidth, windowHeight);

    // clear the menubar
    ui->menubar->clear();
}

void MainWindow::on_pushButton_shuffle_clicked()
{
    if (ui->tableWidget->rowCount() != 0)
    {
        // turn shuffle on (shuffle is off)
        if (shuffleOff == true)
        {

            ui->pushButton_shuffle->setStyleSheet("QPushButton {"
                                                  "border-image: url(:/icons/icons/shuffleOn.png);"
                                                  "background-color: transparent;"
                                                  "}"
                                                  "QPushButton:hover {"
                                                  "border-image: url(:/icons/icons/shuffleOnHover.png);"
                                                  "}"
                                                  );

            // store indices in a list to shuffle
            QList<int> rowIndices;
            for (int row = 0; row < playlist.getPlaylist().size(); row++)
            {
                rowIndices << row;
            }

            // shuffle the list of indices randomly
            std::random_shuffle(rowIndices.begin(), rowIndices.end());

            for (int row = 0; row < playlist.getPlaylist().size(); row++)
            {
                int rowIndex = rowIndices.at(0);

                ui->tableWidget->setItem(row, 0, new QTableWidgetItem(playlist.getPlaylist().at(rowIndex).title));
                ui->tableWidget->setItem(row, 1, new QTableWidgetItem(playlist.getPlaylist().at(rowIndex).author));
                ui->tableWidget->setItem(row, 2, new QTableWidgetItem(playlist.getPlaylist().at(rowIndex).genre));
                ui->tableWidget->setItem(row, 3, new QTableWidgetItem(playlist.getPlaylist().at(rowIndex).playtime));

                rowIndices.removeAt(0);
            }

            // start at the first item (song)
            item_selectedSong = ui->tableWidget->item(0,0);

            for (int row = 0; row < ui->tableWidget->rowCount(); row++)
            {
                for (int column = 0; column < ui->tableWidget->columnCount(); column++)
                {
                    QWidget *customWidget = new QWidget;
                    customWidget->setStyleSheet("background-color: transparent;");
                    ui->tableWidget->setCellWidget(row, column, customWidget);
                }
            }
            playSong();
            shuffleOff = false;
        }
        // turn shuffle off (shuffle is on)
        else
        {
            ui->pushButton_shuffle->setStyleSheet("QPushButton {"
                                                  "border-image: url(:/icons/icons/shuffleOff.png);"
                                                  "background-color: transparent;"
                                                  "}"
                                                  "QPushButton:hover {"
                                                  "border-image: url(:/icons/icons/shuffleOffHover.png);"
                                                  "}"
                                                  );


            if (titleSortedAscending == true)
            {
                ui->tableWidget->sortItems(0, Qt::AscendingOrder);
            }
            else if (titleSortedDescending == true)
            {
                ui->tableWidget->sortItems(0, Qt::DescendingOrder);
            }
            else if (authorSortedAscending == true)
            {
                ui->tableWidget->sortItems(1, Qt::AscendingOrder);
            }
            else if (authorSortedDescending == true)
            {
                ui->tableWidget->sortItems(1, Qt::DescendingOrder);
            }
            else if (genreSortedAscending == true)
            {
                ui->tableWidget->sortItems(2, Qt::AscendingOrder);
            }
            else if (genreSortedDescending == true)
            {
                ui->tableWidget->sortItems(2, Qt::DescendingOrder);
            }
            else if (playtimeSortedAscending == true)
            {
                ui->tableWidget->sortItems(3, Qt::AscendingOrder);
            }
            else if (playtimeSortedDescending == true)
            {
                ui->tableWidget->sortItems(3, Qt::DescendingOrder);
            }
            else
            {
                loadData();

                setOldSelectedCellTransparent();
            }


            if (item_selectedSong != nullptr)
            {
                if (item_selectedSong->row() >= 0)
                {
                    for (int column = 0; column < ui->tableWidget->columnCount(); column++)
                    {
                        QWidget *customWidget = new QWidget;
                        customWidget->setStyleSheet("background-color: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #fcdd80, stop:1 #fbd666); color: white;");
                        QLabel *label = new QLabel(ui->tableWidget->item(item_selectedSong->row(), column)->text());
                        label->setAlignment(Qt::AlignLeft);
                        label->setStyleSheet("color: black;");

                        QVBoxLayout *layout = new QVBoxLayout(customWidget);
                        layout->addWidget(label);
                        layout->setContentsMargins(2, 10, 0, 0);
                        ui->tableWidget->setCellWidget(item_selectedSong->row(), column, customWidget);
                    }
                }
            }

            shuffleOff = true;
        }
    }
}

void MainWindow::on_pushButton_previousSong_clicked()
{
    // doubleClick
    if (timerDoubleClick_previousSong != nullptr)
    {
        // check if a element is selected and isn't in the first row
        if (item_selectedSong && item_selectedSong->row() > 0)
        {
            int nextRow = item_selectedSong->row() - 1;

            setOldSelectedCellTransparent();
            // access the previous item in the row from tableWidget
            item_selectedSong = ui->tableWidget->item(nextRow, 0);

            playNewSong();
        }
        // if the song is in the last row then the song start again from the beginning
        else
        {
            ui->horizontalSlider_songProgress->setValue(0);
        }
    }
    // singleClick
    else
    {
        ui->horizontalSlider_songProgress->setValue(0);
    }

    // initialize the timer
    timerDoubleClick_previousSong = new QTimer(ui->pushButton_previousSong);

    // timer only triggers one time
    timerDoubleClick_previousSong->setSingleShot(true);

    // connect the timeout signal of the timer with onDoubleClickTimerTimeout
    connect(timerDoubleClick_previousSong, &QTimer::timeout, this, &MainWindow::onDoubleClickTimerTimeout);

    // start the timer when a double-click occurs
    // 1000 ms (1 second) timeout
    timerDoubleClick_previousSong->start(1000);
}

void MainWindow::onDoubleClickTimerTimeout()
{
    timerDoubleClick_previousSong = nullptr;
}

void MainWindow::on_pushButton_play_clicked()
{
    if (ui->tableWidget->rowCount() != 0)
    {
        if (item_selectedSong == nullptr)
        {
            // start with the first song when nothing is selected
            item_selectedSong = ui->tableWidget->item(0, 0);
        }
        playSong();
    }
}

void MainWindow::playSong()
{
    // set slider selectable
    ui->horizontalSlider_songProgress->setDisabled(false);

    // set the text from label_song to the selected song
    ui->label_song->setText(item_selectedSong->text());

    // playtime from the selected song
    QString playtime = ui->tableWidget->item(item_selectedSong->row(), 3)->text();

    // set the playtime from the song to the ui
    ui->label_timeDuration->setText(playtime);

    // highlight the selected song (all columns in the row yellow background)
    for (int column = 0; column < ui->tableWidget->columnCount(); column++)
    {
        QWidget *customWidget = new QWidget;
        customWidget->setStyleSheet("background-color: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #fcdd80, stop:1 #fbd666); color: white;");

        QLabel *label = new QLabel(ui->tableWidget->item(item_selectedSong->row(), column)->text());
        label->setAlignment(Qt::AlignLeft);
        label->setStyleSheet("color: black;");

        QVBoxLayout *layout = new QVBoxLayout(customWidget);
        layout->addWidget(label);
        layout->setContentsMargins(2, 10, 0, 0);
        ui->tableWidget->setCellWidget(item_selectedSong->row(), column, customWidget);
    }

    // play the song
    if (songPaused == false)
    {
        QTime time = QTime::fromString(playtime, "hh:mm:ss");
        int songDurationInSeconds = time.second() + time.minute() * 60 + time.hour() * 3600;

        // set up the progressBar and connect the timer
        // Set the maximum value based on the playtime
        ui->horizontalSlider_songProgress->setRange(0, songDurationInSeconds);

        // create a QTimer with the parent as ui->progressBar
        timerPassedPlaytime = new QTimer(ui->horizontalSlider_songProgress);
        connect(timerPassedPlaytime, &QTimer::timeout, this, [this]() mutable
                {
                    // calculate hours, minutes, and seconds
                    int hours = ui->horizontalSlider_songProgress->value() / 3600;
                    int minutes = (ui->horizontalSlider_songProgress->value() % 3600) / 60;
                    int seconds = ui->horizontalSlider_songProgress->value() % 60;

                    // format the time and set it to label_timePassed
                    QString formattedTime = QString("%1:%2:%3").arg(hours, 2, 10, QChar('0')).arg(minutes, 2, 10, QChar('0')).arg(seconds, 2, 10, QChar('0'));
                    ui->label_timePassed->setText(formattedTime);

                    ui->horizontalSlider_songProgress->setValue(ui->horizontalSlider_songProgress->value()+1);

                    // check if the maximum value is reached
                    if (ui->horizontalSlider_songProgress->value() >= ui->horizontalSlider_songProgress->maximum())
                    {
                        if (repeatOn_onlySong)
                        {
                            setOldSelectedCellTransparent();

                            item_selectedSong = ui->tableWidget->item(item_selectedSong->row(), 0);

                            playNewSong();
                        }
                        else
                        {
                            // play next Song
                            nextSong();
                        }
                    }
                });

        // Start the timer with a 1000 ms (1 second) interval
        timerPassedPlaytime->start(1000);


        ui->pushButton_play->setStyleSheet("QPushButton {"
                                           "border-image: url(:/icons/icons/pause.png);"
                                           "background-color: transparent;"
                                           "}"
                                           "QPushButton:hover {"
                                           "border-image: url(:/icons/icons/pauseHover.png);"
                                           "}"
                                           );

        songPaused = true;
    }
    // pause the song
    else
    {
        // check if the timer for playing music is active
        if (timerPassedPlaytime->isActive())
        {
            // pause the timer for playing music
            timerPassedPlaytime->stop();
        }

        ui->pushButton_play->setStyleSheet("QPushButton {"
                                           "border-image: url(:/icons/icons/play.png);"
                                           "background-color: transparent;"
                                           "}"
                                           "QPushButton:hover {"
                                           "border-image: url(:/icons/icons/playHover.png);"
                                           "}"
                                           );

        songPaused = false;
    }
}

void MainWindow::on_pushButton_nextSong_clicked()
{
    // only possible if items in tableWidget (songs) are available
    if (ui->tableWidget->rowCount() != 0)
    {
        nextSong();
    }
}

void MainWindow::nextSong()
{
    // check if queue is on
    // queue off
    if (queueOn == false)
    {
        if (item_selectedSong && item_selectedSong->row() < ui->tableWidget->rowCount() - 1)
        {
            setOldSelectedCellTransparent();

            // access the next song (row + 1) in the item from tableWidget
            item_selectedSong = ui->tableWidget->item(item_selectedSong->row() + 1, 0);

            playNewSong();
        }
        else
        {
            // when the end is reached it begins again at the start
            if (repeatOn)
            {
                setOldSelectedCellTransparent();

                item_selectedSong = ui->tableWidget->item(0, 0);

                playNewSong();
            }
        }
    }
    // queue on
    else
    {
        if (!songQueue.isEmpty())
        {
            for (int row = 0; row < ui->tableWidget->rowCount(); row++)
            {
                if (ui->tableWidget->item(row, 0)->text() == songQueue.first())
                {
                    setOldSelectedCellTransparent();

                    // access the first song in the queue
                    item_selectedSong = ui->tableWidget->item(row, 0);

                    // remove the first song in the queue
                    songQueue.removeFirst();

                    playNewSong();
                    break;
                }
            }
        }
        else
        {
            queueOn = false;
        }
    }
}

void MainWindow::playNewSong()
{
    // reset the timer
    if (timerPassedPlaytime != nullptr)
    {
        timerPassedPlaytime->stop();
        delete timerPassedPlaytime;
        timerPassedPlaytime = nullptr;
    }

    songPaused = false;
    ui->horizontalSlider_songProgress->setValue(0);
    playSong();
}

void MainWindow::on_pushButton_repeat_clicked()
{
    // repeat on
    if (repeatOn == false && repeatOn_onlySong == false)
    {
        repeatOn = true;
        repeatOn_onlySong = false;

        ui->pushButton_repeat->setStyleSheet("QPushButton {"
                                             "border-image: url(:/icons/icons/repeatOn.png);"
                                             "background-color: transparent;"
                                             "max-width: 47px;"
                                             "}"
                                             "QPushButton:hover {"
                                             "border-image: url(:/icons/icons/repeatOnHover.png);"
                                             "}"
                                             );

        ui->pushButton_repeat->setGeometry(367, ui->pushButton_repeat->y(), ui->pushButton_repeat->width(), ui->pushButton_repeat->height());
    }
    // repeat only one song
    else if (repeatOn == true && repeatOn_onlySong == false)
    {
        repeatOn = false;
        repeatOn_onlySong = true;

        ui->pushButton_repeat->setStyleSheet("QPushButton {"
                                             "border-image: url(:/icons/icons/repeatOnlySong.png);"
                                             "background-color: transparent;"
                                             "min-width: 51px;"
                                             "}"
                                             "QPushButton:hover {"
                                             "border-image: url(:/icons/icons/repeatOnlySongHover.png);"
                                             "}"
                                             );

        ui->pushButton_repeat->setGeometry(364, ui->pushButton_repeat->y(), ui->pushButton_repeat->width(), ui->pushButton_repeat->height());
    }
    // repeat off
    else
    {
        repeatOn = false;
        repeatOn_onlySong = false;

        ui->pushButton_repeat->setStyleSheet("QPushButton {"
                                             "border-image: url(:/icons/icons/repeatOff.png);"
                                             "background-color: transparent;"
                                             "min-width: 51px;"
                                             "}"
                                             "QPushButton:hover {"
                                             "border-image: url(:/icons/icons/repeatOffHover.png);"
                                             "}"
                                             );

        ui->pushButton_repeat->setGeometry(364, ui->pushButton_repeat->y(), ui->pushButton_repeat->width(), ui->pushButton_repeat->height());
    }
}

void MainWindow::on_pushButton_volume_clicked()
{
    if (soundMuted == false)
    {
        // save the position from the volumeSlider
        volumePosition = ui->horizontalSlider_volumeLevel->sliderPosition();

        // set sliderPostion to 0
        ui->horizontalSlider_volumeLevel->setSliderPosition(0);

        ui->pushButton_volume->setStyleSheet("QPushButton {"
                                             "border-image: url(:/icons/icons/volumeMute.png);"
                                             "background-color: transparent;"
                                             "}"
                                             "QPushButton:hover {"
                                             "border-image: url(:/icons/icons/volumeMuteHover.png);"
                                             "}"
                                             );

        soundMuted = true;
    }
    else
    {
        // set volumeSlider back to the saved position
        ui->horizontalSlider_volumeLevel->setSliderPosition(volumePosition);
        // setting the right icon
        setVolumeIcon(volumePosition);

        soundMuted = false;
    }
}


void MainWindow::on_tableWidget_itemClicked(QTableWidgetItem *item)
{
    // dont set item_clickedSong when the headers are clicked (item->row() == -1)
    if (item->row() >= 0)
    {
        item_clickedSong = ui->tableWidget->item(item->row(), 0);
    }
}

void MainWindow::on_tableWidget_itemDoubleClicked(QTableWidgetItem *item)
{
    // dont set item_selectedSong when the headers are clicked (item->row() == -1)
    if (item->row() >= 0)
    {
        if (item_selectedSong != nullptr)
        {
            setOldSelectedCellTransparent();
        }

        item_selectedSong = ui->tableWidget->item(item->row(), 0);
        playNewSong();
    }
}

void MainWindow::tableWidget_setItemsFlags()
{
    for (int row = 0; row < ui->tableWidget->rowCount(); row++)
    {
        for (int column = 0; column < ui->tableWidget->columnCount(); column++)
        {
            QTableWidgetItem *item = ui->tableWidget->item(row, column);
            if (item)
            {
                // items are selectable but non-editable
                item->setFlags(item->flags() & ~Qt::ItemIsEditable);
            }
        }
    }
}

// text-moving-animation when the mouse enters a item from tableWidget and the text is too long
void MainWindow::handleItemEntered(QTableWidgetItem *item)
{
    // stop the existing timer
    if (timerLongName && timerLongName->isActive())
    {
        timerLongName->stop();
        delete timerLongName;
        timerLongName = nullptr;

        loadData();
    }
    else
    {
        // check if the text is too long
        QString text = item->text();
        if (ui->tableWidget->fontMetrics().horizontalAdvance(text) + 20 > ui->tableWidget->columnWidth(item->column()))
        {
            bool timerStarted = false;

            // start timer for the cell when the text is too long
            timerLongName = new QTimer(ui->tableWidget);
            connect(timerLongName, &QTimer::timeout, [item, text, timerStarted]() mutable
                    {
                        // at the start: add a spacing between the old text and the added text
                        if (timerStarted == false)
                        {
                            text = text.mid(1) + " | " + text.at(0);
                            item->setText(text);

                            timerStarted = true;
                        }
                        else
                        {
                            text = text.mid(1) + text.at(0);
                            item->setText(text);
                        }
                    });
            timerLongName->start(200);
        }
    }
}

// clicked event from the tableWidget headers ("Title", "Author", "Genre", "Playtime")
void MainWindow::handleHorizontalHeaderClicked(int logicalIndex)
{
    // Title:     logicalIndex = 0
    // Author:    logicalIndex = 1
    // Genre:     logicalIndex = 2
    // Playtime:  logicalIndex = 3

    // Title
    if (logicalIndex == 0)
    {
        authorSortedAscending = false;
        genreSortedAscending = false;
        playtimeSortedAscending = false;
        authorSortedDescending = false;
        genreSortedDescending = false;
        playtimeSortedDescending = false;

        if (titleSortedAscending == false)
        {
            ui->tableWidget->sortItems(0, Qt::AscendingOrder);
            titleSortedAscending = true;
            titleSortedDescending = false;
        }
        else
        {
            ui->tableWidget->sortItems(0, Qt::DescendingOrder);
            titleSortedAscending = false;
            titleSortedDescending = true;
        }


        //shuffleOn = true;
        //on_pushButton_shuffle_clicked();
    }
    // Author
    else if (logicalIndex == 1)
    {
        titleSortedAscending = false;
        genreSortedAscending = false;
        playtimeSortedAscending = false;
        titleSortedDescending = false;
        genreSortedDescending = false;
        playtimeSortedDescending = false;

        if (authorSortedAscending == false)
        {
            ui->tableWidget->sortItems(1, Qt::AscendingOrder);
            authorSortedAscending = true;
            authorSortedDescending = false;
        }
        else
        {
            ui->tableWidget->sortItems(1, Qt::DescendingOrder);
            authorSortedAscending = false;
            authorSortedDescending = true;
        }
    }
    // Genre
    else if (logicalIndex == 2)
    {
        titleSortedAscending = false;
        authorSortedAscending = false;
        playtimeSortedAscending = false;
        titleSortedDescending = false;
        authorSortedDescending = false;
        playtimeSortedDescending = false;

        if (genreSortedAscending == false)
        {
            ui->tableWidget->sortItems(2, Qt::AscendingOrder);
            genreSortedAscending = true;
            genreSortedDescending = false;
        }
        else
        {
            ui->tableWidget->sortItems(2, Qt::DescendingOrder);
            genreSortedAscending = false;
            genreSortedDescending = true;
        }
    }
    // Playtime
    else if (logicalIndex == 3)
    {
        titleSortedAscending = false;
        authorSortedAscending = false;
        genreSortedAscending = false;
        titleSortedDescending = false;
        authorSortedDescending = false;
        genreSortedDescending = false;

        if (playtimeSortedAscending == false)
        {
            ui->tableWidget->sortItems(3, Qt::AscendingOrder);
            playtimeSortedAscending = true;
            playtimeSortedDescending = false;
        }
        else
        {
            ui->tableWidget->sortItems(3, Qt::DescendingOrder);
            playtimeSortedAscending = false;
            playtimeSortedDescending = true;
        }
    }
}


// set the background-color for the cells in tableWidget to transparent
// after a song is selected the old highligthed
void MainWindow::setOldSelectedCellTransparent()
{
    if (item_selectedSong != nullptr)
    {
        if (item_selectedSong->row() >= 0)
        {
            QWidget *customWidget = new QWidget;
            customWidget->setStyleSheet("background-color: transparent");
            for (int column = 0; column < ui->tableWidget->columnCount(); column++)
            {
                ui->tableWidget->setCellWidget(item_selectedSong->row(), column, customWidget);
            }
        }
    }
}

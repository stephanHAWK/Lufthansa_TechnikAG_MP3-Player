#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //QFlags flags = Qt::CustomizeWindowHint; //Qt::FramelessWindowHint;
    //this->setWindowFlags(flags);

    ui->verticalLayout_mp3PlayerLayout->addStretch();
    // Set the central widget's layout
    ui->centralwidget->setLayout(ui->verticalLayout_mp3PlayerLayout);

    // Connect the sectionClicked signal to the handleHorizontalHeaderClicked slot.
    connect(ui->tableWidget->horizontalHeader(), &QHeaderView::sectionClicked, this, &MainWindow::handleHorizontalHeaderClicked);
    // Connect the itemEntered and itemExited signals to your custom slots.
    connect(ui->tableWidget, &QTableWidget::itemEntered, this, &MainWindow::handleItemEntered);

    // Title
    ui->tableWidget->setColumnWidth(0, 200);
    // Author
    ui->tableWidget->setColumnWidth(1, 200);
    // Genre
    ui->tableWidget->setColumnWidth(2, 150);
    // Playtime
    ui->tableWidget->setColumnWidth(3, 80);


    // load the data for the tableWidget
    this->loadData();
    this->setCellWidgetsInTableWidget();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_play_clicked()
{
    if (item_selectedSong == nullptr)
    {
        // start with the first song when nothing is selected
        item_selectedSong = ui->tableWidget->item(0, 0);
    }
    this->playSong();
}

void MainWindow::setCellWidgetsInTableWidget()
{
    for (int row = 0; row < ui->tableWidget->rowCount(); row++)
    {
        for (int column = 0; column < ui->tableWidget->columnCount(); column++)
        {
            QWidget *customWidget = new QWidget;
            customWidget->setMouseTracking(true);
            // odd numbers
            if (row % 2 != 0)
            {
                customWidget->setStyleSheet("background-color: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #4d658f, stop:1 #8091af); color: white;");
            }
            // even numbers
            else
            {
                customWidget->setStyleSheet("background-color: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #8091af, stop:1 #b3bdcf); color: white;");
            }
            QLabel *label = new QLabel(ui->tableWidget->item(row, column)->text());
            label->setAlignment(Qt::AlignLeft);
            label->setStyleSheet("color: black;");
            QVBoxLayout *layout = new QVBoxLayout(customWidget);
            layout->addWidget(label);
            layout->setContentsMargins(5, 10, 0, 0);
            ui->tableWidget->setCellWidget(row, column, customWidget);
        }
    }
}

void MainWindow::playSong()
{
    this->setCellWidgetsInTableWidget();

    QString playtime = ui->tableWidget->item(item_selectedSong->row(), 3)->text();

    // set the playtime from the song to the ui
    ui->label_timeDuration->setText(playtime);

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

    /*
    if (shuffleOn_previousSong == false)
    {
        shuffleSongList.append(ui->tableWidget->item(item_selectedSong->row(), 0)->text());
    }
    */

    // pause the song
    if (songPaused == false)
    {
        QTime time = QTime::fromString(playtime, "hh:mm:ss");
        int songDurationInSeconds = time.second() + time.minute() * 60 + time.hour() * 3600;

        // Set up your QProgressBar and connect the timer
        ui->horizontalSlider_songProgress->setRange(0, songDurationInSeconds); // Set the maximum value based on the playtime.

        // Create a QTimer with the parent as ui->progressBar to manage its memory.
        timerPassedPlaytime = new QTimer(ui->horizontalSlider_songProgress);
        connect(timerPassedPlaytime, &QTimer::timeout, this, [this]() mutable
        {
            // Calculate hours, minutes, and seconds
            int hours = ui->horizontalSlider_songProgress->value() / 3600;
            int minutes = (ui->horizontalSlider_songProgress->value() % 3600) / 60;
            int seconds = ui->horizontalSlider_songProgress->value() % 60;

            // Format the time and set it to a label or any relevant widget
            QString formattedTime = QString("%1:%2:%3").arg(hours, 2, 10, QChar('0')).arg(minutes, 2, 10, QChar('0')).arg(seconds, 2, 10, QChar('0'));
            ui->label_timePassed->setText(formattedTime);

            ui->horizontalSlider_songProgress->setValue(ui->horizontalSlider_songProgress->value()+1);

            // Check if the maximum value is reached
            if (ui->horizontalSlider_songProgress->value() >= ui->horizontalSlider_songProgress->maximum())
            {
                if (repeatOn_onlySong)
                {
                    item_selectedSong = ui->tableWidget->item(item_selectedSong->row(), 0);

                    this->playNewSong();
                }
                else
                {
                    // play next Song
                    this->nextSong();
                }
            }
        });

        // Start the timer with a 1000 ms interval (1 second).
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
    // play the song
    else
    {
        // Pausiere den Timer
        if (timerPassedPlaytime->isActive())
        {
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

void MainWindow::on_pushButton_shuffle_clicked()
{
    if (shuffleOn == false)
    {
        shuffleOn = true;

        ui->pushButton_shuffle->setStyleSheet("QPushButton {"
                                              "border-image: url(:/icons/icons/shuffleOn.png);"
                                              "background-color: transparent;"
                                              "}"
                                              "QPushButton:hover {"
                                              "border-image: url(:/icons/icons/shuffleOnHover.png);"
                                              "}"
                                              );

        Playlist playlist;

        for (int i = 1; i < 11; i++)
        {
            QString filePath = "C:\\Users\\Stephan Alves Dias\\Desktop\\MP3-Player\\Lufthansa_MP3-Player\\MP3-Player\\mp3Tags\\song" + QString::number(i) + ".txt";
            playlist.loadSongInfo(filePath);
        }

        // Store indices in a list to shuffle
        QList<int> rowIndices;
        for (int row = 0; row < playlist.getPlaylist().size(); row++)
        {
            rowIndices << row;
        }

        // Shuffle the list of indices randomly
        std::random_shuffle(rowIndices.begin(), rowIndices.end());

        // Update the QTableWidget with shuffled items
        ui->tableWidget->setRowCount(rowIndices.count());

        for (int row = 0; row < playlist.getPlaylist().size(); row++)
        {
            int rowIndex = rowIndices.at(0);

            ui->tableWidget->setItem(row, 0, new QTableWidgetItem(playlist.getPlaylist().at(rowIndex).title));
            ui->tableWidget->setItem(row, 1, new QTableWidgetItem(playlist.getPlaylist().at(rowIndex).author));
            ui->tableWidget->setItem(row, 2, new QTableWidgetItem(playlist.getPlaylist().at(rowIndex).genre));
            ui->tableWidget->setItem(row, 3, new QTableWidgetItem(playlist.getPlaylist().at(rowIndex).playtime));

            rowIndices.removeAt(0);
        }

        // Auf das Element in der nächsten Zeile zugreifen
        item_selectedSong = ui->tableWidget->item(0, 0);
        this->playNewSong();

        /*
        if (item_selectedSong != nullptr)
        {
            shuffleSongList.append(ui->tableWidget->item(item_selectedSong->row(), 0)->text());
        }
        */
    }
    else
    {
        shuffleOn = false;

        ui->pushButton_shuffle->setStyleSheet("QPushButton {"
                                              "border-image: url(:/icons/icons/shuffleOff.png);"
                                              "background-color: transparent;"
                                              "}"
                                              "QPushButton:hover {"
                                              "border-image: url(:/icons/icons/shuffleOffHover.png);"
                                              "}"
                                              );


        // Auf das Element in der nächsten Zeile zugreifen
        if (item_selectedSong == nullptr)
        {
            item_selectedSong = ui->tableWidget->item(0, 0);
        }

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
            this->loadData();
            item_selectedSong = ui->tableWidget->item(0,0);
        }

        this->setCellWidgetsInTableWidget();


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

void MainWindow::on_pushButton_previousSong_clicked()
{
    //if (shuffleOn == false)
    //{
        // doubleClick
        if (timerDoubleClick_previousSong != nullptr)
        {
            // Überprüfen, ob ein Element ausgewählt ist und es nicht in der letzten Zeile ist
            if (item_selectedSong && item_selectedSong->row() > 0)
            {
                int nextRow = item_selectedSong->row() - 1;

                // Auf das Element in der nächsten Zeile zugreifen
                item_selectedSong = ui->tableWidget->item(nextRow, 0);

                this->playNewSong();
            }
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
    //}
    /*
    // shuffleOn == true
    else
    {
        // doubleClick
        if (timerDoubleClick_previousSong != nullptr)
        {
            shuffleOn_previousSong = true;

            if (shuffleOn_beginSongList == false)
            {
                shuffleOn_songIndex = shuffleSongList.size() - 1;
                shuffleOn_beginSongList = true;
            }
            else
            {
                shuffleOn_songIndex--;
                if (shuffleOn_songIndex < 0)
                {
                    shuffleOn_songIndex = 0;
                }
            }

            // Überprüfen, ob lastIndex gültig ist
            if (shuffleOn_songIndex >= 0)
            {
                // Das letzte Element in shuffleSongList
                QString lastSelectedItemText = shuffleSongList[shuffleOn_songIndex];

                // Finden Sie das entsprechende QTableWidgetItem im tableWidget
                QTableWidgetItem* lastSelectedItem = nullptr;
                for (int row = 0; row < ui->tableWidget->rowCount() - 1; row++)
                {
                    if (ui->tableWidget->item(row, 0)->text() == lastSelectedItemText)
                    {
                        lastSelectedItem = ui->tableWidget->item(row, 0);
                        break;
                    }
                }

                item_selectedSong = lastSelectedItem;
                this->playNewSong();
            }
            else
            {
                // shuffleSongList ist leer
                ui->horizontalSlider_songProgress->setValue(0);
            }
        }
        // singleClick
        else
        {
            ui->horizontalSlider_songProgress->setValue(0);
        }
    }
    */

    timerDoubleClick_previousSong = new QTimer(ui->pushButton_previousSong);
    timerDoubleClick_previousSong->setSingleShot(true);  // Der Timer wird nur einmal ausgelöst

    // Verbinden Sie das Timeout-Signal des Timers mit einer benutzerdefinierten Slot-Funktion
    connect(timerDoubleClick_previousSong, &QTimer::timeout, this, &MainWindow::onDoubleClickTimerTimeout);

    // Starten Sie den Timer, wenn ein Doppelklick auftritt
    timerDoubleClick_previousSong->start(1000);  // 1000 Millisekunden (1 Sekunde) Timeout
}

void MainWindow::onDoubleClickTimerTimeout()
{
    timerDoubleClick_previousSong = nullptr;
}

void MainWindow::on_pushButton_nextSong_clicked()
{
    this->nextSong();
}

void MainWindow::nextSong()
{
    //if (shuffleOn == false)
    //{
        // Überprüfen, ob ein Element ausgewählt ist und es nicht in der letzten Zeile ist
        if (item_selectedSong && item_selectedSong->row() < ui->tableWidget->rowCount() - 1)
        {
           // Auf das Element in der nächsten Zeile zugreifen
           item_selectedSong = ui->tableWidget->item(item_selectedSong->row() + 1, 0);

            this->playNewSong();
        }
        else
        {
            // when the end is reached it begins again at the start
            if (repeatOn)
            {
                item_selectedSong = ui->tableWidget->item(0, 0);

                this->playNewSong();
            }
        }
    //}
    /*
    // shuffle is on
    else
    {
        if (shuffleOn_previousSong == true)
        {
            // Das letzte Element in shuffleSongList
            QString lastSelectedItemText = shuffleSongList[shuffleOn_songIndex];

            for (int row = 0; row < ui->tableWidget->rowCount() - 1; row++)
            {
                if (ui->tableWidget->item(row, 0)->text() == lastSelectedItemText)
                {
                    item_selectedSong = ui->tableWidget->item(row, 0);
                    break;
                }
            }

            this->playNewSong();

            shuffleOn_songIndex++;
            if (shuffleOn_songIndex > shuffleSongList.size())
            {
                shuffleOn_previousSong = false;
            }
        }
        else
        {
            if (shuffleSongList.length() != ui->tableWidget->rowCount() - 1)
            {
                int randomNumber;
                for (;;)
                {
                    randomNumber = QRandomGenerator::global()->bounded(ui->tableWidget->rowCount());

                    if (randomNumber != item_selectedSong->row() && !shuffleSongList.contains(ui->tableWidget->item(randomNumber, 0)->text()))
                    {
                        break;
                    }
                }

                // Auf das Element in der nächsten Zeile zugreifen
                item_selectedSong = ui->tableWidget->item(randomNumber, 0);

                this->playNewSong();
            }
            else
            {
                // nextButton deaktivieren
                //ui->label_test->setText("nice");
            }
        }
    }
    */
}

void MainWindow::on_pushButton_repeat_clicked()
{
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
        // save position from the volumeSlider
        volumePosition = ui->horizontalSlider_volumeLevel->sliderPosition();

        // set sliderPostion to 0
        ui->horizontalSlider_volumeLevel->setSliderPosition(0);

        ui->pushButton_volume->setStyleSheet("QPushButton {"
                                             "border-image: url(:/icons/icons/volumeMute.png);"
                                             "max-width: 31px;"
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
        // volumeSlider back to the saved position
        ui->horizontalSlider_volumeLevel->setSliderPosition(volumePosition);
        // setting the right icon
        this->setVolumeIcon(volumePosition);

        soundMuted = false;
    }
}

void MainWindow::on_pushButton_fullscreen_clicked()
{
    if (fullscreen == false)
    {
        // save the current size of the window
        windowWidth = this->height();
        windowHeight = this->height();

        showFullScreen();

        // add to the menubar the actions
        // close
        QAction *exitAction = new QAction(QIcon(":/icons/icons/closeWindow.png"), tr("close"), this);
        connect(exitAction, &QAction::triggered, qApp, &QApplication::quit);

        // restore
        QAction *restoreAction = new QAction(QIcon(":/icons/icons/restoreWindow.png"), tr("restore"), this);
        connect(restoreAction, &QAction::triggered, this, &MainWindow::showNormalized);

        // minimize
        QAction *minimizeAction = new QAction(QIcon(":/icons/icons/minimizeWindow.png"), tr("minimize"), this);
        connect(minimizeAction, &QAction::triggered, this, &QMainWindow::showMinimized);

        ui->menubar->addAction(exitAction);
        ui->menubar->addAction(restoreAction);
        ui->menubar->addAction(minimizeAction);

        fullscreen = true;
    }
    else
    {
        // set window back to the original size
        this->showNormalized();
        fullscreen = false;
    }
}

void MainWindow::showNormalized()
{
    // set window back to the original size

    showNormal();

    this->setMinimumWidth(windowWidth);
    this->setMinimumHeight(windowHeight);

    // delete the menubar
    ui->menubar->clear();
}

void MainWindow::setVolumeIcon(int position)
{
    // make sure that the image gets the right icon for each volume position

    if (position > 70)
    {
        ui->pushButton_volume->setStyleSheet("QPushButton {"
                                             "border-image: url(:/icons/icons/volumeHigh.png);"
                                             "min-width: 51px;"
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
                                             "max-width: 31px;"
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
                                             "max-width: 31px;"
                                             "background-color: transparent;"
                                             "}"
                                             "QPushButton:hover {"
                                             "border-image: url(:/icons/icons/volumeLowHover.png);"
                                             "}"
                                             );
    }
}

void MainWindow::on_horizontalSlider_volumeLevel_valueChanged(int value)
{
    this->setVolumeIcon(value);
}

void MainWindow::handleHorizontalHeaderClicked(int logicalIndex)
{
    // clicked event from the headers ("Title", "Author", "Genre", "Playtime")
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

    if (item_selectedSong == nullptr)
    {
        // start with the first song when nothing is selected
        item_selectedSong = ui->tableWidget->item(0, 0);
    }

    // set the background-color of the rows
    setCellWidgetsInTableWidget();
    shuffleOn = true;
    this->on_pushButton_shuffle_clicked();
}

void MainWindow::loadData()
{
    Playlist playlist;

    for (int i = 1; i < 11; i++)
    {
        QString filePath = "C:\\Users\\Stephan Alves Dias\\Desktop\\MP3-Player\\Lufthansa_MP3-Player\\MP3-Player\\mp3Tags\\song" + QString::number(i) + ".txt";
        playlist.loadSongInfo(filePath);
    }

    ui->tableWidget->setRowCount(playlist.getPlaylist().size());

    for (int row = 0; row < playlist.getPlaylist().size(); row++)
    {
        ui->tableWidget->setItem(row, 0, new QTableWidgetItem(playlist.getPlaylist().at(row).title));
        ui->tableWidget->setItem(row, 1, new QTableWidgetItem(playlist.getPlaylist().at(row).author));
        ui->tableWidget->setItem(row, 2, new QTableWidgetItem(playlist.getPlaylist().at(row).genre));
        ui->tableWidget->setItem(row, 3, new QTableWidgetItem(playlist.getPlaylist().at(row).playtime));
    }

    this->tableWidget_setItemsFlags();
}

void MainWindow::tableWidget_setItemsFlags()
{
    for (int row = 0; row < ui->tableWidget->rowCount(); row++)
    {
        for (int column = 0; column < ui->tableWidget->columnCount(); column++)
        {
            QTableWidgetItem* item = ui->tableWidget->item(row, column);
            if (item)
            {
                // items are selectable but non-editable
                item->setFlags(item->flags() & ~Qt::ItemIsEditable);
            }
        }
    }
}

void MainWindow::handleItemEntered(QTableWidgetItem* item)
{
    // Perform actions when the mouse enters a item from tableWidget

    // Stop the existing timer if any
    if (timerLongName && timerLongName->isActive())
    {
        timerLongName->stop();
        delete timerLongName;
        timerLongName = nullptr;

        this->loadData();
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

void MainWindow::on_tableWidget_itemClicked(QTableWidgetItem *item)
{
    item_selectedSong = ui->tableWidget->item(item->row(), 0);
}

void MainWindow::on_tableWidget_itemDoubleClicked(QTableWidgetItem *item)
{
    //this->shuffleSongList.clear();
    this->playNewSong();
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
    this->playSong();
}

void MainWindow::on_horizontalSlider_songProgress_valueChanged(int value)
{
    // Hier können Sie die Berechnung für Stunden, Minuten und Sekunden durchführen
    int hours = value / 3600;
    int minutes = (value % 3600) / 60;
    int seconds = value % 60;

    // Anzeige der berechneten Zeit im anderen Label
    ui->label_timePassed->setText(QString("%1:%2:%3").arg(hours, 2, 10, QChar('0')).arg(minutes, 2, 10, QChar('0')).arg(seconds, 2, 10, QChar('0')));
    ui->horizontalSlider_songProgress->setValue(value);
}

void MainWindow::on_horizontalSlider_volumeLevel_sliderPressed()
{
    ui->horizontalSlider_volumeLevel->setStyleSheet("QSlider::groove:horizontal {"
                                                    "border: 1px solid black;"
                                                    "background: white;"
                                                    "height: 10px;"
                                                    "border-radius: 5px;"
                                                    "}"
                                                    "QSlider::handle:horizontal {"
                                                    "background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 white, stop:1 #00235f);"
                                                    "border: 1px solid black;"
                                                    "width: 20px;"
                                                    "margin: -2px 0;"
                                                    "border-radius: 5px;"
                                                    "}"
                                                    "QSlider::add-page:horizontal {"
                                                    "background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #ccd3df, stop:1 #b3bdcf); "
                                                    "border: 1px solid black;"
                                                    "border-radius: 5px;"
                                                    "}"
                                                    "QSlider::sub-page:horizontal {"
                                                    "background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 white, stop:1 #f9ba00);"
                                                    "border: 1px solid black;"
                                                    "border-radius: 5px;"
                                                    "}"
                                                    );
}

void MainWindow::on_horizontalSlider_volumeLevel_sliderReleased()
{
    ui->horizontalSlider_volumeLevel->setStyleSheet("QSlider::groove:horizontal {"
                                                    "border: 1px solid black;"
                                                    "background: white;"
                                                    "height: 10px;"
                                                    "border-radius: 5px;"
                                                    "}"
                                                    "QSlider::handle:horizontal {"
                                                    "background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 white, stop:1 #00235f);"
                                                    "border: 1px solid black;"
                                                    "width: 20px;"
                                                    "margin: -2px 0;"
                                                    "border-radius: 5px;"
                                                    "}"
                                                    "QSlider::add-page:horizontal {"
                                                    "background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #ccd3df, stop:1 #b3bdcf); "
                                                    "border: 1px solid black;"
                                                    "border-radius: 5px;"
                                                    "}"
                                                    "QSlider::sub-page:horizontal {"
                                                    "background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 white, stop:1 #00235f);"
                                                    "border: 1px solid black;"
                                                    "border-radius: 5px;"
                                                    "}"
                                                    );
}

void MainWindow::on_horizontalSlider_songProgress_sliderPressed()
{
    ui->horizontalSlider_songProgress->setStyleSheet("QSlider::groove:horizontal {"
                                                    "border: 1px solid black;"
                                                    "background: white;"
                                                    "height: 10px;"
                                                    "border-radius: 5px;"
                                                    "}"
                                                    "QSlider::handle:horizontal {"
                                                    "background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 white, stop:1 #00235f);"
                                                    "border: 1px solid black;"
                                                    "width: 20px;"
                                                    "margin: -2px 0;"
                                                    "border-radius: 5px;"
                                                    "}"
                                                    "QSlider::add-page:horizontal {"
                                                    "background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #ccd3df, stop:1 #b3bdcf);"
                                                    "border: 1px solid black;"
                                                    "border-radius: 5px;"
                                                    "}"
                                                    "QSlider::sub-page:horizontal {"
                                                    "background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 white, stop:1 #f9ba00);"
                                                    "border: 1px solid black;"
                                                    "border-radius: 5px;"
                                                    "}"
                                                    );
}

void MainWindow::on_horizontalSlider_songProgress_sliderReleased()
{
    ui->horizontalSlider_songProgress->setStyleSheet("QSlider::groove:horizontal {"
                                                    "border: 1px solid black;"
                                                    "background: white;"
                                                    "height: 10px;"
                                                    "border-radius: 5px;"
                                                    "}"
                                                    "QSlider::handle:horizontal {"
                                                    "background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 white, stop:1 #00235f);"
                                                    "border: 1px solid black;"
                                                    "width: 20px;"
                                                    "margin: -2px 0;"
                                                    "border-radius: 5px;"
                                                    "}"
                                                    "QSlider::add-page:horizontal {"
                                                    "background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #ccd3df, stop:1 #b3bdcf);"
                                                    "border: 1px solid black;"
                                                    "border-radius: 5px;"
                                                    "}"
                                                    "QSlider::sub-page:horizontal {"
                                                    "background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 white, stop:1 #00235f);"
                                                    "border: 1px solid black;"
                                                    "border-radius: 5px;"
                                                    "}"
                                                    );
}

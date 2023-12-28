#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Connect the sectionClicked signal to the handleHorizontalHeaderClicked slot.
    connect(ui->tableWidget->horizontalHeader(), &QHeaderView::sectionClicked, this, &MainWindow::handleHorizontalHeaderClicked);
    // Connect the itemEntered and itemExited signals to your custom slots.
    connect(ui->tableWidget, &QTableWidget::itemEntered, this, &MainWindow::handleItemEntered);

    // Title
    ui->tableWidget->setColumnWidth(0, 150);
    // Author
    ui->tableWidget->setColumnWidth(1, 200);
    // Genre
    ui->tableWidget->setColumnWidth(2, 150);
    // Playtime
    ui->tableWidget->setColumnWidth(3, 80);

    // load the data for the tableWidget
    this->loadData();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_play_clicked()
{
    if (songPaused == false)
    {
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
    else
    {
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

     item_selectedSong->row(), 3;
    ui->label_timeDuration->setText(item->text());
}

void MainWindow::on_pushButton_shuffle_clicked()
{

}


void MainWindow::on_pushButton_previousSong_clicked()
{

}


void MainWindow::on_pushButton_nextSong_clicked()
{

}


void MainWindow::on_pushButton_repeat_clicked()
{

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
        authorSorted = false;
        genreSorted = false;
        playtimeSorted = false;

        this->loadData();

        if (titleSorted == false)
        {
            ui->tableWidget->sortItems(0, Qt::AscendingOrder);
            titleSorted = true;
        }
        else
        {
            ui->tableWidget->sortItems(0, Qt::DescendingOrder);
            titleSorted = false;
        }
    }
    // Author
    else if (logicalIndex == 1)
    {
        titleSorted = false;
        genreSorted = false;
        playtimeSorted = false;

        this->loadData();

        if (authorSorted == false)
        {
            ui->tableWidget->sortItems(1, Qt::AscendingOrder);
            authorSorted = true;
        }
        else
        {
            ui->tableWidget->sortItems(1, Qt::DescendingOrder);
            authorSorted = false;
        }
    }
    // Genre
    else if (logicalIndex == 2)
    {
        titleSorted = false;
        authorSorted = false;
        playtimeSorted = false;

        this->loadData();

        if (genreSorted == false)
        {
            ui->tableWidget->sortItems(2, Qt::AscendingOrder);
            genreSorted = true;
        }
        else
        {
            ui->tableWidget->sortItems(2, Qt::DescendingOrder);
            genreSorted = false;
        }
    }
    // Playtime
    else if (logicalIndex == 3)
    {
        titleSorted = false;
        authorSorted = false;
        genreSorted = false;

        this->loadData();

        if (playtimeSorted == false)
        {
            ui->tableWidget->sortItems(3, Qt::AscendingOrder);
            playtimeSorted = true;
        }
        else
        {
            ui->tableWidget->sortItems(3, Qt::DescendingOrder);
            playtimeSorted = false;
        }
    }
}

void MainWindow::loadData()
{
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
    if (timer && timer->isActive())
    {
        timer->stop();
        delete timer;
        timer = nullptr;

        this->loadData();
    }
    else
    {
        // check if the text is too long
        QString text = item->text();
        if (ui->tableWidget->fontMetrics().horizontalAdvance(text) + 20 > ui->tableWidget->columnWidth(item->column()))
        {
            bool timerStarted = false;

            // start timer for each cell with long text
            timer = new QTimer(ui->tableWidget);
            connect(timer, &QTimer::timeout, [item, text, timerStarted]() mutable
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
            timer->start(200);
        }
    }
}

void MainWindow::on_tableWidget_itemClicked(QTableWidgetItem *item)
{
    item_selectedSong = item;
    item = ui->tableWidget->item(item->row(), 0);
    ui->label_test->setText(item->text());
}


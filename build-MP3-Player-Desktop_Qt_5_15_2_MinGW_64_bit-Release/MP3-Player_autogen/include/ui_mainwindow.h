/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_mp3PlayerLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_2;
    QTableWidget *tableWidget;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *pushButton_addSongToQueue;
    QPushButton *pushButton_removeSong;
    QPushButton *pushButton_addSong;
    QPushButton *pushButton_addDirectory;
    QSpacerItem *horizontalSpacer_8;
    QSpacerItem *verticalSpacer_5;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_10;
    QLabel *label_song;
    QSpacerItem *horizontalSpacer_9;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_songInfos;
    QLabel *label_timeDuration;
    QSlider *horizontalSlider_songProgress;
    QLabel *label_timePassed;
    QSpacerItem *verticalSpacer_4;
    QHBoxLayout *horizontalLayout_songButtons;
    QSlider *horizontalSlider_volumeLevel;
    QPushButton *pushButton_volume;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *pushButton_repeat;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *pushButton_nextSong;
    QPushButton *pushButton_play;
    QPushButton *pushButton_previousSong;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButton_shuffle;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *pushButton_fullscreen;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1000, 800);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(800, 600));
        MainWindow->setCursor(QCursor(Qt::PointingHandCursor));
        MainWindow->setMouseTracking(false);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/icons/logo.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setLayoutDirection(Qt::RightToLeft);
        MainWindow->setAutoFillBackground(false);
        MainWindow->setStyleSheet(QString::fromUtf8("QMainWindow\n"
"{\n"
"	background-color: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #667b9f, stop:1 #1a396f);\n"
"}"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy1);
        centralwidget->setLayoutDirection(Qt::RightToLeft);
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 50, 800, 635));
        verticalLayout_mp3PlayerLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_mp3PlayerLayout->setSpacing(0);
        verticalLayout_mp3PlayerLayout->setObjectName(QString::fromUtf8("verticalLayout_mp3PlayerLayout"));
        verticalLayout_mp3PlayerLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        tableWidget = new QTableWidget(verticalLayoutWidget);
        if (tableWidget->columnCount() < 4)
            tableWidget->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setTextAlignment(Qt::AlignLeading|Qt::AlignVCenter);
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setTextAlignment(Qt::AlignLeading|Qt::AlignVCenter);
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setTextAlignment(Qt::AlignLeading|Qt::AlignVCenter);
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setTextAlignment(Qt::AlignLeading|Qt::AlignVCenter);
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(tableWidget->sizePolicy().hasHeightForWidth());
        tableWidget->setSizePolicy(sizePolicy2);
        tableWidget->setMinimumSize(QSize(660, 380));
        tableWidget->setMaximumSize(QSize(16777215, 16777215));
        tableWidget->setMouseTracking(true);
        tableWidget->setTabletTracking(true);
        tableWidget->setToolTipDuration(-1);
        tableWidget->setLayoutDirection(Qt::LeftToRight);
        tableWidget->setAutoFillBackground(true);
        tableWidget->setStyleSheet(QString::fromUtf8("QTableWidget\n"
"{\n"
"	background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #ccd3df, stop:1 #8091af); \n"
"}\n"
"\n"
"QHeaderView\n"
"{ \n"
"	background-color: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #ccd3df, stop:1 #b3bdcf); \n"
"}\n"
"\n"
"QHeaderView::section\n"
"{ \n"
"	background-color: transparent; \n"
"	border: 1px solid black;\n"
"	padding-left:  5px;\n"
"}\n"
"\n"
"QTableWidget::item\n"
"{\n"
"	color: black;\n"
"	background-color: transparent;\n"
"	border-bottom: 1px solid black; \n"
"	border-top: 1px solid black;\n"
"}\n"
"\n"
"QTableWidget::item:hover\n"
"{\n"
"	background-color: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #8091af, stop:1#99a7bf);\n"
"    border: 1px solid black;\n"
"}\n"
"\n"
"QTableWidget::item:selected\n"
"{\n"
"	background-color: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #8091af, stop:1#99a7bf);\n"
"    border: 1px solid black;\n"
"}\n"
"\n"
"QTableWidget::cell\n"
"{\n"
"	background-color: transparent;\n"
"}"));
        tableWidget->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        tableWidget->horizontalHeader()->setCascadingSectionResizes(false);

        horizontalLayout_3->addWidget(tableWidget);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(7);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_5 = new QSpacerItem(620, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);

        pushButton_addSongToQueue = new QPushButton(verticalLayoutWidget);
        pushButton_addSongToQueue->setObjectName(QString::fromUtf8("pushButton_addSongToQueue"));
        sizePolicy.setHeightForWidth(pushButton_addSongToQueue->sizePolicy().hasHeightForWidth());
        pushButton_addSongToQueue->setSizePolicy(sizePolicy);
        pushButton_addSongToQueue->setMinimumSize(QSize(51, 45));
        pushButton_addSongToQueue->setBaseSize(QSize(0, 0));
        QFont font;
        font.setBold(true);
        pushButton_addSongToQueue->setFont(font);
        pushButton_addSongToQueue->setMouseTracking(true);
        pushButton_addSongToQueue->setToolTipDuration(-1);
        pushButton_addSongToQueue->setLayoutDirection(Qt::RightToLeft);
        pushButton_addSongToQueue->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	background-color: transparent;\n"
"	border-image: url(:/icons/icons/songQueue.png); \n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"	border-image: url(:/icons/icons/songQueueHover.png); \n"
"}"));
        pushButton_addSongToQueue->setIconSize(QSize(20, 20));

        horizontalLayout_2->addWidget(pushButton_addSongToQueue);

        pushButton_removeSong = new QPushButton(verticalLayoutWidget);
        pushButton_removeSong->setObjectName(QString::fromUtf8("pushButton_removeSong"));
        sizePolicy.setHeightForWidth(pushButton_removeSong->sizePolicy().hasHeightForWidth());
        pushButton_removeSong->setSizePolicy(sizePolicy);
        pushButton_removeSong->setMinimumSize(QSize(41, 41));
        pushButton_removeSong->setBaseSize(QSize(0, 0));
        pushButton_removeSong->setFont(font);
        pushButton_removeSong->setMouseTracking(true);
        pushButton_removeSong->setLayoutDirection(Qt::RightToLeft);
        pushButton_removeSong->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	background-color: transparent;\n"
"	border-image: url(:/icons/icons/minus.png); \n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"	border-image: url(:/icons/icons/minusHover.png); \n"
"}"));
        pushButton_removeSong->setIconSize(QSize(20, 20));

        horizontalLayout_2->addWidget(pushButton_removeSong);

        pushButton_addSong = new QPushButton(verticalLayoutWidget);
        pushButton_addSong->setObjectName(QString::fromUtf8("pushButton_addSong"));
        sizePolicy.setHeightForWidth(pushButton_addSong->sizePolicy().hasHeightForWidth());
        pushButton_addSong->setSizePolicy(sizePolicy);
        pushButton_addSong->setMinimumSize(QSize(41, 41));
        pushButton_addSong->setBaseSize(QSize(0, 0));
        pushButton_addSong->setFont(font);
        pushButton_addSong->setMouseTracking(true);
        pushButton_addSong->setToolTipDuration(-1);
        pushButton_addSong->setLayoutDirection(Qt::RightToLeft);
        pushButton_addSong->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	background-color: transparent;\n"
"	border-image: url(:/icons/icons/plus.png); \n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"	border-image: url(:/icons/icons/plusHover.png); \n"
"}"));
        pushButton_addSong->setIconSize(QSize(20, 20));

        horizontalLayout_2->addWidget(pushButton_addSong);

        pushButton_addDirectory = new QPushButton(verticalLayoutWidget);
        pushButton_addDirectory->setObjectName(QString::fromUtf8("pushButton_addDirectory"));
        sizePolicy.setHeightForWidth(pushButton_addDirectory->sizePolicy().hasHeightForWidth());
        pushButton_addDirectory->setSizePolicy(sizePolicy);
        pushButton_addDirectory->setMinimumSize(QSize(51, 51));
        pushButton_addDirectory->setBaseSize(QSize(0, 0));
        pushButton_addDirectory->setFont(font);
        pushButton_addDirectory->setMouseTracking(true);
        pushButton_addDirectory->setToolTipDuration(-1);
        pushButton_addDirectory->setLayoutDirection(Qt::RightToLeft);
        pushButton_addDirectory->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	background-color: transparent;\n"
"	border-image: url(:/icons/icons/directory.png); \n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"	border-image: url(:/icons/icons/directoryHover.png); \n"
"}"));
        pushButton_addDirectory->setIconSize(QSize(20, 20));

        horizontalLayout_2->addWidget(pushButton_addDirectory);

        horizontalSpacer_8 = new QSpacerItem(620, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_8);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer_5 = new QSpacerItem(18, 518, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_5);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_10);

        label_song = new QLabel(verticalLayoutWidget);
        label_song->setObjectName(QString::fromUtf8("label_song"));
        sizePolicy.setHeightForWidth(label_song->sizePolicy().hasHeightForWidth());
        label_song->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setPointSize(13);
        label_song->setFont(font1);

        horizontalLayout->addWidget(label_song);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_9);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer_3 = new QSpacerItem(18, 518, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        horizontalLayout_songInfos = new QHBoxLayout();
        horizontalLayout_songInfos->setSpacing(6);
        horizontalLayout_songInfos->setObjectName(QString::fromUtf8("horizontalLayout_songInfos"));
        horizontalLayout_songInfos->setSizeConstraint(QLayout::SetDefaultConstraint);
        label_timeDuration = new QLabel(verticalLayoutWidget);
        label_timeDuration->setObjectName(QString::fromUtf8("label_timeDuration"));
        sizePolicy.setHeightForWidth(label_timeDuration->sizePolicy().hasHeightForWidth());
        label_timeDuration->setSizePolicy(sizePolicy);
        label_timeDuration->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	color: gray;\n"
"}"));

        horizontalLayout_songInfos->addWidget(label_timeDuration);

        horizontalSlider_songProgress = new QSlider(verticalLayoutWidget);
        horizontalSlider_songProgress->setObjectName(QString::fromUtf8("horizontalSlider_songProgress"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(horizontalSlider_songProgress->sizePolicy().hasHeightForWidth());
        horizontalSlider_songProgress->setSizePolicy(sizePolicy3);
        horizontalSlider_songProgress->setLayoutDirection(Qt::LeftToRight);
        horizontalSlider_songProgress->setStyleSheet(QString::fromUtf8("QSlider::groove:horizontal \n"
"{\n"
"    border: 1px solid black;\n"
"    background: white;\n"
"    height: 20px;\n"
"    border-radius: 5px;\n"
"}\n"
"\n"
"QSlider::handle:horizontal \n"
"{\n"
"    /*background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 white, stop:1 #00235f);*/\n"
"	background: transparent;\n"
"	background-image: url(:/icons/icons/airplane.png);\n"
"    border: none;\n"
"	background-repeat: no-repeat;\n"
"    width: 40px;\n"
"    height: 40px;\n"
"    margin: -2px 0;\n"
"}\n"
"\n"
"QSlider::handle:horizontal:hover\n"
"{\n"
"	background-image: url(:/icons/icons/airplaneHover.png);\n"
"}\n"
"\n"
"/* right side from handle */\n"
"QSlider::add-page:horizontal\n"
" {\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #ccd3df, stop:1 #b3bdcf);  \n"
"    border: none;\n"
"	border-radius: 5px;\n"
"}\n"
"\n"
" /* left side from handle */\n"
"QSlider::sub-page:horizontal\n"
" {\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 white, stop:1 #00235f);\n"
"    bor"
                        "der: none;\n"
"	border-radius: 5px;\n"
"}"));
        horizontalSlider_songProgress->setMaximum(100);
        horizontalSlider_songProgress->setPageStep(1);
        horizontalSlider_songProgress->setSliderPosition(0);
        horizontalSlider_songProgress->setOrientation(Qt::Horizontal);

        horizontalLayout_songInfos->addWidget(horizontalSlider_songProgress);

        label_timePassed = new QLabel(verticalLayoutWidget);
        label_timePassed->setObjectName(QString::fromUtf8("label_timePassed"));
        sizePolicy.setHeightForWidth(label_timePassed->sizePolicy().hasHeightForWidth());
        label_timePassed->setSizePolicy(sizePolicy);
        label_timePassed->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	color: gray;\n"
"}"));

        horizontalLayout_songInfos->addWidget(label_timePassed);


        verticalLayout->addLayout(horizontalLayout_songInfos);

        verticalSpacer_4 = new QSpacerItem(18, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_4);

        horizontalLayout_songButtons = new QHBoxLayout();
        horizontalLayout_songButtons->setSpacing(0);
        horizontalLayout_songButtons->setObjectName(QString::fromUtf8("horizontalLayout_songButtons"));
        horizontalLayout_songButtons->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalSlider_volumeLevel = new QSlider(verticalLayoutWidget);
        horizontalSlider_volumeLevel->setObjectName(QString::fromUtf8("horizontalSlider_volumeLevel"));
        sizePolicy.setHeightForWidth(horizontalSlider_volumeLevel->sizePolicy().hasHeightForWidth());
        horizontalSlider_volumeLevel->setSizePolicy(sizePolicy);
        horizontalSlider_volumeLevel->setMinimumSize(QSize(200, 0));
        horizontalSlider_volumeLevel->setMaximumSize(QSize(16777215, 16777215));
        horizontalSlider_volumeLevel->setLayoutDirection(Qt::LeftToRight);
        horizontalSlider_volumeLevel->setStyleSheet(QString::fromUtf8("QSlider::groove:horizontal \n"
"{\n"
"    border: 1px solid black;\n"
"    background: white;\n"
"    height: 20px;\n"
"    border-radius: 5px;\n"
"}\n"
"\n"
"QSlider::handle:horizontal \n"
"{\n"
"    /*background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 white, stop:1 #00235f);*/\n"
"	background: transparent;\n"
"	background-image: url(:/icons/icons/airplane.png);\n"
"    border: none;\n"
"	background-repeat: no-repeat;\n"
"    width: 40px;\n"
"    height: 40px;\n"
"    margin: -2px 0;\n"
"}\n"
"\n"
"QSlider::handle:horizontal:hover\n"
"{\n"
"	background-image: url(:/icons/icons/airplaneHover.png);\n"
"}\n"
"\n"
"/* right side from handle */\n"
"QSlider::add-page:horizontal\n"
" {\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #ccd3df, stop:1 #b3bdcf);  \n"
"    border: none;\n"
"	border-radius: 5px;\n"
"}\n"
"\n"
" /*  left side from handle */\n"
"QSlider::sub-page:horizontal\n"
" {\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 white, stop:1 #00235f);\n"
"    bo"
                        "rder: none;\n"
"	border-radius: 5px;\n"
"}"));
        horizontalSlider_volumeLevel->setMaximum(100);
        horizontalSlider_volumeLevel->setSliderPosition(50);
        horizontalSlider_volumeLevel->setOrientation(Qt::Horizontal);

        horizontalLayout_songButtons->addWidget(horizontalSlider_volumeLevel);

        pushButton_volume = new QPushButton(verticalLayoutWidget);
        pushButton_volume->setObjectName(QString::fromUtf8("pushButton_volume"));
        sizePolicy.setHeightForWidth(pushButton_volume->sizePolicy().hasHeightForWidth());
        pushButton_volume->setSizePolicy(sizePolicy);
        pushButton_volume->setMinimumSize(QSize(51, 31));
        pushButton_volume->setBaseSize(QSize(0, 0));
        pushButton_volume->setFont(font);
        pushButton_volume->setMouseTracking(true);
        pushButton_volume->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	background-color: transparent;\n"
"	border-image: url(:/icons/icons/volumeLow.png); \n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"	border-image: url(:/icons/icons/volumeLowHover.png);\n"
"}"));
        pushButton_volume->setIconSize(QSize(20, 20));

        horizontalLayout_songButtons->addWidget(pushButton_volume);

        horizontalSpacer_7 = new QSpacerItem(31, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_songButtons->addItem(horizontalSpacer_7);

        pushButton_repeat = new QPushButton(verticalLayoutWidget);
        pushButton_repeat->setObjectName(QString::fromUtf8("pushButton_repeat"));
        sizePolicy.setHeightForWidth(pushButton_repeat->sizePolicy().hasHeightForWidth());
        pushButton_repeat->setSizePolicy(sizePolicy);
        pushButton_repeat->setMinimumSize(QSize(51, 51));
        pushButton_repeat->setFont(font);
        pushButton_repeat->setMouseTracking(true);
        pushButton_repeat->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	background-color: transparent;\n"
"	border-image: url(:/icons/icons/repeatOff.png);\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"	border-image: url(:/icons/icons/repeatOffHover.png);\n"
"}"));

        horizontalLayout_songButtons->addWidget(pushButton_repeat);

        horizontalSpacer_4 = new QSpacerItem(31, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_songButtons->addItem(horizontalSpacer_4);

        pushButton_nextSong = new QPushButton(verticalLayoutWidget);
        pushButton_nextSong->setObjectName(QString::fromUtf8("pushButton_nextSong"));
        sizePolicy.setHeightForWidth(pushButton_nextSong->sizePolicy().hasHeightForWidth());
        pushButton_nextSong->setSizePolicy(sizePolicy);
        pushButton_nextSong->setMinimumSize(QSize(31, 31));
        pushButton_nextSong->setFont(font);
        pushButton_nextSong->setMouseTracking(true);
        pushButton_nextSong->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	background-color: transparent;\n"
"	border-image: url(:/icons/icons/next.png);\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"	border-image: url(:/icons/icons/nextHover.png);\n"
"}"));

        horizontalLayout_songButtons->addWidget(pushButton_nextSong);

        pushButton_play = new QPushButton(verticalLayoutWidget);
        pushButton_play->setObjectName(QString::fromUtf8("pushButton_play"));
        pushButton_play->setEnabled(true);
        QSizePolicy sizePolicy4(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(22);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(pushButton_play->sizePolicy().hasHeightForWidth());
        pushButton_play->setSizePolicy(sizePolicy4);
        pushButton_play->setMinimumSize(QSize(71, 71));
        pushButton_play->setBaseSize(QSize(0, 0));
        QFont font2;
        font2.setBold(false);
        pushButton_play->setFont(font2);
        pushButton_play->setMouseTracking(true);
        pushButton_play->setToolTipDuration(-1);
        pushButton_play->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	background-color: transparent;\n"
"	border-image: url(:/icons/icons/play.png);\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"	border-image: url(:/icons/icons/playHover.png);\n"
"}"));
        pushButton_play->setIconSize(QSize(34, 20));

        horizontalLayout_songButtons->addWidget(pushButton_play);

        pushButton_previousSong = new QPushButton(verticalLayoutWidget);
        pushButton_previousSong->setObjectName(QString::fromUtf8("pushButton_previousSong"));
        sizePolicy.setHeightForWidth(pushButton_previousSong->sizePolicy().hasHeightForWidth());
        pushButton_previousSong->setSizePolicy(sizePolicy);
        pushButton_previousSong->setMinimumSize(QSize(31, 31));
        pushButton_previousSong->setFont(font);
        pushButton_previousSong->setMouseTracking(true);
        pushButton_previousSong->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	background-color: transparent;\n"
"	border-image: url(:/icons/icons/previous.png);\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"	border-image: url(:/icons/icons/previousHover.png);\n"
"}"));

        horizontalLayout_songButtons->addWidget(pushButton_previousSong);

        horizontalSpacer_3 = new QSpacerItem(30, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_songButtons->addItem(horizontalSpacer_3);

        pushButton_shuffle = new QPushButton(verticalLayoutWidget);
        pushButton_shuffle->setObjectName(QString::fromUtf8("pushButton_shuffle"));
        sizePolicy.setHeightForWidth(pushButton_shuffle->sizePolicy().hasHeightForWidth());
        pushButton_shuffle->setSizePolicy(sizePolicy);
        pushButton_shuffle->setMinimumSize(QSize(51, 41));
        pushButton_shuffle->setFont(font);
        pushButton_shuffle->setMouseTracking(true);
        pushButton_shuffle->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	background-color: transparent;\n"
"	border-image: url(:/icons/icons/shuffleOff.png);\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"	border-image: url(:/icons/icons/shuffleOffHover.png);\n"
"}"));

        horizontalLayout_songButtons->addWidget(pushButton_shuffle);

        horizontalSpacer_6 = new QSpacerItem(31, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_songButtons->addItem(horizontalSpacer_6);

        pushButton_fullscreen = new QPushButton(verticalLayoutWidget);
        pushButton_fullscreen->setObjectName(QString::fromUtf8("pushButton_fullscreen"));
        sizePolicy.setHeightForWidth(pushButton_fullscreen->sizePolicy().hasHeightForWidth());
        pushButton_fullscreen->setSizePolicy(sizePolicy);
        pushButton_fullscreen->setMinimumSize(QSize(41, 41));
        pushButton_fullscreen->setBaseSize(QSize(0, 0));
        pushButton_fullscreen->setFont(font);
        pushButton_fullscreen->setMouseTracking(true);
        pushButton_fullscreen->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	background-color: transparent;\n"
"	border-image: url(:/icons/icons/fullscreen.png); \n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"	background-color: transparent;\n"
"	border-image: url(:/icons/icons/fullscreenHover.png); \n"
"}"));
        pushButton_fullscreen->setIconSize(QSize(20, 20));

        horizontalLayout_songButtons->addWidget(pushButton_fullscreen);


        verticalLayout->addLayout(horizontalLayout_songButtons);


        verticalLayout_mp3PlayerLayout->addLayout(verticalLayout);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1000, 25));
        menubar->setLayoutDirection(Qt::RightToLeft);
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MP3-Player", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "Title", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Author", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Genre", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "Playtime", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_addSongToQueue->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        pushButton_addSongToQueue->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
        pushButton_addSongToQueue->setText(QString());
        pushButton_removeSong->setText(QString());
#if QT_CONFIG(tooltip)
        pushButton_addSong->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        pushButton_addSong->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
        pushButton_addSong->setText(QString());
#if QT_CONFIG(tooltip)
        pushButton_addDirectory->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        pushButton_addDirectory->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
        pushButton_addDirectory->setText(QString());
        label_song->setText(QString());
        label_timeDuration->setText(QCoreApplication::translate("MainWindow", "00:00:00", nullptr));
        label_timePassed->setText(QCoreApplication::translate("MainWindow", "00:00:00", nullptr));
        pushButton_volume->setText(QString());
        pushButton_repeat->setText(QString());
        pushButton_nextSong->setText(QString());
#if QT_CONFIG(tooltip)
        pushButton_play->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(statustip)
        pushButton_play->setStatusTip(QString());
#endif // QT_CONFIG(statustip)
#if QT_CONFIG(whatsthis)
        pushButton_play->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
        pushButton_play->setText(QString());
        pushButton_previousSong->setText(QString());
        pushButton_shuffle->setText(QString());
        pushButton_fullscreen->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

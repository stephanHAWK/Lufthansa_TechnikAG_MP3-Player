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
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton_play;
    QPushButton *pushButton_nextSong;
    QPushButton *pushButton_previousSong;
    QPushButton *pushButton_shuffle;
    QPushButton *pushButton_repeat;
    QProgressBar *progressBar;
    QLabel *label_timePassed;
    QLabel *label_timeDuration;
    QLabel *label_test;
    QPushButton *pushButton_volume;
    QSlider *horizontalSlider_volumeLevel;
    QPushButton *pushButton_fullscreen;
    QTableWidget *tableWidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        MainWindow->setCursor(QCursor(Qt::PointingHandCursor));
        MainWindow->setMouseTracking(false);
        MainWindow->setLayoutDirection(Qt::RightToLeft);
        MainWindow->setStyleSheet(QString::fromUtf8("QMainWindow\n"
"{\n"
"	background-color: white;\n"
"}"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        pushButton_play = new QPushButton(centralwidget);
        pushButton_play->setObjectName(QString::fromUtf8("pushButton_play"));
        pushButton_play->setEnabled(true);
        pushButton_play->setGeometry(QRect(220, 450, 81, 81));
        pushButton_play->setBaseSize(QSize(0, 0));
        QFont font;
        font.setBold(false);
        pushButton_play->setFont(font);
        pushButton_play->setMouseTracking(true);
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
        pushButton_nextSong = new QPushButton(centralwidget);
        pushButton_nextSong->setObjectName(QString::fromUtf8("pushButton_nextSong"));
        pushButton_nextSong->setGeometry(QRect(310, 475, 41, 31));
        QFont font1;
        font1.setBold(true);
        pushButton_nextSong->setFont(font1);
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
        pushButton_previousSong = new QPushButton(centralwidget);
        pushButton_previousSong->setObjectName(QString::fromUtf8("pushButton_previousSong"));
        pushButton_previousSong->setGeometry(QRect(170, 475, 41, 31));
        pushButton_previousSong->setFont(font1);
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
        pushButton_shuffle = new QPushButton(centralwidget);
        pushButton_shuffle->setObjectName(QString::fromUtf8("pushButton_shuffle"));
        pushButton_shuffle->setGeometry(QRect(90, 470, 61, 41));
        pushButton_shuffle->setFont(font1);
        pushButton_shuffle->setMouseTracking(true);
        pushButton_shuffle->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	background-color: transparent;\n"
"	border-image: url(:/icons/icons/shuffle.png);\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"	border-image: url(:/icons/icons/shuffleHover.png);\n"
"}"));
        pushButton_repeat = new QPushButton(centralwidget);
        pushButton_repeat->setObjectName(QString::fromUtf8("pushButton_repeat"));
        pushButton_repeat->setGeometry(QRect(364, 463, 51, 51));
        pushButton_repeat->setFont(font1);
        pushButton_repeat->setMouseTracking(true);
        pushButton_repeat->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	background-color: transparent;\n"
"	border-image: url(:/icons/icons/repeat.png);\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"	border-image: url(:/icons/icons/repeatHover.png);\n"
"}"));
        progressBar = new QProgressBar(centralwidget);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(120, 430, 351, 16));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(progressBar->sizePolicy().hasHeightForWidth());
        progressBar->setSizePolicy(sizePolicy1);
        progressBar->setStyleSheet(QString::fromUtf8("QProgressBar {\n"
"    border-radius: 5px;\n"
"	color: transparent;\n"
"	background-color: gray;\n"
"}\n"
"\n"
"QProgressBar::chunk {\n"
"    background-color: white; \n"
"    width: 20px; \n"
"}\n"
"\n"
"QProgressBar::chunk:hover {\n"
"    background-color: #f9bb00;\n"
"}\n"
""));
        progressBar->setValue(24);
        label_timePassed = new QLabel(centralwidget);
        label_timePassed->setObjectName(QString::fromUtf8("label_timePassed"));
        label_timePassed->setGeometry(QRect(50, 430, 63, 20));
        label_timePassed->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	color: gray;\n"
"}"));
        label_timeDuration = new QLabel(centralwidget);
        label_timeDuration->setObjectName(QString::fromUtf8("label_timeDuration"));
        label_timeDuration->setGeometry(QRect(490, 430, 63, 20));
        label_timeDuration->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	color: gray;\n"
"}"));
        label_test = new QLabel(centralwidget);
        label_test->setObjectName(QString::fromUtf8("label_test"));
        label_test->setGeometry(QRect(290, 350, 151, 91));
        pushButton_volume = new QPushButton(centralwidget);
        pushButton_volume->setObjectName(QString::fromUtf8("pushButton_volume"));
        pushButton_volume->setGeometry(QRect(470, 475, 31, 31));
        pushButton_volume->setBaseSize(QSize(0, 0));
        pushButton_volume->setFont(font1);
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
        horizontalSlider_volumeLevel = new QSlider(centralwidget);
        horizontalSlider_volumeLevel->setObjectName(QString::fromUtf8("horizontalSlider_volumeLevel"));
        horizontalSlider_volumeLevel->setGeometry(QRect(550, 470, 141, 22));
        horizontalSlider_volumeLevel->setLayoutDirection(Qt::LeftToRight);
        horizontalSlider_volumeLevel->setStyleSheet(QString::fromUtf8("QSlider::groove:horizontal \n"
"{\n"
"    border: 1px solid #5c5c5c;\n"
"    background: #dddddd;\n"
"    height: 10px;\n"
"    border-radius: 5px;\n"
"}\n"
"\n"
"QSlider::handle:horizontal \n"
"{\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #eeeeee, stop:1 black);\n"
"    border: 1px solid #5c5c5c;\n"
"    width: 20px;\n"
"    margin: -2px 0;\n"
"    border-radius: 5px;\n"
"}\n"
"\n"
"/* color on the right side from handle */\n"
"QSlider::add-page:horizontal\n"
" {\n"
"    background: #dddddd;  \n"
"    border: 1px solid #999999;\n"
"    border-radius: 5px;\n"
"}\n"
"\n"
" /* color on the left side from handle */\n"
"QSlider::sub-page:horizontal\n"
" {\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #eeeeee, stop:1 black);\n"
"    border: 1px solid #5c5c5c;\n"
"    border-radius: 5px;\n"
"}"));
        horizontalSlider_volumeLevel->setMaximum(100);
        horizontalSlider_volumeLevel->setSliderPosition(50);
        horizontalSlider_volumeLevel->setOrientation(Qt::Horizontal);
        pushButton_fullscreen = new QPushButton(centralwidget);
        pushButton_fullscreen->setObjectName(QString::fromUtf8("pushButton_fullscreen"));
        pushButton_fullscreen->setGeometry(QRect(720, 470, 31, 31));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pushButton_fullscreen->sizePolicy().hasHeightForWidth());
        pushButton_fullscreen->setSizePolicy(sizePolicy2);
        pushButton_fullscreen->setBaseSize(QSize(0, 0));
        pushButton_fullscreen->setFont(font1);
        pushButton_fullscreen->setMouseTracking(true);
        pushButton_fullscreen->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	background-color: transparent;\n"
"	border-image: url(:/icons/icons/fullscreen.png); \n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"	background-color: gray;\n"
"}"));
        pushButton_fullscreen->setIconSize(QSize(20, 20));
        tableWidget = new QTableWidget(centralwidget);
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
        tableWidget->setGeometry(QRect(10, 10, 781, 361));
        tableWidget->setMouseTracking(true);
        tableWidget->setLayoutDirection(Qt::LeftToRight);
        tableWidget->setStyleSheet(QString::fromUtf8("QTableWidget::item\n"
"{\n"
"	background-color: lightblue;\n"
"    border: 1px solid black;\n"
"}\n"
""));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
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
        pushButton_play->setText(QString());
        pushButton_nextSong->setText(QString());
        pushButton_previousSong->setText(QString());
        pushButton_shuffle->setText(QString());
        pushButton_repeat->setText(QString());
        label_timePassed->setText(QCoreApplication::translate("MainWindow", "00:00:00", nullptr));
        label_timeDuration->setText(QCoreApplication::translate("MainWindow", "00:00:00", nullptr));
        label_test->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        pushButton_volume->setText(QString());
        pushButton_fullscreen->setText(QString());
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "Title", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Author", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Genre", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "Playtime", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

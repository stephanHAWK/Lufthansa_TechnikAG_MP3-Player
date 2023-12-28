/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../MP3-Player/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[22];
    char stringdata0[461];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 26), // "on_pushButton_play_clicked"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 29), // "on_pushButton_shuffle_clicked"
QT_MOC_LITERAL(4, 69, 34), // "on_pushButton_previousSong_cl..."
QT_MOC_LITERAL(5, 104, 30), // "on_pushButton_nextSong_clicked"
QT_MOC_LITERAL(6, 135, 28), // "on_pushButton_repeat_clicked"
QT_MOC_LITERAL(7, 164, 28), // "on_pushButton_volume_clicked"
QT_MOC_LITERAL(8, 193, 32), // "on_pushButton_fullscreen_clicked"
QT_MOC_LITERAL(9, 226, 14), // "showNormalized"
QT_MOC_LITERAL(10, 241, 13), // "setVolumeIcon"
QT_MOC_LITERAL(11, 255, 8), // "position"
QT_MOC_LITERAL(12, 264, 44), // "on_horizontalSlider_volumeLev..."
QT_MOC_LITERAL(13, 309, 5), // "value"
QT_MOC_LITERAL(14, 315, 29), // "handleHorizontalHeaderClicked"
QT_MOC_LITERAL(15, 345, 12), // "logicalIndex"
QT_MOC_LITERAL(16, 358, 8), // "loadData"
QT_MOC_LITERAL(17, 367, 25), // "tableWidget_setItemsFlags"
QT_MOC_LITERAL(18, 393, 17), // "handleItemEntered"
QT_MOC_LITERAL(19, 411, 17), // "QTableWidgetItem*"
QT_MOC_LITERAL(20, 429, 4), // "item"
QT_MOC_LITERAL(21, 434, 26) // "on_tableWidget_itemClicked"

    },
    "MainWindow\0on_pushButton_play_clicked\0"
    "\0on_pushButton_shuffle_clicked\0"
    "on_pushButton_previousSong_clicked\0"
    "on_pushButton_nextSong_clicked\0"
    "on_pushButton_repeat_clicked\0"
    "on_pushButton_volume_clicked\0"
    "on_pushButton_fullscreen_clicked\0"
    "showNormalized\0setVolumeIcon\0position\0"
    "on_horizontalSlider_volumeLevel_valueChanged\0"
    "value\0handleHorizontalHeaderClicked\0"
    "logicalIndex\0loadData\0tableWidget_setItemsFlags\0"
    "handleItemEntered\0QTableWidgetItem*\0"
    "item\0on_tableWidget_itemClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x08 /* Private */,
       3,    0,   90,    2, 0x08 /* Private */,
       4,    0,   91,    2, 0x08 /* Private */,
       5,    0,   92,    2, 0x08 /* Private */,
       6,    0,   93,    2, 0x08 /* Private */,
       7,    0,   94,    2, 0x08 /* Private */,
       8,    0,   95,    2, 0x08 /* Private */,
       9,    0,   96,    2, 0x08 /* Private */,
      10,    1,   97,    2, 0x08 /* Private */,
      12,    1,  100,    2, 0x08 /* Private */,
      14,    1,  103,    2, 0x08 /* Private */,
      16,    0,  106,    2, 0x08 /* Private */,
      17,    0,  107,    2, 0x08 /* Private */,
      18,    1,  108,    2, 0x08 /* Private */,
      21,    1,  111,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void, QMetaType::Int,   15,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 19,   20,
    QMetaType::Void, 0x80000000 | 19,   20,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_pushButton_play_clicked(); break;
        case 1: _t->on_pushButton_shuffle_clicked(); break;
        case 2: _t->on_pushButton_previousSong_clicked(); break;
        case 3: _t->on_pushButton_nextSong_clicked(); break;
        case 4: _t->on_pushButton_repeat_clicked(); break;
        case 5: _t->on_pushButton_volume_clicked(); break;
        case 6: _t->on_pushButton_fullscreen_clicked(); break;
        case 7: _t->showNormalized(); break;
        case 8: _t->setVolumeIcon((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->on_horizontalSlider_volumeLevel_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->handleHorizontalHeaderClicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->loadData(); break;
        case 12: _t->tableWidget_setItemsFlags(); break;
        case 13: _t->handleItemEntered((*reinterpret_cast< QTableWidgetItem*(*)>(_a[1]))); break;
        case 14: _t->on_tableWidget_itemClicked((*reinterpret_cast< QTableWidgetItem*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

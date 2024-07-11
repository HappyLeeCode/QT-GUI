/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../ImageProcess/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[23];
    char stringdata0[284];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 18), // "displayImageSignal"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 13), // "newActionSlot"
QT_MOC_LITERAL(4, 45, 18), // "openFileActionSlot"
QT_MOC_LITERAL(5, 64, 17), // "openBmpActionSlot"
QT_MOC_LITERAL(6, 82, 16), // "displayImageSlot"
QT_MOC_LITERAL(7, 99, 7), // "QImage*"
QT_MOC_LITERAL(8, 107, 12), // "setPointSlot"
QT_MOC_LITERAL(9, 120, 10), // "StartPoint"
QT_MOC_LITERAL(10, 131, 8), // "EndPoint"
QT_MOC_LITERAL(11, 140, 12), // "setColorSlot"
QT_MOC_LITERAL(12, 153, 5), // "color"
QT_MOC_LITERAL(13, 159, 18), // "pointSetActionSlot"
QT_MOC_LITERAL(14, 178, 16), // "RGBSetActionSlot"
QT_MOC_LITERAL(15, 195, 11), // "RegionPaint"
QT_MOC_LITERAL(16, 207, 19), // "histogramActionSlot"
QT_MOC_LITERAL(17, 227, 7), // "cv::Mat"
QT_MOC_LITERAL(18, 235, 10), // "inputImage"
QT_MOC_LITERAL(19, 246, 7), // "QLabel*"
QT_MOC_LITERAL(20, 254, 5), // "label"
QT_MOC_LITERAL(21, 260, 5), // "image"
QT_MOC_LITERAL(22, 266, 17) // "QImageTocvMatSlot"

    },
    "MainWindow\0displayImageSignal\0\0"
    "newActionSlot\0openFileActionSlot\0"
    "openBmpActionSlot\0displayImageSlot\0"
    "QImage*\0setPointSlot\0StartPoint\0"
    "EndPoint\0setColorSlot\0color\0"
    "pointSetActionSlot\0RGBSetActionSlot\0"
    "RegionPaint\0histogramActionSlot\0cv::Mat\0"
    "inputImage\0QLabel*\0label\0image\0"
    "QImageTocvMatSlot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   85,    2, 0x08 /* Private */,
       4,    0,   86,    2, 0x08 /* Private */,
       5,    0,   87,    2, 0x08 /* Private */,
       6,    0,   88,    2, 0x08 /* Private */,
       6,    4,   89,    2, 0x08 /* Private */,
       8,    2,   98,    2, 0x08 /* Private */,
      11,    1,  103,    2, 0x08 /* Private */,
      13,    0,  106,    2, 0x08 /* Private */,
      14,    0,  107,    2, 0x08 /* Private */,
      15,    0,  108,    2, 0x08 /* Private */,
      16,    1,  109,    2, 0x08 /* Private */,
       6,    2,  112,    2, 0x08 /* Private */,
      22,    0,  117,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPoint, QMetaType::QPoint, QMetaType::QColor, 0x80000000 | 7,    2,    2,    2,    2,
    QMetaType::Void, QMetaType::QPoint, QMetaType::QPoint,    9,   10,
    QMetaType::Void, QMetaType::QColor,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    0x80000000 | 17, 0x80000000 | 17,   18,
    QMetaType::Void, 0x80000000 | 19, 0x80000000 | 17,   20,   21,
    0x80000000 | 17,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->displayImageSignal(); break;
        case 1: _t->newActionSlot(); break;
        case 2: _t->openFileActionSlot(); break;
        case 3: _t->openBmpActionSlot(); break;
        case 4: _t->displayImageSlot(); break;
        case 5: _t->displayImageSlot((*reinterpret_cast< QPoint(*)>(_a[1])),(*reinterpret_cast< QPoint(*)>(_a[2])),(*reinterpret_cast< QColor(*)>(_a[3])),(*reinterpret_cast< QImage*(*)>(_a[4]))); break;
        case 6: _t->setPointSlot((*reinterpret_cast< QPoint(*)>(_a[1])),(*reinterpret_cast< QPoint(*)>(_a[2]))); break;
        case 7: _t->setColorSlot((*reinterpret_cast< QColor(*)>(_a[1]))); break;
        case 8: _t->pointSetActionSlot(); break;
        case 9: _t->RGBSetActionSlot(); break;
        case 10: _t->RegionPaint(); break;
        case 11: { cv::Mat _r = _t->histogramActionSlot((*reinterpret_cast< const cv::Mat(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< cv::Mat*>(_a[0]) = std::move(_r); }  break;
        case 12: _t->displayImageSlot((*reinterpret_cast< QLabel*(*)>(_a[1])),(*reinterpret_cast< const cv::Mat(*)>(_a[2]))); break;
        case 13: { cv::Mat _r = _t->QImageTocvMatSlot();
            if (_a[0]) *reinterpret_cast< cv::Mat*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::displayImageSignal)) {
                *result = 0;
                return;
            }
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
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::displayImageSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../PhotonenGitarre/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[17];
    char stringdata0[370];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 27), // "on_hueMaxValue_valueChanged"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 4), // "arg1"
QT_MOC_LITERAL(4, 45, 27), // "on_hueMinValue_valueChanged"
QT_MOC_LITERAL(5, 73, 34), // "on_saturationMaxValue_valueCh..."
QT_MOC_LITERAL(6, 108, 34), // "on_saturationMinValue_valueCh..."
QT_MOC_LITERAL(7, 143, 29), // "on_valueMaxValue_valueChanged"
QT_MOC_LITERAL(8, 173, 29), // "on_valueMinValue_valueChanged"
QT_MOC_LITERAL(9, 203, 21), // "on_saveButton_clicked"
QT_MOC_LITERAL(10, 225, 21), // "on_blueButton_toggled"
QT_MOC_LITERAL(11, 247, 7), // "checked"
QT_MOC_LITERAL(12, 255, 21), // "on_cyanButton_toggled"
QT_MOC_LITERAL(13, 277, 22), // "on_greenButton_toggled"
QT_MOC_LITERAL(14, 300, 24), // "on_magentaButton_toggled"
QT_MOC_LITERAL(15, 325, 20), // "on_redButton_toggled"
QT_MOC_LITERAL(16, 346, 23) // "on_yellowButton_toggled"

    },
    "MainWindow\0on_hueMaxValue_valueChanged\0"
    "\0arg1\0on_hueMinValue_valueChanged\0"
    "on_saturationMaxValue_valueChanged\0"
    "on_saturationMinValue_valueChanged\0"
    "on_valueMaxValue_valueChanged\0"
    "on_valueMinValue_valueChanged\0"
    "on_saveButton_clicked\0on_blueButton_toggled\0"
    "checked\0on_cyanButton_toggled\0"
    "on_greenButton_toggled\0on_magentaButton_toggled\0"
    "on_redButton_toggled\0on_yellowButton_toggled"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   79,    2, 0x08 /* Private */,
       4,    1,   82,    2, 0x08 /* Private */,
       5,    1,   85,    2, 0x08 /* Private */,
       6,    1,   88,    2, 0x08 /* Private */,
       7,    1,   91,    2, 0x08 /* Private */,
       8,    1,   94,    2, 0x08 /* Private */,
       9,    0,   97,    2, 0x08 /* Private */,
      10,    1,   98,    2, 0x08 /* Private */,
      12,    1,  101,    2, 0x08 /* Private */,
      13,    1,  104,    2, 0x08 /* Private */,
      14,    1,  107,    2, 0x08 /* Private */,
      15,    1,  110,    2, 0x08 /* Private */,
      16,    1,  113,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   11,
    QMetaType::Void, QMetaType::Bool,   11,
    QMetaType::Void, QMetaType::Bool,   11,
    QMetaType::Void, QMetaType::Bool,   11,
    QMetaType::Void, QMetaType::Bool,   11,
    QMetaType::Void, QMetaType::Bool,   11,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_hueMaxValue_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->on_hueMinValue_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->on_saturationMaxValue_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->on_saturationMinValue_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_valueMaxValue_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->on_valueMinValue_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_saveButton_clicked(); break;
        case 7: _t->on_blueButton_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->on_cyanButton_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->on_greenButton_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: _t->on_magentaButton_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 11: _t->on_redButton_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 12: _t->on_yellowButton_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

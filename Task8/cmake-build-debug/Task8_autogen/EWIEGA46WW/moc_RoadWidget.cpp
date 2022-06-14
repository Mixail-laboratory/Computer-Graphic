/****************************************************************************
** Meta object code from reading C++ file 'RoadWidget.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../RoadWidget.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'RoadWidget.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_RoadWidget_t {
    QByteArrayData data[8];
    char stringdata0[104];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RoadWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RoadWidget_t qt_meta_stringdata_RoadWidget = {
    {
QT_MOC_LITERAL(0, 0, 10), // "RoadWidget"
QT_MOC_LITERAL(1, 11, 19), // "changeRoadFiltering"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 4), // "filt"
QT_MOC_LITERAL(4, 37, 19), // "changeRockFiltering"
QT_MOC_LITERAL(5, 57, 21), // "changeCracksFiltering"
QT_MOC_LITERAL(6, 79, 18), // "changeMixParameter"
QT_MOC_LITERAL(7, 98, 5) // "value"

    },
    "RoadWidget\0changeRoadFiltering\0\0filt\0"
    "changeRockFiltering\0changeCracksFiltering\0"
    "changeMixParameter\0value"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RoadWidget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x0a /* Public */,
       4,    1,   37,    2, 0x0a /* Public */,
       5,    1,   40,    2, 0x0a /* Public */,
       6,    1,   43,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    7,

       0        // eod
};

void RoadWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<RoadWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->changeRoadFiltering((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->changeRockFiltering((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->changeCracksFiltering((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->changeMixParameter((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject RoadWidget::staticMetaObject = { {
    &QOpenGLWidget::staticMetaObject,
    qt_meta_stringdata_RoadWidget.data,
    qt_meta_data_RoadWidget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *RoadWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RoadWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_RoadWidget.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "QOpenGLFunctions"))
        return static_cast< QOpenGLFunctions*>(this);
    return QOpenGLWidget::qt_metacast(_clname);
}

int RoadWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QOpenGLWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

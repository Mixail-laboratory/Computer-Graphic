/****************************************************************************
** Meta object code from reading C++ file 'cubesettingswindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../cubesettingswindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cubesettingswindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CubeSettingsWindow_t {
    QByteArrayData data[15];
    char stringdata0[336];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CubeSettingsWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CubeSettingsWindow_t qt_meta_stringdata_CubeSettingsWindow = {
    {
QT_MOC_LITERAL(0, 0, 18), // "CubeSettingsWindow"
QT_MOC_LITERAL(1, 19, 26), // "on_spin_div_n_valueChanged"
QT_MOC_LITERAL(2, 46, 0), // ""
QT_MOC_LITERAL(3, 47, 4), // "arg1"
QT_MOC_LITERAL(4, 52, 26), // "on_spin_div_m_valueChanged"
QT_MOC_LITERAL(5, 79, 24), // "on_camera_x_valueChanged"
QT_MOC_LITERAL(6, 104, 24), // "on_camera_y_valueChanged"
QT_MOC_LITERAL(7, 129, 24), // "on_camera_z_valueChanged"
QT_MOC_LITERAL(8, 154, 31), // "on_enable_directed_stateChanged"
QT_MOC_LITERAL(9, 186, 27), // "on_dir_color_button_clicked"
QT_MOC_LITERAL(10, 214, 27), // "on_dir_light_x_valueChanged"
QT_MOC_LITERAL(11, 242, 27), // "on_dir_light_y_valueChanged"
QT_MOC_LITERAL(12, 270, 27), // "on_dir_light_z_valueChanged"
QT_MOC_LITERAL(13, 298, 31), // "on_comboBox_currentIndexChanged"
QT_MOC_LITERAL(14, 330, 5) // "index"

    },
    "CubeSettingsWindow\0on_spin_div_n_valueChanged\0"
    "\0arg1\0on_spin_div_m_valueChanged\0"
    "on_camera_x_valueChanged\0"
    "on_camera_y_valueChanged\0"
    "on_camera_z_valueChanged\0"
    "on_enable_directed_stateChanged\0"
    "on_dir_color_button_clicked\0"
    "on_dir_light_x_valueChanged\0"
    "on_dir_light_y_valueChanged\0"
    "on_dir_light_z_valueChanged\0"
    "on_comboBox_currentIndexChanged\0index"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CubeSettingsWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x08 /* Private */,
       4,    1,   72,    2, 0x08 /* Private */,
       5,    1,   75,    2, 0x08 /* Private */,
       6,    1,   78,    2, 0x08 /* Private */,
       7,    1,   81,    2, 0x08 /* Private */,
       8,    1,   84,    2, 0x08 /* Private */,
       9,    0,   87,    2, 0x08 /* Private */,
      10,    1,   88,    2, 0x08 /* Private */,
      11,    1,   91,    2, 0x08 /* Private */,
      12,    1,   94,    2, 0x08 /* Private */,
      13,    1,   97,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::Int,   14,

       0        // eod
};

void CubeSettingsWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CubeSettingsWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_spin_div_n_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->on_spin_div_m_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->on_camera_x_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 3: _t->on_camera_y_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 4: _t->on_camera_z_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 5: _t->on_enable_directed_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_dir_color_button_clicked(); break;
        case 7: _t->on_dir_light_x_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 8: _t->on_dir_light_y_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 9: _t->on_dir_light_z_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 10: _t->on_comboBox_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CubeSettingsWindow::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_CubeSettingsWindow.data,
    qt_meta_data_CubeSettingsWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CubeSettingsWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CubeSettingsWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CubeSettingsWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int CubeSettingsWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

/****************************************************************************
** Meta object code from reading C++ file 'conf.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.10)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../App/ui/settings/conf.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'conf.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.10. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_conf_t {
    QByteArrayData data[14];
    char stringdata0[130];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_conf_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_conf_t qt_meta_stringdata_conf = {
    {
QT_MOC_LITERAL(0, 0, 4), // "conf"
QT_MOC_LITERAL(1, 5, 11), // "setCellSize"
QT_MOC_LITERAL(2, 17, 0), // ""
QT_MOC_LITERAL(3, 18, 4), // "size"
QT_MOC_LITERAL(4, 23, 10), // "setGapSize"
QT_MOC_LITERAL(5, 34, 11), // "changeColor"
QT_MOC_LITERAL(6, 46, 5), // "color"
QT_MOC_LITERAL(7, 52, 5), // "index"
QT_MOC_LITERAL(8, 58, 10), // "aliveColor"
QT_MOC_LITERAL(9, 69, 10), // "emptyColor"
QT_MOC_LITERAL(10, 80, 11), // "borderColor"
QT_MOC_LITERAL(11, 92, 16), // "onCellSizeChange"
QT_MOC_LITERAL(12, 109, 4), // "vaue"
QT_MOC_LITERAL(13, 114, 15) // "onGapSizeChange"

    },
    "conf\0setCellSize\0\0size\0setGapSize\0"
    "changeColor\0color\0index\0aliveColor\0"
    "emptyColor\0borderColor\0onCellSizeChange\0"
    "vaue\0onGapSizeChange"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_conf[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x06 /* Public */,
       4,    1,   57,    2, 0x06 /* Public */,
       5,    2,   60,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   65,    2, 0x0a /* Public */,
       9,    0,   66,    2, 0x0a /* Public */,
      10,    0,   67,    2, 0x0a /* Public */,
      11,    1,   68,    2, 0x0a /* Public */,
      13,    1,   71,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::QColor, QMetaType::Int,    6,    7,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void, QMetaType::Int,   12,

       0        // eod
};

void conf::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<conf *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->setCellSize((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->setGapSize((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->changeColor((*reinterpret_cast< const QColor(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->aliveColor(); break;
        case 4: _t->emptyColor(); break;
        case 5: _t->borderColor(); break;
        case 6: _t->onCellSizeChange((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->onGapSizeChange((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (conf::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&conf::setCellSize)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (conf::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&conf::setGapSize)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (conf::*)(const QColor & , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&conf::changeColor)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject conf::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_conf.data,
    qt_meta_data_conf,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *conf::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *conf::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_conf.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int conf::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void conf::setCellSize(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void conf::setGapSize(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void conf::changeColor(const QColor & _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

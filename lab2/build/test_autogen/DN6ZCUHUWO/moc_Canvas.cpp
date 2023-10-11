/****************************************************************************
** Meta object code from reading C++ file 'Canvas.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.10)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../App/ui/Canvas/Canvas.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Canvas.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.10. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Canvas_t {
    QByteArrayData data[17];
    char stringdata0[114];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Canvas_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Canvas_t qt_meta_stringdata_Canvas = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Canvas"
QT_MOC_LITERAL(1, 7, 10), // "toggleCell"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 3), // "row"
QT_MOC_LITERAL(4, 23, 3), // "col"
QT_MOC_LITERAL(5, 27, 11), // "setCellSize"
QT_MOC_LITERAL(6, 39, 4), // "size"
QT_MOC_LITERAL(7, 44, 10), // "setGapSize"
QT_MOC_LITERAL(8, 55, 6), // "redraw"
QT_MOC_LITERAL(9, 62, 5), // "char*"
QT_MOC_LITERAL(10, 68, 4), // "data"
QT_MOC_LITERAL(11, 73, 6), // "size_t"
QT_MOC_LITERAL(12, 80, 5), // "width"
QT_MOC_LITERAL(13, 86, 6), // "height"
QT_MOC_LITERAL(14, 93, 8), // "setColor"
QT_MOC_LITERAL(15, 102, 5), // "color"
QT_MOC_LITERAL(16, 108, 5) // "index"

    },
    "Canvas\0toggleCell\0\0row\0col\0setCellSize\0"
    "size\0setGapSize\0redraw\0char*\0data\0"
    "size_t\0width\0height\0setColor\0color\0"
    "index"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Canvas[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   44,    2, 0x0a /* Public */,
       7,    1,   47,    2, 0x0a /* Public */,
       8,    3,   50,    2, 0x0a /* Public */,
      14,    2,   57,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, 0x80000000 | 9, 0x80000000 | 11, 0x80000000 | 11,   10,   12,   13,
    QMetaType::Void, QMetaType::QColor, QMetaType::Int,   15,   16,

       0        // eod
};

void Canvas::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Canvas *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->toggleCell((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->setCellSize((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->setGapSize((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->redraw((*reinterpret_cast< char*(*)>(_a[1])),(*reinterpret_cast< size_t(*)>(_a[2])),(*reinterpret_cast< size_t(*)>(_a[3]))); break;
        case 4: _t->setColor((*reinterpret_cast< const QColor(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Canvas::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Canvas::toggleCell)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Canvas::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_Canvas.data,
    qt_meta_data_Canvas,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Canvas::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Canvas::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Canvas.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Canvas::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void Canvas::toggleCell(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

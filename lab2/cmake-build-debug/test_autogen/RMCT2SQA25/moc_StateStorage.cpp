/****************************************************************************
** Meta object code from reading C++ file 'StateStorage.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.10)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../App/StateStorage/StateStorage.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'StateStorage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.10. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_StateStorage_t {
    QByteArrayData data[14];
    char stringdata0[132];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_StateStorage_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_StateStorage_t qt_meta_stringdata_StateStorage = {
    {
QT_MOC_LITERAL(0, 0, 12), // "StateStorage"
QT_MOC_LITERAL(1, 13, 11), // "invalidRule"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 10), // "renderLife"
QT_MOC_LITERAL(4, 37, 4), // "Life"
QT_MOC_LITERAL(5, 42, 4), // "life"
QT_MOC_LITERAL(6, 47, 8), // "testSlot"
QT_MOC_LITERAL(7, 56, 8), // "setRules"
QT_MOC_LITERAL(8, 65, 11), // "std::string"
QT_MOC_LITERAL(9, 77, 8), // "newRules"
QT_MOC_LITERAL(10, 86, 15), // "setNeighborhood"
QT_MOC_LITERAL(11, 102, 13), // "ENeighborhood"
QT_MOC_LITERAL(12, 116, 8), // "newNeigh"
QT_MOC_LITERAL(13, 125, 6) // "degree"

    },
    "StateStorage\0invalidRule\0\0renderLife\0"
    "Life\0life\0testSlot\0setRules\0std::string\0"
    "newRules\0setNeighborhood\0ENeighborhood\0"
    "newNeigh\0degree"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_StateStorage[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,
       3,    1,   45,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   48,    2, 0x0a /* Public */,
       7,    1,   49,    2, 0x0a /* Public */,
      10,    2,   52,    2, 0x0a /* Public */,
      10,    1,   57,    2, 0x2a /* Public | MethodCloned */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, 0x80000000 | 11, QMetaType::Int,   12,   13,
    QMetaType::Void, 0x80000000 | 11,   12,

       0        // eod
};

void StateStorage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<StateStorage *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->invalidRule(); break;
        case 1: _t->renderLife((*reinterpret_cast< const Life(*)>(_a[1]))); break;
        case 2: _t->testSlot(); break;
        case 3: _t->setRules((*reinterpret_cast< const std::string(*)>(_a[1]))); break;
        case 4: _t->setNeighborhood((*reinterpret_cast< ENeighborhood(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 5: _t->setNeighborhood((*reinterpret_cast< ENeighborhood(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (StateStorage::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&StateStorage::invalidRule)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (StateStorage::*)(const Life & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&StateStorage::renderLife)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject StateStorage::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_StateStorage.data,
    qt_meta_data_StateStorage,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *StateStorage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *StateStorage::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_StateStorage.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int StateStorage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void StateStorage::invalidRule()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void StateStorage::renderLife(const Life & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

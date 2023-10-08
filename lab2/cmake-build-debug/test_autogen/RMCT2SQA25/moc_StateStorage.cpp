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
    QByteArrayData data[35];
    char stringdata0[297];
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
QT_MOC_LITERAL(3, 26, 6), // "redraw"
QT_MOC_LITERAL(4, 33, 5), // "char*"
QT_MOC_LITERAL(5, 39, 4), // "data"
QT_MOC_LITERAL(6, 44, 6), // "size_t"
QT_MOC_LITERAL(7, 51, 5), // "width"
QT_MOC_LITERAL(8, 57, 6), // "height"
QT_MOC_LITERAL(9, 64, 11), // "updateRules"
QT_MOC_LITERAL(10, 76, 6), // "TRules"
QT_MOC_LITERAL(11, 83, 5), // "rules"
QT_MOC_LITERAL(12, 89, 18), // "updateNeighborhood"
QT_MOC_LITERAL(13, 108, 13), // "TNeighborhood"
QT_MOC_LITERAL(14, 122, 1), // "n"
QT_MOC_LITERAL(15, 124, 8), // "setRules"
QT_MOC_LITERAL(16, 133, 11), // "std::string"
QT_MOC_LITERAL(17, 145, 8), // "newRules"
QT_MOC_LITERAL(18, 154, 15), // "setNeighborhood"
QT_MOC_LITERAL(19, 170, 13), // "ENeighborhood"
QT_MOC_LITERAL(20, 184, 8), // "newNeigh"
QT_MOC_LITERAL(21, 193, 6), // "degree"
QT_MOC_LITERAL(22, 200, 8), // "InitLife"
QT_MOC_LITERAL(23, 209, 9), // "countRows"
QT_MOC_LITERAL(24, 219, 9), // "countCols"
QT_MOC_LITERAL(25, 229, 10), // "toggleLife"
QT_MOC_LITERAL(26, 240, 3), // "row"
QT_MOC_LITERAL(27, 244, 3), // "col"
QT_MOC_LITERAL(28, 248, 8), // "tickGame"
QT_MOC_LITERAL(29, 257, 10), // "tickCanvas"
QT_MOC_LITERAL(30, 268, 4), // "step"
QT_MOC_LITERAL(31, 273, 4), // "stop"
QT_MOC_LITERAL(32, 278, 3), // "run"
QT_MOC_LITERAL(33, 282, 8), // "setSpeed"
QT_MOC_LITERAL(34, 291, 5) // "value"

    },
    "StateStorage\0invalidRule\0\0redraw\0char*\0"
    "data\0size_t\0width\0height\0updateRules\0"
    "TRules\0rules\0updateNeighborhood\0"
    "TNeighborhood\0n\0setRules\0std::string\0"
    "newRules\0setNeighborhood\0ENeighborhood\0"
    "newNeigh\0degree\0InitLife\0countRows\0"
    "countCols\0toggleLife\0row\0col\0tickGame\0"
    "tickCanvas\0step\0stop\0run\0setSpeed\0"
    "value"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_StateStorage[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x06 /* Public */,
       3,    3,   90,    2, 0x06 /* Public */,
       9,    1,   97,    2, 0x06 /* Public */,
      12,    1,  100,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      15,    1,  103,    2, 0x0a /* Public */,
      18,    2,  106,    2, 0x0a /* Public */,
      18,    1,  111,    2, 0x2a /* Public | MethodCloned */,
      22,    2,  114,    2, 0x0a /* Public */,
      25,    2,  119,    2, 0x0a /* Public */,
      28,    0,  124,    2, 0x0a /* Public */,
      29,    0,  125,    2, 0x0a /* Public */,
      30,    0,  126,    2, 0x0a /* Public */,
      31,    0,  127,    2, 0x0a /* Public */,
      32,    0,  128,    2, 0x0a /* Public */,
      33,    1,  129,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4, 0x80000000 | 6, 0x80000000 | 6,    5,    7,    8,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void, 0x80000000 | 13,   14,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 16,   17,
    QMetaType::Void, 0x80000000 | 19, QMetaType::Int,   20,   21,
    QMetaType::Void, 0x80000000 | 19,   20,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   23,   24,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   26,   27,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   34,

       0        // eod
};

void StateStorage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<StateStorage *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->invalidRule(); break;
        case 1: _t->redraw((*reinterpret_cast< char*(*)>(_a[1])),(*reinterpret_cast< size_t(*)>(_a[2])),(*reinterpret_cast< size_t(*)>(_a[3]))); break;
        case 2: _t->updateRules((*reinterpret_cast< const TRules(*)>(_a[1]))); break;
        case 3: _t->updateNeighborhood((*reinterpret_cast< const TNeighborhood(*)>(_a[1]))); break;
        case 4: _t->setRules((*reinterpret_cast< const std::string(*)>(_a[1]))); break;
        case 5: _t->setNeighborhood((*reinterpret_cast< ENeighborhood(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 6: _t->setNeighborhood((*reinterpret_cast< ENeighborhood(*)>(_a[1]))); break;
        case 7: _t->InitLife((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 8: _t->toggleLife((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 9: _t->tickGame(); break;
        case 10: _t->tickCanvas(); break;
        case 11: _t->step(); break;
        case 12: _t->stop(); break;
        case 13: _t->run(); break;
        case 14: _t->setSpeed((*reinterpret_cast< int(*)>(_a[1]))); break;
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
            using _t = void (StateStorage::*)(char * , size_t , size_t );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&StateStorage::redraw)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (StateStorage::*)(const TRules & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&StateStorage::updateRules)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (StateStorage::*)(const TNeighborhood & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&StateStorage::updateNeighborhood)) {
                *result = 3;
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

// SIGNAL 0
void StateStorage::invalidRule()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void StateStorage::redraw(char * _t1, size_t _t2, size_t _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void StateStorage::updateRules(const TRules & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void StateStorage::updateNeighborhood(const TNeighborhood & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

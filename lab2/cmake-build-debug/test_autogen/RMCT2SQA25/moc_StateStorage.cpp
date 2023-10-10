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
    QByteArrayData data[44];
    char stringdata0[390];
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
QT_MOC_LITERAL(15, 124, 14), // "cellSizeSignal"
QT_MOC_LITERAL(16, 139, 4), // "size"
QT_MOC_LITERAL(17, 144, 13), // "gapSizeSignal"
QT_MOC_LITERAL(18, 158, 14), // "setColorSignal"
QT_MOC_LITERAL(19, 173, 5), // "color"
QT_MOC_LITERAL(20, 179, 5), // "index"
QT_MOC_LITERAL(21, 185, 8), // "setRules"
QT_MOC_LITERAL(22, 194, 11), // "std::string"
QT_MOC_LITERAL(23, 206, 8), // "newRules"
QT_MOC_LITERAL(24, 215, 15), // "setNeighborhood"
QT_MOC_LITERAL(25, 231, 13), // "ENeighborhood"
QT_MOC_LITERAL(26, 245, 8), // "newNeigh"
QT_MOC_LITERAL(27, 254, 6), // "degree"
QT_MOC_LITERAL(28, 261, 8), // "InitLife"
QT_MOC_LITERAL(29, 270, 9), // "countRows"
QT_MOC_LITERAL(30, 280, 9), // "countCols"
QT_MOC_LITERAL(31, 290, 10), // "toggleLife"
QT_MOC_LITERAL(32, 301, 3), // "row"
QT_MOC_LITERAL(33, 305, 3), // "col"
QT_MOC_LITERAL(34, 309, 8), // "tickGame"
QT_MOC_LITERAL(35, 318, 10), // "tickCanvas"
QT_MOC_LITERAL(36, 329, 4), // "step"
QT_MOC_LITERAL(37, 334, 4), // "stop"
QT_MOC_LITERAL(38, 339, 3), // "run"
QT_MOC_LITERAL(39, 343, 8), // "setSpeed"
QT_MOC_LITERAL(40, 352, 5), // "value"
QT_MOC_LITERAL(41, 358, 11), // "setCellSize"
QT_MOC_LITERAL(42, 370, 10), // "setGapSize"
QT_MOC_LITERAL(43, 381, 8) // "setColor"

    },
    "StateStorage\0invalidRule\0\0redraw\0char*\0"
    "data\0size_t\0width\0height\0updateRules\0"
    "TRules\0rules\0updateNeighborhood\0"
    "TNeighborhood\0n\0cellSizeSignal\0size\0"
    "gapSizeSignal\0setColorSignal\0color\0"
    "index\0setRules\0std::string\0newRules\0"
    "setNeighborhood\0ENeighborhood\0newNeigh\0"
    "degree\0InitLife\0countRows\0countCols\0"
    "toggleLife\0row\0col\0tickGame\0tickCanvas\0"
    "step\0stop\0run\0setSpeed\0value\0setCellSize\0"
    "setGapSize\0setColor"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_StateStorage[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      21,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  119,    2, 0x06 /* Public */,
       3,    3,  120,    2, 0x06 /* Public */,
       9,    1,  127,    2, 0x06 /* Public */,
      12,    1,  130,    2, 0x06 /* Public */,
      15,    1,  133,    2, 0x06 /* Public */,
      17,    1,  136,    2, 0x06 /* Public */,
      18,    2,  139,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      21,    1,  144,    2, 0x0a /* Public */,
      24,    2,  147,    2, 0x0a /* Public */,
      24,    1,  152,    2, 0x2a /* Public | MethodCloned */,
      28,    2,  155,    2, 0x0a /* Public */,
      31,    2,  160,    2, 0x0a /* Public */,
      34,    0,  165,    2, 0x0a /* Public */,
      35,    0,  166,    2, 0x0a /* Public */,
      36,    0,  167,    2, 0x0a /* Public */,
      37,    0,  168,    2, 0x0a /* Public */,
      38,    0,  169,    2, 0x0a /* Public */,
      39,    1,  170,    2, 0x0a /* Public */,
      41,    1,  173,    2, 0x0a /* Public */,
      42,    1,  176,    2, 0x0a /* Public */,
      43,    2,  179,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4, 0x80000000 | 6, 0x80000000 | 6,    5,    7,    8,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void, 0x80000000 | 13,   14,
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Void, QMetaType::QColor, QMetaType::Int,   19,   20,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 22,   23,
    QMetaType::Void, 0x80000000 | 25, QMetaType::Int,   26,   27,
    QMetaType::Void, 0x80000000 | 25,   26,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   29,   30,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   32,   33,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   40,
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Void, QMetaType::QColor, QMetaType::Int,   19,   20,

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
        case 4: _t->cellSizeSignal((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->gapSizeSignal((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->setColorSignal((*reinterpret_cast< const QColor(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 7: _t->setRules((*reinterpret_cast< const std::string(*)>(_a[1]))); break;
        case 8: _t->setNeighborhood((*reinterpret_cast< ENeighborhood(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 9: _t->setNeighborhood((*reinterpret_cast< ENeighborhood(*)>(_a[1]))); break;
        case 10: _t->InitLife((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 11: _t->toggleLife((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 12: _t->tickGame(); break;
        case 13: _t->tickCanvas(); break;
        case 14: _t->step(); break;
        case 15: _t->stop(); break;
        case 16: _t->run(); break;
        case 17: _t->setSpeed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 18: _t->setCellSize((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 19: _t->setGapSize((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 20: _t->setColor((*reinterpret_cast< const QColor(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
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
        {
            using _t = void (StateStorage::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&StateStorage::cellSizeSignal)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (StateStorage::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&StateStorage::gapSizeSignal)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (StateStorage::*)(const QColor & , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&StateStorage::setColorSignal)) {
                *result = 6;
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
        if (_id < 21)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 21;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 21)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 21;
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

// SIGNAL 4
void StateStorage::cellSizeSignal(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void StateStorage::gapSizeSignal(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void StateStorage::setColorSignal(const QColor & _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

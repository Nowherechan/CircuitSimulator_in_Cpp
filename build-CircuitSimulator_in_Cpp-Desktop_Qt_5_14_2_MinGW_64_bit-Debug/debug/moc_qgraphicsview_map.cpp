/****************************************************************************
** Meta object code from reading C++ file 'qgraphicsview_map.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../CircuitSimulator_in_Cpp/qgraphicsview_map.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qgraphicsview_map.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QGraphicsView_Map_t {
    QByteArrayData data[9];
    char stringdata0[107];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QGraphicsView_Map_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QGraphicsView_Map_t qt_meta_stringdata_QGraphicsView_Map = {
    {
QT_MOC_LITERAL(0, 0, 17), // "QGraphicsView_Map"
QT_MOC_LITERAL(1, 18, 12), // "mousePressed"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 11), // "QMouseEvent"
QT_MOC_LITERAL(4, 44, 12), // "eventPressed"
QT_MOC_LITERAL(5, 57, 10), // "mouseMoved"
QT_MOC_LITERAL(6, 68, 10), // "eventMoved"
QT_MOC_LITERAL(7, 79, 13), // "mouseReleased"
QT_MOC_LITERAL(8, 93, 13) // "eventReleased"

    },
    "QGraphicsView_Map\0mousePressed\0\0"
    "QMouseEvent\0eventPressed\0mouseMoved\0"
    "eventMoved\0mouseReleased\0eventReleased"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QGraphicsView_Map[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,
       5,    1,   32,    2, 0x06 /* Public */,
       7,    1,   35,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    6,
    QMetaType::Void, 0x80000000 | 3,    8,

       0        // eod
};

void QGraphicsView_Map::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QGraphicsView_Map *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->mousePressed((*reinterpret_cast< QMouseEvent(*)>(_a[1]))); break;
        case 1: _t->mouseMoved((*reinterpret_cast< QMouseEvent(*)>(_a[1]))); break;
        case 2: _t->mouseReleased((*reinterpret_cast< QMouseEvent(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (QGraphicsView_Map::*)(QMouseEvent );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QGraphicsView_Map::mousePressed)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (QGraphicsView_Map::*)(QMouseEvent );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QGraphicsView_Map::mouseMoved)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (QGraphicsView_Map::*)(QMouseEvent );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QGraphicsView_Map::mouseReleased)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QGraphicsView_Map::staticMetaObject = { {
    QMetaObject::SuperData::link<QGraphicsView::staticMetaObject>(),
    qt_meta_stringdata_QGraphicsView_Map.data,
    qt_meta_data_QGraphicsView_Map,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QGraphicsView_Map::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QGraphicsView_Map::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QGraphicsView_Map.stringdata0))
        return static_cast<void*>(this);
    return QGraphicsView::qt_metacast(_clname);
}

int QGraphicsView_Map::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void QGraphicsView_Map::mousePressed(QMouseEvent _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QGraphicsView_Map::mouseMoved(QMouseEvent _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void QGraphicsView_Map::mouseReleased(QMouseEvent _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

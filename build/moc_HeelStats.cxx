/****************************************************************************
** Meta object code from reading C++ file 'HeelStats.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../HeelStats.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'HeelStats.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_HeelStats[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x0a,
      22,   10,   10,   10, 0x0a,
      42,   10,   10,   10, 0x0a,
      56,   10,   10,   10, 0x0a,
      75,   10,   10,   10, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_HeelStats[] = {
    "HeelStats\0\0slotExit()\0pushButtonClicked()\0"
    "openDataSet()\0updateImageSlice()\0"
    "updateSlice()\0"
};

void HeelStats::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        HeelStats *_t = static_cast<HeelStats *>(_o);
        switch (_id) {
        case 0: _t->slotExit(); break;
        case 1: _t->pushButtonClicked(); break;
        case 2: _t->openDataSet(); break;
        case 3: _t->updateImageSlice(); break;
        case 4: _t->updateSlice(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData HeelStats::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject HeelStats::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_HeelStats,
      qt_meta_data_HeelStats, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &HeelStats::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *HeelStats::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *HeelStats::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_HeelStats))
        return static_cast<void*>(const_cast< HeelStats*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int HeelStats::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

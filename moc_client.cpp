/****************************************************************************
** Meta object code from reading C++ file 'client.h'
**
** Created: Sun Mar 10 13:38:04 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "client.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'client.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_client[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
       8,    7,    7,    7, 0x05,

 // slots: signature, parameters, type, tag, flags
      28,    7,    7,    7, 0x0a,
      46,    7,    7,    7, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_client[] = {
    "client\0\0sendtomain(QString)\0"
    "tookthis(QString)\0dosomething()\0"
};

void client::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        client *_t = static_cast<client *>(_o);
        switch (_id) {
        case 0: _t->sendtomain((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->tookthis((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->dosomething(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData client::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject client::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_client,
      qt_meta_data_client, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &client::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *client::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *client::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_client))
        return static_cast<void*>(const_cast< client*>(this));
    return QThread::qt_metacast(_clname);
}

int client::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void client::sendtomain(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE

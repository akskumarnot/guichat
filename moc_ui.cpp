/****************************************************************************
** Meta object code from reading C++ file 'ui.h'
**
** Created: Mon Mar 11 20:00:45 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "ui.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ui.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ui[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
       4,    3,    3,    3, 0x05,
      22,    3,    3,    3, 0x05,

 // slots: signature, parameters, type, tag, flags
      32,    3,    3,    3, 0x0a,
      49,    3,    3,    3, 0x0a,
      55,    3,    3,    3, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_ui[] = {
    "ui\0\0takethis(QString)\0closing()\0"
    "rAtMain(QString)\0bye()\0newavatar()\0"
};

void ui::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ui *_t = static_cast<ui *>(_o);
        switch (_id) {
        case 0: _t->takethis((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->closing(); break;
        case 2: _t->rAtMain((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->bye(); break;
        case 4: _t->newavatar(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ui::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ui::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ui,
      qt_meta_data_ui, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ui::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ui::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ui::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ui))
        return static_cast<void*>(const_cast< ui*>(this));
    return QWidget::qt_metacast(_clname);
}

int ui::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void ui::takethis(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ui::closing()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE

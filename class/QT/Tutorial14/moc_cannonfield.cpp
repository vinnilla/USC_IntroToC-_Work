/****************************************************************************
** Meta object code from reading C++ file 'cannonfield.h'
**
** Created: Wed Apr 30 11:01:40 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "cannonfield.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cannonfield.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CannonField[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x05,
      19,   12,   12,   12, 0x05,
      37,   28,   12,   12, 0x05,
      64,   55,   12,   12, 0x05,
      86,   82,   12,   12, 0x05,

 // slots: signature, parameters, type, tag, flags
     107,  101,   12,   12, 0x0a,
     127,  121,   12,   12, 0x0a,
     141,   12,   12,   12, 0x0a,
     149,   12,   12,   12, 0x0a,
     161,   12,   12,   12, 0x0a,
     175,   12,   12,   12, 0x0a,
     189,   12,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_CannonField[] = {
    "CannonField\0\0hit()\0missed()\0newAngle\0"
    "angleChanged(int)\0newForce\0forceChanged(int)\0"
    "can\0canShoot(bool)\0angle\0setAngle(int)\0"
    "force\0setForce(int)\0shoot()\0newTarget()\0"
    "setGameOver()\0restartGame()\0moveShot()\0"
};

void CannonField::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CannonField *_t = static_cast<CannonField *>(_o);
        switch (_id) {
        case 0: _t->hit(); break;
        case 1: _t->missed(); break;
        case 2: _t->angleChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->forceChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->canShoot((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->setAngle((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->setForce((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->shoot(); break;
        case 8: _t->newTarget(); break;
        case 9: _t->setGameOver(); break;
        case 10: _t->restartGame(); break;
        case 11: _t->moveShot(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData CannonField::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CannonField::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_CannonField,
      qt_meta_data_CannonField, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CannonField::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CannonField::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CannonField::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CannonField))
        return static_cast<void*>(const_cast< CannonField*>(this));
    return QWidget::qt_metacast(_clname);
}

int CannonField::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void CannonField::hit()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void CannonField::missed()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void CannonField::angleChanged(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void CannonField::forceChanged(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void CannonField::canShoot(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_END_MOC_NAMESPACE

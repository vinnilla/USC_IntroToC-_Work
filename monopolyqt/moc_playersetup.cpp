/****************************************************************************
** Meta object code from reading C++ file 'playersetup.h'
**
** Created: Fri May 2 12:25:54 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "playersetup.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'playersetup.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_PlayerSetup[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x08,
      23,   12,   12,   12, 0x08,
      34,   12,   12,   12, 0x08,
      43,   12,   12,   12, 0x08,
      52,   12,   12,   12, 0x08,
      64,   12,   12,   12, 0x08,
      75,   12,   12,   12, 0x08,
      89,   12,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_PlayerSetup[] = {
    "PlayerSetup\0\0hideAll()\0heartAct()\0"
    "pawAct()\0sunAct()\0targetAct()\0swordAct()\0"
    "yingyangAct()\0setPlayers()\0"
};

void PlayerSetup::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        PlayerSetup *_t = static_cast<PlayerSetup *>(_o);
        switch (_id) {
        case 0: _t->hideAll(); break;
        case 1: _t->heartAct(); break;
        case 2: _t->pawAct(); break;
        case 3: _t->sunAct(); break;
        case 4: _t->targetAct(); break;
        case 5: _t->swordAct(); break;
        case 6: _t->yingyangAct(); break;
        case 7: _t->setPlayers(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData PlayerSetup::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject PlayerSetup::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_PlayerSetup,
      qt_meta_data_PlayerSetup, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &PlayerSetup::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *PlayerSetup::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *PlayerSetup::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PlayerSetup))
        return static_cast<void*>(const_cast< PlayerSetup*>(this));
    return QWidget::qt_metacast(_clname);
}

int PlayerSetup::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

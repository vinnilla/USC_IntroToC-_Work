/****************************************************************************
** Meta object code from reading C++ file 'centralwidget.h'
**
** Created: Sun May 4 23:48:04 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "centralwidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'centralwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CentralWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x08,
      26,   14,   14,   14, 0x08,
      38,   36,   14,   14, 0x08,
      73,   14,   14,   14, 0x08,
      84,   14,   14,   14, 0x08,
      95,   14,   14,   14, 0x08,
     104,   14,   14,   14, 0x08,
     116,   14,   14,   14, 0x08,
     129,   14,   14,   14, 0x08,
     145,   14,   14,   14, 0x08,
     158,   14,   14,   14, 0x08,
     175,   14,   14,   14, 0x08,
     195,   14,   14,   14, 0x08,
     211,   14,   14,   14, 0x08,
     226,   14,   14,   14, 0x08,
     241,   14,   14,   14, 0x08,
     255,   14,   14,   14, 0x08,
     265,   14,   14,   14, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_CentralWidget[] = {
    "CentralWidget\0\0drawCard()\0rollDie()\0"
    ",\0determineDieFace(QPushButton*,int)\0"
    "nextTurn()\0buySpace()\0chance()\0"
    "community()\0percentTax()\0straightupTax()\0"
    "upgradeAct()\0tinyupgrade(int)\0"
    "advancetoSpace(int)\0moveSpaces(int)\0"
    "GainMoney(int)\0LoseMoney(int)\0"
    "gotoJail(int)\0duud(int)\0flip()\0"
};

void CentralWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CentralWidget *_t = static_cast<CentralWidget *>(_o);
        switch (_id) {
        case 0: _t->drawCard(); break;
        case 1: _t->rollDie(); break;
        case 2: _t->determineDieFace((*reinterpret_cast< QPushButton*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->nextTurn(); break;
        case 4: _t->buySpace(); break;
        case 5: _t->chance(); break;
        case 6: _t->community(); break;
        case 7: _t->percentTax(); break;
        case 8: _t->straightupTax(); break;
        case 9: _t->upgradeAct(); break;
        case 10: _t->tinyupgrade((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->advancetoSpace((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->moveSpaces((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->GainMoney((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->LoseMoney((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 15: _t->gotoJail((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 16: _t->duud((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 17: _t->flip(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData CentralWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CentralWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_CentralWidget,
      qt_meta_data_CentralWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CentralWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CentralWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CentralWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CentralWidget))
        return static_cast<void*>(const_cast< CentralWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int CentralWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

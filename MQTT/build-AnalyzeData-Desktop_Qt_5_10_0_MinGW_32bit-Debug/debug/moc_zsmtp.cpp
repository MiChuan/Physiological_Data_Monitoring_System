/****************************************************************************
** Meta object code from reading C++ file 'zsmtp.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../AnalyzeData/tools/zsmtp.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'zsmtp.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ZSmtp_t {
    QByteArrayData data[16];
    char stringdata0[144];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ZSmtp_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ZSmtp_t qt_meta_stringdata_ZSmtp = {
    {
QT_MOC_LITERAL(0, 0, 5), // "ZSmtp"
QT_MOC_LITERAL(1, 6, 12), // "disconnected"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 11), // "emailStatus"
QT_MOC_LITERAL(4, 32, 6), // "status"
QT_MOC_LITERAL(5, 39, 8), // "progress"
QT_MOC_LITERAL(6, 48, 1), // "p"
QT_MOC_LITERAL(7, 50, 15), // "connectToServer"
QT_MOC_LITERAL(8, 66, 20), // "disconnectFromServer"
QT_MOC_LITERAL(9, 87, 10), // "getMessage"
QT_MOC_LITERAL(10, 98, 13), // "sendEmailSlot"
QT_MOC_LITERAL(11, 112, 8), // "username"
QT_MOC_LITERAL(12, 121, 8), // "password"
QT_MOC_LITERAL(13, 130, 2), // "to"
QT_MOC_LITERAL(14, 133, 5), // "title"
QT_MOC_LITERAL(15, 139, 4) // "text"

    },
    "ZSmtp\0disconnected\0\0emailStatus\0status\0"
    "progress\0p\0connectToServer\0"
    "disconnectFromServer\0getMessage\0"
    "sendEmailSlot\0username\0password\0to\0"
    "title\0text"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ZSmtp[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x06 /* Public */,
       3,    1,   50,    2, 0x06 /* Public */,
       5,    1,   53,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   56,    2, 0x0a /* Public */,
       8,    0,   57,    2, 0x0a /* Public */,
       9,    0,   58,    2, 0x0a /* Public */,
      10,    5,   59,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Double,    6,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,   11,   12,   13,   14,   15,

       0        // eod
};

void ZSmtp::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ZSmtp *_t = static_cast<ZSmtp *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->disconnected(); break;
        case 1: _t->emailStatus((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->progress((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 3: _t->connectToServer(); break;
        case 4: _t->disconnectFromServer(); break;
        case 5: _t->getMessage(); break;
        case 6: _t->sendEmailSlot((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (ZSmtp::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ZSmtp::disconnected)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (ZSmtp::*_t)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ZSmtp::emailStatus)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (ZSmtp::*_t)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ZSmtp::progress)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject ZSmtp::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ZSmtp.data,
      qt_meta_data_ZSmtp,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ZSmtp::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ZSmtp::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ZSmtp.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ZSmtp::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void ZSmtp::disconnected()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void ZSmtp::emailStatus(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ZSmtp::progress(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

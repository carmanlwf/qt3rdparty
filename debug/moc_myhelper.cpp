/****************************************************************************
** Meta object code from reading C++ file 'myhelper.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../myhelper.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'myhelper.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MqttHelper_t {
    QByteArrayData data[15];
    char stringdata0[174];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MqttHelper_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MqttHelper_t qt_meta_stringdata_MqttHelper = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MqttHelper"
QT_MOC_LITERAL(1, 11, 7), // "Connect"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 9), // "Subscribe"
QT_MOC_LITERAL(4, 30, 7), // "publish"
QT_MOC_LITERAL(5, 38, 17), // "MqttMsgSubscribed"
QT_MOC_LITERAL(6, 56, 22), // "MqttMsgPublishReceived"
QT_MOC_LITERAL(7, 79, 16), // "ConnectionClosed"
QT_MOC_LITERAL(8, 96, 9), // "onTimeout"
QT_MOC_LITERAL(9, 106, 14), // "onDisconnected"
QT_MOC_LITERAL(10, 121, 12), // "onSubscribed"
QT_MOC_LITERAL(11, 134, 5), // "topic"
QT_MOC_LITERAL(12, 140, 10), // "onReceived"
QT_MOC_LITERAL(13, 151, 14), // "QMQTT::Message"
QT_MOC_LITERAL(14, 166, 7) // "message"

    },
    "MqttHelper\0Connect\0\0Subscribe\0publish\0"
    "MqttMsgSubscribed\0MqttMsgPublishReceived\0"
    "ConnectionClosed\0onTimeout\0onDisconnected\0"
    "onSubscribed\0topic\0onReceived\0"
    "QMQTT::Message\0message"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MqttHelper[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x0a /* Public */,
       3,    0,   65,    2, 0x0a /* Public */,
       4,    0,   66,    2, 0x0a /* Public */,
       5,    0,   67,    2, 0x0a /* Public */,
       6,    0,   68,    2, 0x0a /* Public */,
       7,    0,   69,    2, 0x0a /* Public */,
       8,    0,   70,    2, 0x0a /* Public */,
       9,    0,   71,    2, 0x0a /* Public */,
      10,    1,   72,    2, 0x0a /* Public */,
      12,    1,   75,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::QString,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void, 0x80000000 | 13,   14,

       0        // eod
};

void MqttHelper::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MqttHelper *_t = static_cast<MqttHelper *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->Connect(); break;
        case 1: _t->Subscribe(); break;
        case 2: _t->publish(); break;
        case 3: _t->MqttMsgSubscribed(); break;
        case 4: { QString _r = _t->MqttMsgPublishReceived();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 5: _t->ConnectionClosed(); break;
        case 6: _t->onTimeout(); break;
        case 7: _t->onDisconnected(); break;
        case 8: _t->onSubscribed((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 9: _t->onReceived((*reinterpret_cast< const QMQTT::Message(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 9:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QMQTT::Message >(); break;
            }
            break;
        }
    }
}

const QMetaObject MqttHelper::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_MqttHelper.data,
      qt_meta_data_MqttHelper,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MqttHelper::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MqttHelper::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MqttHelper.stringdata0))
        return static_cast<void*>(const_cast< MqttHelper*>(this));
    return QObject::qt_metacast(_clname);
}

int MqttHelper::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

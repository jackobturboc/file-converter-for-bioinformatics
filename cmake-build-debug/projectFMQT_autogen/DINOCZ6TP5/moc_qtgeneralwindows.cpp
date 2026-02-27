/****************************************************************************
** Meta object code from reading C++ file 'qtgeneralwindows.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../sourceFiles/qtgeneralwindows.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qtgeneralwindows.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_qtImportWindow_t {
    QByteArrayData data[6];
    char stringdata0[85];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_qtImportWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_qtImportWindow_t qt_meta_stringdata_qtImportWindow = {
    {
QT_MOC_LITERAL(0, 0, 14), // "qtImportWindow"
QT_MOC_LITERAL(1, 15, 16), // "reviewButtonSlot"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 17), // "isFileCorrectSlot"
QT_MOC_LITERAL(4, 51, 15), // "ListOfTypesSlot"
QT_MOC_LITERAL(5, 67, 17) // "ListOfFormatsSlot"

    },
    "qtImportWindow\0reviewButtonSlot\0\0"
    "isFileCorrectSlot\0ListOfTypesSlot\0"
    "ListOfFormatsSlot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_qtImportWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x0a /* Public */,
       3,    0,   35,    2, 0x0a /* Public */,
       4,    0,   36,    2, 0x0a /* Public */,
       5,    0,   37,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void qtImportWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<qtImportWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->reviewButtonSlot(); break;
        case 1: _t->isFileCorrectSlot(); break;
        case 2: _t->ListOfTypesSlot(); break;
        case 3: _t->ListOfFormatsSlot(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject qtImportWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_qtImportWindow.data,
    qt_meta_data_qtImportWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *qtImportWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *qtImportWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_qtImportWindow.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int qtImportWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
struct qt_meta_stringdata_qtSettingsWindow_t {
    QByteArrayData data[1];
    char stringdata0[17];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_qtSettingsWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_qtSettingsWindow_t qt_meta_stringdata_qtSettingsWindow = {
    {
QT_MOC_LITERAL(0, 0, 16) // "qtSettingsWindow"

    },
    "qtSettingsWindow"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_qtSettingsWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void qtSettingsWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject qtSettingsWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_qtSettingsWindow.data,
    qt_meta_data_qtSettingsWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *qtSettingsWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *qtSettingsWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_qtSettingsWindow.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int qtSettingsWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_qtExportWindow_t {
    QByteArrayData data[11];
    char stringdata0[163];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_qtExportWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_qtExportWindow_t qt_meta_stringdata_qtExportWindow = {
    {
QT_MOC_LITERAL(0, 0, 14), // "qtExportWindow"
QT_MOC_LITERAL(1, 15, 10), // "getOutPath"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 10), // "setOutName"
QT_MOC_LITERAL(4, 38, 8), // "Settings"
QT_MOC_LITERAL(5, 47, 15), // "copyRecordsSlot"
QT_MOC_LITERAL(6, 63, 22), // "deleteExportRecordSlot"
QT_MOC_LITERAL(7, 86, 21), // "clearMemoryRecordSlot"
QT_MOC_LITERAL(8, 108, 21), // "clearExportRecordSlot"
QT_MOC_LITERAL(9, 130, 17), // "ListOfFormatsSlot"
QT_MOC_LITERAL(10, 148, 14) // "saveButtonSlot"

    },
    "qtExportWindow\0getOutPath\0\0setOutName\0"
    "Settings\0copyRecordsSlot\0"
    "deleteExportRecordSlot\0clearMemoryRecordSlot\0"
    "clearExportRecordSlot\0ListOfFormatsSlot\0"
    "saveButtonSlot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_qtExportWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x0a /* Public */,
       3,    0,   60,    2, 0x0a /* Public */,
       4,    0,   61,    2, 0x0a /* Public */,
       5,    0,   62,    2, 0x0a /* Public */,
       6,    0,   63,    2, 0x0a /* Public */,
       7,    0,   64,    2, 0x0a /* Public */,
       8,    0,   65,    2, 0x0a /* Public */,
       9,    0,   66,    2, 0x0a /* Public */,
      10,    0,   67,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void qtExportWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<qtExportWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->getOutPath(); break;
        case 1: _t->setOutName(); break;
        case 2: _t->Settings(); break;
        case 3: _t->copyRecordsSlot(); break;
        case 4: _t->deleteExportRecordSlot(); break;
        case 5: _t->clearMemoryRecordSlot(); break;
        case 6: _t->clearExportRecordSlot(); break;
        case 7: _t->ListOfFormatsSlot(); break;
        case 8: _t->saveButtonSlot(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject qtExportWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_qtExportWindow.data,
    qt_meta_data_qtExportWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *qtExportWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *qtExportWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_qtExportWindow.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int qtExportWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
struct qt_meta_stringdata_qtGeneralWindow_t {
    QByteArrayData data[6];
    char stringdata0[64];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_qtGeneralWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_qtGeneralWindow_t qt_meta_stringdata_qtGeneralWindow = {
    {
QT_MOC_LITERAL(0, 0, 15), // "qtGeneralWindow"
QT_MOC_LITERAL(1, 16, 12), // "openSettings"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 9), // "openStart"
QT_MOC_LITERAL(4, 40, 10), // "getStarted"
QT_MOC_LITERAL(5, 51, 12) // "comeBackSlot"

    },
    "qtGeneralWindow\0openSettings\0\0openStart\0"
    "getStarted\0comeBackSlot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_qtGeneralWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x0a /* Public */,
       3,    0,   35,    2, 0x0a /* Public */,
       4,    0,   36,    2, 0x0a /* Public */,
       5,    0,   37,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void qtGeneralWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<qtGeneralWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->openSettings(); break;
        case 1: _t->openStart(); break;
        case 2: _t->getStarted(); break;
        case 3: _t->comeBackSlot(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject qtGeneralWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_qtGeneralWindow.data,
    qt_meta_data_qtGeneralWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *qtGeneralWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *qtGeneralWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_qtGeneralWindow.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int qtGeneralWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

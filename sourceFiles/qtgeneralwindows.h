#ifndef QTGENERALWINDOWS_H
#define QTGENERALWINDOWS_H

#include "manager.hpp"
#include "global_const.hpp"

class qtImportWindow:public QObject {
    Q_OBJECT
public:
    Manager *managerI;
    QWidget * window;
    QGridLayout * importLayout;
    QPushButton * reviewButton;
    QPlainTextEdit * reviewFileInformation;
    QComboBox * ListOfTypes;
    QComboBox * ListOfFormats;
    QPushButton * isFileCorrect;
    QPushButton * comeBack;
    void initalize();
public slots:
    void reviewButtonSlot();
    void isFileCorrectSlot();
    void ListOfTypesSlot();
    void ListOfFormatsSlot();
};

class qtSettingsWindow:public QObject {
Q_OBJECT
public:
    QLineEdit * setLineSize;
    QLineEdit * setLineSizeName;
    QLineEdit * setTitle;
    QLineEdit * setTitleName;
    QPlainTextEdit * selectFileInM;
    QComboBox * selectFileInMName;
    QPushButton * saveSet;
    void initalize();
public slots:
//    void saveAll();
//    void showIt();
};

class qtExportWindow:public QObject {
    Q_OBJECT
public:
    Manager *managerE;
    QWidget * window;
    QGridLayout * exportLayout;
    QPlainTextEdit * memoryRecord;
    QPlainTextEdit * exportRecord;
    QPushButton * clearMemoryRecord;
    QPushButton * clearExportRecord;
    QPushButton * selectPath;
    QPlainTextEdit * selectName;
    QPushButton * settings;
    QComboBox * ListOfFormats;
    QPushButton * saveButton;
    void initalize();
public slots:
    void getOutPath();
    void setOutName();
    void Settings();
    void copyRecordsSlot();
    void deleteExportRecordSlot();
    void clearMemoryRecordSlot();
    void clearExportRecordSlot();
    void ListOfFormatsSlot();
    void saveButtonSlot();
};

class qtGeneralWindow:public QObject {
Q_OBJECT
public:
    QGridLayout * generalGrid;
    QLineEdit * helloText;
    QPushButton * getStart;
    QPushButton * getSetting;
    Manager manager;
    qtImportWindow importW;
    qtExportWindow exportW;
    QWidget * windowGeneral;
    std::string type;
    std::string format;
    void initalize();
public slots:
    void openSettings();
    void openStart();
    void getStarted();
    void comeBackSlot();
};

#endif // QTGENERALWINDOWS_H

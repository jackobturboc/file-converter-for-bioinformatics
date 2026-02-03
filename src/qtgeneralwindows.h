#ifndef QTGENERALWINDOWS_H
#define QTGENERALWINDOWS_H

#include "manager.hpp"
#include "global_const.hpp"

class qtImportWindow:public QObject {
    Q_OBJECT
public:
    QWidget * window;
    QGridLayout * importLayout;
    QPushButton * reviewButton;
    QLineEdit * reviewFileInformation;
    QComboBox * ListOfTypes;
    QComboBox * ListOfFormats;
    QPushButton * isFileCorrect;
    QPushButton * loadButton;
    void initalize();
public slots:

};

class qtExportWindow:public QObject {
    Q_OBJECT
public:
    QWidget * window;
    QGridLayout * exportLayout;
    void initalize();
public slots:

};

class qtGeneralWindow:public QObject {
    Q_OBJECT
public:
    bool isImport;
    qtImportWindow importW;
    qtExportWindow exportW;
    QWidget * windowGeneral;
    std::string type;
    std::string format;
    void initalize();
public slots:
    void reviewButtonSlot();
    void isFileCorrectSlot();
    void loadButtonSlot();
    void ListOfTypesSlot();
};

#endif // QTGENERALWINDOWS_H

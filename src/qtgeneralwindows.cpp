#include "qtgeneralwindows.h"

void qtGeneralWindow::initalize() {
    windowGeneral = new QWidget;
    importW.initalize();
    exportW.initalize();
    if (!isImport) {
        importW.window->show();
    }
    else {
        exportW.window->show();
    }
}
void qtGeneralWindow::isFileCorrectSlot() {

}

void qtGeneralWindow::reviewButtonSlot() {

}

void qtGeneralWindow::loadButtonSlot() {
    if (importW.ListOfFormats->currentText() == "AUTO") {
//        manager.detect.fileFormatSearcher();
    } else {
//        manager.properties.inpFileTy = importW.ListOfFormats->currentText().toStdString();
    }
}

void qtGeneralWindow::ListOfTypesSlot() {
    if(importW.ListOfTypes->currentText() == "Sequenсe"){
//        qDebug() << "sequence";
    }
}



void qtImportWindow::initalize() {
    window = new QWidget;
    window->resize(400, 400);
    window->setMaximumHeight(400);
    window->setMaximumWidth(400);
    importLayout = new QGridLayout(window);
    isFileCorrect = new QPushButton;
    reviewButton = new QPushButton;
    loadButton = new QPushButton;
    ListOfTypes = new QComboBox;
    ListOfFormats = new QComboBox;
    reviewFileInformation = new QLineEdit;
    reviewFileInformation->setReadOnly(true);
    ListOfFormats->addItems(
        {
            "AUTO",
            "FASTA_bare",
            "FASTA_general",
            "FASTA_NCBI_db_link",
            "FASTA_GenBank",
            "NCBI_common",
            "EMBL",
            "FASTAQ Sanger",
            "FASTAQ Solexa",
            "FASTAQ Illumina"
        }
    );
    ListOfTypes->addItems(
        {
        "Pair",
        "Sequenсe",
        "MSA"
        }
    );

    reviewFileInformation->setMinimumHeight(200);

    reviewButton->setText("Обзор");
    isFileCorrect->setText("Проверка корректности");
    loadButton->setText("Загрузка");
    importLayout->addWidget(ListOfTypes, 1, 0);
    importLayout->addWidget(ListOfFormats, 2, 0);
    importLayout->addWidget(reviewButton, 3, 0);
    importLayout->addWidget(isFileCorrect, 4, 0);
    importLayout->addWidget(loadButton, 5, 0);
    importLayout->addWidget(reviewFileInformation,0, 1, 1, 2);
    window->setLayout(importLayout);
}
void qtExportWindow::initalize() {
    window = new QWidget;
    exportLayout = new QGridLayout;

};

#include "qtgeneralwindows.h"

void qtSettingsWindow::initalize() {
    saveSet = new QPushButton;
//    setPathLog = new QLineEdit;
}

void qtGeneralWindow::initalize() {
    importW.managerI = &manager;
    exportW.managerE = &manager;
    windowGeneral = new QWidget;
    generalGrid = new QGridLayout(windowGeneral);
    helloText = new QLineEdit;
    getStart = new QPushButton;
    getSetting = new QPushButton;
    manager.properties.isImport = 1;
    windowGeneral->setWindowTitle("Project Fm");
    helloText->setText("проект FM");
    getSetting->setText("GitHub");
    getStart->setText("Начать");
    helloText->setReadOnly(true);
    generalGrid->addWidget(helloText, 0, 0, 1, 2);
    generalGrid->addWidget(getStart, 1, 0);
    generalGrid->addWidget(getSetting, 1, 1);
    windowGeneral->show();
    connect(getStart, &QPushButton::clicked, this, &qtGeneralWindow::getStarted);
    importW.initalize();

    exportW.initalize();
    connect(importW.comeBack,&QPushButton::clicked, this, &qtGeneralWindow::comeBackSlot);
//    exportW.window->show();
}

void qtGeneralWindow::getStarted(){
    windowGeneral->hide();
    if (manager.properties.isImport == 1) {
        importW.window->show();
    }
    else if (manager.properties.isImport == 2) {
        manager.fileType = importW.ListOfTypes->currentText().toStdString();
        manager.doProperties();
        manager.getFiles();
        if (manager.fileType == "seq") {
            exportW.memoryRecord->setPlainText(QString::fromStdString(manager.sList.show(1, 1, 1, 1, 0)));
        }
        else if (manager.fileType == "msa") {
//            exportW.memoryRecord->setPlainText(QString::fromStdString(manager.mList.show(1, 1, 1, 1));
        } else {
//            exportW.memoryRecord->setPlainText(QString::fromStdString(manager.sList.show(1, 1, 1, 1, 0)));
        }
        exportW.window->show();
    }
}
void qtGeneralWindow::comeBackSlot(){
    if (manager.detect.fileFormatSearcher() == 1){
        importW.reviewFileInformation->setPlainText("Incorrect format, check the file and whether it is in the list of available files in the program.");
        return;
    }
    if (importW.ListOfFormats->currentText() == "AUTO") {
        manager.detect.fileFormatSearcher();
    } else {

        manager.properties.inpFileTy = importW.ListOfFormats->currentText().toStdString();
    }
    importW.window->hide();
    manager.properties.isImport = 2;
    getStarted();
}

void qtGeneralWindow::openSettings(){
    system("https://github.com/jackobturboc/file-converter-for-bioinformatics");
}
void qtGeneralWindow::openStart(){

}

void qtImportWindow::initalize() {
    window = new QWidget;
    window->resize(600, 400);
    window->setMaximumHeight(400);
    window->setMaximumWidth(600);
    importLayout = new QGridLayout(window);
    isFileCorrect = new QPushButton;
    reviewButton = new QPushButton;
    ListOfTypes = new QComboBox;
    comeBack = new QPushButton;
    ListOfFormats = new QComboBox;
    reviewFileInformation = new QPlainTextEdit;
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
                    "FASTAQ_sanger",
                    "FASTAQ_solexa",
                    "FASTAQ_illumina"
            }
    );
    ListOfTypes->addItems(
            {
                    "seq",
                    "Pair",
                    "MSA"
            }
    );

    reviewFileInformation->setMinimumHeight(200);

    reviewButton->setText("Обзор");
    isFileCorrect->setText("Проверка корректности");
    comeBack->setText("Загрузка");
    window->setWindowTitle("Импорт");
    importLayout->addWidget(ListOfTypes, 1, 0);
    importLayout->addWidget(ListOfFormats, 2, 0);
    importLayout->addWidget(reviewButton, 3, 0);
    importLayout->addWidget(isFileCorrect, 4, 0);
    importLayout->addWidget(comeBack, 5, 0);
    //importLayout->addWidget(loadButton, 6, 0);
    importLayout->addWidget(reviewFileInformation, 0, 1, 1, 2);
    window->setLayout(importLayout);
    connect(isFileCorrect, &QPushButton::clicked, this, &qtImportWindow::isFileCorrectSlot);
    connect(ListOfFormats, &QComboBox::currentTextChanged, this, &qtImportWindow::ListOfFormatsSlot);
    connect(ListOfTypes, &QComboBox::currentTextChanged, this, &qtImportWindow::ListOfTypesSlot);
    connect(reviewButton, &QPushButton::clicked, this, &qtImportWindow::reviewButtonSlot);
}

void qtImportWindow::isFileCorrectSlot() {
    managerI->detect.fileFormatSearcher();
    reviewFileInformation->setPlainText(QString::fromStdString(managerI->properties.codeOut));
}
//Обзор
void qtImportWindow::reviewButtonSlot() {
    managerI->properties.pathToInp = QFileDialog::getOpenFileName(0, "Открыть", "examples/  ", "").toStdString();
    ListOfFormatsSlot();
}

void qtImportWindow::ListOfTypesSlot() {
    if(ListOfTypes->currentText() == "Sequenсe"){
        //        qDebug() << "sequence";
    }
}

void qtImportWindow::ListOfFormatsSlot() {
    managerI->properties.inpFileTy = ListOfFormats->currentText().toStdString();
    if (managerI->properties.pathToInp == "nothing") {
        return;
    }
    std::string inp;
    std::string line;
    std::ifstream in(managerI->properties.pathToInp);
    if (in.is_open()) {
        while (getline(in, line)) {
            inp += line + "\n";
        }
    }
    in.close();
    reviewFileInformation->setPlainText(QString::fromStdString(inp));
}

void qtExportWindow::initalize() {
    window = new QWidget;
    window->resize(600, 400);
    window->setWindowTitle("Окно экспорта");
    window->setMaximumHeight(400);
    window->setMaximumWidth(600);
    exportLayout = new QGridLayout(window);
    memoryRecord = new QPlainTextEdit;
    exportRecord = new QPlainTextEdit;
    selectPath = new QPushButton;
    selectName = new QPlainTextEdit;
    selectPath->setText("имя файла");
    settings = new QPushButton;
    // TODO Дописать лайнэдиты
    clearMemoryRecord = new QPushButton;
    clearMemoryRecord->setText("Очистка памяти");
    clearExportRecord = new QPushButton;
    clearExportRecord->setText("Очистка записи в файл");
    ListOfFormats = new QComboBox;
    ListOfFormats->addItems(
            {
                    "FASTA_bare",
                    "FASTA_general",
                    "FASTA_NCBI_db_link",
                    "FASTA_GenBank",
                    "NCBI_common",
//                    "EMBL",
                    "FASTAQ Sanger",
                    "FASTAQ Solexa",
                    "FASTAQ Illumina"
                }
    );
    // lengthOfString = new QLineEdit;
    // nameOfFile  = new QLineEdit;
    // и тут тоже
    saveButton  = new QPushButton;
    saveButton->setText("Сохранить");
    memoryRecord->setMinimumHeight(200);
    exportRecord->setMinimumHeight(200);
    exportLayout->addWidget(selectPath, 0, 0);
    exportLayout->addWidget(settings, 2, 0);
    exportLayout->addWidget(ListOfFormats, 4, 0);
    exportLayout->addWidget(saveButton, 5, 0);
    exportLayout->addWidget(memoryRecord, 0, 1);
    exportLayout->addWidget(exportRecord, 3, 1);
    connect(clearMemoryRecord, &QPushButton::clicked, this, &qtExportWindow::clearMemoryRecordSlot);
    connect(saveButton, &QPushButton::clicked, this, &qtExportWindow::saveButtonSlot);
    connect(ListOfFormats, &QComboBox::currentTextChanged, this, &qtExportWindow::ListOfFormatsSlot);
    connect(selectName, &QPlainTextEdit::textChanged, this, &qtExportWindow::setOutName);
    connect(selectPath, &QPushButton::clicked, this, &qtExportWindow::getOutPath);
    window->setLayout(exportLayout);
}
//Export

void qtExportWindow::getOutPath() {
    managerE->properties.log("RUN: path to out select");
    managerE->properties.pathToOut =
            QFileDialog::getOpenFileName(0, "Открыть", "C:\\", "").toStdString();
}

void qtExportWindow::setOutName() {
    managerE->properties.log("RUN: name to out select");
    managerE->properties.outFileName = selectName->toPlainText().toStdString();

}

void qtExportWindow::Settings() {
    managerE->properties.log("RUN: setting in import was opened");
}

void qtExportWindow::copyRecordsSlot() {

}

void qtExportWindow::deleteExportRecordSlot() {

}

void qtExportWindow::clearMemoryRecordSlot() {
    managerE->properties.log("RUN: Start memory clearing \n");
    std::ofstream out(managerE->properties.pathToOut, std::ios::out);
    out << " ";
    out.close();
    managerE->properties.log("RUN: Finish memory is cleared \n");
}

void qtExportWindow::clearExportRecordSlot() {

}

void qtExportWindow::ListOfFormatsSlot() {
    managerE->properties.outFileTy = ListOfFormats->currentText().toStdString();
    exportRecord->setPlainText(QString::fromStdString(managerE->writeT()));
}

void qtExportWindow::saveButtonSlot() {
    managerE->properties.log("RUN: Start file saving \n");
    managerE->writeFiles();
    managerE->properties.log("RUN: Finish file is saved \n");
}
//Setting

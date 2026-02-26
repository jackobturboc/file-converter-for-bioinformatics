#include "qtgeneralwindows.h"
#include "interface.hpp"
#include <QApplication>

int main(int argc, char *argv[]) {
    Properties p;
    QApplication a(argc, argv);
    qtGeneralWindow IAN;
//    Manager manager;
//    p.pathToInp = QFileDialog::getOpenFileName(0, "Открыть", "examples\\examples_better\\", "").toStdString();
//    manager.run(p);
//    std::cout << manager.sList.format << "\n";
//    manager.sList.show(1, 1, 1, 1);
    IAN.manager.properties.log("Code was started\n");
    IAN.initalize();
    return a.exec();
//    int n = 1;
//    for (int i = 1; i < 25; ++i) {
//        n *= i;
//    }
//    std::cout << n;
}

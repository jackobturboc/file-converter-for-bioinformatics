#include "qtgeneralwindows.h"
#include "interface.hpp"
#include <QApplication>
#include <webSocet.hpp>


int main(int argc, char *argv[]) {
//    Properties p;
    QApplication a(argc, argv);
    qtGeneralWindow IAN;

    //IAN.manager.properties.log("Code was started\n");
    IAN.initalize();
    return a.exec();

}

#include "widget.h"
#include "qtgeneralwindows.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    qtGeneralWindow IAN;

    IAN.initalize();
    return a.exec();
}

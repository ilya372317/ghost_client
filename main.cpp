#include <QApplication>
#include "QListView"
#include "src/Widget/MainWindow.h"

int main(int argc, char *argv[]) {
    QApplication ghostClientApp(argc, argv);
    MainWindow mainWindow;
    mainWindow.show();
    return ghostClientApp.exec();
}

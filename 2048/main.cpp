#include "App/app.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    App w;
    w.run();

    return a.exec();
}

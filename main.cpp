#include <QCoreApplication>
#include <QTimer>

#include "mainclass.h"

MainClass *mainTask;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // create the main class
    mainTask = new MainClass(&a);

    // connect up the signals
    QObject::connect(mainTask, SIGNAL(finished()), &a, SLOT(quit()));
    QObject::connect(&a, SIGNAL(aboutToQuit()), mainTask, SLOT(aboutToQuitApp()));

    // create singleshot timer to start run() in mainTask after 100ms
    QTimer::singleShot(100, mainTask, SLOT(run()));

    return a.exec();
}

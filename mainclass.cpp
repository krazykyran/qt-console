#include "mainclass.h"

MainClass::MainClass(QObject *parent) : QObject(parent)
{
    app = QCoreApplication::instance();
    // setup everything here
    // create any global objects
    // setup debug and warning mode
}

void MainClass::quit()
{
    // send finished signal to quit
    emit finished();
}

void MainClass::run()
{
    // do some processing here
    qDebug() << "Hello World!";
    qDebug() << "MainClass::run() is executing...";

    quit();
}

void MainClass::aboutToQuitApp()
{
    // stop threads
    qDebug() << "stopping threads ...";
    // sleep(1)
    // delete any objects ...
}

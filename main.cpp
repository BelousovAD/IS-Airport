#include "authorisationwindow.h"

#include <QApplication>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    AuthorisationWindow w;
    w.show();
    return a.exec();
}

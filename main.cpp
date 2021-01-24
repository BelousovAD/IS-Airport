#include "authorisationdialog.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    AuthorisationDialog window;
    window.show();
    return a.exec();
}

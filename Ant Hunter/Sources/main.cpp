#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
    /** makes window save results of previous session */
    a.setQuitOnLastWindowClosed(false);

    return a.exec();
}

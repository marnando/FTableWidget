#include "ftablewidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FTableWidget w;
    w.show();

    return a.exec();
}

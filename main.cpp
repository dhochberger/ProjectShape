#include <QApplication>
#include "PageAppli.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    PageAppli p;
    p.show();

    return a.exec();
}

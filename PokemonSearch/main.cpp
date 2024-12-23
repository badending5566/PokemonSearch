#include "PokemonSearch.h"
#include <QtWidgets/QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PokemonSearch w;
    w.show();
    return a.exec();
}

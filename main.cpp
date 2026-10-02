#include "Spravca_autoservisu.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Spravca_autoservisu window;
    window.show();
    return app.exec();
}

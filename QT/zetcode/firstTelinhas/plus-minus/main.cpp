#include<plus-minus.h>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    PlusMinus window;
    window.resize(350, 250);
    window.setWindowTitle("bibi");
    window.show();

    return app.exec();
}
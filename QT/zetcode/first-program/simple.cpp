#include <QApplication>
#include <QWidget>

int main(int argc, char *argv[]) 
{
 QApplication app(argc, argv);
 QWidget window;

 window.resize(350, 150);
 window.setWindowTitle("teste e testando");
 window.setToolTip("Easter egg");
 window.show();

 return app.exec();
    return 0;
}
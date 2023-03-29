/*
#include<QApplication>
#include<QWidget>
#include<QPushButton>

class Button: public QWidget
{
    public:
    Button(QWidget *parent = nullptr);


};

Button::Button(QWidget *parent ) : QWidget(parent) // construinod o construtor
{

    auto *quitButton = new QPushButton("Sair", this);
    quitButton->setGeometry(50,70,90, 30);

    connect(quitButton, &QPushButton::clicked, qApp, &QApplication::quit);
    // connect (oq, faz oq, pra onde, que faz oq)


}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Button window;
    window.resize(350,250);
    window.setWindowTitle("butao");
    window.show();

    return app.exec();
}
*/

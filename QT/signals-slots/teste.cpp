#include <QApplication>
#include <QTextStream>
#include <QPushButton>
#include <QObject>
#include<QMainWindow>
#include <QWidget>

class Counter : public QWidget
{
    Q_OBJECT // todas as classes que usam signal e slots devem declarar isso ao topo

    public:
        explicit Counter(QWidget *parent = nullptr) {

        connect(&a, &Counter::valueChanged, &b, &Counter::setValue);

        m_value = 0;
    }
        int value() const { return m_value;}

        public slots:
        void setValue(int value)
        {
            if(value != m_value)
            {
                m_value = value;
                emit valueChanged(value); // emite o sinal 
            }
        }


        signals:
            void valueChanged(int value)
            {
                QTextStream out(stdout);
                out << "mudou para " << value<<Qt::endl;
            }
        private:
         int m_value;
};

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    QMainWindow *window = new QMainWindow();



    a.setValue(12);
    b.setValue(48);

    return app.exec();
}

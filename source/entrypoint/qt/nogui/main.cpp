#ifdef USE_QT

#include <QCoreApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qDebug() << "Hello from Qt Console!";

    return a.exec();
}

#else
#error Please enable USE_QT cmake variable!
#endif

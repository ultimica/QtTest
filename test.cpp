#include <QDebug>
#include <QList>
#include <QMap>
#include <QString>
#include <functional>
#include <iostream>
#include <string>

template <class T1, class T2>
auto MAXXXX(T1 a, T2 b) -> decltype(false ? a : b)
{
    return a > b ? a : b;
}

int main()
{
    // int i;
    // int j;
    // (false ? i : j) = 45;

    // int i;
    // int j;
    // (true ? i : j) = 45;

    // true ? return 0 : return 1;

    std::cout << (false ? 9 : '9') << " " << (true ? 9 : '9') << std::endl;

    int a = 1;
    int b = 1;
    int c = 1;
    a = true ? ++b : ++c;

    int Ainput = 10.0;
    double Binput = 30;

    auto retvalue = MAXXXX(Ainput, Binput);
    qDebug() << retvalue;

    return 0;
}

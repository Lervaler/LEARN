#include <iostream>

using namespace std;

int main()
{
   int a{5}, c{5};
   int b, d;

    cout << "a ="                  << a << endl;

    cout << "c ="                  << c << endl;

    cout << "a = a + b - 2 = "     << a + b - 2 << endl;

    cout << "c = c + 1 = "          << c + 1 << endl;

    cout << "d = c - a + d = "      << c - a + d << endl;

    cout << "a = a * c = "              << a * c << endl;

    cout << "c = c - 1 = "              << c - 1 << endl;

    cout << "a = a / 10 = "             << a / 10 << endl;

    cout << "c = c / 2 = "             << c / 2 << endl;

    cout << "b = b - 1 ="              << b - 1 << endl;

    cout << "d = d *( c + b + a)"      << d * ( c + b + a) << endl;

    getchar();

    return 0;
}

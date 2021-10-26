#include <iostream>

using namespace std;

int main()
{
    double a, b, c, x, p;
    cout << "Podaj a" << endl;
    cin >> a;
    cout << "Podaj b" << endl;
    cin >> b;
    cout << "Podaj c" << endl;
    cin >> c;

    x = (a + b + c) / 2;
    if (x <= 0)
    {
        cout << "Taki trojkat nie istnieje";
        goto End;
    }

    p = sqrt(x * (x - a) * (x - b) * (x - c));
    cout << "Pole trojkata :" << p << endl;

End:
    return 0;


}

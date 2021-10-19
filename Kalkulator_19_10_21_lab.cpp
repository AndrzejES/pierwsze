#include <iomanip>
#include <iostream>

using namespace std;

void WezLiczby(int* a, int* b)
{
	cout << "Podaj a:";
	cin >> *a;
	cout << "Podaj b:";
	cin >> *b;
}


int main(void)
{
	system("color 0a");

	int x = 0;
	int y = 0;
	int wynik;

	int i;
	while (1)
	{
		system("cls");
		cout << "1 - Dodawanie" << endl;
		cout << "2 - Odejmowanie" << endl;
		cout << "3 - Mnozenie" << endl;
		cout << "4 - Dzielenie" << endl;
		cout << "5 - Koniec" << endl;

		cout << "Make your choice : ";
		cin >> i;

		switch (i)
		{
		case 1:
			cout << "Wybrales dodawanie." << endl;
			WezLiczby(&x, &y);
			cout << "Wynik dodawania: " << x << "+" << y << "=" << x + y << endl;
			break;
		case 2:
			cout << "Wybrales odejmowanie." << endl;
			WezLiczby(&x, &y);
			cout << "Wynik odejmowania: " << x << "-" << y << "=" << x - y << endl;
			break;
		case 3:
			cout << "Wybrales mnozenie" << endl;
			WezLiczby(&x, &y);
			cout << "Wynik mnozenia: " << x << "x" << y << "=" << x * y << endl;
			break;
		case 4:
			cout << "Wybrales dzielenia" << endl;
			WezLiczby(&x, &y);
			if (y != 0)
				cout << "Wynik dzielenia: " << x << "x" << y << "=" << x / y << endl;
			else
				cout << "Error!" << endl;
			break;
		case 5:
			   goto The_End;
			   break;
		default:
			cout << "Bledny argument!" << endl;
		}
		system("pause");
	}

The_End:
	return 0;



	

}

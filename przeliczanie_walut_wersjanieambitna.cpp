#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <iostream>


#define USD  3.8691
#define EUR  4.2652
#define GBP  4.9470
#define CHF  3.8787
#define JPY  0.35434
#define CAD  2.9256

using namespace std;

int main(void)
{
	string odUsera;
    string kwota,waluta;
	
    unsigned int ret;
	unsigned float f_kwota;

START:

	printf("1 USD = 3.8691  PLN\n" \
		   "1 EUR = 4.2652  PLN\n" \
		   "1 GBP = 4.9470  PLN\n" \
		   "1 CHF = 3.8787  PLN\n" \
		   "1 JPY = 0.35434 PLN\n" \
		   "1 CAD = 2.9256  PLN\n\n");

	
	cout << "Podaj kwote i walute (format: <kwota>-<waluta>): ";
	cin >> odUsera;

	//cout << "User wpisal : " << odUsera << "\n";
    size_t len = odUsera.length();
	if ((ret = odUsera.find('-')) != 0)
	{
		kwota = odUsera.substr(0, ret);
		waluta = odUsera.substr(ret+1, len);

		//cout << "Po parsowaniu\n" << "Kwota : " << kwota << "\n" << "Waluta : " << waluta << "\n\n";
		//cout << "len " << len;
		if (isdigit(kwota[0]))
		{
			f_kwota = stof(kwota);
			//cout << "Kwota float " << f_kwota << "\n";
			if (waluta.compare("USD") == 0)
			{cout << "Rownowartosc w zlotowkach : " << f_kwota * USD << endl << endl;}
			else if (waluta.compare("EUR") == 0)
			{cout << "Rownowartosc w zlotowkach : " << f_kwota * EUR << endl << endl;}
			else if (waluta.compare("GBP") == 0)
			{cout << "Rownowartosc w zlotowkach : " << f_kwota * GBP << endl << endl;}
			else if (waluta.compare("CHF") == 0)
			{cout << "Rownowartosc w zlotowkach : " << f_kwota * CHF << endl << endl;}
			else if (waluta.compare("JPY") == 0)
			{cout << "Rownowartosc w zlotowkach : " << f_kwota * JPY << endl << endl;}
			else if (waluta.compare("CAD") == 0)
			{cout << "Rownowartosc w zlotowkach : " << f_kwota * CAD << endl << endl;}
			else
			{
				cout << "Nie obslugiwana waluta" << endl;
			}
		}
		else
		{cout << "Bledna kwota !! " << "\n";}

		system("pause");
		system("cls");
		
}

	goto START;

}

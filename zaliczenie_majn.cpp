#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <vector>

#define BAZA "./baza.txt"
using namespace std;

vector <string> Category;
vector <string> Products;
vector <string> ID_Prod;
vector <string> Price;
vector <string> Description;

int CatIndex;
string TableNumber;

vector <string> OrderName;
vector <float> OrderPrice;

void PrintError(string ErrorCode)
{
	system("cls");
	printf("  .--.    ___ .-.     ___ .-.      .--.    ___ .-.    \n" \
		" /    \  (   )   \   (   )   \    /    \  (   )   \   \n" \
		"|  .-. ;  | ' .-. ;   | ' .-. ;  |  .-. ;  | ' .-. ;  \n" \
		"|  | | |  |  / (___)  |  / (___) | |  | |  |  / (___) \n" \
		"|  |/  |  | |         | |        | |  | |  | |        \n" \
		"|  ' _.'  | |         | |        | |  | |  | |        \n" \
		"|  .'.-.  | |         | |        | '  | |  | |        \n" \
		"'  `-' /  | |         | |        '  `-' /  | |        \n" \
		" `.__.'  (___)       (___)        `.__.'  (___)       \n");
	cout << ErrorCode;
	system("pause");

}

void CleanOrder(void)
{
	OrderName.clear();
	OrderPrice.clear();
}

short OrderToFile(void)
{
	char FileName[32] = { 0 };

	time_t rawtime;
	struct tm* timeinfo;

	time(&rawtime);
	timeinfo = localtime(&rawtime);
	
	sprintf(FileName, "S%s_%d_%d_%d.txt\0", TableNumber.c_str(), timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec); // Mozliwy bufferoverflow

	unsigned short i;
	size_t OrderLen = OrderName.size();

	if (OrderLen == 0)
	{
		PrintError("PUSTE ZAMOWIENIE!");
		return 0;
	}

	float TotalPrice = 0;
	FILE* fp;
	if ((fp = fopen(FileName, "wb")))
	{
		fprintf(fp, "Stolik nr %s\n", TableNumber.c_str());
		fprintf(fp, "%d:%d\n", timeinfo->tm_hour, timeinfo->tm_min);
		for (i = 0; i < OrderLen; ++i)
		{
			fprintf(fp, "%s \t %2.2f\n", OrderName[i].c_str(), OrderPrice[i]);
			TotalPrice = TotalPrice + OrderPrice[i];
		}
		fprintf(fp, "===========\n");
		fprintf(fp, "%2.2f\n", TotalPrice);
		fclose(fp);
		return 1;
	}
	else
	{
		PrintError("Nie mozna otworzyc pliku!\n\n");
		return 0;
	}
}

void AddToOrder(string PName, float PPrice)
{
	OrderName.push_back(PName);
	OrderPrice.push_back(PPrice);

}
void PrintSubMenu(string CatName, int CatID)
{
	int iUsera;
	int ProdCat;
	size_t rest;
	float f_price;
	unsigned short i;
	string odUsera;
	size_t ProdLen = ID_Prod.size();
	vector <int> ProdIndex;
	vector <string> ProdName;

	// Poszukujemy produktow zaczynajacych sie od CatID

	for (i = 0; i < ProdLen; ++i)
	{
		ProdCat = stoi(Products[i].c_str(), &rest);
		if (ProdCat == CatID)
		{
			ProdIndex.push_back(i);
			ProdName.push_back(Products[i].substr(rest));
		}

	}

	ProdLen = ProdName.size();
SUBMENU_START:
	system("cls");
	cout << "\n\n\t=====" << CatName << "=====\n\n";

	for (i = 0; i < ProdLen; ++i)
	{

		printf("\t %d. %25s \t %2.2f;   %s\n", i + 1, ProdName[i].c_str(), (f_price = stof(Price[ProdIndex[i]].c_str())), Description[ProdIndex[i]].c_str());
	}
	cout << "\n\t " << i + 1 << ". Powrot" << endl << endl << endl;
	cout << "Twoj wybor(dodanie do zamowienia) : ";
	cin >> odUsera;

	if (isdigit(odUsera[0]))
	{
		iUsera = stoi(odUsera);
		if (iUsera == (i + 1))
		{
			return;
		}
		else if (iUsera > (i + 1) || iUsera < 0)
		{
			PrintError("t\tBLEDNY INDEKS !\n\n\n");
			goto SUBMENU_START;

		}
		else
		{
			iUsera = iUsera - 1;
			AddToOrder(ProdName[iUsera], (f_price = stof(Price[ProdIndex[iUsera]].c_str())));
			cout << "{Dodano doo zamowienia: " << ProdName[iUsera] << " " << f_price << " } " << endl;
			system("pause");
			goto SUBMENU_START;
		}

	}
	else
	{

		PrintError("t\tPODAJ LICZBE !\n\n\n");
		goto SUBMENU_START;

	}




}

void PrintMenu()
{
MENU_START:
	system("cls");
	short i;
	int iUsera;
	string odUsera;
	size_t Cat_Size = Category.size();

	cout << "\n\n\t\tMENU\n\n";
	for (i = 0; i < Cat_Size; ++i)
		cout << "\t" << i + 1 << ". " << Category[i] << endl;
	cout << endl << "\t" << i + 1 << ".  Zloz zamowienie" << endl;
	cout << "\t" << i + 2 << ".  Wyczysc zamowienie" << endl << endl << endl;
	cout << "\t" << i + 3 << ".  Wyjscie" << endl << endl << endl;
	cout << "Twoj wybor : ";

	cin >> odUsera;
	if (isdigit(odUsera[0]))
	{
		iUsera = stoi(odUsera);
		if (iUsera == (i + 3))
		{
			cout << " Bye Bye!";
			return;
		}
		else if (iUsera > (i + 3))
		{
			PrintError("t\tBLEDNY INDEKS !\n\n\n");
			goto MENU_START;

		}
		else if (iUsera == (i + 1))
		{
			if (OrderToFile())
			{
				cout << endl << "Zamowienie zapisano do pliku!" << endl;
				cout << "Czyszczenie starego zamowienia" << endl;
				CleanOrder();
				system("pause");
				goto MENU_START;
			}
			else
			{
				PrintError("BLAD ZAPISU DO PLIKU!\n\n");
			}

		}
		else if (iUsera == (i + 2))
		{
			CleanOrder();
			goto MENU_START;
		}
		else
		{
			PrintSubMenu(Category[iUsera - 1], iUsera - 1);
			goto MENU_START;
		}

	}
	else
	{

		PrintError("t\tPODAJ LICZBE !\n\n\n");
		goto MENU_START;

	}


}


unsigned short AddCat(string CatName)
{
	size_t i;
	size_t CatSize = Category.size();

	if (CatSize == 0)
	{
		Category.push_back(CatName);
		return 0;
	}

	for (i = 0; i < CatSize; ++i)
	{
		if (CatName.compare(Category[i]) == 0)
		  return i;
		

	}
	Category.push_back(CatName);
	return AddCat(CatName);  // REKURENCJA :D 

}

void ParseLine(string line)
{
	string local_cat;
	string local_pro;
	string local_id_pro;
	string local_desc;
	string local_price;

	int i = 0;
	size_t pos = 0;
	size_t pos_buff = 0;
	size_t local_len = line.length();
	unsigned short cat_index;

	for (i = 0; i < 5; ++i, pos_buff = pos)
	{
		pos = line.find_first_of(";", pos_buff + 1);
		switch (i)
		{
		case 0:        //Zaczynamy od id_pro
			local_id_pro = line.substr(0, pos);
			break;
		case 1:       // teraz produkt
			local_pro = line.substr(pos_buff + 1, pos - 2);
			break;
		case 2:      //teraz kategoria
			local_cat = line.substr(pos_buff + 1, pos - pos_buff - 1);
			break;
		case 3:     // i cena
			local_price = line.substr(pos_buff + 1, pos - pos_buff - 1);
			break;
		case 4:    // jeszcze tylko opis
			local_desc = line.substr(pos_buff + 1, local_len);
			break;

		}

	}

	cat_index = AddCat(local_cat);
	local_pro = to_string(cat_index) + local_pro;
	Products.push_back(local_pro);
	ID_Prod.push_back(local_id_pro);
	Price.push_back(local_price);
	Description.push_back(local_desc);

}

short FileLine(void)
{
	unsigned short i = 1;
	int czar;
	FILE* fp;
	if ((fp = fopen(BAZA, "rb")) != 0)
	{
		while ((czar = fgetc(fp)) != EOF)
			if (czar == 0x0A) ++i;

		fclose(fp);
		return i;
	}
	return -1;

}

bool GetBase(void)
{
	unsigned short i = 0;
	ifstream Base(BAZA);
	string line;

	if (Base.is_open())
	{
		while (getline(Base, line))
		{
			i += 1;
			cout << line << endl;
			ParseLine(line);

		}
	}
	else
	{
		return false;
	}

	return true;


}


void PrintUsage(void)
{
	printf("Uzycie : program -s {Numer Stolika}\n\n");
}


int main(int argc, char** argv)
{
	string TabNum;
	if (argc == 0 || argc == 1 || argc == 2 || argc > 3)
	{
		PrintUsage();
	}
	else if (argc == 3)
	{
		string arg1 = argv[1];
		string arg2 = argv[2];
		if (arg1[0] == '-')
			if (arg1[1] == 's')
			{
				if (isdigit(arg2[0]))
				{
					if (FileLine() == -1)
					{
						PrintError("BrakBazy!"); return 0;
					}
					if (GetBase() == false)
					{
						PrintError("BrakBazy!"); return 0;
					}

					TableNumber = arg2;
					PrintMenu();

				}
				else
				{
					PrintUsage();
					return 0;
				}
			}
			else
			{
				PrintUsage();

				return 0;

			}
	}



}

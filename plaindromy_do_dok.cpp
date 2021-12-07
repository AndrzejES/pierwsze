#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

//aga naga 7
//elf ukladal kufle  13
//kamil slimak 11

void Palindrom(string s)
{
	int i;
	size_t len;
	while ((i=s.find(' ')) != string::npos) s.erase(i, 1);
	len = string.length();
	for (i = 0; i < len; ++i)
	{
		if(s[i] > 0x41 && s[i] < 0x5A) s.replace()
	}


	cout << "Po parsowaniu : " << s << endl;

}

int main(void)
{
	Palindrom("Elf ukladal kufle");
	system("pause");
	return 0;
}

#include<iostream>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include"Header.h"
using namespace std;

long int p, q, n, flag, e[100], d[100], t,j, temp[100], m[100], en[100];
char msg[100];
//int prime(long int);
//void ce();
//long int cd(long int);
//void encrypt();
//void decrypt();
/*int prime(long int pr)
{
	int i;
	j = sqrt(pr);
	for (i = 2; i <= j; i++)
	{
		if (pr % i == 0)
			return 0;
	}
	return 1;
}*/
int main()
{
	char ch = '0';
	do {
		cout << "\nENTER FIRST PRIME NUMBER\n";
		cin >> p;
		flag = prime(p,j);
		while (flag == 0)
		{
			cout << "\nWRONG INPUT\n";
			cout << "\nENTER FIRST PRIME NUMBER\n";
			cin >> p;
			flag = prime(p,j);
		}
		cout << "\nENTER SECOND PRIME NUMBER\n";
		cin >> q;
		flag = prime(q,j);
		while (flag == 0 || p == q)
		{
			if (p == q) {
				cout << "FIRST PRIME NUMBER " << p << endl;
				cout << "SECOND PRIME NUMBER " << p << endl;
				cout << "FIRST PRIME NUMBER !=SECOND PRIME NUMBER" << endl;
				cout << "ENTER SECOND PRIME NUMBER" << endl;
				cin >> q;
			}
			cout << "\nWRONG INPUT" << endl;
			cout << "\nENTER SECOND PRIME NUMBER" << endl;

			cin >> q;
			flag = prime(q,j);

		}
		cout << "\nENTER MESSAGE" << endl;
		fflush(stdin);
		cin >> msg;
		for (int i = 0; msg[i] != '\0'; i++)
			m[i] = msg[i];
		n = p * q;
		t = (p - 1) * (q - 1);
		ce(t,q,p);
		cout << "\nPOSSIBLE VALUES OF e AND d ARE" << endl;
		for (int i = 0; i < j - 1; i++)
			cout << e[i] << "\t" << d[i] << "\n";
		encrypt(m, temp, n, msg);
		decrypt(m, temp);
	} while (ch != 27);
	return 0;
}

#include<iostream>
#include<math.h>
#include<string.h>
#include<stdlib.h>
using namespace std;

bool prime(unsigned int pr)
{

	int i;

	for (i = 2; i <= sqrt(pr); i++)
	{
		if (pr % i == 0)
			return false;
	}
	return true;
}


int chekInput(unsigned int &number)
{
	prime(number);
	while (prime(number) == false)
	{
		cout << "WONG NUMBER" << endl;
		cout << "ENTER PRIME NUMBER" << endl;;
		cin >> number;
		prime(number);
	}
	return number;

}

unsigned int gcdEuclid(int b, int a)
{

	int c;
	while (b)
	{
		c = a % b;
		a = b;
		b = c;
	}
	return abs(a);
}
unsigned int createClosedKey(unsigned int n, unsigned int e)
{
	unsigned int d = n - 1;
	if (d % 2 == 0)
	{
		d--;
	}

	gcdEuclid(e*d, n);
	while (gcdEuclid(e*d, n) != 1) {
		d = d - 2;
	}
	//if ((n % i == 0) && (d % i == 0)) //если имеют общие делители
	//{
	//	d--;
	//	i = 1;
	//}

	return d;
}
unsigned int createOpendKey(unsigned int eulerFunc)
{
	unsigned int e = 3;
	gcdEuclid(e, eulerFunc);
	while (gcdEuclid(e, eulerFunc) != 1) {
		e = e + 2;
	}
	return e;

}

unsigned int Power(unsigned int  value, unsigned int pow)
{
	int result = 1;
	while (pow > 0)
	{
		if (pow % 2 == 1)
		{
			result *= value;

		}
		value *= value;
		pow /= 2;
	}
	return result;
}
// Ў»‘–”≈ћ ќ“ –џ“џћ  Ћё„ќћ
unsigned char  encript(char mass, unsigned int e, unsigned int N)
{
	mass = (Power(mass, e) % N);

	cout << mass << endl;
	return mass;
}
unsigned char decript(unsigned char mass, unsigned int d, unsigned int N)
{
	mass = (Power(mass, d) % N);
	//temp>>=1;
	cout << mass << endl;
	return mass;
}
int main()
{
	unsigned int p;// первое простое число
	unsigned int q;// второе простое число
	unsigned int n;// n=p*q
	unsigned int eulerFunc;// верхн€€ граница
	unsigned int d;
	unsigned int e;// открыта€ экспонента должны соблюдатьс€ услови€ 1). e<eulerFunc  и 2) gcd(e,eulerFunc)==1

	char ch = '0';

	do {

		cout << "ENTER FIRST PRIME NUMBER" << endl;;
		cin >> p;

		chekInput(p);

		cout << "ENTER SECOND PRIME NUMBER" << endl;
		cin >> q;
		chekInput(q);
		while (p == q)
		{
			cout << " FIRST=SECOND " << endl;
			cout << "ENTER SECOND PRIME NUMBER" << endl;
			cin >> q;
			chekInput(q);
		}

		chekInput(q);
		n = p * q;
		eulerFunc = (p - 1)*(q - 1);

		e = createOpendKey(eulerFunc);
		cout << "OPEN  KEY " << e << endl;
		d = createClosedKey(eulerFunc, e);
		cout << "ClOSED KEY " << d << endl;
		cout << "ENTER MESSAGE" << endl;
		char msg[100];
		int mass[100];
		cin >> msg;


		for (unsigned int i = 0; msg[i] != NULL; i++) {

		

			encript(mass[i], e, n);
		}
		for (int i = 0; msg[i] != NULL; i++) {


			decript(mass[i], d, n);
		}
	} while (ch != 27);

	return 0;
}
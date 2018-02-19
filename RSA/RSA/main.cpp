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

	while (a != b)
	{
		if (a > b)
		{
			long tmp = a;
			a = b;
			b = tmp;
		}
		b = b - a;
	}
	return a;
}
unsigned int createClosedKey(unsigned int n)
{
	unsigned int d = n - 1;
	for (unsigned int i = 2; i <= n; i++)
		if ((n % i == 0) && (d % i == 0)) //если имеют общие делители
		{
			d--;
			i = 1;
		}

	return d;

}
unsigned int createOpendKey(unsigned int eulerFunc, unsigned int p, unsigned int q, unsigned int d)
{
	unsigned int e = eulerFunc / 2;

	while (e < (eulerFunc))
	{
		if ((gcdEuclid(eulerFunc, e) == 1) && (e != p) && (e != q))
		{
			if ((prime(e) == true))
			{
				if ((e * d) % eulerFunc == 1)
					cout << e << endl;
				break;
			}
		}
		e--;
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
unsigned int  encript(unsigned int mass, unsigned int e, unsigned int N)
{

	/*for (int i = 0; i < sizeof(mass); i++)
	{*/
	
		mass =(Power(mass,e)% N);
		//temp>>=1;
		cout << mass << endl;
	return mass;
}
unsigned int decript(unsigned int mass, unsigned int d, unsigned int N)
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
	unsigned int e = 2;// открыта€ экспонента должны соблюдатьс€ услови€ 1). e<eulerFunc  и 2) gcd(e,eulerFunc)==1

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
		d = createClosedKey(eulerFunc);
		cout << "ClOSED KEY " << d << endl;
		e = createOpendKey(eulerFunc, p, q, d);
		cout << "OPEN  KEY " << e << endl;

		cout << "ENTER MESSAGE" << endl;
		char msg[100];
		int mass[100];
		cin >> msg;

	
		for (unsigned int i = 0; msg[i] != NULL; i++) {

			mass[i] = (unsigned int)msg[i];

			encript(mass[i],e, n);
		}
		for (int i = 0; msg[i] != NULL; i++) {


			decript(mass[i], d, n);
		}
	} while (ch != 27);

	return 0;
}
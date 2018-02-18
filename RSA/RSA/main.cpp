#include<iostream>
#include<math.h>
#include<string.h>
#include<stdlib.h>
using namespace std;

bool prime(long int pr)
{

	int i;

	for (i = 2; i <= sqrt(pr); i++)
	{
		if (pr % i == 0)
			return false;
	}
	return true;
}


int chekInput(long int &number)
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

long gcdEuclid(long  b, long a)
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
long createClosedKey(long n)
{
	long d = n - 1;
	for (long i = 2; i <= n; i++)
		if ((n % i == 0) && (d % i == 0)) //если имеют общие делители
		{
			d--;
			i = 1;
		}

	return d;

}
long createOpendKey(long int eulerFunc, long int p, long int q, long int d)
{
	long e = eulerFunc / 2;

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
int main()
{
	long int p;// первое простое число
	long int q;// второе простое число
	long int n;// n=p*q
	long int eulerFunc;// верхняя граница
	long int d;
	long int e = 2;// открытая экспонента должны соблюдаться условия 1). e<eulerFunc  и 2) gcd(e,eulerFunc)==1
	char msg[100];
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
		cin >> msg;
	} while (ch != 27);

	return 0;
}
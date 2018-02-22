#include<iostream>
#include<math.h>
#include<string.h>
#include<stdlib.h>
using namespace std;

bool prime(unsigned long long  pr)
{

	int i;

	for (i = 2; i <= sqrt(pr); i++)
	{
		if (pr % i == 0)
			return false;
	}
	return true;
}


unsigned long long chekInput(unsigned long long number)
{
	prime(number);
	while (prime(number) == false)
	{
		cout << "WRONG NUMBER" << endl;
		cout << "ENTER PRIME NUMBER" << endl;;
		cin >> number;
		prime(number);
	}
	return number;

}

unsigned long long  gcdEuclid(unsigned long long b, unsigned  long long a)
{

	unsigned long long  c;
	while (b)
	{
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}
unsigned long long createClosedKey(unsigned long long n, unsigned long long e, unsigned long long EF)
{
	unsigned long long d, d_simple;
	d = 0;
	d_simple = 0;
	while (d_simple != 1) {
		d = rand() % EF + 3;
		d_simple = (e * d) % n;
	}



	return d;
}
unsigned long long  createOpendKey(unsigned long long eulerFunc)
{
	unsigned long long  e = rand() % (eulerFunc / 2) + 3;
	gcdEuclid(e, eulerFunc);
	while (gcdEuclid(e, eulerFunc) != 1) {
		e++;
	}
	return e;

}

unsigned long long modPow(unsigned long long base, unsigned long long exponent, unsigned long long mod);

// ШИФРУЕМ ОТКРЫТЫМ КЛЮЧОМ
unsigned long long encript(unsigned long long mass, unsigned long long e, unsigned long long N)
{
	return modPow(mass, e, N);
}


unsigned long long modPow(unsigned long long base, unsigned long long exponent, unsigned long long mod) {
	base %= mod;
	unsigned long long pow;
	if (exponent == 0) {
		pow = 1;
	}
	else if (exponent % 2 == 0) {
		pow = modPow(base * base, exponent / 2, mod) % mod;
	}
	else {
		pow = (base * modPow(base, exponent - 1, mod)) % mod;
	}
	return pow;
}
unsigned long long decript(unsigned long long mass, unsigned long   long d, unsigned long long N)
{
	//  mass = pow(mass, d);
	return modPow(mass, d, N);
	//  fmod(mass, N);

}
int main()
{
	unsigned long long p;// первое простое число
	unsigned long  long q;// второе простое число
	unsigned long long  n;// n=p*q
	unsigned  long long eulerFunc;// верхняя граница
	unsigned long long d;
	unsigned long long e;// открытая экспонента должны соблюдаться условия 1). e<eulerFunc  и 2) gcd(e,eulerFunc)==1

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
		d = createClosedKey(eulerFunc, e, eulerFunc);
		cout << "ClOSED KEY " << d << endl;
		cout << "ENTER MESSAGE" << endl;
		char msg[100];
		unsigned   long long  mass[100];
		cin >> msg;
		for (int i = 0; msg[i] != NULL; i++)
		{
			mass[i] = (unsigned long long) msg[i];
			cout << mass[i] << endl;

		}
		cout << "\n\n\n";
		for (int i = 0; msg[i] != NULL; i++)
		{
			mass[i] = encript(mass[i], e, n);
			cout << mass[i] << endl;
		}
		cout << "\n\n\n";

		for (int i = 0; msg[i] != NULL; i++)
		{

			mass[i] = decript(mass[i], d, n);
			cout << mass[i] << endl;
		}
	} while (ch != 27);

	return 0;
}
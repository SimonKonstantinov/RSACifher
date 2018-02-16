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

long int gcd(int a, int b) {
	int t;
	t = b;
	b = a % b;
	a = t;
	return abs(b);
}
int openExp(long int &e, long int eulerFunc )
{
	while(gcd(e, eulerFunc)!=1)
	{
		gcd(e, eulerFunc);
		e++;
	}
	return e;
}
int main()

{

	long int p;// ������ ������� �����
	long int q;// ������ ������� �����
	long int n;// n=p*q
	long int eulerFunc;// ������� �������
	long int e=2;// �������� ���������� ������ ����������� ������� 1). 1<e<eulerFunc  � 2).
	char ch = '0';

	do {

		cout << "ENTER FIRST PRIME NUMBER\n";
		cin >> p;

		chekInput(p);

		cout << "ENTER SECOND PRIME NUMBER\n";
		cin >> q;

		chekInput(q);
		n = p * q;
		eulerFunc = (p - 1)*(q - 1);

		openExp(e, eulerFunc);





	} while (ch != 27);

	return 0;

}
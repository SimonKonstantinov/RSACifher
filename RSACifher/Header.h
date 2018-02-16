#pragma once
#include<iostream>
#include<math.h>
#include<string.h>
#include<stdlib.h>

using namespace std;


int prime(long int pr,long int j)
{
	int i;
	j = sqrt(pr);
	for (i = 2; i <= j; i++)
	{
		if (pr % i == 0)
			return 0;
	}
	return 1;
}

void ce(long int t,long int q, long int p)
{
	
	int k;
	k = 0;
	for (long int i = 2; i < t; i++)
	{
		if (t % i == 0)
			continue;
		flag = prime(i,j);
		if (flag == 1 && i != p && i != q)
		{
			e[k] = i;
			flag = cd(e[k],t);
			if (flag > 0)
			{
				d[k] = flag;
				k++;
			}
			if (k == 99)
				break;
		}
	}
}
long int cd(long int x, long int t)
{
	long int k = 1;
	while (1)
	{
		k = k + t;
		if (k % x == 0)
			return (k / x);
	}
}
void encrypt(long int m[], long int temp[], long int n, char  msg[])
{
	long int pt, ct, key = e[0], k, len;
	int i = 0;
	len = strlen(msg);
	while (i != len)
	{
		pt = m[i];
		pt = pt - 96;
		k = 1;
		for (j = 0; j < key; j++)
		{
			k = k * pt;
			k = k % n;
		}
		temp[i] = k;
		ct = k + 96;
		en[i] = ct;
		i++;
	}
	en[i] = -1;
	cout << "\nTHE ENCRYPTED MESSAGE IS\n";
	for (i = 0; en[i] != -1; i++)
		printf("%c", en[i]);
}
void decrypt(long int m[], long int temp[])
{
	long int pt, ct, key = d[0], k;
	long int i = 0;
	while (en[i] != -1)
	{
		ct = temp[i];
		k = 1;
		for (j = 0; j < key; j++)
		{
			k = k * ct;
			k = k % n;
		}
		pt = k + 96;
		m[i] = pt;
		i++;
	}
	m[i] = -1;
	cout << "\nTHE DECRYPTED MESSAGE IS\n";
	for (int i = 0; m[i] != -1; i++)
		printf("%c", m[i]);
}
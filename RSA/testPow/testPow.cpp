// testPow.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

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

int main()
{
	unsigned long long base = 10;
	unsigned long long exponent = 17;
	unsigned long long mod = 21;
	modPow(base, exponent, mod);
    return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "primes.h"
#define LARGEST_PRIME_INDEX 5239

double GammaApproximation(double n, double k)
{
	double result = 0;
	result = (lgamma(n+1) -lgamma(n-k+1) -lgamma(k+1)) / log(2);
	return result;
}


double FindLogarithmOfExponent(int number, int exponent)
{
	double result = (double) exponent * log2(number);
	return result;
}

int FindLargestNLogarithm(int number, int exponent, int base)
{
	double searchLog = FindLogarithmOfExponent(number, exponent);
	double currentLog = 0;
	double k = (double)base;
	int n = 0;
	while(currentLog <= searchLog)
	{
		currentLog = GammaApproximation((double)n, k);
		n++;
	}	
	return n-2;
}

int FindLargestPrimeIndex(int number, int exponent)
{
	double searchLog = FindLogarithmOfExponent(number, exponent);
	double currentLog = 0;
	int i = 0;
	for(i = 0; i < LARGEST_PRIME_INDEX; i++)
	{
		if(currentLog > searchLog)
		{
			break;
		}
		currentLog += log2(first5239[i]);
	}
	if(currentLog <= searchLog)
	{
		printf("Error: Increase number of prime numbers");
		return -1;
	}
	return i;
}

//https://www.geeksforgeeks.org/primeNumberular-exponentiation-power-in-primeNumberular-arithmetic/
int FastModularExponentiation(int number, int exponent, int primeNumber)
{
	int result = 1;
	number %= primeNumber;
	if(number == 0)
	{
		return 0;
	}
	while(exponent > 0)
	{
		if(exponent & 1)
		{
			result = (result * number) % primeNumber;
		}
		exponent >>= 1;
		number = (number * number)%primeNumber;	
	}
	return result;
}

int *FindModularRepresentation(int number, int exponent, int primeNumber, int *length)
{
	int primeArrayLength = FindLargestPrimeIndex(number,exponent);
	if(primeArrayLength == -1)
	{
		printf("\nUnable to find primeNumberular representation of number\n");
		return NULL;
	}
	*length = primeArrayLength;
	int *primeNumberArray = calloc(primeArrayLength,sizeof(int));
	int result = FastModularExponentiation(number,exponent,primeNumber);
	for(int i = 0; i < primeArrayLength; i++)
	{
		primeNumberArray[i] = FastModularExponentiation(number,exponent,first5239[i]);
	}
	return primeNumberArray;
}

int DivisibilityTest(int n, int k, int primeNumber)
{
	int a = 0;
	int b = 0;
	int exponent = 0;
	int r = 0;
	
	if(k > (n/2))
	{	
		k = n - k; 
	}

	if(primeNumber > n - k)
	{
		return 1;
	}

	if(primeNumber > n/2)
	{
		return 0;
	}
	if(primeNumber * primeNumber > n)
	{
		if(n % primeNumber < k % primeNumber)
		{	
			return 1;
		}
		else
		{	
			return 0;
		}
	}
	while(n > 0)
	{
		a = n % primeNumber;
		n = n / primeNumber;
		b = k % primeNumber + r;
		k = k / primeNumber;
		if(a < b)
		{
			exponent = exponent + 1;
			r = 1;
		}
		else
		{
			r = 0;
		}
	}
	return exponent;	
}

int *FindPrimeFactorization(int n, int k, int *length)
{
	int currentPrime = 2;
	int singleExponent = 0;
	int i = 0;
	int count = 0;
	int *exponents = calloc(LARGEST_PRIME_INDEX , sizeof(int));
	for(i = 0; i < LARGEST_PRIME_INDEX; i++)
	{
		currentPrime = first5239[i];
		if(currentPrime > n)
		{
			break;
		}		
		singleExponent = DivisibilityTest(n,k,currentPrime);
		if(singleExponent != 0)
		{
			count++;
		}
		exponents[i] = singleExponent;
	}
	exponents = realloc(exponents, i *sizeof(int));	
	*length = i;
	printf("Factors: %d\n", count);
	return exponents;
}


void FindCoefficients(int number, int exponent, int primeNumber)
{
	int k = 100;
	int n = FindLargestNLogarithm(number,exponent,k);
	int power = DivisibilityTest(n,k,primeNumber);
	
	int primeArrayLength = 0;
	int *primeNumberArray = FindModularRepresentation(number, exponent, primeNumber, &primeArrayLength);
	if(primeNumberArray == NULL)
	{
		return;
	}
	
	if(power >= 1)
	{
		printf("Yes %d %d\n",n,k);
		//144 100
//(2 4)(3 3)(5 1)(11 1)(13 1)(17 1)(23 1)(47 1)(53 1)(59 1)(61 1)(67 1)(71 1)(101 1)(103 1)(107 1)(109 1)(113 1)(127 1)(131 1)(137 1)(139 1)
		int primeExponentsLength = 0;
		int *primeExponents = FindPrimeFactorization(n,k,&primeExponentsLength);
		for(int i = 0; i < primeExponentsLength; i++)
		{
			if(primeExponents[i] != 0)
			{
				printf("(%d %d)", first5239[i], primeExponents[i]);
			}
		}
		
	}
	else
	{
		printf("No");
	}
	free(primeNumberArray);
}

/*
Yes 144 100
Factors: 22
(2 4)(3 3)(5 1)(11 1)(13 1)(17 1)(23 1)(47 1)(53 1)(59 1)(61 1)(67 1)(71 1)(101 1)(103 1)(107 1)(109 1)(113 1)(127 1)(131 1)(137 1)(139 1)
*/
int main()
{
	int number = 313;
	int exponent = 15;
	int primeNumber = 13;
	FindCoefficients(number,exponent,primeNumber);
	return 0;
} 

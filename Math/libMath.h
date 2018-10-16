#pragma once
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>


double Abs(double base);

unsigned long long Gcd(unsigned long long a, unsigned long long b);

long long Pow(long long base, unsigned short int exponent);

double Sqrt(double base);

unsigned long long Factorial(unsigned short int n);

unsigned long long FibRecursive(unsigned short int n);

unsigned long long FibIterative(unsigned short int n);

bool IsPrime(unsigned long long n);

int PrimeFactors (unsigned long long** factors, unsigned short int* size, unsigned long long n);

unsigned long long Mersenne(unsigned int n);

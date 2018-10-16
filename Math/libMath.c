#include "libMath.h"


double Abs(double base)
{
    if (base < 0)
        base = -1 * base;

    return base;
}

unsigned long long Gcd(unsigned long long a, unsigned long long b)
{
    while (b != 0)
    {
        unsigned long long r = a % b;
        a = b;
        b = r;
    }
    return a;
}

long long Pow(long long base, unsigned short int exp)
{
    long long temp = base;
    for(int i = 1; i < exp; ++i)
        base = base * temp;

    return base;
}

double Sqrt(double base)
{
    double sqRoot = 1;
    double accuracy = 1;

    while (Abs(sqRoot*sqRoot - base) >= accuracy)
        sqRoot = ((base / sqRoot) + sqRoot) / 2;

    return sqRoot;
}

unsigned long long Factorial(unsigned short int n)
{
    unsigned long long result = 1;
    for (unsigned long long i = 1; i <= n; ++i)
        result = result * i;

    return result;
}

unsigned long long FibRecursive(unsigned short int n)
{
    if (n == 0 || n == 1)
        return n;

    return FibRecursive(n - 1) + FibRecursive(n - 2);
}

bool IsPrime(unsigned long long n)
{
    if (n == 1) return false;

    if (n % 2 == 0) return (n == 2);

    if (n % 3 == 0) return (n == 3);

    double nSqrt = Sqrt(n);
    for (unsigned int i = 5; i <= nSqrt; i = i +6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;

    return true;
}

int PrimeFactors (unsigned long long** factorsPtr, unsigned short int* size, unsigned long long n)
{
    *size = 1;
    *factorsPtr = realloc(*factorsPtr, (*size) * sizeof(unsigned long long));
    if (*factorsPtr == NULL)
    {
        printf("realloc failed re-allocating factors array\n");
        return -1;
    }

    if (IsPrime(n))
    {
        (*factorsPtr)[0] = n;
        return 0;
    }

    unsigned short int factorsCount = 0;
    for (unsigned long long i = 2; i <= n; ++i)
    {
        while(n % i == 0)
        {
            if(factorsCount >= *size)
            {
                *factorsPtr = realloc(*factorsPtr, ++(*size) * sizeof(unsigned long long));
                if (*factorsPtr == NULL)
                {
                    printf("realloc failed re-allocating factors array\n");
                    return -1;
                }
            }
            (*factorsPtr)[factorsCount] = i;
            ++factorsCount;

            n /= i;
        }
    }

    return 0;
}

unsigned long long Mersenne(unsigned int n)
{
    return Pow(2, n) - 1;
}

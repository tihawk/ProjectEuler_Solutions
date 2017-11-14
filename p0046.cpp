#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> GeneratePrimes(int maxInteger)
{
    vector<int> primes;
    bool isPrime = true;
    primes.push_back(1);

    for( int i = 2; i <= maxInteger; i++ )
    {
        for( int j = 2; j < (int)(sqrt(i)+1); j++ )
        {
            if( i%j == 0 )
            {
                isPrime = false;
            }
        }

        if(isPrime)
        {
            primes.push_back(i);
        }
        isPrime = true;
    }

    return primes;
}

bool IsTwiceSquare(int n)
{
    double squareTest = sqrt(n/2);
    return squareTest == (int)squareTest;
}

int main()
{
    int k = 0;
    int oddNumber = 9;
    bool notTrue = false;
    vector<int> primes = GeneratePrimes(5000);
    //man, is that convoluted...
    while(notTrue == false)
    {
        k = 0;
        notTrue = true;
        for( int i = primes[k]; i <= oddNumber; i = primes[k++] )
        {
            if( IsTwiceSquare( oddNumber - primes[k] ) )
            {
                notTrue = false;
                oddNumber += 2;
                break;
            }
        }
    }


    cout<<oddNumber;

    return 0;
}

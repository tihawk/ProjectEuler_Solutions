#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>

using namespace std;

bool IsPrime(int n)
{
    bool isPrime = true;
    for( int j = 2; j <= (int)sqrt(n); j++ )
    {
        if( n%j == 0 )
        {
            isPrime = false;
        }
    }
    if(isPrime)
    {
        return true;
    }
    else
        return false;
}

vector<int> GeneratePrimes(int maxNumber)
{
    vector<int> primes;

    for( int i = 2; i <= maxNumber; i++ )
    {
        if(IsPrime(i))
        {
            primes.push_back(i);
            //cout<<i<<", ";
        }
    }
    return primes;
}

int main()
{
    int maxNum = 1000000;
    vector<int> primes = GeneratePrimes(maxNum);
    int sum = 0;
    int biggestPrime[] = {2, 1, 0}; //prime, components, index reached
    int index = 0;
    int ticks = 0;
    int temp = 0;

    while( sum < maxNum )
    {
        sum += primes[index];
        ticks++;
        if( IsPrime(sum) && sum > biggestPrime[0] && sum < maxNum )
        {
            biggestPrime[0] = sum;
            biggestPrime[1] = ticks;
            biggestPrime[2] = index;
        }
        index++;
    }

    cout<<biggestPrime[0]<<" at "<<biggestPrime[1]<<endl;
    int shifter = 0;

    for( int i = 1; i < sqrt(maxNum); i++ )
    {
        //remove one element from start
        sum = biggestPrime[0] - accumulate(primes.begin()+shifter, primes.begin()+i, 0);
        //cout<<accumulate(primes.begin(), primes.begin()+i, 0)<<", ";
        ticks = biggestPrime[1] - i+shifter;

        //start adding new elements from last viable
        index = biggestPrime[2]+1;
        while(sum<maxNum)
        {
            sum += primes[index];
            ticks++;
            if( IsPrime(sum) && sum > biggestPrime[0] && sum < maxNum && ticks > biggestPrime[1] )
            {
                biggestPrime[0] = sum;
                biggestPrime[1] = ticks;
                biggestPrime[2] = index;
                shifter = i;
            }
            index++;
        }

    }

    cout<<biggestPrime[0]<<" at "<<biggestPrime[1];

    return 0;
}

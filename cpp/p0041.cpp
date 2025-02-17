#include <iostream>
#include <vector>
#include <set>
#include <numeric>
#include <cmath>

using namespace std;

vector<int> GeneratePrimes(int minNum, int maxNum)
{
    vector<int> primes;
    bool isPrime = true;

    for( int i = minNum; i <= maxNum; i++ )
    {
        for( int j = 2; j <= sqrt(i); j++ )
        {
            if( i%j == 0 )
                isPrime = false;
        }
        if(isPrime)
        {
            primes.push_back(i);
            //cout<<i<<", ";
        }
        isPrime = true;
    }
    cout<<"Generated primes";
    return primes;
}

bool IsPandigital(int n)
{
    int digits = 0;
    int counter = 0;
    int temp;

    while( n > 0 )
    {
        temp = digits;
        //putting in the binary form of digits ones in all the places where there is a unique digit, i.e. for 1234 digits = 1111, and for 1235, digits = 10111
        digits = digits | 1 << (n%10 - 1);
        if( digits == temp )
        {
            //if there is no change to digits, it means there is the same digit being added, or there is a zero
            return false;
        }
        n /= 10;
        counter++;
    }
    if( digits == ( 1 << counter ) -1 )
        return true;
    else
        return false;

}

int main()
{
    int minNum = 1000000;
    int maxNum = 9999999;
    vector<int> primes = GeneratePrimes(minNum, maxNum);

    for( int i = 0; i < primes.size(); i++ )
    {
        if( IsPandigital(primes[i]) )
            cout<<primes[i]<<", ";
    }

    //cout<<endl<<IsPandigital(654123);

    return 0;
}

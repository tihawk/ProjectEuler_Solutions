#include <iostream>

using namespace std;

int FindSumFactors(int n)
{
    int result = 0;
    for( int i = 1; i < n; i++ )
    {
        if( n%i == 0 )
        {
            result += i;
        }
    }
    return result;
}

int main()
{
    int amicableSum = 0;

    for( int i = 0; i < 10000; i++ )
    {
        if( FindSumFactors(FindSumFactors(i)) == i && FindSumFactors(i) > i )
        {
            amicableSum += i + FindSumFactors(i);
        }
        /*my first implementation didn't work, because it included numbers which are equal to the sum of their factors.
         apparently they are called perfect numbers:
        if( FindSumFactors(i) == i )
            cout<<i<<", ";*/
    }

    cout<<endl<<amicableSum;

    return 0;
}

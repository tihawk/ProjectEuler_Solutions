#include <iostream>

using namespace std;

int main()
{
    long sumOfSquares = 0;
    long sum = 0;
    long result = 0;

    for ( int i = 1; i <= 100; i++ )
    {
        sumOfSquares += i*i;
        sum += i;
    }

    cout<<sumOfSquares<<", "<<sum*sum<<endl;
    result = sum*sum - sumOfSquares;
    cout<<result<<endl;

    return 0;
}

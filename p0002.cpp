#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main()
{
    int n = 4000000;
    int newFibonacci;
    vector<int> fibonacci;
    vector<int> evenFibonacci;
    fibonacci.push_back(1);
    fibonacci.push_back(2);

    for ( int i = 0; i < n; i++ )
    {
        newFibonacci = fibonacci[i] + fibonacci[i+1];
        if ( newFibonacci < n )
        {
            fibonacci.push_back(newFibonacci);
            cout<<newFibonacci<<", ";
        }

        else
        {
            cout<<endl;
            break;
        }
    }

    for ( vector<int>::iterator i = fibonacci.begin(); i != fibonacci.end(); i++ )
    {
        if ( *i % 2 == 0)
            evenFibonacci.push_back(*i);
    }

    int sum = accumulate(evenFibonacci.begin(), evenFibonacci.end(), 0);
    cout<<sum<<endl;

    return 0;
}

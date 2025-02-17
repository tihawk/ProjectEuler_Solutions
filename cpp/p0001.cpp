#include <iostream>
#include <list>

using namespace std;

int main()
{
    int n = 1000;
    int sum = 0;
    list<int> multiples;

    for ( int k = 1; k < n; k++ )
    {
        if ( k%3 ==0 || k%5 == 0 )
        {
            multiples.push_back(k);
            cout<<k<<", ";
        }
    }

    for ( list<int>::iterator i = multiples.begin(); i != multiples.end(); ++i  )
    {
        sum += *i;
    }
    cout<<sum<<endl;

    return 0;
}

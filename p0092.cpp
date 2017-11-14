#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

unsigned long NextInChain(unsigned long n)
{
    vector<int> digits;
    while ( n > 0 )
        {
            digits.push_back((n%10)*(n%10));
            n /= 10;
        }
    n = accumulate(digits.begin(), digits.end(), 0);
    //cout<<n<<", ";
    return n;
}

int main()
{
    unsigned long n;
    int score = 0;

    for ( int i = 2; i < 10000000; i++ )
    {
        if (i%50000 == 0)
            cout<<(float)i/100000<<"%"<<endl;

        n = i;
        //cout<<endl<<n<<", ";
        while (n!=1)
        {
            if (n != 89)
                n = NextInChain(n);
            else
            {
                score++;
                break;
            }
        }

    }

    cout<<score;
    return 0;
}

#include <iostream>

using namespace std;

int main()
{
    int a, b, c, x, abc;
    x = 1000;

    for ( a = 0; a <= x/3; a++ )
    {
        for ( b = a; b <= x/2; b++ )
        {
            c = x - ( a + b );
            //cout<<a<<" "<<b<<" "<<c<<endl;
            if ( a*a + b*b == c*c )
            {
                cout<<a*b*c;
                break;
            }
        }
    }

    return 0;
}

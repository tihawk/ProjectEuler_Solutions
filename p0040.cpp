#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> constant;
    constant.push_back(0);
    vector<int> digits;
    int n = 0;
    int result = 1;

    for( int i = 1; i <= 200000; i++ )
    {
        n = i;
        while( n > 0 )
        {
            digits.push_back(n%10);
            n /= 10;
        }

        for( int j = digits.size()-1; j >= 0; j-- )
        {
            constant.push_back(digits[j]);
        }
        digits.clear();
        /*if(constant.size() > 1000000)
            break;*/
    }

    for( int k = 1; k <= 1000000; k *= 10 )
    {
        result *= constant[k];
    }

    cout<<result;

    return 0;
}

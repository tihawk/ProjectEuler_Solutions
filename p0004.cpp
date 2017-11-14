#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    int biggest[3] = {0, 0, 0};
    vector<int> digits;
    vector<int> matrix[3];
    bool isPalindrome = true;

    for(int i = 100; i < 1000; i++)
    {
        for(int k = 100; k < 1000; k++)
        {

            n = i*k;
            while (n > 0)
            {
                digits.push_back(n%10);
                //cout<<n%10<<endl;
                n /= 10;
            }

            int jMax = (int)(digits.size()/2+1);
            for( int j = 0; j <= jMax/2; j++ )
            {
                if( digits[j] != digits[digits.size()-(j+1)] )
                {
                    isPalindrome = false;
                    break;
                }
            }

            if (isPalindrome)
            {
                matrix[0].push_back(i);
                matrix[1].push_back(k);
                matrix[2].push_back(i*k);
                //cout<<i*k<<endl;
            }
            isPalindrome = true;
            digits.clear();

        }
    }

    for (int i = 0; i < matrix[2].size(); i++)
    {
        if ( matrix[2][i] > biggest[2] )
        {
            biggest[0] = matrix[0][i];
            biggest[1] = matrix[1][i];
            biggest[2] = matrix[2][i];
        }

    }
    cout<<biggest[2]<<" = "<<biggest[0]<<"*"<<biggest[1];

    return 0;
}

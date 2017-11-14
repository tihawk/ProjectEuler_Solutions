#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <set>
#include <cmath>
//USING SET INCREASES THE FIND() EFFICIENCY!!! (instead of O(n) time, it takes O(log(n)) time!!!
// new way of finding factors, yay

using namespace std;

vector <unsigned int> FindAbundants(unsigned int maxNum)
{
    vector<unsigned int> abundants;
    vector<unsigned int> factors;
    for( int i = 2; i <= maxNum; i++ )
    {
        factors.push_back(1);
        //cout<<i<<": "<<1<<"one, ";

        int sqrtOfI = (int)sqrt(i);
        if( sqrtOfI*sqrtOfI == i )
        {
            factors.push_back(sqrtOfI);
            //cout<<sqrtOfI<<"sqrt, ";
            sqrtOfI--;
        }

        for( int j = 2; j <= sqrtOfI; j++ )
        {
            if( i%j == 0 )
            {
                factors.push_back(j);
                factors.push_back(i/j);
                //cout<<j<<", "<<i/j<<", ";
            }
        }
        //cout<<endl;

        if( accumulate(factors.begin(), factors.end(), 0) > i )
        {
            abundants.push_back(i);
            //cout<<i<<", ";
        }
        factors.clear();
    }

    return abundants;
}

set<unsigned int> FindAbundantSums(vector<unsigned int> abundants, unsigned int maxNum)
{
    set<unsigned int> abundantSums;

    for( int i = 0; i < abundants.size(); i++ )
    {
        for( int j = 0; j < abundants.size(); j++ )
        {
            if( abundants[i] + abundants[j] <= maxNum )
            {
                abundantSums.insert(abundants[i]+abundants[j]);
                //cout<<abundants[i]+abundants[j]<<", ";
            }
        }
    }

    return abundantSums;
}

int main()
{
    unsigned int maxNum = 28123;
    set<unsigned int> abundantsSums = FindAbundantSums(FindAbundants(maxNum), maxNum);
    vector<unsigned int> otherNumbers;

    for( int i = 1; i <= 28123; i++ )
    {
        if( find( abundantsSums.begin(), abundantsSums.end(), i ) == abundantsSums.end() )
        {
            otherNumbers.push_back(i);
            cout<<i<<", ";
        }
    }

    cout<<accumulate(otherNumbers.begin(), otherNumbers.end(), 0);

    return 0;
}

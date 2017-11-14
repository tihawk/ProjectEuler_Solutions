#include <iostream>
#include <vector>
#include <numeric>
//BRUTEFORCE BULSHIT
using namespace std;

vector<long> PopulateNaturals(long maxNatural)
{
    vector<long> naturals;
    for( long i = 1; i <= maxNatural; i++ )
    {
        naturals.push_back(i);
    }
    return naturals;
}

vector<unsigned long> PopulateTriangulars(long maxNatural)
{
    vector<unsigned long> triangulars;
    vector<long> naturals = PopulateNaturals(maxNatural);
    unsigned long currentTriangular = 0;
    for( unsigned long i = 1; i < naturals.size(); i++ )
    {
        currentTriangular = accumulate(naturals.begin(), naturals.begin()+i, 0);
        triangulars.push_back(currentTriangular);
    }
    return triangulars;
}

int main()
{
    vector<unsigned long> triangulars = PopulateTriangulars(100000);
    vector<unsigned long> factors;

    /*for( int i = 0; i < triangulars.size(); i++ )
        cout<<triangulars[i]<<", ";*/

    for( int i = 0; i < triangulars.size(); i++ )
    {
        //cout<<triangulars[i]<<" - ";
        for( int j = 1; j <= triangulars[i]; j++ )
        {
            if( triangulars[i]%j == 0 )
            {
                factors.push_back(j);
            }
        }

        for( int k = 0; k < factors.size(); k++ )
            //cout<<factors[k]<<", ";
        //cout<<endl;

        if( factors.size() >= 500 )
        {
            cout<<triangulars[i];
            break;
        }

        factors.clear();

    }

    return 0;
}

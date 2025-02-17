#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

vector<int> BigNum(unsigned long long x)
{
    vector<int> result;
    while( x > 0 )
    {
        result.push_back(x%10);
        x /= 10;
    }
    return result;
}

vector<int> BigNumAdd(vector<int> x, vector<int> y)
{
    vector<int> result;

    //lots of resizing rules
    if( x.size() < y.size() )
        x.resize(y.size(), 0);
    if( y.size() < x.size() )
        y.resize(x.size(), 0);
    result.resize(x.size()+1, 0);
    /*if( x[x.size()-1] >= 5 && y[y.size()-1] >= 5 )
        result.resize(x.size()+1, 0);
    else
        result.resize(x.size(), 0);*/

    //cout<<endl<<"x=";
    for ( int k = x.size() - 1; k >= 0; k-- )
        {
            //cout<<x[k];
        }
    //cout<<endl<<"y=";
    for ( int k = y.size() - 1; k >= 0; k-- )
        {
            //cout<<y[k];
        }

    int carry = 0;

    for( int i = 0; i < result.size(); i++ )
    {
        //add carry
        result[i] += carry;
        //check if still under x and y size limit
        if( i < x.size() )
        {
            //add elements according to rules
            if( x[i] + y[i] < 10 )
            {
                result[i] += x[i] + y[i];
                carry = 0;
            }
            else
                if( x[i] + y[i] >= 10 )
            {
                result[i] += x[i] + y[i] - 10;
                carry = 1;
            }
        }

    }

    //cout<<endl<<"z=";
    for ( int k = result.size() - 1; k >= 0; k-- )
        {
            //cout<<result[k];
        }
    return result;
}

vector<int> BigNumMult(vector<int> x, vector<int> y)
{
    vector<int> temp[y.size()];
    vector<int> result;
    int carry = 0;

    for( int i = 0; i < y.size(); i++ )
    {
        //pushing back zeros
        temp[i].resize(x.size()+i+1, 0);
        /*for( int k = 0; k <= i; k++ )
        {
            temp[i][k] = 0;
        }*/
        //multiplying the whole x by i-th element of y
        for( int j = 0; j <= x.size(); j++ )
        {

            if( j < x.size() )
            {
                //check if product less or more than 10 and proceed accordingly
                if( x[j]*y[i] + carry < 10 )
                {
                    temp[i][j+i] = x[j]*y[i];
                    temp[i][j+i] += carry;
                    carry = 0;
                    //cout<<temp[i][j+i]<<" sh ";
                }
                if( x[j]*y[i] + carry >= 10 )
                {
                    temp[i][j+i] = (x[j]*y[i] + carry) % 10;
                    //temp[i][j+i] += carry;
                    carry = (x[j]*y[i] + carry) / 10;
                    //cout<<temp[i][j+i]<<" fu ";
                }
            }
            else if(carry > 0)
            {
                if( carry < 10 )
                {
                    temp[i][j+i] = carry;
                    carry = 0;
                    //cout<<temp[i][j+i]<<" gg ";
                }
                 else
                    if (carry >= 10)
                    {
                        temp[i][j+i] = carry%10;
                        carry /= 10;
                        temp[i].push_back(carry);
                        carry = 0;
                        //cout<<temp[i][j+i]<<" wp ";
                    }
            }

        }
    }

    for( int i = 1; i < y.size(); i++ )
    {
        for ( int k = temp[i].size() - 1; k >= 0; k-- )
        {
            //cout<<temp[i][k];
        }        //if( temp[i][temp[i].size()-1] == 0 )
        temp[0] = BigNumAdd(temp[0], temp[i]);
    }

    return temp[0];
}

void PrintBigNum(vector<int> n)
{
    for( int i = n.size()-1; i >= 0; i-- )
        cout<<n[i];
    cout<<", ";
}

int main()
{
    vector<int> n = BigNum(1);

    for( unsigned long long i = 1000000000000; i >= 100000000000; i-- )
    {
        n = BigNumMult(n, BigNum(i));
    }

    PrintBigNum(n);
    /*solves problem 20 Factorial Digit Sum
    cout<<accumulate(n.begin(), n.end(), 0);*/
    return 0;
}

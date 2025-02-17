#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

vector<int> BigNum(string x)
{
    vector<int> result;
    result.resize(x.size(), 0);
    for( int i = 0; i < x.size(); i++ )
    {
        result[result.size()-1-i] = x[i] - '0';
    }
    return result;
}

vector<int> RemoveFrontZeros(vector<int> n)
{
    int i = n.size()-1;
    while( n[i] == 0 )
    {
        n.erase(n.begin()+i);
        i--;
    }
    return n;
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

    return RemoveFrontZeros(result);
}

vector<int> BigNumMult(vector<int> x, vector<int> y)
{
    vector<int> temp[y.size()];
    int carry = 0;

    for( int i = 0; i < y.size(); i++ )
    {
        //resizing
        temp[i].resize(x.size()+i+1, 0);
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
                }
                if( x[j]*y[i] + carry >= 10 )
                {
                    temp[i][j+i] = (x[j]*y[i] + carry) % 10;
                    carry = (x[j]*y[i] + carry) / 10;
                }
            }
            else if(carry > 0)
            {
                if( carry < 10 )
                {
                    temp[i][j+i] = carry;
                    carry = 0;
                }
                 else
                    if (carry >= 10)
                    {
                        temp[i][j+i] = carry%10;
                        carry /= 10;
                        temp[i].push_back(carry);
                        carry = 0;
                    }
            }

        }
    }

    for( int i = 1; i < y.size(); i++ )
    {
        temp[0] = BigNumAdd(temp[0], temp[i]);
    }

    return RemoveFrontZeros(temp[0]);
}

void PrintBigNum(vector<int> n)
{
    for( int i = n.size()-1; i >= 0; i-- )
    {
        cout<<n[i];
    }
    cout<<", ";
}

int main()
{
    vector<int> number = BigNum("2");
    vector<int> result = BigNum("1");

    for( int i = 1; i <= 1000; i++ )
    {
        result = BigNumMult(result, number);
        //PrintBigNum(result);
    }

    cout<<accumulate(result.begin(), result.end(), 0);

    return 0;
}

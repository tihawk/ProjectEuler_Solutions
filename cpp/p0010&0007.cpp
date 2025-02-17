#include <iostream>
#include <ctime>
#include <vector>
#include <numeric>
#include <cmath>

using namespace std;

int main()
{
    int n = 2000000;
    bool isPrime = true;
    clock_t t = clock();
    //vector<int> primes;
    unsigned long long sum = 0;

    for(int k=2;k<=n;k++)
    {
        for(int i=2;i<(int)(sqrt(k)+1);i++)
        {
            if(k%i==0)
            {
                isPrime=false;
            }
        }
        if(isPrime)
        {
            //primes.push_back(k);
            //cout<<k<<", ";
            sum += k;
        }
            /*if ((float)(clock() - t)/CLOCKS_PER_SEC >= 10)
            {
                //for(list<int>::iterator i = primes.begin(); i != primes.end(); i++)
                //    cout<<*i<<", ";
                break;
            }*/
        isPrime = true;
    }

    //sum = accumulate(primes.begin(), primes.end(),0);
    cout<<sum<<endl;
    return 0;
}

#include <iostream>

using namespace std;

int main()
{
    bool isEvenlyDivisible = false;
    int n = 20;
    int score;

    while (!isEvenlyDivisible)
    {
        score = 0;
        for (int i = 1; i <= 20; i++)
        {
            if ( n%i == 0 )
                score++;
        }

        if (score == 20)
        {
            isEvenlyDivisible = true;
        }
        else
            n++;
    }

    cout<<n<<endl;

    return 0;
}

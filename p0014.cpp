#include <iostream>

using namespace std;

int main()
{
    unsigned long n, contestent;
    unsigned long score = 1, highScore[] = {1, 1};

    for ( int i = 2; i < 1000000; i++ )
    {
        n = i;
        contestent = n;

        while (n!=1)
        {
            //cout<<n<<", ";
            if ( n%2 == 0 )
                n /= 2;
            else
                n = 3*n + 1;
            score++;
        }

        //cout<<score<<endl;
        if (score > highScore[1])
        {
            highScore[0] = contestent;
            highScore[1] = score;
        }
        score = 1;
    }

    cout<<highScore[0]<<", "<<highScore[1];
    return 0;
}

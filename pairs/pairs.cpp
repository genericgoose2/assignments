#include<iostream>
#include <time.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

//count the number of pairs of numbers in an array of random numbers

int main()
{
    int socks[100], pairs=0;

    srand (time(NULL));

    for (int i = 0; i < 100; i++)
    {
        socks[i] = rand () % 100 + 1;
    }

    sort(begin(socks), end(socks));

/* 
    for (int i = 0; i < 100; i++)
    {
        cout << socks[i] << "\n";
    }
*/
    //              start with 2nd item in the array
    for (int n = 0, i = 1; i < 100; i++)
    {
        if(socks[i] == socks[i-1])
        {
            //compare current and previous numbers. if they are equal - increase the counter
            n++;
        }
        else
        {   //otherwise, we have the next set of numbers
            pairs += (n+1)/2;
            //counting the pairs. divided by 2 rounds down (1/2 = 0, 3/2 = 1), excluding pairless numbers. n is how many of the same number we have -1, so n+1
            n=0;
            //counter reset 
        }
    }

    cout << pairs;

    return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define MAX 1000000

int digit[MAX+10];


int get_number(int n)
{
    int i = 0;
    while(n)
    {
        n /= 10;
        i++;
    }
    return i;
}



int main()
{
    int digital = 1;
    digit[1] = 1;
    for(int i=2;digital<=MAX+10;i++)
    {
        int t = get_number(i);
        int w = i;
        for(int j=t;j>=1;j--)
        {
            digit[digital+j] = w%10;
            w /= 10;
        }
        digital += t;
    }
    int test;
    //while(cin >> test) cout << digit[test] << endl;
    cout << digit[1]*digit[10]*digit[100]*digit[1000]*digit[10000]*digit[100000]*digit[1000000] << endl;
}

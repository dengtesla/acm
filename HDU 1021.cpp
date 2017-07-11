#include<cstdio>
#include<cmath>
#include<iostream>
using namespace std;

int main()
{
    int n;
    while(cin >> n)
    {
        if(n%4==2)
        {
            cout << "yes" << endl;
        }
        else
        {
            cout << "no" << endl;
        }
    }
}

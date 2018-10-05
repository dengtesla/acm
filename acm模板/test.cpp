#include<bits/stdc++.h>
#include"tesla.h"
using namespace std;
#define long long ll


int main()
{
    matrix::mat A;
    A.hang = 3;
    A.lie = 3;
    for(int i=1;i<=3;i++)
    {
        for(int j=1;j<=3;j++)
        {
            cin >> A.v[i][j];
        }
    }
    cout << matrix::det(A) << endl;
}
/*
2 4 -2
1 -1 5
4 1 -2
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a[1001];
    memset(a,0,sizeof(a));
    a[0] = 0;
    a[1] = 3;
    a[2] = 3;
    a[3] = 5;
    a[4] = 4;
    a[5] = 4;
    a[6] = 3;
    a[7] = 5;
    a[8] = 5;
    a[9] = 4;
    a[10] = 3;
    a[11] = 6;
    a[12] = 6;
    a[13] = 8;
    a[14] = 8;
    a[15] = 7;
    a[16] = 7;
    a[17] = 9;
    a[18] = 8;
    a[19] = 8;
    a[20] = 6;
    a[30] = 6;
    a[40] = 5;
    a[50] = 5;
    a[60] = 5;
    a[70] = 7;
    a[80] = 6;
    a[90] = 6;
    a[100] = 10;//one hundred
    a[1000] = 11;//one thousand
    for(int i=0;i<=1000;i++)
        {
            if(a[i]==0)
            {
                if(i>10&&i<100)
                a[i] = a[i-i%10] + a[i%10];
                if(i>100&&i<200)
                a[i] = a[100] + 3 + a[i%100];
                if(i>=200){
                a[i] = a[i/100] + a[100] - 3 + 3 + a[i%100];
                if(i%100==0) a[i] -= 3;}
            }
        }
    int ans = 0;
    for(int i=1;i<=1000;i++){
        ans += a[i];
        //cout << i << " = " << a[i] << endl;
        }
    cout << ans << endl;
    int i;
    //while(cin >> i) cout << a[i] << endl;
    //cout << a[414] << endl;
}

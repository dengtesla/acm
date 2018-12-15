#include<bits/stdc++.h>
using namespace std;

int times[50];
int cnt = 0;

int CH_poker[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
int times_ch = 0;
int CC_poker[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
int times_cc = 0;

int get_dice()
{
    int a = rand()%4 + 1;
    int b = rand()%4 + 1;
    //cout << a << " " << b << endl;
    if(a==b) cnt++;
    else cnt = 0;
    return a + b;
}

int CC(int a)
{
    int w = CH_poker[times_ch%16];
    times_ch++;
    //int w = rand()%16+1;
    switch(w)
    {
        case 1:return 0;
        case 2:return 10;

    }return a;
}

int get_r(int a)
{
    if(a==33) return 35;
    if(a==17) return 25;
    if(a==2) return 5;
}

int get_u(int a)
{
    if(a==33) return 12;
    if(a==17) return 28;
    if(a==2) return 12;
}


int CH(int a)
{
    int w = CC_poker[times_cc%16];
    times_cc++;
    //int w = rand()%16+1;
    //cout << w << endl;
    switch(w)
    {
        case 1:return 0;
        case 2:return 10;
        case 3:return 11;
        case 4:return 24;
        case 5:return 39;
        case 6:return 5;
        case 7:return get_r(a);
        case 8:return get_r(a);
        case 9:return get_u(a);
        case 10:return ((a+37)%40);
        //return a;
    }
    return a;
}


int main()
{
    srand(19260817);
    int tt = 1;
    while(tt--){
    random_shuffle(CH_poker,CH_poker+16);
    random_shuffle(CC_poker,CC_poker+16);
    times_ch = 0;
    times_cc = 0;
    cnt = 0;
    int st = 0;
    int t = 10000000;
    bool flag = 0;
    while(t--)
    {
        if(flag)
        {
            cnt = 0;
            times[st]++;
            flag = 0;
            continue;
        }
        int dice = get_dice();
        //cout << dice << endl;
        st += dice;
        if(cnt==3)
        {
            cnt = 0;
            st = 10;
        }
        if(st>39) st %= 40;
        if(st==30) st = 10;
        if(st==36||st==22||st==7)
        {
            st = CH(st);
        }
        if(st==33||st==17||st==2)
        {
            st = CC(st);
        }

        if(st==30) st = 10;
        if(st==10)
        {
            flag = 1;
            times[st]++;
            continue;
        }
        times[st]++;
    }
    }
    int w1=41,w2=41,w3=41;

    for(int i=0;i<=39;i++)
    {
        cout << i << " : " << times[i] << endl;
        if(times[i]>times[w1])
        {
            w3 = w2;
            w2 = w1;
            w1 = i;
        }
        else if(times[i]>times[w2])
        {
            w3 = w2;
            w2 = i;
        }
        else if(times[i]>times[w3])
        {
            w3 = i;
        }
    }

    cout << w1 << w2 << w3 << endl;

}


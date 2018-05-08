#include<bits/stdc++.h>
using namespace std;
int shuwei[20];

/*
A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 ¡Á 99.

Find the largest palindrome made from the product of two 3-digit numbers.
*/


int huiwen(int t)
{
  int ii,ans=0;
  int k=t;
  memset(shuwei,0,sizeof(shuwei));
  for(int i=0;i<=10;i++)
  {
    shuwei[i] = t % 10;
    t = t / 10;
    if(t == 0)
    {
      ii = i;
      break;
    }
  }
  for(int i=0;i<=ii;i++)
  {
      for(int j=i;j<ii;j++){
        shuwei[i] = shuwei[i] * 10;
        }
         //cout << shuwei[1] << endl;
        ans += shuwei[i];
  }
  //cout << ans << endl;
  //cout << k << endl;
  if(ans == k) return 1;
  else return 0;
}

int main()
{
    int answer=0;
  for(int i=100;i<=999;i++)
  {
      for(int j=i;j<=999;j++)
      {
          if(huiwen(i*j)) answer = max(answer,i*j);
      }
  }
  //huiwen(12345);
  //cout << huiwen(1001) << endl;
  cout << answer << endl;
}

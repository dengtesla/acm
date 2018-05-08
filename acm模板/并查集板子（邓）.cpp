#include<bits/stdc++.h>
using namespace std;
#define MAX 10000;

struct UF
{
  int rank;
  int parent;
}UF[MAX];

void init(int n)
{
  for(int i=0;i<=n;i++)
  {
    UF[i].parent=i;
    UF[i].rank=0;
  }
}

int get_parent(int x)
{
   if(UF[x].parent==x) return x;
   return get_parent(UF[x].parent);
}

void Union(int a,int b)
{
  a=get_parent(a);
  b=get_parent(b);
  if(UF[a].rank>UF[b].rank) UF[b].parent = UF[a].parent;
  else
  {
    UF[a].parent = UF[b].parent;
    if(UF[a].rank==UF[b].rank) UF[a].rank++;
  }
}

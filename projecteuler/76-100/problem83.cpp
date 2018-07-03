#include<bits/stdc++.h>
using namespace std;
int mmap[80][80];

typedef pair<int,int> pii;

struct EDGE
{
    int next;
    int to;
    int w;
}edge[500500];
int head[500500];
int cnt = -1;

void Add(int u,int v,int w)
{
     cnt++;
     edge[cnt].w = w;
     edge[cnt].to = v;
     edge[cnt].next = head[u];
     head[u] = cnt;
}
int tag[500500];
int d[500500];
int vis[500500];


void dijkstra(int s) {
    priority_queue<pii, vector<pii>, greater<pii> > Q;
    memset(d, 0x3f, sizeof(d));
    d[s] = 0;
    memset(vis, false, sizeof(vis));
    Q.push(make_pair(d[s], s));
    while(!Q.empty()) {
        pii tmp = Q.top();
        Q.pop();
        int x = tmp.second;
        if(vis[x]) continue;
        vis[x] = true;
        for(int i = head[x]; i+1; i = edge[i].next) {
            if(d[edge[i].to] > d[x] + edge[i].w) {
                d[edge[i].to] = d[x] + edge[i].w;
                Q.push(make_pair(d[edge[i].to], edge[i].to));
            }
        }
    }
}




int main()
{
    freopen("problem83.in","r",stdin);
    int n;
    n = 80;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&mmap[i][0]);
        for(int j=1;j<n;j++)
        {
            scanf(",%d",&mmap[i][j]);
        }
    }
    //cout << mmap[0][1] << endl;
    memset(head,-1,sizeof(head));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-1;j++)
        {
            Add(i*n+j,i*n+j+1,mmap[i][j+1]);
            Add(j*n+i,(j+1)*n+i,mmap[j+1][i]);
            Add(i*n+j+1,i*n+j,mmap[i][j]);
            Add((j+1)*n+i,j*n+i,mmap[j][i]);
        }
    }

    dijkstra(0);
    cout << d[80*80-1]+mmap[0][0] << endl;
}

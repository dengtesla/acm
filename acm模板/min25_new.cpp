#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 2000000+100;

/******************************

f()函数中(31-37行) 填函数在质数幂次处的表达式
pow_sum()函数中(38-43行) 填幂和函数（如果需要更高次的话可以在这里添加）
202-205行按要求填写
f_p[][0/1/2/3/...]分别代表质数个数/质数和/质数平方和/质数三次方和/...根据自己需要添加
例：如果该函数在质数处表达式为f(p) = p^2+3*p+1，则表明需要质数个数/质数和/质数平方和，即f_p[][0],f_p[][1],f_p[][2]

******************************/

ll poww(ll a,ll b){
    ll res = 1;
    ll base = a;
    while(b){
        if(b&1){
            res *= base;
            //res %= mod;
        }
        base *= base;
        //base %= mod;
        b>>=1;
    }
    return res;
}

inline ll f(ll p,int e){
    if(p==1||e==0) return 1;
    ///return f(p^e)
    ll res = poww(p,e);
    return res*res+3*res+1;

}
ll pow_sum(ll n,int k){
    ///return sum(i^k),i from 1 to n.
    if(k==0) return n;
    if(k==1) return n*(n+1)/2;
    if(k==2) return n*(n+1)*(2*n+1)/6;
}
ll f_p[maxn][3];///F_prime(id(n/i))
ll n;
int n_2; ///(int)sqrt(n)
int n_3; ///(int)pow(n,1.0/3.0)
int n_6; ///(int)pow(n,1.0/6.0)
ll val_id[maxn]; ///give the id, return the id-th number like 'n/i' ,(val_id[1] = 1)
int val_id_num; ///how many numbers like 'n/i'
int val_id_num_3; ///how many numbers like 'n/i' below n/n_3;
int p[200000+100];
bool isp[maxn];
int p_sz_2; ///pi(n_2)
int p_sz_3; ///pi(n_3)
int p_sz_6; ///pi(n_6)
void init(){
    n_2 = (int)sqrt(n);
    n_3 = (int)pow(n,1.0/3.0);
    n_6 = (int)pow(n,1.0/6.0);
    val_id_num = 0;
    for(ll i=1;i<=n;){
        val_id[++val_id_num] = i;
        if(i==n) break;
        i = n/(n/(i+1));
    }
    memset(isp,1,sizeof isp);
    isp[1] = 0;
    for(int i=2;i<=n_2;i++){
        if(isp[i]){
            p[++p_sz_2] = i;
            if(i<=n_3) p_sz_3++;
            if(i<=n_6) p_sz_6++;
        }
        for(int j=1;j<=p_sz_2&&p[j]*i<=n_2;j++){
            isp[i*p[j]] = 0;
            if(i%p[j]==0) break;
        }
    }
}
inline int get_id(ll k){ ///give a number like 'n/i', return the id of it
    if(k>n_2) return val_id_num-n/k+1;
    else return k;
}
ll c[maxn];
int lowbit(int n){return n & (-n);}
void add(int x,ll d){
    while(x<maxn){
        c[x]+=d;
        x+=lowbit(x);
    }
}
ll sum(int x){
    ll ans=0;
    while(x){
        ans+=c[x];
        x-=lowbit(x);
    }
    return ans;
}

struct node{
    int k_max;
    ll val;
    ll f_val;
};
void update_bfs(int k,int type){
    queue<node> q;
    while(!q.empty()) q.pop();
    int e = 1;
    for(ll i=p[k];i<n/n_3;i*=p[k]){
        node st;
        st.k_max = k;
        st.val = i;
        if(type==-1)st.f_val = f(p[k],e);
        else st.f_val = poww(i,type);
        q.push(st);
        e++;
    }
    while(!q.empty()){
        node hd = q.front();
        q.pop();
        if((hd.val!=p[hd.k_max]&&type>=0)||type==-1) {//if(type==-1)cout << "****" << hd.val << "****" << hd.f_val << endl;
            ll w = n/hd.val;
            w = n/w;//cout << hd.val << "[" << w<<" , " << val_id[val_id_num] << "]" << endl;
            if(type==-1){
                add(get_id(w),hd.f_val);
                add(val_id_num+1,-1ll*hd.f_val);
            }
            else{
                add(get_id(w),-1ll*hd.f_val);
                add(val_id_num+1,hd.f_val);
            }
        }
        for(int i=hd.k_max+1;hd.val*p[i]<n/n_3&&i<=p_sz_2;i++){
            ll res = p[i];
            for(int e=1;;e++){
                if(hd.val*res<n/n_3){
                    node nxt;
                    nxt.k_max = i;
                    nxt.val = hd.val*res;
                    if(type==-1) nxt.f_val = hd.f_val*f(p[i],e);
                    else nxt.f_val = hd.f_val*poww(res,type);
                    q.push(nxt);
                }
                else break;
                res *= p[i];
            }
        }
    }
}
void get_f_p(ll n,int times){
    for(int i=1;i<=val_id_num;i++){
        for(int j=0;j<=times;j++){
            f_p[i][j] = pow_sum(val_id[i],j)-1;
        }
    }
    int now;
    //for(now=1;now<=p_sz_2;now++){
    for(now=1;p[now]<=n_6;now++){
        for(int j=val_id_num;j>=1;j--){
            ll w = val_id[j]/p[now];
            if(w<p[now]) break;
            ll val=1;
            for(int k = 0;k<=times;k++){
                f_p[j][k] = f_p[j][k] - val*(f_p[get_id(w)][k]-f_p[p[now-1]][k]);
                val *= p[now];
            }
        }
    }
    int nnow = now;
    int val = 1;
    for(int tt = 0;tt<=times;tt++){
        now = nnow;
        memset(c,0,sizeof c);
        add(1,f_p[1][tt]);
        for(int i=2;val_id[i]<n/n_3;i++){
            add(i,f_p[i][tt] - f_p[i-1][tt]);
        }
        for(;p[now]<=n_3;now++){
            for(int j=val_id_num;j>=1;j--){
                ll w = val_id[j]/p[now];
                if(val_id[j]<n/n_3) break;
                if(w<p[now]) break;
                if(w<n/n_3) f_p[j][tt] = f_p[j][tt] - (sum(get_id(w)) - sum(p[now-1]))*poww(p[now],tt);
                else f_p[j][tt] = f_p[j][tt] - (f_p[get_id(w)][tt]-sum(p[now-1]))*poww(p[now],tt);
            }
            update_bfs(now,tt);
        }
        for(int i=1;i<=val_id_num&&val_id[i]<n/n_3;i++)
            f_p[i][tt] = sum(i);
        for(;now<=p_sz_2;now++){
            for(int j=val_id_num;j>=1;j--){
                ll w = val_id[j]/p[now];
                if(val_id[j]<n/n_3) break;
                if(w<p[now]) break;
                f_p[j][tt] -= (f_p[get_id(w)][tt]-f_p[p[now-1]][tt])*poww(p[now],tt);
            }
        }
    }

    for(int i=1;i<=val_id_num;i++){
        ///if f(p) = p^2+3p+1,then write:f_p[i][0] = f_p[i][2] + 3*f_p[i][1] + f_p[i][0];
        f_p[i][0] = f_p[i][2] + 3*f_p[i][1] + f_p[i][0];
    }

}
ll F[2000000+100];
void get_f_3(ll n){ ///V(F_{pi(n^(1/3))+1},n)
    ll q = p[p_sz_3+1];
    for(int now=1;now<=val_id_num;now++){
        if(val_id[now]<q){
            F[now] = 1;
        }
        else if(val_id[now]<q*q){
            F[now] = 1+(f_p[now][0]-f_p[q-1][0]);
        }
        else{
            F[now] = 1+(f_p[now][0]-f_p[q-1][0]);
            for(int pp=p_sz_3+1;p[pp]<=(int)(sqrt(val_id[now]))&&pp<=p_sz_2;pp++){
                F[now] += f(p[pp],2) + (f(p[pp],1))*(f_p[get_id(val_id[now]/p[pp])][0]-f_p[get_id(p[pp])][0]);
            }
        }
    }
}
void get_f_6(ll n){ ///V(F_{pi(n^(1/6))+1},n)
    memset(c,0,sizeof c);
    add(1,F[1]);
    for(int i=2;val_id[i]<n/n_3;i++){
        add(i,F[i] - F[i-1]);
    }
    for(int k=p_sz_3;k>p_sz_6;k--){
        int now = val_id_num;
        for(;val_id[now]>=n/n_3;now--){
            int e = 1;
            ll _p = p[k];
            while(val_id[now]/_p){
                if(val_id[now]/_p>=n/n_3){
                    F[now] += F[get_id(val_id[now]/_p)]*f(p[k],e);
                }
                else{
                    F[now] += sum(get_id(val_id[now]/_p))*f(p[k],e);
                }
                _p *= p[k];
                e++;
            }
        }
        if(k==1) break;
        //cout << "******" << p[k] << "******" << n/n_3 << endl;
        update_bfs(k,-1);///bfs to update [lpf(i)==P{k-1}]f(i)
    }
    for(int i=1;i<=val_id_num&&val_id[i]<n/n_3;i++)
        F[i] = sum(i);
}
void get_f(ll n){
    for(int k=p_sz_6;k>=1;k--){
        for(int now = val_id_num;now>=1;now--){
            int e = 1;
            ll _p = p[k];
            while(val_id[now]/_p){
                    F[now] += F[get_id(val_id[now]/_p)]*f(p[k],e);
                _p *= p[k];
                e++;
            }
        }
    }
}
int main(){//n = 1000000000; //1e10:455052511,0.83s/0.58s 1e12:37607912018 9.224s/5.105s
    cin >> n;
    init();
    get_f_p(n,2);
    get_f_3(n);
    get_f_6(n);
    get_f(n);
    for(int i=1;i<=val_id_num;i++){
        cout << val_id[i] << " : " << F[i] << endl;
    }

}


#include<bits/stdc++.h>
#define ll long long

ll poww(ll a,ll b,ll mod)
{
    ll ans = 1,base = a;
    while(b)
    {
        if(b&1)
        {
            ans *= base;
            ans %= mod;
        }
        base *= base;
        base %= mod;
        b>>=1;
    }
    return ans;
}

ll multi(ll a,ll b,ll mod)
{
    ll ans = 0;
    while(b)
    {
        if(b&1)
        {
            ans += a;
            ans %= mod;
        }
        a *= 2;
        a %= mod;
        b>>=1;
    }
    return ans;
}


namespace matrix
{
    const int N = 100;
    struct mat
    {
        int hang;
        int lie;
        ll v[N][N];
    };

    mat multi(mat A,mat B)
    {
        mat ans;
        memset(ans.v,0,sizeof(ans.v));
        if(A.lie!=B.hang)
        {
            std::cout << "error!" << std::endl;
            return ans;
        }

        for(int i=1;i<=A.hang;i++)
            for(int j=1;j<=B.lie;j++)
                for(int k=1;k<=A.lie;k++)
                    ans.v[i][j] += A.v[i][k]*B.v[k][j];
        return ans;
    }

    mat mat_pow(mat A,ll b)
    {
        mat ans;
        memset(ans.v,0,sizeof(ans.v));
        if(A.hang!=A.lie)
        {
            std::cout << "error!" << std::endl;
            return ans;
        }
        ans.hang = A.hang;
        ans.lie = A.lie;
        for(int i=1;i<=A.hang;i++) ans.v[i][i] = 1;
        while(b)
        {
            if(b&1) ans = multi(ans,A);
            A = multi(A,A);
            b>>=1;
        }
        return ans;
    }

    ll det(mat A)
    {
        if(A.hang!=A.lie) return 0;
        double L[100][100];
        double U[100][100];
        for(int i=1;i<=A.hang;i++)
        {
            U[1][i] = 1.0*A.v[1][i];
            L[i][1] = 1.0*A.v[i][1]/U[1][1];
        }

        for(int i=1;i<=A.hang;i++)
        {
            for(int k=i;k<=A.hang;k++)
            {
                double sum1 = 0;
                double sum2 = 0;
                for(int j=1;j<=i-1;j++)
                {
                    sum1 += L[i][j]*U[j][k];
                    sum2 += L[k][j]*U[j][i];
                }
                U[i][k] = 1.0*A.v[i][k] - sum1;
                L[k][i] = (1.0*A.v[k][i] - sum2)/U[i][i];
            }
        }

        for(int i=1;i<=A.hang;i++)
        {
            for(int j=1;j<=A.hang;j++)
            {
                std::cout << U[i][j] << " ";
            }
            std::cout << std::endl;
        }

        double ans = 1;
        for(int i=1;i<=A.hang;i++)
            ans *= U[i][i];
        return ans;
    }


}



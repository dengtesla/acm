#include<bits/stdc++.h>
using namespace std;

struct spot ///存储点，也可指代向量
{
    double x;
    double y;
    double z;
};

spot cross(const spot &a,const spot &b) ///计算向量a和向量b的叉乘(有顺序)
{
    spot w;
    w.x = a.y*b.z-b.y*a.z;
    w.y = a.z*b.x-a.x*b.z;
    w.z = a.x*b.y-a.y*b.x;
    return w;
}

double dot(const spot &a,const spot &b) ///计算向量a和向量b的点乘积
{
    return a.x*b.x+a.y*b.y+a.z*b.z;
}

double norm(const spot &a) ///计算向量a的模长
{
    return sqrt(a.x*a.x+a.y*a.y+a.z*a.z);
}



bool intersect(spot a,spot b,spod c,spod d) ///判断ab线段和cd线段是否有相交，如果相交返回1
{
    spot ab;
    spot cd;
    ///waiting...
}

int main()
{
    spot a,b;
    cin >> a.x >> a.y >> a.z;
    cin >> b.x >> b.y >> b.z;
    spot w = cross(a,b);
    //cout << w.x  << " " << w.y << " " << w.z;
    cout << dot(a,b);
    return 0;
}


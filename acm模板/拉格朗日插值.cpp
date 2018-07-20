#include<iostream>
#include<string>
#include<vector>
using namespace std;

double Lagrange(int N,vector<double>&X,vector<double>&Y,double x);

int main(){
  char a='n';
  do{
    cout<<"请输入差值次数n的值："<<endl;
    int N;
    cin>>N;
    vector<double>X(N,0);
    vector<double>Y(N,0);
    cout<<"请输入插值点对应的值及函数值(Xi,Yi)："<<endl;
    for(int a=0;a<N;a++){
        cin>>X[a]>>Y[a];
    }
    cout<<"请输入要求值x的值："<<endl;
    double x;
    cin>>x;
    double result=Lagrange(N,X,Y,x);
    cout<<"由拉格朗日插值法得出结果： "<<result<<endl;
    cout<<"是否要继续？(y/n)：";
    cin>>a;
  }while(a=='y');
  return 0;
}

double Lagrange(int N,vector<double>&X,vector<double>&Y,double x){
  double result=0;
  for(int i=0;i<N;i++){
    double temp=Y[i];
    for(int j=0;j<N;j++){
    if(i!=j){
        temp = temp*(x-X[j]);
        temp = temp/(X[i]-X[j]);
   }
  }
  result += temp;
}
 return result;
};

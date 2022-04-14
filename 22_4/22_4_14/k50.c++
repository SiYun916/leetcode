#include<iostream>
using namespace std;
//我用pow函数提交了一次 可以直接过  
//然后x一个一个乘 超时了
//我就想x^2 x^4那么做 但是我不知道如何处理奇数的情况就直接看了题解
//我发现我的大致思路和题解一致  还以为有更好的方法
//第一种方法：快速幂加递归
//我们考虑幂从最大的n到0 如果当前幂n是奇数 那么返回的是  x的n/2次幂再乘一个x
//幂n一直减半 直到n等于0时 返回1
double fastmul(double x,long long n){
    if(n==0) 
        return 1;
    double y = fastmul(x,n/2);
    if(n%2==0)
        return y*y;
    else
        return y*y*x;
}
double myPow(double x,int n){
    bool flag;
    long long N = n;
    if(N>0)
        flag = 1;
    else {
        flag = 0;
        N = -N;
    }
    double res;
    res = fastmul(x,N);
    if(flag)
        return res;
    else
        return 1/res;
}
int main(){
    double x;
    int n;
    cin>>x>>n;
    double result = myPow(x,n);
    cout<<result<<endl;
    return 0;
}
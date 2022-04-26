#include<iostream>
using namespace std;
//这道题 没仔细想
//方法其实很多
//用e^(1/2*ln x) 来计算
//二分法
//牛顿迭代法
//这里写牛顿迭代法 
//思想很简单 取函数一点作其导数 当该点无限趋近于解的时候 导数与x轴的交点可看作解
//可以推导出一个迭代公式来
int mySqrt(int x) {
    //x^2-a=0
    int a = x;
    //取点的初始值
    long long ans = x/2+1;
    while(ans*ans>x){
        //迭代公式
        ans = (ans+a/ans)/2;
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    int res = mySqrt(n);
    cout<<res<<endl;
    return 0;
}

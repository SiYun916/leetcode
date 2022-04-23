#include<iostream>
#include<map>
#include<algorithm>
#include<math.h>
using namespace std;
//这道快乐数 使我也很快乐
//计算不难 主要是如何判断是否有循环
//一开始我觉得可以用数学做 但是我不会证明就没做
//于是我就想到了空间换时间 用map记录值 如果有循环就会出现重复值 即map记录的值大于1
//计算一个数每位的平方和
int calsum(int n){
        int res = 0;
        while(n){
            res = res + pow(n%10,2);
            n = n /10;
        }
        return res;
    }
bool isHappy(int n) {
        //记录值的个数
        map<int,int> s;
        //用于更新每次平方和的值
        int copyn = n;
        while(true){
            copyn = calsum(copyn);
            //如果满足条件
            if(copyn==1)
                return true;
            //记录
            s[copyn]++;
            //有循环
            if(s[copyn]==2)
                return false;
        }
}
int main(){
    int n;
    cin>>n;
    bool flag = isHappy(n);
    if(flag)
        cout<<"true"<<endl;
    else
        cout<<"false"<<endl;
    return 0;
}

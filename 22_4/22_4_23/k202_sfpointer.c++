#include<iostream>
#include <math.h>
using namespace std;
//看了题解之后 我学会了快慢指针的方法 
//以后判断循环就用快慢指针了
//大体来说 就是快指针执行多次操作 慢指针执行少次 如果有循环 总有快指针等于慢指针的时候
//如果满足条件 快慢指针最后都是满足条件的结果  且相等
//如果有循环 那么快慢指针相等的时候都不满足最终条件
int calsum(int n){
        int res = 0;
        while(n){
            res = res + pow(n%10,2);
            n = n /10;
        }
        return res;
    }
    bool isHappy(int n) {
        int slow=n,fast=n;
        while(true){
            slow = calsum(slow);
            fast = calsum(fast);
            fast = calsum(fast);
            if(slow==fast)
                break;
        }
        return slow==1;
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

#include <iostream>
using namespace std;
//一开始我写的是带循环的
/*
        int a=n,b;
        if(n==1)
            return true;
        if(n==0)
            return false;
        while(true){
            b = a%4;
            if(b!=0)
                return false;
            a = a/4;
            if(a==1)
                return true;  
        }
 * */
//判断一个数是不是4的幂
//首先0不是 把0排除
//其次 是4的幂必定是2的幂 先判断2的幂 n&(n-1)==0则是2的幂
//最后 如果 n 是 4 的幂，那么 n 的二进制表示中有且仅有一个 1，并且这个 1 出现在从低位开始的第奇数位上
//我们构造一个mask 它的所有偶数位都是1奇数位都是0 
//那么只要是4的幂 n&mask等于0 不考虑奇数 是因为已经判断了2的幂
bool isPowerOfFour(int n){
    return n>0 & !(n & (n-1)) & !(n&(0xaaaaaaaa));
}
int main(){
    int n;
    cin>>n;
    if(isPowerOfFour(n))
        cout<<"true"<<endl;
    else
        cout<<"false"<<endl;
    return 0;
}



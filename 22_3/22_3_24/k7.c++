#include <iostream>
using namespace std;
//这道题虽然我做出来了
//但并没有完全做出来
//因为丢了一个条件 所以我在做判断的时候使用了64位的整数 严格来说是不对的
//这里直接写题解的方法
//大体思路都一样  digit=x%10  x=x/10 res=res*10+digit
//但是在判断是否越界的时候题解的方法更严谨且简单
//我是直接采用了64位的变量 与边界比较
//而题解则在边界数前一位进行判断 不越界的情况下再进行*10
//通过严谨的数学证明 判断了等号能否成立
int reverse(int x){
    int res = 0;
    //截至条件一定要注意  x!=0不是!x  x再不截至时都是true  !x都是false 
    while(x!=0){
        if(res < INT32_MIN/10 || res > INT32_MAX/10)
            return 0;
        int digit = x % 10;
        x = x/ 10;
        res = res * 10 + digit;
    }
    return res;
}
int main(){
    int n;
    cin >> n;
    int xx = reverse(n);
    cout<<xx<<endl;
    return 0;
}

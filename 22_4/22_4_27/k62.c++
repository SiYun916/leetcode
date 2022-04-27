#include <iostream>
#include <vector>
using namespace std;
//这道题又是一个没有看出来的动态规划
//不过这道题倒是做出来了 用数学方法做出来
//其实就是m+n-2个位置中选min(n,m)-1个位置 因为min(n,m)-1是相同的  需要去重
//所以就用到了C^(min(n,m)-1)_(m+n-2)
//直接一个循环解决问题
//但一定要注意的是 res要设置成long long类型
//因为res是先乘的 一定会有越界问题
//不先除的原因是 整型除法会把小数位省略 导致结果错误
int uniquePaths(int m, int n) {
    long long  res = 1;
        int minnum = min(m,n)-1;
        int snum = m + n - 2 - minnum + 1;
        if(m==1&&n==1)
            return 1;
        for(int i = 1; i <= minnum; ++i){
            res = res * snum / i;
            snum++;
        }
        return res;
}
int main(){
    int m,n;
    cin>>m>>n;
    int res = uniquePaths(m,n);
    cout<<res<<endl;
    return 0;
}

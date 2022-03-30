#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//今天的题目看起来似乎很简单 但我不会 开摆
//这是第一次遇到动态规划的题
//之前的算法课没认真听过 所以根本不会实操
//从今天开始 一点一点把动态规划的题目练会
//就今天的题目而言 我对于动态规划的题有了以下大致几点的认识
//1. 解题首先要分析问题 看问题是否还可以分解成其子问题加上一个固定的量
//2. 列动态转移方程 我感觉就跟数列找规律差不多 第n项依赖于第n-1项的结果
//3. 注意一下特定值
//我感觉动态规划是通过迭代一点一点求出结果的  下一个值依赖于前面的所有值
int numSquares(int n){
    //设dp[i]代表整数i的完全平方数的最少数量
    //注意特殊值dp[0]为0，因为当i-j*j==0时只要一个完全平方数就可
    vector<int> dp(n+1);
    for(int i=1; i<=n; ++i){
        //最差情况下全是由1组成
        dp[i] = i;
        for(int j = 1; i-j*j>=0;++j){
            //求解dp[i]的结果，可以先求dp[i-j*j]+1的结果
            dp[i] = min(dp[i],dp[i-j*j]+1);
        }
    }
    return dp[n];
}
int main(){
    int n;
    cin>>n;
    int result;
    result = numSquares(n);
    cout<<result<<endl;
    return 0;
}
//以下是别人的题解
// dp[i] 表示数字i最少可以由几个完全平方数相加构成
// 位置i只依赖 i-j*j 的位置，如 i-1、i-4、i-9 等等位置，才能满足完全平方分割的条件。
// 因此dp[i]可以取的最小值即为 1 + min(dp[i-1],dp[i-4],dp[i-9]...)
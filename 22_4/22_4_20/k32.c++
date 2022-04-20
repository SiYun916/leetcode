#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
//这道题两个字：不会 
//一开始我想的是用栈的方法来做 然鹅理解错了题意 它要求的是连续的最长有效括号 而不是有效括号数
//接着改 但是需要考虑的情况太多了 基本上错一个就要加一个条件判断 最后搞的自己太混乱了 abandon
//直接题解 又是动态规划 好！很有精神！
//我看懂了 但我不想写具体过程！贴链接
//https://leetcode-cn.com/problems/longest-valid-parentheses/solution/dong-tai-gui-hua-si-lu-xiang-jie-c-by-zhanganan042/
//大体思路：
//对最后一个元素s[i]分两种情况讨论
// 1. ( 一定不可能 直接0 
// 2. ) 对s[i-1]进行分两种情况讨论
//   i. ( 找到配对的了  s[i] = s[i-2] + 2
//   ii. ) 如果s[i-1]不为0，说明前面有 有效序列，重点来了：看 i-1-s[i-1]是否为 (
//           I. 如果是 则匹配 s[i] = s[i-1] + 2 + s[i-1-dp[i-1]-1];  易错点：()(())前面()是单独出来的 与(())相互独立 如果计数需要加上
//           II. 不匹配 则s[i]为0 
int longestValidParentheses(string s){
    int slen = s.length();
    vector<int> dp(slen,0);
    if(slen==0)
        return 0;
    for(int i = 1; i < slen; ++i){
        if(s[i]==')'){
            if(s[i-1]=='('){
                if(i-2>=0)
                    dp[i] = 2 + dp[i-2];
                else
                    dp[i] = 2;
            }else if(s[i-1]>0){
                if((i-1-dp[i-1])>=0&&s[i-1-dp[i-1]]=='('){
                    if((i-1-dp[i-1]-1)>=0)
                        dp[i] = dp[i-1] + 2 + dp[i-1-dp[i-1]-1];
                    else
                        dp[i] = dp[i-1] + 2; 
                }
            }
        }
    }
    int maxValue = *max_element(dp.begin(),dp.end());
    return maxValue;
}
int main(){
    string s;
    cin>>s;
    int res = longestValidParentheses(s);
    cout<<res<<endl;
    return 0;
}
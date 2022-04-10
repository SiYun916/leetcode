#include <iostream>
#include <vector>
using namespace std;
//这道题 我一开始的想法是DFS回溯
//但是回溯有报错 我不知道哪里错了
//但是看题解 我发现DFS超时了 淦 唯一一个觉得会做的方法还是错的 日了
//首先我说下我DFS错在哪里了  首先是返回的条件少了一个 cur > n 这个错我找出来了 
//但是最重要的是 我其实还是不理解DFS的本质或者是没认真想 我在cur++后进行的DFS(cur+1,n)
//随后又进行了cur--  其实DFS(cur+1,n)就蕴含了cur++以及cur--两步 
//cur++ DFS(cur,n) cur-- 等价于 DFS(cur+1,n)
//超时代码如下
/*int count = 0;
    void DFS(int cur,int n){
        if(cur==n){
            count++;
            return ;
        }
        if(cur>n)
            return ;
        cur++;
        DFS(cur,n);
        cur--;
        if(cur+2<=n){
            cur = cur+2;
            DFS(cur,n);
            cur = cur-2;
        }
          
    }
    int climbStairs(int n) {
        DFS(0,n);
        return count;
    }
*/
//这题的正确解法是动态规划  说实话我还是不明白动态规划本质 遇到这种题都不会
//我们可以发现 f(n)的步数其实是f(n-1) 和 f(n-2)步数之和  因为f(n-1)加一步到它 f(n-2)加两步也到它
int climbStairs(int n){
    //定义dp数组  加1的原因是记录到第n层
    vector<int> res(n+1);
    //当f(2)不符合 f(1) + f(0)这是例外情况
    if(n<=1)
        return n;
    //初始化
    res[1]=1;
    res[2]=2;
    //i代表楼梯数
    for(int i = 3; i <= n;i++){
        res[i] = res[i-1] + res[i-2];
    }
    return res[n];
}
int main(){
    int n;
    cin>>n;
    int result = climbStairs(n);
    cout<<result<<endl;
    return 0;
}

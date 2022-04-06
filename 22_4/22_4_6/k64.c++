#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//这道题一开始我有种预感是动态规划 但是没想明白咋做 
//后来我又想了想 DFS也可以做 而且我比较较熟悉 所以就开始用回溯的方法写
//DFS确实写出来了 代码附在另外一个里面  但是DFS的时间复杂度太高 根本过不了 笑死
//看了题解之后我才发现dp真简单
//上左两条线的最小数都是固定的 因为不可能往回走
//所以中间的最小值就依赖于它的上边一个和左边一个的最小值加上它本身的值
//最后最后一位一定是最小的路径  其实就是局部最优解到全局最优解
//这道题一定要注意的是 在双重遍历的时候一定要内层遍历列 外层遍历行
int minPathSum(vector<vector<int>>& grid){
    //行值
    int m = grid.size();
    //列值
    int n = grid[0].size();
    //排除异常情况
    if(m==0||n==0)
        return 0;
    auto dp = vector<vector<int>> (m,vector<int>(n));
    dp[0][0] = grid[0][0];
    //计算第一行最小路径  遍历的是列
    for(int j = 1; j < n; j++){
        dp[0][j] = dp[0][j-1] + grid[0][j];
    }
    //计算第一列最小路径，遍历的是行
    for(int i = 1; i < m; i++){
        dp[i][0] = dp[i-1][0] + grid[i][0];
    }
    //内循环遍历列
    for(int i = 1; i < m; i++){
        for(int j = 1; j < n; j++){
            //选左 上当中最小的路径
            dp[i][j] = min(dp[i-1][j],dp[i][j-1])+grid[i][j];
        }
    }
    return dp[m-1][n-1];
}
int main(){
    int n,m;
    cin>>m>>n;
    vector<vector<int>> nums;
    for(int i = 0; i < m; i++){
        vector<int> tmp1;
        for(int j = 0; j < n; j++){
            int tmp2;
            cin>>tmp2;
            tmp1.push_back(tmp2);
        }
        nums.push_back(tmp1);
    }
    int result = minPathSum(nums);
    cout<<result<<endl;
    return 0;
}

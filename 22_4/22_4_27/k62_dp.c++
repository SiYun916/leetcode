#include <iostream>
#include <vector>
using namespace std;
//两个条件
//到左边界 上边界路径只能是1
//dp[i][j] = dp[i-1][j] + dp[i][j-1]  (i,j)位置的路径数等于(i-1,j)的路径加上(i,j-1)
int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,(vector<int>)n);
        for(int i = 0; i < m; i++){
            dp[i][0] = 1;
        }
        for(int j = 0; j < n; j++){
            dp[0][j] = 1;
        }
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
}
int main(){
    int m,n;
    cin>>m>>n;
    int res = uniquePaths(m,n);
    cout<<res<<endl;
    return 0;
}

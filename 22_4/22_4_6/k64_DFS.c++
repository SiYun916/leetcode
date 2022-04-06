#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
void DFS(int m,int n,int x,int y,vector<vector<int>>& grid,vector<int>& res,int count){
        count = count + grid[y][x];
        if(x==n&&y==m){
            res.push_back(count);
            return ;
        }
        if(x<n&&y<m){
            DFS(m,n,x+1,y,grid,res,count);
            DFS(m,n,x,y+1,grid,res,count);
        }else if(x==n&&y<m){
            DFS(m,n,x,y+1,grid,res,count);
            return ;
        }else if(x<n&&y==m){
            DFS(m,n,x+1,y,grid,res,count);
            return ;
        }
    }
int minPathSum(vector<vector<int>>& grid) {
        int n = grid[0].size() - 1;
        int m = grid.size() - 1;
        vector<int> res;
        DFS(m,n,0,0,grid,res,0);
        sort(res.begin(),res.end());
        return res[0];
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

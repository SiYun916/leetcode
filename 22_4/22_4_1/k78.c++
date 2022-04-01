#include <iostream>
#include <vector>
using namespace std;
//这道题 一开始没想到用回溯
//而且有点赶时间 没认真想就直接看题解
//
//大体思路就是 每个元素都有选择和不选两种
//先选择push 然后不选pop 
//结束条件是当前数位是否等于nums.size()
void dfs(int n,vector<int>& nums,vector<int>& tmp,vector<vector<int>>& res){
        //终止条件
        if(n == nums.size()){
            res.push_back(tmp);
            return ;
        }
        //选择当前元素
        tmp.push_back(nums[n]);
        //下一位
        dfs(n+1,nums,tmp,res);
        //删除当前元素 即不选
        tmp.pop_back();
        //下一位
        dfs(n+1,nums,tmp,res);
    }
vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> tmp;
        dfs(0,nums,tmp,res);
        return res;
    }
int main(){
    int n;
    vector<int> nums;
    cin>>n;
    for(int i = 0; i < n; i++){
        int tmp;
        cin>>tmp;
        nums.push_back(tmp);
    }
    vector<vector<int>> result; 
    result = subsets(nums);
    for(int i = 0; i < result.size();++i){
        for(int j = 0; j<result[i].size();j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
}


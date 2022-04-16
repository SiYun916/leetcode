#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;
//我没想到这道题也能动态规划的
//实际上我并不太懂
//对于一个数x 它所处序列的最长长度 是x-1所处序列的最长长度 加上 x+1所处序列的最长长读 加上 1
//长度怎么记呢？ 这里就用到了hash表 hash的value值用来记录该key值所处序列的长度
//至于每次更新的为什么不是key=x-1/x+1时 hash的值 而是边界值 
//我也不太清楚  我只是感觉当一个新数来了之后
//如果它两边有紧邻的数   哎呀我也说不清楚
int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> dp;
        int l,r,len;
        int res = 0;
        for(int i = 0; i < nums.size();i++){
            if(!dp[nums[i]]){
                l = nums[i] - 1;
                r = nums[i] + 1;
                len = dp[l]+dp[r]+1;
                if(res < len) res = len;
                dp[nums[i]] = len;
                dp[nums[i]-dp[l]] = len;
                dp[nums[i]+dp[r]] = len;
            }
        }
        return res;
}
int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin>>nums[i];
    }
    int res = longestConsecutive(nums);
    cout<<res<<endl;
    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//贪心算法
//按照结束时间从小到大排序（右边界）  最先结束的一定最先选 然后更新结束点
//局部最优解：取右边界最小的区间
//全局最优解：取最多的非交叉区间
//感觉写不清楚  直接看代码吧

//自定义排序方式
static bool cmp(vector<int>&a,vector<int>&b){
    return a[1] < b[1]; 
}
int eraseOverlapIntervals(vector<vector<int>>& intervals){
    int n = intervals.size();
    //计数   第一个是一定要选的
    int count = 1;
    //排序
    sort(intervals.begin(), intervals.end(),cmp);
    //先定义右边界
    int right = intervals[0][1];
    for(int i = 1; i < n; ++i) {
        if(intervals[i][0]>=right){
            count++;
            right = intervals[i][1];
        }
    }
    return n-count;
}
int main(){
    int n;
    cin>>n;
    vector<vector<int>> nums;
    for(int i=0;i<n;i++){
        vector<int> tmp(2);
        cin>>tmp[0]>>tmp[1];
        nums.push_back(tmp);
    }
    int res;
    res = eraseOverlapIntervals(nums);
    cout<<res<<endl;
    return 0;
}
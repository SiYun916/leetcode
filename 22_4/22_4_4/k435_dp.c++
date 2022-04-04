#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//我只能说我是带便  我自己没做出来这道题  即便是我看了题解 我还是不会贪心和动态规划咋做
//这里先说动态规划
//这道题 返回需要移除区间的最小数量 等价于 总数量减去最多不重叠区间的数量
//其实到这里就和算法课里讲的会议不冲突安排问题相似了
//但是我还是不会做 早忘了T.T
//假设当前区间为j 则f(j)等于前一个不冲突区间i的最多不冲突数量f(i)+1
//不冲突区间i 要靠区间右端点和j的左端点比较
//如果有冲突就是就是原f(i)值
//在列动态转移方程前 首先要对左（右）端点进行排序  

//自定义排序方式
static bool cmp(vector<int>&a,vector<int>&b){
    return a[0] < b[0]; 
}
int eraseOverlapIntervals(vector<vector<int>>& intervals){
    int n = intervals.size();
    //初始值都是1 即只能存在当前的区间
    vector<int> f(n,1);
    //排序
    sort(intervals.begin(), intervals.end(),cmp);
    //动态规划方程
    for(int i =1; i < n; i++){
        for(int j = 0; j < i; j++){
            //满足条件时 才进行进行替换
            //一定要注意有等号 
            if(intervals[j][1]<=intervals[i][0])
                f[i] = max(f[i],f[j]+1);
        }
    }
    //找出最大的不重叠区间个数
    sort(f.begin(),f.end());
    return n-f[n-1];
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
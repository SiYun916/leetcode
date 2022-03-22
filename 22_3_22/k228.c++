#include <iostream>
#include <vector>
#include <string>
using namespace std;
//写在前面  
//这道题 我只能说我真的很气
//按我的思路写 这道题执行代码的时候过了 结果也对了 我觉得逻辑上也没毛病
//但偏偏提交的时候告诉我有越界  执行错误
//我真的日了🐕了 你tm执行代码的时候不让我过没啥 可tm提交的时候告诉我有错
//真绷不住了
//
//题解思路：
//从数组的开头遍历
//left表示区间的左 right表示区间的右
//遍历i，从当前i开始查找有跳跃的两点
//查找到后更新区间右节点
//然后按照所给格式记录区间
//这里题解比我巧妙的两点是
//1. 直接用while 判断i<n 跳过连续点的i  不像我还得一个个去遍历
//2. 这里记录时 我是采用了left和right相同和不同两种情况来记录 而题解采用的是如果left<right就不记录了
vector<string> summaryRanges(vector<int>& nums){
    vector<string> res;
    int i = 0;
    int n = nums.size();
    while(i < n){
        int left = i;
        //因为是要利用第i-1元素+1判断 为保证数组不越界 i要先加1
        i++;
        while( i < n && nums[i] == nums[i-1]+1){
            i++;    
        }
        int right = i - 1;
        string tmp;
        tmp = to_string(nums[left]);
        if(left < right){
            tmp.append("->");
            tmp.append(to_string(nums[right]));
        }
        res.push_back(tmp);
    }
    return res;
}
int main(){
    vector<string> result;
    vector<int> nums;
    int x;
    cin>>x;
    for (int i = 0; i < x;i++ ){
        int t;
        cin>>t;
        nums.push_back(t);
    }
    result = summaryRanges(nums);
    for(int i = 0; i < result.size();i++)
        cout<<result[i]<<endl;
    return 0;
}

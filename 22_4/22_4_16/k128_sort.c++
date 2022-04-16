#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
//这道题 准备用三种方法写
//第一种 排序+去重+一次遍历 这是自己想出来的
//一开始其实也没想到 感觉排序后一个一个遍历能做 但是时间复杂度要达到n^2
//与题意要求的n不符合 就没做
//但是最后看完题解 自己想把自己得这种方法实现一下 虽然自己写得过程中有许多问题
//却发现执行时间以及内存消耗都有93%以上的得分 很神奇
//空间复杂度还好 时间复杂度我觉得至少有 nlogn 竟然能有93% 很离谱
int longestConsecutive(vector<int>& nums) {
    //排好序 否则还得一个一个遍历去看有没有目标值 
    sort(nums.begin(),nums.end());
    //去重  不去重的话  在有相同元素时 由于判断 会少记录
    nums.erase(unique(nums.begin(), nums.end()), nums.end());
    int i = 1;
    int res = 1;
    int n = nums.size();
    //两种特殊情况一定要单独出来 否则会报错
    if(n==0)
        return 0;
    if(n==1)
        return 1; 
    //在nums数目2以上时 res最小必为1
    while(i<n){
        int mnum = 1;
        //下面这样做可以保证中间的数不用重复计算 因为开头确定了 已经可以确定最长的了
        while(i<n&&nums[i-1]+1==nums[i]){
            mnum++;
            i++;
        }
        //选最大值
        if(res < mnum)
            res = mnum;
        i++;
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

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//这道题 一开始的想法就是动态规划但我不会
//所以我看了题解
//看完题解
//通透！（其实并不太懂）
//只学了一种方法 感觉像是模拟 有感觉像是层级遍历 看有多少层
int jump(vector<int>& nums){
    //start end都是代表当前层的起始位置
    int start = 0;
    int end = 0;
    int fl = nums.size() - 1;
    int res = 0;
    //当一层的终止位置小于最终的终止位置时
    while(end < fl){
        int maxstep = 0;
        for(int i = start; i <= end; i++){
            //计算该层到下层的最远距离
            maxstep = max (maxstep,i+nums[i]);
        }
        //下一层起始位置 是上层终止位置加1
        start = end + 1;
        //下一层的终止位置 是上层最远的距离
        end = maxstep;
        //计算跳动的次数 或者说层数
        res++;
    }
    return res;
}
int main(){
    int n ;
    cin>>n;
    vector<int> nums(n);
    for(int i = 0; i < n;i++){
        cin>>nums[i];
    } 
    int result = jump(nums);
    cout<<result<<endl;
    return 0;
}

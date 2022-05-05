#include<iostream>
#include<vector>
using namespace std;
//补
//之前放纵的代价要自己承受
//每天补一道题
//这道题一开始我想的是直接暴力
//连续子数组 搞循环就可以
//第一层规定子数组中元素的个数m  第二层是起始位置  第三层计算从起始位置开始m个元素乘积与k的大小关系
//我感觉复杂度应该在三次方级别  大概率是超时的
//所以手写代码后直接看了题解 没有实际提交
//题解很巧妙用了滑动窗口 记得之前的一个题也用到了滑动窗口
//总之就是在窗口右端点到达数组末尾之前
//每右移一次就计算一次乘积
//如果乘积小于k就把当前窗口内新增的子数组加上 就是 right+1-left
//如果乘积大了就缩小窗口  右移左端点
//直至乘积小了 或者端口重合了
int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int left = 0;
        int right = 0;
        int res = 0;
        int mul = 1;
        while(right < nums.size()){
            mul = mul * nums[right];
            while(left <= right && mul >= k){
                mul = mul / nums[left];
                left++;
            }
            res = res + right + 1 - left;
            right++;
        }
        return res;
}
int main(){
    int n,k;
    cin>>n>>k;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin>>nums[i];
    }
    int result = numSubarrayProductLessThanK(nums,k);
    cout<<result<<endl;
    return 0;
}

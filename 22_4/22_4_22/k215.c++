#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//这道题 暴力的方法其实不难想 直接排序 取n-k下标的数就行
//但最好的排序 快排的时间复杂度也在O(nlogn) 
//考虑到快排的过程  每次其实都可以确定一个数的位置以及得到它的下标
//所以我们要想得到n-k下标的数就可以模仿这个过程 把不需要确定位置的数排除就可以大大加快选择的速度
int quickSelection(vector<int>& nums,int l,int r);
int findKthLargest(vector<int>& nums, int k){
    //左右边界 以及目标下标
    int l = 0;
    int r = nums.size() - 1;
    int target = nums.size() - k;
    //当左下标小于右下标时 查找
    while(l < r){
        int mid = quickSelection(nums,l,r);
        if(mid == target)
            return nums[mid];
        else if(mid < target)
            l = mid + 1;
        else
            r = mid - 1;
    }
    //如果l<r没找到 那么说明重合位置就是目标下标
    return nums[l];
}
int quickSelection(vector<int>& nums,int l,int r){
    //假定设置最左边元素为要查找位置的元素
    //从它的下一位到截至位置开始查找
    int i = l + 1;
    int j = r;
    while(true){
        //在右边界的范围内 查找第一个大于最左边元素的数的下标
        while(i<r&&nums[i]<=nums[l]){
            i++;
        }
        //在左边界的范围内 查找第一个小于最左边元素的数的下标
        while(j>l&&nums[j]>=nums[l]){
            j--;
        }
        //当第一个大于最左边元素的数的下标 大于等于 第一个小于最左边元素的数的下标 说明已经分好了两块
        //等于情况是出现了相等元素 
        if(i>=j)
            break;
        //找到之后交换
        swap(nums[i],nums[j]);
    }
    //已经确定最左边元素的下标 为j的下标交换位置
    swap(nums[l],nums[j]);
    return j;
}
int main(){
    int n,k;
    cin>>n>>k;
    vector<int> nums(n);
    for(int i = 0; i < n;i++){
        cin>>nums[i];
    }
    int result = findKthLargest(nums,k);
    cout<<result<<endl;
    return 0;
}
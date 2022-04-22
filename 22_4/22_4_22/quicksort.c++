#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//写一下快排
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
void quicksort(vector<int>& nums,int l,int r) {
    if(l<r){
        int mid = quickSelection(nums,l,r);
        quicksort(nums,l,mid-1);
        quicksort(nums,mid+1,r);
    }
}
int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i = 0; i < n;i++){
        cin>>nums[i];
    }
    quicksort(nums,0,n-1);
    for(int i = 0; i < n;i++){
        cout<<nums[i]<<" ";
    }
    return 0;
}
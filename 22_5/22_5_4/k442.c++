#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//这道题一眼hashmap 能过 但是空间复杂度不符合题意O(1)
//第二种排序找相邻的相同的两个数 时间复杂度不符合
//没想出来时间复杂度O(n)空间复杂度O(1)的解
//看了题解，原地哈希 只能说特殊题特殊解 
//首先分析条件 数组中每个数都是1 - n中的一个 而数组下标是0 - n-1
//那么数组中所有的数字都可以用下标表示且不会出现越界情况
//每个数只出现一次或者两次 所以只有两种状态 可以想到用正负来表示
//扫描每个数 将数对应的下标的那个数变成负的
//如果已经是负的了说明已经出现过一次 就将该数加入结果
//要注意的是 扫描每个数时首先都要取其绝对值 因为遍历前面的数可能已经将其对应下标的值变成了负的
//判断当前数是不是出现了两次不是依据当前数的正负而是其对应下标的数的正负
vector<int> findDuplicates(vector<int>& nums){
    vector<int> result;
    for(int i=0; i<nums.size();i++){
        int tmp = abs(nums[i]);
        if(nums[tmp-1]>0)
            nums[tmp-1] = -nums[tmp-1];
        else
            result.push_back(tmp);
    }
    return result;
}
int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n; i++){
        cin>>nums[i];
    }
    vector<int> result;
    result = findDuplicates(nums);
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
    cout<<endl;
    return 0;
}

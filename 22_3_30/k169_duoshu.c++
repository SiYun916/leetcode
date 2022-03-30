#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//在上道题的基础上 我直接用了hash表 找到大于n/2的元素
//这里不多写hash的解法
//第一种方法：排序
//因为是众数且大于n/2，所以排序后最中间的值必定为众数  考虑两种极端情况就好
//第二种方法：
//Boyer-Moore 投票算法
//如果我们把众数记为 +1+1+1，把其他数记为 −1-1−1，将它们全部加起来，显然和大于 0，从结果本身我们可以看出众数比其他数多。
//具体我们维护一个候选众数 candidate 和它出现的次数 count。初始时 candidate 可以为任意值，count 为 0；
/*
我们遍历数组 nums 中的所有元素，对于每个元素 x，在判断 x 之前，如果 count 的值为 0，我们先将 x 的值赋予 candidate，随后我们判断 x：

    如果 x 与 candidate 相等，那么计数器 count 的值增加 1；

    如果 x 与 candidate 不等，那么计数器 count 的值减少 1。

在遍历完成后，candidate 即为整个数组的众数。
*/
//具体证明看leetcode题解


//排序法
/*
int majorityElement(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    return nums[nums.size()/2];
}
*/
int majorityElement(vector<int>& nums) {
    int candidate = -1;
    int count = 0;
    for (int i = 0; i < nums.size(); i++){
        if(candidate==nums[i])
            count++;
        else
            count--;
        if(count<0){
            candidate = nums[i];
            count = 0;
        }
    }
    return candidate;
}
int main(){
    int n;
    cin >> n;
    vector<int> nums;
    for(int i=0;i<n;i++){
        int tmp;
        cin >> tmp;
        nums.push_back(tmp);
    }
    int result = majorityElement(nums);
    cout<<result<<endl;
    return 0;
}
#include <iostream>
#include <vector>
using namespace std;
int findMini(vector<int>& nums){
    int left = 0;
    int right = nums.size() - 1;
    int mid;
    while(left <= right){
        mid = left + (right - left)/2;
        if(nums[mid] > nums[right])
            left = mid + 1;
        else if (nums[mid] < nums[right])
            right = mid;
        else
            right--;
    }
    return nums[left];
}

int main(){
    //这道题 解出来不难 按自己的方法直接遍历一遍取最小值就好
    //如果追求时间复杂度小  可以使用二分的方法
    //
    //考虑旋转数组的特性 可以分为两个序列 前面num1 和 后面num2
    //num1中的所有数  都是要大于 num2中的所有数的
    //所以只要找出两个序列的分界点就好
    //考虑二分的方法   
    //如果mid大于最右边的数 ，说明mid在num1里面  left就要右移来找分界点
    //如果mid小于最右边的数 ， 说明mid在num2里面  分界点肯定在mid左边  所以right左移
    //这里最需要考虑的特殊情况是  当mid和最右边的值相等时 无法判断实在哪个序列里 
    //很巧妙的方法就是right-1重新界定第二个序列
    //具体方法题解看leetcode
    vector<int> nums;
    int num;
    cin>>num;
    for (int i = 0; i < num; ++i){
        int tmp;
        cin>>tmp;
        nums.push_back(tmp);
    }
    int min_num = findMini(nums);
    cout<<min_num<<endl;
    return 0;
}

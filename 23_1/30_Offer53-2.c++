#include <iostream>
#include <vector>
using namespace std;
//1. 暴力便利
//2. 二分法：如果nums[mid] == mid，索引等于值说明左边都没问题，left = mid + 1
//           如果nums[mid] !=mid 说明mid右边全不对应，缺值只能在mid左边，right = mid - 1
//           找到缺值后，right=left，这时right - 1 退出循环，left索引指向缺值
//           考虑到边界的缺值比如0,n
class Solution{
    public:
        int missingNumber(vector<int>& nums){
            int left = 0, right = nums.size()-1;
            while(left <= right){
                int mid = left + (right - left)/2;
                if(nums[mid] == mid)    left = mid  + 1;
                else right = mid - 1;
            }
            return left;
        }
};
int main(){
    vector<int> nums{0,1,2,3,4,5,6,7,9};
    Solution* obj = new Solution();
    int result = obj->missingNumber(nums);
    cout<<"Result is "<<result<<endl;
    return 0;
}




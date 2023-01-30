#include <iostream>
#include <vector>
using namespace std;
//我直接遍历的
//二分法，找target的右边界和target-1的右边界，相减即为个数
//左边界的值在小于等于target时，一直右移即可找到
class Solution{
    public:
        int search(vector<int>& nums,int target){
            return searchRight(nums,target)-searchRight(nums,target-1);
        }
        int searchRight(vector<int>& nums,int target){
            int left = 0, right = nums.size()-1;
            while(left <= right){
                int mid = left + ( right - left ) / 2;
                if(nums[left] <= target)    left = mid + 1;
                else right = mid - 1;
            }
            return left;
        }

};

int main(){
    vector<int> nums{5,7,7,8,8,10};
    int target = 8;
    Solution* obj = new Solution();
    int result = obj->search(nums,target);
    cout<<"Result is "<<result<<endl;
    return 0;
}




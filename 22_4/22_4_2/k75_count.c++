#include <iostream>
#include <vector>
using namespace std;
//我只能说 我是个大菜B 
//这道题指定了不使用排序算法 然后我就不会做了
//记录这道题的几个思路
//第一个 可以用vector或者map记录0 1 2每个的数量
//最后按照数量输出即可
//第二个 单指针 指定分界点ptr 两次遍历 交换
//记录值
void sortColors(vector<int>& nums) {
        vector<int> count(3);
        for(int i = 0; i < nums.size();i++){
            if(nums[i]==0) count[0]++;
            else if(nums[i]==1) count[1]++;
            else count[2]++;
        }
        for(int i = 0; i < count[0]; i++)
            nums[i]=0;
        for(int i = count[0]; i < count[0]+count[1]; i++)
            nums[i]=1;
        for(int i = count[0]+count[1]; i < count[0]+count[1]+count[2];i++)
            nums[i]=2;
}
/* 单指针
void sortColors(vector<int>& nums) {
        int n = nums.size();
        int ptr = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) {
                swap(nums[i], nums[ptr]);
                ++ptr;
            }
        }
        for (int i = ptr; i < n; ++i) {
            if (nums[i] == 1) {
                swap(nums[i], nums[ptr]);
                ++ptr;
            }
        }
    }
*/
int main(){
    int n;
    cin>>n;
    vector<int> nums;
    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        nums.push_back(tmp);
    }
    sortColors(nums);
    for(int i=0;i<n;i++){
        cout<<nums[i]<<" ";
    }
    return 0;
}

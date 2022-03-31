#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//这道题 只能说细节有点多
//一开始我想的是3重循环，i j=i+1 k=j+1 来找到符合的三元组
//但是我忽略了重复 而且一开始没有排序 相同的三元组有不同的排列 导致不知道如何去重
//参考题解后 我开始排序，然后去重 但是是时间复杂度太大 还是没过
//
//看了题解之后 我突然觉得和之前的最大容器有点相似
//它只是从前到后选择一个值 然后在其后的所有数中找两个数使其和等于该值的相反数
//而找这两个数就可以使用双指针
//之所以可以使用双指针 也是因为它的特性
//因为排序后 如果左右两指针的值大于目标值 就要使右边指针（大的数）左移 如果小了 就右移左指针
//相等了就记录
vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        //先进行排序
        sort(nums.begin(),nums.end());
        for(int first = 0;first < nums.size();first++){
            //如果后面出现相同的数字 跳过  这样可以直接避免重复
            if(first>0&&nums[first]==nums[first-1]){
                continue;
            }
            //二三目标之和是第一个的相反数
            int target = -nums[first];
            //第三个值从最右往左找
            int third = nums.size()-1;

            for(int second=first+1; second<nums.size(); second++){
                //如果第二个值有重复 直接跳过 避免重复
                if(second>first+1&&nums[second]==nums[second-1])
                    continue;
                //下面两步的顺序不能错 一定要先移动 
                //和大于目标值时 右边的值左移
                while(second<third&&nums[second]+nums[third]>target)
                    third--;
                //如果左移到second 说明并没有符合条件的
                if(second==third)
                    break;
                //如果二三之和小于等于target  且符合等于条件时 记录值
                if(nums[second]+nums[third]==target)
                    res.push_back({nums[first],nums[second],nums[third]});
            }

        }
        return res;
}
int main(){
    int n;
    cin >> n;
    vector<int> nums;
    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        nums.push_back(tmp);
    }
    vector<vector<int>> result;
    result = threeSum(nums);
    for(int i=0; i < result.size();i++){
        for(int j= 0; j <result[i].size();j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}



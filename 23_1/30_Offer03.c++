#include <iostream>
#include <vector>
#include <map>
using namespace std;
//个人思路：hashmap<int,int>记录每个数出现的次数，默认value值是0，所以当value==2时输出该key即可
//题解：
//1. 用hashmap<int,bool> 出现过一次对应key的value变为true，再出现就输出key（思路基本一样）
//2. 索引多而数值少，把数值放到对应的索引上比如0值放到0索引，此之前先判断交换的双方值相不相等
//   如果相等就输出，不等就交换
/* 1  
class Solution{
    public:
        map<int,bool> hashMap;
        int findRepeatNumber(vector<int>& nums){
            for(int num : nums){
                if(hashMap[num]) return num;
                hashMap[num] = true;
            }
            return -1;
        }

};
*/
class Solution{
    public:
        int findRepeatNumber(vector<int>& nums){
            int i = 0;
            while(i < nums.size()){
                if(nums[i] ==  i){
                    i++;
                    continue;
                }
                if(nums[i] == nums[nums[i]]) return nums[i];
                swap(nums[i],nums[nums[i]]);
            }
            return -1;
        }
};
int main(){
    vector<int> nums{2, 3, 1, 0, 2, 5, 3};
    Solution* obj = new Solution();
    int result = obj->findRepeatNumber(nums);
    cout<<"repeatNumber is "<<result<<endl;
    return 0;
}

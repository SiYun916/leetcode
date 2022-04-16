#include <iostream>
#include <vector>
#include <map>
using namespace std;
//这个题解来自官方
//我觉得这个的主要思路就是去重以及查找的优化
//为了方便查找某个数  他先用一个hash来存所有的数 hash key是数 value是数的个数
//如果某个数在hash中有前一个数 说明从它开始的序列必定不是最长的 可以直接跳过
//如果没有前一个数 则进行序列长读的计算
//但我感觉实际上这种方法的时间复杂度也到不了n
//但也只是感觉 不会证明
 int longestConsecutive(vector<int>& nums) {
        //用hash存一遍  空间换时间
        map<int,int> hp;
        for(int num : nums){
            hp[num]++;
        }
        int res = 0;
        //每个数都遍历一遍 
        for(int num : nums){
            int cur = num;
            int mnum = 0;
            //判断是否有前一个数  如果没有 从当前开始的序列最长
            if(hp[num-1] < 1){
                while(hp[cur]){
                    mnum += 1;
                    cur++;
                }
                if(mnum>res)
                    res = mnum;
            }
        }
        return res;
}
int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin>>nums[i];
    }
    int res = longestConsecutive(nums);
    cout<<res<<endl;
    return 0;
}

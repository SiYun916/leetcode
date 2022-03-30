#include <iostream>
#include <vector>
using namespace std;
//首先我是菜比 我直接暴力 时间复杂度o(n*n)
//其次一般容易想到的方法是hash 遍历一遍记录 遍历map找到为1的值
//最牛比的是位运算
//考虑到异或的特性：
//a ^ a = 0
//a ^ 0 = a
//异或运算符合交换律
//所以 将数组内的数异或一遍 剩下的就是单独的数
int singleNumber(vector<int>& nums){
    //0不影响异或运算
    int res = 0;
    for(int i=0; i < nums.size(); i++){
        res = res ^ nums[i];
    }
    return res;
}
/* hash表解法
        int res;
        map<int,int> tt;
           for(int i = 0; i < nums.size();++i){
            tt[nums[i]] +=1;
        }
        for(int i = 0; i < nums.size();++i){
            if(tt[nums[i]]==1)
                res = nums[i];
        }
        return res;

*/
int main(){
    int n;
    cin >> n;
    vector<int> nums;
    for(int i=0;i<n;i++){
        int tmp;
        cin >> tmp;
        nums.push_back(tmp);
    }
    int result = singleNumber(nums);
    cout<<result<<endl;
    return 0;
}
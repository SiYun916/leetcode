#include <iostream>
#include <vector>
using namespace std;
//这道题 我一开始的想法是位运算  因为之前有做过一个类似的
//但是我不明白要怎么分开两个不同数的异或
//完全忘记了普通方法   hash表其实是最容易想的
//这里仅重复一下
/*
  vector<int> singleNumber(vector<int>& nums) {
        map<int,int> tmp;
        vector<int> res;
        for(int i = 0; i < nums.size();i++){
            tmp[nums[i]]++;
        }
        for(int i = 0; i < nums.size();i++){
            if(tmp[nums[i]]<2)
                res.push_back(nums[i]);
        }
        return res;
    }
 * */
//下面主要讲下异或的做法
//首先来介绍整体思路  题解来自三叶
//官方题解真的看不懂
//利用除答案以外的元素均出现两次，我们可以先对 nums 中的所有元素执行异或操作，得到 sum，sum 为两答案的异或值（sum 必然不为 00）。
//然后取 sum 二进制表示中为 1 的任意一位 k，sum 中的第 k 位为 1 意味着两答案的第 k 位二进制表示不同。
//对 nums 进行遍历，对第 k 位分别为 0 和 1 的元素分别求异或和（两答案必然会被分到不同的组），即为答案
//下面主要是如何分类的问题 即如何取一位为1
//利用a&(-a)可以找出一位 为1的位置  https://blog.csdn.net/oyoung_2012/article/details/79932394  我直接挂在这里  
//而至于题解中的 三元运算符  主要是为了防止溢出
// 因为二进制有正负0，负零用于多表示一位负数，这个负数如果取相反数，会产生溢出，所以不能用 a & (-a) 取最低有效位
// 负0的特点是第一位是1，其余位是0，所以它的最低有效位就是自己
vector<int> singleNumber(vector<int>& nums) {
        int xornum = 0;
        for(int i = 0; i < nums.size();i++){
            xornum = xornum ^ nums[i];
        }
        int lsb = (xornum==INT32_MIN?xornum:xornum&(-xornum));
        vector<int> res(2,0);
        for(int i = 0; i < nums.size();i++){
            if(nums[i]&lsb)
                res[0] = res[0]^nums[i];
            else
                res[1] = res[1]^nums[i];
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
    vector<int> result;
    result = singleNumber(nums);
    for(int i = 0; i < result.size();i++){
        cout<<result[i]<<endl;
    }
    return 0;
}



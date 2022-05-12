#include<iostream>
#include<vector>
using namespace std;
//hash可解但空间复杂度太高
//全部数转换成二进制 三个数相同 所有数总和 在二进制下某一数位要么是3的倍数 要么是3的倍数加1
//所以按位统计 如果是3的倍数加1说明只出现一次的数在该位置是1
//由于每次取得都是最低位 所以在恢复的时候需要恢复其数位
int singleNumber(vector<int>& nums) {
    //定义结果
    int ans = 0;
    for(int i =0; i < 32; i++){
        //记录nums中所有数 在某一数位为1的总数
        int total = 0;
        for(int num : nums){
            //i是0就表示最低位 i是1就表示第二位 total记录的是该位下1的总数
            total += (num>>i) & 1;
        }
        //判断出现一次的元素在该位是否是1
        if(total%3){
            //或 表示加上该位 比如 1000 | 0001就表示1001 
            ans = ans | (1<<i);
        }
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0; i<n; i++){
        cin>>nums[i];
    }
    int ans = singleNumber(nums);
    cout<<ans<<endl;
    return 0;
}
#include<iostream>
#include<vector>
using namespace std;
//贪心算法 把问题转换 长度偶数 且偶数下标和它的下一位 两个数不等
//其实就是两个数字组成一个对 且两个数字不相等
//如果数对符合条件则遍历下一个数对 
//如果数对不符合条件 则删除数对中第一个相同的数 从第二个数开始重新配对
//佩到最后 如果是奇数就删除最后一个 偶数就不用管 
int minDeletion(vector<int>& nums) {
    int len = nums.size();
    int ans = 0;
    //这里i+1要保证nums[i+1]存在，数对存在
    for (int i = 0; i+1 < len; i++) {
        //如果不符合条件 删除第一个 从第二个开始继续判断
        if(nums[i]==nums[i+1]) ans++;
        //如果符合条件 就开始判断下一对
        else i++;
    }
    //如果多出来一个数没有配对
    if((len - ans)%2) ans++;
    return ans;
}
int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n; i++){
        cin>>nums[i];
    }
    int res = minDeletion(nums);
    cout<<res<<endl;
    return 0;
}
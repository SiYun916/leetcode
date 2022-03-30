#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
//我并没有写出来这道题甚至没有思路
//我想到是每个都容量都计算一遍 取最大值  但是并不会写
//
//看了题解之后我才知道用双指针解决这个问题
//大体思路如下
//首先将容器的长拉满，比较最远两个高的大小
//容器的大小取决于左右最小的那个高 记录此时的面积 
//如果左高最小 则left右移   同理右高左移
//计算最小高的大小  与之前的ans容器大小比较
//将ans赋值为两者中最大的一个
//
//双指针的解法时间复杂度为O(n)
//因为每次移动都是排除了一类情况  比如第一次时 就把最小高所有长的情况排除掉了
int maxArea(vector<int>& height){
    int ans = 0;
    int left = 0;
    int right = height.size() - 1;
    while (left < right){
        ans = max(ans,(right-left)*min(height[left],height[right]));
        if(height[left] <= height[right]) left++;
        else right--;
    }
    return ans;
}
int main(){
    int num;
    vector<int> nn;
    cin>>num;
    for (int i = 0; i < num; i++){
        int tmp;
        cin>>tmp;
        nn.push_back(tmp);
    }
    int res;
    res = maxArea(nn);
    cout<<res<<endl;
    return 0;
}

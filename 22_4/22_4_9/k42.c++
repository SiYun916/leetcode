#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
//这道题 没认真写  前面最大面积的那道题知道了这个用单调栈
//但这道题自己写的单调栈有问题
//这道题单调栈是递减的  和之前那道题不一样
//大体思路就是如果遇到前一个比后一个大的情况 再递减栈的情况下 
//是一定有一个凹槽可以接雨水的
//宽度是两个高位置索引之差  高度是两个高位置中最小的那个 减去栈顶元素位置的高度（其实就是前一个的高度）
int trap(vector<int>& height){
    int res = 0;
    stack<int> tmp;
    for(int i = 0;i < height.size();i++){
        while(!tmp.empty()&&height[tmp.top()]<height[i]){
            //凹槽位置的高度
            int tt = tmp.top();
            tmp.pop();
            //要判断一下是否为空 如果为空了还去进行加的话 会有溢出报错
            if(tmp.empty())
                break;
            int width = i - tmp.top() - 1;
            int h = min(height[tmp.top()],height[i]) - height[tt];
            res = res + width*h;
        }
        tmp.push(i);
    }
    return res;
}
int main(){
    int n,result;
    cin>>n;
    vector<int> heights(n);
    for(int i = 0; i < n;i++){
        cin>>heights[i];
    }
    result = trap(heights);
    cout<<result<<endl;
    return 0;
}

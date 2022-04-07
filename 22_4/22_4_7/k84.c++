#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
//这道题 暴力的方法：遍历宽度 找最小的高度 时间复杂度o(n^2) 超时了 过不了
//看了快2小时的单调栈题解  还是似懂非懂的样子 人都快麻了
//答题思路是 对于每个高度都找出其面积的最大值 每个高度是确定的 需要找的是宽度
//可以想到 对于一个确定的高度 如果它左或者右边的高度都比它高那么它的宽度还可以扩展
//一旦出现两边的两个高都比它小 那么宽度就确定下来了
//但是如何实现？
//结合题解谈一下我的理解：
//由于要对每一个高度都要求其最大面积 需要确定其两边低于它的高度的位置，所以压栈出栈的都是位置坐标而不是高度
//高度由位置坐标确定
//但是如果还没找到低于它的高度 就要储存该位置  这里就用了栈
//当第n+1个位置的高度大于第n个时，这时无法确定第n个位置处高度对应的面积最大值是多少 就要将第n个位置压入栈中
//如果记录的话，由于第n+1个位置的高度大于第n个  所以栈内的元素一定是递增的 即递增栈
//找到了低于某位置高度的位置 就将该位置出栈 计算其面积 然后判断是否最大 进行选择
//遍历完所有位置后 如果栈内还有元素 那么终止位置就固定了 起始位置是它前一元素位置 
int largestRectangleArea(vector<int>& heights){
    int n = heights.size();
    if(n==1)
        return heights[0];
    int res = 0;
    stack<int> inc;
    for(int i = 0; i < n; i++){
        while(!inc.empty()&&heights[i]<heights[inc.top()]){
            int height = heights[inc.top()];
            inc.pop();
            int width = i;
            if(!inc.empty())
                width = i - inc.top() - 1;
            res = max(res,width*height);
        }
        inc.push(i);
    }
    while(!inc.empty()){
        int height = heights[inc.top()];
        inc.pop();
        int width = n;
        if(!inc.empty())
            width = n - inc.top() - 1;
        res = max(res,width*height);
    }
    return res;
}
int main(){
    int n;
    cin>>n;
    vector<int> num(n);
    for(int i = 0; i < n; ++i){
        cin>>num[i];
    }
    int result = largestRectangleArea(num);
    cout<<result<<endl;
    return 0;
}
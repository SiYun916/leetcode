#include <iostream>
#include <vector>
using namespace std;
//这道题 只能说 蒙对的 
//一眼回溯 然后就按照回溯的步骤开始写
//第一次把所有的重复全都返回了
//然后就开始想 第二步回溯怎么才能从下一数开始 一开始我想的是通过判断终止变量实现
//很明显不行 因为它的返回和层数相关
//之后我就想再添加一个变量index 来记录开始的值
//比如k=3 第一次回溯时index=1 第二次回溯时index=2然后要添加的数从index=2开始添加 第三次回溯时index=3要添加的数从3开始遍历
//所以index就和遍历量i的初始值产生了关系
//按此想法  
//只要每次执行回溯函数时把index赋值为当前i+1就能保证
//下一次的回溯是从下一个下一个数开始的 避免了重复的数据

//n代表范围  k代表终止条件  t代表当前条件  res存储最终结果  tmp存储一次的结果  index代表遍历开始值
void DFS(int n,int k,int t,vector<vector<int>>& res,vector<int>& tmp,int index){
        if(t == k){
            res.push_back(tmp);
            return ;
        }
        for(int i = index; i <= n; ++i){
            tmp.push_back(i);
            //下面的i不能index 逻辑要清晰 下一次的回溯一定是要从当前数的下一个数开始 而不是当前数的曾经的起始数开始
            DFS(n,k,t+1,res,tmp,i+1);
            tmp.pop_back();
        }
    }
vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> res;
    vector<int> tmp;
    DFS(n,k,0,res,tmp,1);
    return res;
}
int main(){
    int n;
    int k;
    cin>>n>>k;
    vector<vector<int>> result;
    result = combine(n,k);
    for(int i = 0; i < result.size(); ++i){
        for(int j = 0; j < result[i].size();j++){
            cout<<result[i][j]<<" "; 
        }
        cout<<endl;
    }
    return 0;
}

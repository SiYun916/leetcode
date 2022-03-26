#include <iostream>
#include <vector>
#include <string>
using namespace std;
//今天的每日一题 n皇后
//虽然用时比较长 代码效率不高 用的是相对无脑的回溯 但好歹完全是自己写出来的 还是很开心的
//这里简单记录下我的思路以及出错点
//首先 要分成n=1和n=2，3...   当n=1时直接记录值（一开始我忽略了这种情况，最后报错只有一个没通过时我才想到）
//下面介绍n>1的情况
//首先是把皇后在一行的位置用一个string向量记录下来 这里一开始其实我出错了 我多打印了一个. 后来打印出来对比答案的时候才发现
//然后进行回溯
//这里的回溯和先前的题有所不同
//当前回溯结束的条件有两个 第一个是所有的位置都满足条件，记录此时各行的位置，返回  第二个是当前存在不满足条件的行，不记录值，返回
//而且一定要注意是 要先判断第二个条件 因为第一个判断条件是当前n与输入的n相同，假如先判断第一个，则会出现最后一行不满足题目条件的情况
//先判断第二个条件 最后一行不满足条件的情况 不会被记录下来 直接返回
//接下来主要的问题是如何判定当前的位置状态是否满足题目条件
//这里我用了两个循环 从第一行开始比较两行 Q 之间的位置关系
//如果在同一列即y0==y1 或在同一行 x0==x1 或对角 y1-y0==x1-x0 || y1-y0==x0-x1
//说明当前存在两行 Q的位置不满足题目
//直接return
//满足所有条件的值 记录到res里面
void backtracking(int n,int nn,vector<string>& pl,vector<vector<string>>& res,vector<string>& temp){
    //判断当前所有行Q的位置是否满足要求
    if(n!=0&&n!=1){
        for(int j = 0; j < temp.size()-1; ++j){
            //记录某一行第一个Q的位置
            int y0 = j + 1;
            int x0;
            for(int k = 0; k < temp[j].size(); ++k){
                if(temp[j][k] == 'Q'){
                    x0 = k + 1;
                    break;
                }
            }
            for(int l = j+1; l < temp.size(); ++l){
                //记录另外一行Q的位置
                int y1 = l + 1;
                int x1;
                //一定要注意 下面temp[]中的都是l 一开始写成了j x1一定和x0一样 结果就没有输出
                for(int k = 0; k < temp[l].size(); ++k){
                    if(temp[l][k] == 'Q'){
                        x1 = k + 1;
                        break;
                    }
                }
                //对两个Q的位置进行判断 是否满足条件
                if(x1 == x0 || y1 == y0 || y1-y0==x1-x0 || y1-y0==x0-x1)
                    return ;
            }
        }
    }
    //满足所有条件 记录
    if(n == nn){
        res.push_back(temp);
        return ;
    }
    //回溯
    for(int i = 0; i < nn; ++i){
        temp.push_back(pl[i]);
        backtracking(n+1,nn,pl,res,temp);
        temp.pop_back();
    }
}
vector<vector<string>> solveNQueens(int n) {
    int nn = n;
    vector<string> temp;
    vector<vector<string>> res;
    vector<string> pl;
    //n==1单独列出来
    if(n==1){
        temp.push_back("Q");
        res.push_back(temp);
        return res;
    } else{
        for(int i = 0; i < n; ++i){
            string tmp;
            for(int j = 0; j < n; ++j){
                if(j == i)
                    tmp.push_back('Q');
                //一定要有else 否则会多一个.
                else
                    tmp.push_back('.');
                }
                pl.push_back(tmp);
        }
        backtracking(0,nn,pl,res,temp);
        return res;
    }
}
int main(){
    int n;
    cin>>n;
    vector<vector<string>> res;
    res =solveNQueens(n);
    for(int i=0;i<res.size(); ++i){
        for(int j=0;j<res[i].size(); ++j){
            cout<<res[i][j]<<endl;
        }
        cout<<endl;
    }
    return 0;
}
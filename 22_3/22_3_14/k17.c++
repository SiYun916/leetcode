#include <iostream>
#include <vector>
using namespace std;

//本题的主要思想是深度优先搜索，具体实现采用了回溯方法

//tmp用于存放深度遍历结束的结果
string tmp;
//result存放结果,hp存放数字对应的字母
vector<string> result;
vector<string> hp = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

//深度优先搜索
//pos表示深度，如果pos等于digits.size()的时候，说明深度已经达到最大，需要往回退
void DFS(int pos,string digits){
    //这里一定要注意,pos一定要等于digits.size()。如果是其减1，则深度是没到最大的。这里容易和数组遍历 0-digits.size()-1搞混
    if(pos == digits.size()){
        result.push_back(tmp);
        return ;
    }
    
    //num存放digits的一个数字，查找hp向量
    int num = digits[pos] - '0';
    //数字对应的每个字符都要加遍历一次
    for (int i = 0; i < hp[num].size(); ++i){
        //选择其中一个节点
        tmp.push_back(hp[num][i]);
        //向下
        DFS(pos + 1,digits);
        //回退
        tmp.pop_back();
    }
}
int main(){
    string digits;
    cin>>digits;
    if (digits.size() == 0)
        cout<<""<<endl;
    DFS(0,digits);
    for (int i = 0; i < result.size(); ++i){
        cout<<result[i]<<endl;
    }
    return 0;
}

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <map>
#include <algorithm>
using namespace std;
//今天这道题是自己做出来的 虽然时间复杂度和空间复杂度都不咋地
//但是我觉得我的思路和题解一样 可能代码写的有点复杂了
//答题思路：对一个复制的strs中每一项进行排序 这样同样字母的不同组合就相同了
//然后用一个hash表记录相同字符串的位置
//对每一个相同的字符串记录其原位置的串
vector<vector<string>> groupAnagrams(vector<string>& strs) {
        //返回结果
        vector<vector<string>> res;
        //用于保存复制的元素
        vector<string> s;
        //复制原字符串并对每一个进行排序
        for(int i = 0; i < strs.size(); ++i){
            s.push_back(strs[i]);
            sort(s[i].begin(),s[i].end());
        }
        //保存相同字符串的位置  这里用stack的原因是 我觉的在记录结果时判断为空和取值方便
        map<string,stack<int>> countSame;
        //记录相同字符串的位置
        for(int i = 0; i < s.size(); ++i){
            countSame[s[i]].push(i);
        }
        //记录结果
        for(auto &t : countSame){
            //临时string 用于记录某一字母异位词的所有字符串
            vector<string> tmp;
            //当位置不为空的时候，保存到tmp中
            while(!(t.second).empty()){
                tmp.push_back(strs[(t.second).top()]);
                (t.second).pop();
            }
            //记录完一个就加到结果里
            res.push_back(tmp);
        }
        return res;
}
int main(){
    int n;
    cin>>n;
    vector<string> strs(n);
    for(int i = 0; i < n; ++i){
        cin>>strs[i];
    }
    vector<vector<string>> result = groupAnagrams(strs);
    for(int i = 0; i < result.size(); ++i){
        for(int j = 0; j < result[i].size(); ++j){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
}









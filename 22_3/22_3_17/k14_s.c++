#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
//下面的方法是参考别人的思路
//将字符串大小排序
//只需要找出最大和最小字符串之间的差别就行
string longestCommonPrefix(vector<string>& strs) {
    if(strs.empty()) return "";
    //排序
    sort(strs.begin(),strs.end());
    //找出最大 最小字符串
    string st = strs.front();
    string en = strs.back();
    //定义遍历变量，
    int i; 
    int num = min(st.size(),en.size());
    for ( i = 0;i < num && st[i] == en[i]; ++i);
    return string(st,0,i);

    }
int main(){
    vector<string> tmp;
    int n;
    cin>>n;
    for ( int i = 0; i < n; ++i){
        string tt;
        cin>>tt;
        tmp.push_back(tt);
    }
    
    string res =  longestCommonPrefix(tmp);
    cout<<res<<endl;
    return 0;
}

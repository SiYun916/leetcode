#include <iostream>
#include <string>
#include <vector>
using namespace std;
//本人思路  暴力破解
//首先找出最小的字符串 记录其size大小
//按最小字符串的数量遍历
//设置一个flag记录公共字符串的数量
//在遍历的时候每次都要判断该字符是否时公共字符
//如果是 flag加1
//如果不是 推出两个循环  结束输出就行
//这种方法的复杂度为O(mn)  
string longestCommonPrefix(vector<string>& strs) {
        int str_min = INT32_MAX;
        for (int i = 0; i < strs.size(); ++i){
            if(str_min >= strs[i].size())
                str_min = strs[i].size();
        } 

        int flag = 0;
        string res;

        for (int i = 0; i < str_min; ++i){
            int ff = 1;
            for (int j = 1; j < strs.size(); ++j){
                if( strs[0][i] != strs[j][i]){
                    ff = 0;
                    break;
                }
            }
            if( ff == 1){
                flag += 1;
            }else{
                break;
            }
        }

        

        if( flag < 0) 
            return "";
        else{
            res = strs[0].substr(0,flag);
            return res;
        }


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

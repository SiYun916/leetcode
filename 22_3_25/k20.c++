#include <iostream>
#include <stack>
#include <string>
using namespace std;
//这道题 以前遇到过
//当时可能不是自己写的 这次自己做出来了 还是挺开心的
//因为之前见过一次 知道大体思路 所以这次主要写一点细节
//
//主要利用栈
//当是左括号的时候 进行压栈操作
//如果是右括号 则取出栈顶元素并pop 
//如果栈为空即无右括号 或者 取出的栈顶元素与左括号不匹配则说明是false
//当遍历完整个sring串后 如果栈中还有元素 说明左括号有剩余 也是false
//一定要注意括号多余的情况 我就是栽在这两种情况上才一开始没过
bool isValid(string s) {
    int i = 0;
    int n = s.size();
    stack<char> tmp;
    while(i < n){
        //左括号压栈
        if(s[i]=='(' || s[i]=='[' || s[i]=='{')
            tmp.push(s[i]);
        //右括号先进行栈空判断 然后进行是否匹配判断
        if(s[i]==')'){
            if(!tmp.empty()){
                char tt = tmp.top();
                tmp.pop();
                if(tt+1 != s[i])
                    return false;
            }else{
                return false;
            }
        }
        if(s[i]==']' || s[i]=='}'){
             if(!tmp.empty()){
                    char tt = tmp.top();
                    tmp.pop();
                    if(tt+2!=s[i])
                        return false;
                }else{
                    return false;
                }
        }
        i++;
    }
    //如果栈非空 说明有剩余的括号  不匹配
    if(!tmp.empty())
        return false;
    return true;
}
int main(){
    string s;
    cin>>s;
    bool res = isValid(s);
    cout<<res<<endl;
    return 0;
}

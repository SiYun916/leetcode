#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <stack>
#include <vector>
using namespace std;
//今天选了一个中等题，但对于我来说算是个简单题
//逆波兰表达式求值  直接使用栈就行
//遍历整个向量 当是数的时候就直接入栈 
//当是运算符号时 从栈顶取出第一和第二个值
//第二个值 加减乘除 第一个值  （一定要注意顺序，是第二个数减第一个）
//将结果压栈 
//重复上述步骤 直至循环结束
//栈中只剩下一个元素 就是结果
//对于我来说 这道题最大的难点是string转换成int
//参考了网上的方法 int a = atoi(s.c_str());
int evalRPN(vector<string>& tokens) {
        int result;
        stack<int> tmp;
        for(int i = 0; i < tokens.size(); ++i){
            int num1,num2,res;
            if(tokens[i]=="+"){
                num2 = tmp.top();
                tmp.pop();
                num1 = tmp.top();
                tmp.pop();
                res = num1 + num2;
                tmp.push(res);
            }else if(tokens[i]=="-"){
                num2 = tmp.top();
                tmp.pop();
                num1 = tmp.top();
                tmp.pop();
                res = num1 - num2;
                tmp.push(res);
            }else if(tokens[i]=="*"){
                num2 = tmp.top();
                tmp.pop();
                num1 = tmp.top();
                tmp.pop();
                res = num1 * num2;
                tmp.push(res);
            }else if(tokens[i]=="/"){
                num2 = tmp.top();
                tmp.pop();
                num1 = tmp.top();
                tmp.pop();
                res = num1 / num2;
                tmp.push(res);
            }else{
                int it = atoi(tokens[i].c_str());
                tmp.push(it);
            }
        }
        result = tmp.top();
        return result;
}
int main(){
    int n;
    cin>>n;
    vector<string> tokens;
    for(int i = 0; i < n; ++i){
        string tmp;
        cin>>tmp;
        tokens.push_back(tmp);       
    }   
    int result = evalRPN(tokens);
    cout<<result<<endl;
    return 0;
}
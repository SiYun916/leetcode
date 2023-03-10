#include <iostream>
#include <string>
#include <stack>
using namespace std;
/*
没思路，看了题解
可以用后缀表达式计算解决
输入一行式子，用两个栈来记录，一个栈记录数，一个栈记录运算符
1. 遇到数字直接压栈
2. 遇到运算符有两种情况如下：
    - 如果运算符栈为空，出不了栈，直接压栈
    - 如果运算符栈不为空，则需要先出栈，在把这个符号进栈
    
    那么，如何出栈？
        是否出栈需要先比较，比较谁？
        当前运算符和栈顶运算符
        a. 如果当前运算符优先级高，明显需要先计算当前运算符的计算，自然不需要出栈计算
        b. 如果当前运算符优先级小于等于栈顶，说明栈顶运算符可以先计算（或运算顺序不重要），则需要出栈运算，直至优先级高于栈顶或栈空
    ps：一定要注意最后，需要一直出栈到优先级高
*/
double  getNum(string &str,int &i){
    string number = "";
    for(;i<str.size();i++){
        if(str[i]>='0'&&str[i]<='9'||str[i]=='.')
            number += str[i];
        else{
            i--;
            break;
        }
    }
    return stod(number);
}


void calTmpRes(stack<double> &num,stack<char> &op){
    char opTmp = op.top();
    op.pop();
    double x = num.top();
    num.pop();
    double y = num.top();
    num.pop();
    double res;
    switch(opTmp){
        case '+': res = y + x;break;
        case '-': res = y - x;break;
        case '*': res = y * x;break;
        case '/': res = y / x;break;
        default: ;
    }
    num.push(res);
}
double calRes(string str){
    stack<double>   num;
    stack<char> op;
    for(int i = 0; i < str.size(); i++){
        if(str[i]=='+' || str[i]=='-'){
            while(!op.empty())
                calTmpRes(num,op);
            op.push(str[i]);
        }
        else if(str[i]=='*' || str[i]=='/'){
            while(!op.empty() && op.top()!='+' && op.top()!='-')
                calTmpRes(num,op);
            op.push(str[i]);
        }
        else
            num.push(getNum(str,i));
    }
    while(!op.empty())
        calTmpRes(num,op);

    return num.top();
}


int main(){
    int n;
    cin>>n;
    while(n--){
        string str;
        cin>>str;
        double result = calRes(str);
        printf("%.1f",result);
    }
    return 0;
}

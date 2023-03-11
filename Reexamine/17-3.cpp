#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
double getNum(int &i,string &opStr){
    string num = "";
    for(;i < opStr.size();i++){
        if(opStr[i] >='0' && opStr[i] <='9' || opStr[i] == '.')
            num += opStr[i];
        else{
            i--;
            break;
        }
    }
    return stod(num);
}

void calTmpStack(stack<double> &nums,stack<char> &op){
    double x,y,res;
    x = nums.top();
    nums.pop();
    y = nums.top();
    nums.pop();
    char oper = op.top();
    op.pop();
    switch(oper){
        case '+' : res = x + y; break;
        case '-' : res = y - x; break;
        case '*' : res = x * y; break;
        case '/' : res = y / x; break;
        default: ; 
    }
    nums.push(res);
}

double calResult(string opStr){
    stack<char> op;
    stack<double> nums;
    for(int i = 0; i < opStr.size(); i++){
        if(opStr[i] == '+' || opStr[i] == '-'){
            while(!op.empty())
                calTmpStack(nums,op);
            op.push(opStr[i]);
        }else if(opStr[i] == '*' || opStr[i] == '/'){
            while(!op.empty() && op.top()!='+' && op.top()!='-')
                calTmpStack(nums,op);
            op.push(opStr[i]);
        }else{
            nums.push(getNum(i,opStr));
        }
    }
    while(!op.empty())
        calTmpStack(nums,op);
    return nums.top();
}

int main(){
    vector<double>  res;
    int n;
    cin>>n;
    while(n--){
        string opStr;
        cin>>opStr;
        res.push_back(calResult(opStr));
    }
    for(int i = 0; i < res.size(); i++){
        printf("%.2f\n",res[i]);
    }
    return 0;
}


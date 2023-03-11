#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
bool judgePar(string str){
    stack<char> tmp;
    int i;
    for(i = 0; i < str.size(); i++){
        if(str[i] == '{' || str[i] == '[' || str[i] =='(')
            tmp.push(str[i]);
        if(str[i] == '}'){
            if(tmp.empty())
                break;
            char x = tmp.top();
            if(x!='{')
                break;
            else
                tmp.pop();
        }else if(str[i] == ']'){
            if(tmp.empty())
                break;
            char x = tmp.top();
            if(x!='[')
                break;
            else
                tmp.pop();
        }else if(str[i] == ')'){
            if(tmp.empty())
                break;
            char x = tmp.top();
            if(x!='(')
                break;
            else
                tmp.pop();
        }
    }
    if(i!=str.size() || !tmp.empty())
        return false;
    else
        return true;
}

int main(){
    int n;
    cin>>n;
    vector<bool> result;
    while(n--){
        string str;
        cin>>str;
        result.push_back(judgePar(str));
    }
    for(int i = 0; i < result.size();i++){
        if(result[i])
            cout<<"yes"<<endl;
        else
            cout<<"no"<<endl;
    }
    return 0;
}
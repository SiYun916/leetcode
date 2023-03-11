#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<bool> judge(int n){
    vector<bool> res;
    while(n--){
        string str;
        cin>>str;

        stack<char> tmp;

        int i;
        for(i = 0; i <str.size(); i++){
            //zuo kuo hao ya zhan
            //bu shi zuo kuo hao bu yong guan
            if(str[i] == '(' || str[i] == '[' || str[i] == '{')
                tmp.push(str[i]);
            //yu dao yi ge you kuo hao jiu chu zhan
            if(str[i] == ')'){
                if(tmp.empty()){
                    res.push_back(false);
                    break;
                }
                char x = tmp.top();
                if(x == '(')
                    tmp.pop();
                else{
                    res.push_back(false);
                    break;
                }
            }
            if(str[i] == ']'){
                if(tmp.empty()){
                    res.push_back(false);
                    break;
                }
                char x = tmp.top();
                if(x == '[')
                    tmp.pop();
                else{
                    res.push_back(false);
                    break;
                }
            }
            if(str[i] == '}'){
                if(tmp.empty()){
                    res.push_back(false);
                    break;
                }
                char x = tmp.top();
                if(x == '{')
                    tmp.pop();
                else{
                    res.push_back(false);
                    break;
                }
            }
        }
        if(tmp.empty() && i==str.size())
            res.push_back(true);
    }
    return res;
}
int main(){
    int n;
    cin>>n;
    vector<bool> res = judge(n);
    for(int i = 0; i < res.size(); i++){
        if(res[i])
            cout<<"yes"<<endl;
        else
            cout<<"no"<<endl;
    }
    return 0;
}
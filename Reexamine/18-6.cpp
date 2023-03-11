#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<bool> judge(int n,vector<string> arrs){
    vector<bool> result;
    for(int i = 1; i < arrs.size(); i++){
        int j;
        for(j = 0; j < arrs[i].size()/2; j++){
            if(arrs[i][j] != arrs[i][arrs[i].size()-1-j]){
            result.push_back(false);
            break;
            }
        }
        if(j == arrs[i].size()/2)
            result.push_back(true);
    }
    return result;
}
int main(){
    int n;
    cin>>n;
    vector<string> arrs;
    for(int i = 0; i < n+1; i++){
        string arr;
        getline(cin,arr);
        arrs.push_back(arr);
    }
    vector<bool> res = judge(n,arrs);
    for(int i = 0; i < res.size(); i++){
        if(res[i])
            cout<<"yes"<<endl;
        else
            cout<<"no"<<endl;
    }
    return 0;
}

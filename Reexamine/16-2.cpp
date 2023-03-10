#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> sortArr(int n,int m){
    vector<vector<int>> result;
    for(int i = 0; i < n; i++){
        vector<int> tmp;
        for(int j = 0; j < m; j++){
            int num;
            cin>>num;
            tmp.push_back(num);
        }
        sort(tmp.begin(),tmp.end());
        result.push_back(tmp);
    }
    return result;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> result = sortArr(n,m);
    for(int i = 0; i < result.size(); i++){
        for(int j = 0; j < result[i].size(); j++){
            cout<<result[i][j]<<' ';
        }
        cout<<endl;
    }
    return 0;   
}
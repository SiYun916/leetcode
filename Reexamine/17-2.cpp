#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> sortArr(int n){
    vector<vector<int>> result;
    for(int i = 0; i < n; i++){
        vector<int> arr;
        int tmpnum;
        while(cin>>tmpnum){
            arr.push_back(tmpnum);
            if(cin.get()=='\n')  break;
        }
        sort(arr.begin(),arr.end());
        reverse(arr.begin(),arr.end());
        result.push_back(arr);
    }
    return result;
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>> result = sortArr(n);
    for(int i = 0; i < result.size(); i++){
        for(int j = 0; j < result[i].size(); j++)
            cout<<result[i][j]<<' ';
        cout<<endl;
    }
    return 0; 
}


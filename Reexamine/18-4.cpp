#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<vector<int>> sortArr(int n,int m){
    vector<vector<int>> res;
    while(n--){
        vector<int> tmpArr;
        for(int i = 0; i < m; i++){
            int num ;
            cin>>num;
            tmpArr.push_back(num);
        }
        sort(tmpArr.begin(),tmpArr.end());
        res.push_back(tmpArr);
    }
    return res;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> result = sortArr(n,m);
    for(int i = 0; i < result.size(); i++){
        for(int j = 0; j < result[i].size(); j++)
            cout<<result[i][j]<<' ';
        cout<<endl;
    }
    return 0;
}



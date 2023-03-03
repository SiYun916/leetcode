#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> transferBit(int num){
    vector<int> result;
    int tmpnum = num;
    int res = 0;
    while(tmpnum){
        res = tmpnum % 2;
        tmpnum = tmpnum / 2;
        result.push_back(res);
    }
    return result;
}

int main(){
    int num;
    cin>>num;
    vector<int> result = transferBit(num);
    reverse(result.begin(),result.end());
    for(int i = 0; i < result.size(); i++){
        cout<<result[i];
    }
    return 0;
}
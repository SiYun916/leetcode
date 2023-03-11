#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
//getline(cin,str) 
//huo qu dai kong ge de zi fu chuan
vector<string>  calRev(int n){
    vector<string>  res;
    n = n + 1;
    while(n--){
        string arr;
        getline(cin,arr);        
        reverse(arr.begin(),arr.end());
        res.push_back(arr);
    }
    return res;
}

int main(){
    int n;
    cin>>n;
    vector<string> result = calRev(n);
    for(int i = 0; i < result.size(); i++){
        cout<<result[i]<<endl;
    }
    return 0;
}




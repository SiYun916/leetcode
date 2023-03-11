#include <iostream>
#include <vector>
using namespace std;
vector<int> calSum(int n){
    vector<int> res;
    for(int i = 0; i < n; i++){
        int x,y;
        cin>>x>>y;
        res.push_back(x*y);
    }
    return res;
}



int main(){
    int n;
    cin>>n;
    vector<int> result = calSum(n);
    for(int i = 0; i < result.size(); i++)
        cout<<result[i]<<endl;
}
#include <iostream>
#include <vector>
using namespace std;

vector<int> calX(int n){
    vector<int> res;
    while(n--){
        int tmp;
        int X = 1;
        cin>>tmp;
        for(int i = 1; i <= tmp; i++)
            X = X * i;
        res.push_back(X);
    }
    return res;
}


int main(){
    int n;
    cin>>n;
    vector<int> result = calX(n);
    for(int i = 0; i < result.size(); i++)
        cout<<result[i]<<endl;
    return 0;
}

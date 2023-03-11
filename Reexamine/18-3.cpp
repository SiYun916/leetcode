#include <iostream>
#include <vector>
using namespace std;
int calSelect(int top,int bottom){
    int res = 1;
    for(int i = top; i >= top-bottom+1; i--)
        res = res * i;
    for(int i = 1; i <= bottom ; i++)
        res = res / i;
    return res;
}



int main(){
    int n,m;
    cin>>n>>m;
    int result = calSelect(n,m);
    cout<<result<<endl;
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
int main(){
    int a,b,c;
    cin>>a>>b>>c;
    int minNum = a;
    if(b < minNum)
        minNum = b;
    if(c < minNum)
        minNum = c;
    cout<<minNum<<endl;
}
*/
int main(){
    int tmp;
    vector<int> nums;
    while(cin>>tmp){
        nums.push_back(tmp);
        if(cin.get() == '\n') break;
    }
    int minNum = *min_element(nums.begin(),nums.end());
    cout<<minNum<<endl;
    return 0;
}
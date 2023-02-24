#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    while(n--){
        int tmp;
        vector<int> arr;
        while(cin>>tmp){
            arr.push_back(tmp);
            if(cin.get()=='\n') break;
        }
        sort(arr.begin(),arr.end());
        int i = 0;
        for(i = 0; i < arr.size()-1; i++)
            cout<<arr[i]<<" ";
        cout<<arr[i]<<"\n";
    }
    return 0;
}

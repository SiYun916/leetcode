#include <iostream>
#include <vector>
using namespace std;
int main(){
    int tmp;
    vector<int> arr;
    while(cin>>tmp){
        arr.push_back(tmp);
        if(cin.get()=='\n') break;}
    /*
    for(int i = 0; i < arr.size(); i++){
        for(int j = 1; j < arr.size()-i; j++){
            if(arr[j] <= arr[j-1]){
                swap(arr[j],arr[j-1]);
            }
        }
    }
    */
    for(int i = 0; i < arr.size(); i++){
        for(int j = i + 1; j < arr.size(); j++){
            if(arr[i] >= arr[j])
                swap(arr[i],arr[j]);
        }
    }

    for(int i = 0; i < arr.size(); i++){
        cout<<arr[i]<<" ";
    }
    
    return 0;
}

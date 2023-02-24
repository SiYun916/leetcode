#include <iostream>
#include <vector>
using namespace std;
int main(){
    //input
    int arr1Num = 0, arr2Num = 0;
    vector<int> arr1,arr2;
    cin>>arr1Num;
    for(int i = 0; i < arr1Num; i++){
        int tmp;
        cin>>tmp;
        arr1.push_back(tmp);
    }
    cin>>arr2Num;
    for(int i = 0; i < arr2Num; i++){
        int tmp;
        cin>>tmp;
        arr2.push_back(tmp);
    }
    //sort 
    //new arr
    vector<int> arr3;
    int i = 0, j = 0;
    while(i < arr1Num && j < arr2Num){
        if(arr1[i] <= arr2[j]){
            arr3.push_back(arr1[i]);
            i++;
        }
        else{
            arr3.push_back(arr2[j]);
            j++;
        }
    }
    while(i < arr1Num){
        arr3.push_back(arr1[i]);
        i++;
    }
    while(j < arr2Num){
        arr3.push_back(arr2[j]);
        j++;
    }
    
    //output
    for(int k = 0; k < arr1Num+arr2Num; k++){
        cout<<arr3[k]<<endl;
    }
   //old arr1 
   //保存在原数组中是基于特定条件的，比如给的arr1的空间是两个arr之和
   //这时候就要考虑从后往前双指针   后面是空的，所以从后往前

    return 0;
}

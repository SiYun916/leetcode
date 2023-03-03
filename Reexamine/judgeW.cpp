#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> recordY(int num){
    int mid = num / 2;
    vector<int> result;
    for(int i = 1; i <= mid; i++){
        if(num%i == 0)
            result.push_back(i);
    }
    return result;
}

int calSum(int num){
    int result = 0;
    vector<int> tmp = recordY(num);
    for(int i = 0; i < tmp.size(); i++){
        result += tmp[i];
    }
    return result;
}

int main(){
    for(int i = 1;i <= 1000;i++){
        if(i == calSum(i)){
            cout<<i<<"=";
            vector<int> recordNum = recordY(i);
            for(int j = 0; j < recordNum.size();j++){
                cout<<"+"<<recordNum[j];
            }
            cout<<endl;
        }
    }
    return 0;
}
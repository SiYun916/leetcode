#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> countAveTime(int n){
    vector<vector<int>> result;
    for(int i = 0;i < n; i++){
        vector<int> tmp;
        int fmin,fs,fms,smin,ss,sms,tmin,ts,tms;
        cin>>fmin>>fs>>fms>>smin>>ss>>sms>>tmin>>ts>>tms;
        int sum = (60000*(fmin+smin+tmin)+1000*(fs+ss+ts)+(fms+sms+tms))/3;
        int resMin = sum / 60000;
        int ret = sum % 60000;
        int resS = ret / 1000;
        int resMs = ret % 1000;
        tmp.push_back(resMin);
        tmp.push_back(resS);
        tmp.push_back(resMs);
        result.push_back(tmp);
    }
    return result;
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>> result = countAveTime(n);
    for(int i = 0; i < result.size(); i++){
        for(int j = 0; j < result[i].size(); j++){
            cout<<result[i][j]<<' ';
        }
        cout<<endl;
    }
    return 0;
}
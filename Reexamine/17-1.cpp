#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

vector<vector<int>> calAveTime(){
    vector<vector<int>> result;
    for(int i = 0; i < 2; i++){
        int h1,h2,m1,m2,s1,s2;
        vector<int> timeTmp;
        cin>>h1>>m1>>s1>>h2>>m2>>s2;
        if(abs(h1-h2) < 2){
        int timeSum = (3600*(h1+h2) + 60*(m1+m2) + s1+s2) / 2;
        int hour = timeSum / 3600;
        int ret = timeSum % 3600;
        int minutes = ret / 60;
        int s = ret % 60;
        timeTmp.push_back(hour);
        timeTmp.push_back(minutes);
        timeTmp.push_back(s);
        }else{
            if(h1==0){
                h1 = 12;
                int timeCha = (3600*(h1-h2) + 60*(m1-m2) + s1-s2) / 2;
                int timeMin = h2*3600 + 60*m2 + s2;
                int timeSum = timeMin + timeCha;
                int hour = timeSum / 3600;
                int ret = timeSum % 3600;
                int minutes = ret / 60;
                int s = ret % 60;
                if(hour>11)
                    hour = 0;
                timeTmp.push_back(hour);
                timeTmp.push_back(minutes);
                timeTmp.push_back(s);
            }
            else{
                h2 = 12;
                int timeCha = (3600*(h2-h1) + 60*(m2-m1) + s2-s1) / 2;
                int timeMin = h1*3600 + 60*m1 + s1;
                int timeSum = timeMin + timeCha;
                int hour = timeSum / 3600;
                int ret = timeSum % 3600;
                int minutes = ret / 60;
                int s = ret % 60;
                if(hour>11)
                    hour = 0;
                timeTmp.push_back(hour);
                timeTmp.push_back(minutes);
                timeTmp.push_back(s);
            }
        }
        result.push_back(timeTmp);
    }
    return result;
} 

int main(){
    vector<vector<int>> result = calAveTime();
    for(int i = 0; i < result.size(); i++){
        for(int j = 0; j < result[i].size(); j++)
            cout<<result[i][j]<<' ';
        cout<<endl;
    }
    return 0;   
}
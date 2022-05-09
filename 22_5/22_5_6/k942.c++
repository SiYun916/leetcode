#include<iostream>
#include<string>
#include<vector>
using namespace std;
//这道题读了半天才读懂
//翻译成人话就是 如果遇到I后面的数比前面的数大 如果遇到D后面的数比前面的数小
//贪心加双指针（虽然我一开始不知道叫什么，但思路就是这样的）
//遇到I就输入当前最小的值这样就能保证无论后一个是什么都比前一个大
//遇到D就输入当前最大的值这样就能保证后一个比前一个小
//所以每次选择都是局部最优值 这就是贪心
vector<int> diStringMatch(string s) {
        vector<int> result;
        int minNum = 0;
        int maxNum = s.length();
        for(int i = 0; i < s.length(); ++i){
            if(s[i]=='I'){
                result.push_back(minNum);
                minNum++;
            }
            else{
                result.push_back(maxNum);
                maxNum--;
            }
        }
        result.push_back(maxNum);
        return result;
}
int main(){
    string s;
    cin>>s;
    vector<int> result = diStringMatch(s);
    for(int i = 0; i < result.size();i++){
        cout<<result[i]<<" ";
    }
    cout<<endl;
    return 0;
}

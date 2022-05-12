#include<iostream>
#include<string>
#include<vector>
using namespace std;
//好吧 直接模拟 按照给的要求直接写列字符串
//在记录列字符串的同时判断前后大小关系
//如果不符合 ans+1提前终止
int minDeletionSize(vector<string>& strs) {
        int rowNum = strs.size();
        int colNum = strs[1].length();
        int ans = 0;
        vector<string> cstrs(colNum,"");
        for(int col = 0; col < colNum; col++){
            for(int row = 0; row < rowNum; row++){
                cstrs[col] += strs[row][col];
                if(row>=1&&cstrs[col][row]<cstrs[col][row-1]){
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
int main(){
    int n;
    cin>>n;
    vector<string> strs(n);
    for(int i = 0; i < n; ++i){
        cin>>strs[i];
    }
    int res = minDeletionSize(strs);
    cout<<res<<endl;
    return 0;
}
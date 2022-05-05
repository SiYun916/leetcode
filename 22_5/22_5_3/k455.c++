#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
//这道题 虽然我不知道方法的名字
//但是自己写出来了  看了题解才知道是贪心
//我的思路就是 先把两个数组排序
//从最少需求的人开始  找到一个能满足他需求的最小的饼干
//找到了就记录 然后找下一个人的
//如果找到最后也没找到 就跳出循环
int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int glens = g.size();
        int slens = s.size();
        int i = 0,j = 0;
        int res = 0;
        while(i < glens){
            while(j < slens&&g[i] > s[j]){
                j++;
            }
            if(j>=slens)
                break;
            i++;
            j++;
            res++;
        }
        return res;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> g(n);
    vector<int> s(m);
    for(int i = 0; i < n; i++){
        cin>>g[i];
    }
    for(int j = 0; j < m; j++){
        cin>>s[j];
    }
    int result = findContentChildren(g,s);
    cout<<result<<endl;
    return 0;
}

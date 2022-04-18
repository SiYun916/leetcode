#include<iostream>
#include<vector>
using namespace std;
//这道题属实是没有难度 我写的代码有点复杂而且不知道方法名字
//这里仅简化下代码
//这里用到了双指针  虽然我不知道它 但是我的思路和它一样
//交换时我用了一个tmp来存储 有点多此一举 因为c++有swap函数
//并且我又学了for中的一种形式
//
//好吧好吧 今天的题有点简单了  有点摆  
//明天写个难点得
void reverseString(vector<char>& s){
    int n = s.size();
    for(int left=0,right=n-1;left<right;left++,right--){
        swap(s[left],s[right]);
    }
}
int main(){
    int n;
    cin>>n;
    vector<char> s(n);
    for(int i = 0 ; i < n;i++){
        cin>>s[i];
    }
    reverseString(s);
    for(int i=0;i<n;i++){
        cout<<s[i]<<" ";
    }
    cout<<endl;
    return 0;
}

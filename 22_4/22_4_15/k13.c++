#include <iostream>
#include <stack>
#include <algorithm>
#include <string>
using namespace std;
//按照我自己思路是 从后往前看 到最大数位前都是加 一旦前面的小于后面的 就开始减
//所以我就想到了栈 先转换的数据最后才加或减到结果里面  
//直接贴代码  由于这种方法的空间复杂度太高 所以我看了题解的方法 写在下个代码里
int romanToInt(string s) {
        stack<int> nums;
        int mnum = 0;
        int res = 0;
        for(int i = 0; i <s.length();i++){
            switch(s[i]){
                case 'I':nums.push(1);break;
                case 'V':nums.push(5);break;
                case 'X':nums.push(10);break;
                case 'L':nums.push(50);break;
                case 'C':nums.push(100);break;
                case 'D':nums.push(500);break;
                case 'M':nums.push(1000);break;
                default : ;
            }
        }
        while(!nums.empty()){
            if(nums.top()>=mnum){
                res += nums.top();
                mnum = nums.top();
            }else{
                res -= nums.top();
            }
            nums.pop();
        }
        return res;
}
int main(){
    string s;
    cin>>s;
    int result = romanToInt(s);
    cout<<result<<endl;
    return 0;
}

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
//这次直接从前往后看  如果前面是递增的 结果就是减  如果是递减 结果就是加
//这里怎么判断前后谁大呢   
//这里就需要两个数 一个数记录前面 一个数记录后面
//如果前面的数大就加上 如果前面的数小 结果就减
int getnum(char sc){
        switch(sc){
            case 'I':return 1;break;
            case 'V':return 5;break;
            case 'X':return 10;break;
            case 'L':return 50;break;
            case 'C':return 100;break;
            case 'D':return 500;break;
            case 'M':return 1000;break;
            default : return 0;
            }
    }
int romanToInt(string s) {
        int prenum = getnum(s[0]);
        int res = 0;
        for(int i = 1; i < s.length();i++){
            int cur = getnum(s[i]);
            if(cur > prenum){
                res -= prenum;
            }else{
                res += prenum;
            }
            prenum = cur;
        }
        res += prenum;
        return res;
}
int main(){
    string s;
    cin>>s;
    int res = romanToInt(s);
    cout<<res<<endl;
    return 0;
}

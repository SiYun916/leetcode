#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
//这道题用模拟的方法来做 让我想到了大一时候的大数加减法也是模拟加减法 直接得到字符
//一开始我的思路是直接将两个数换成10进制整数然后相加在转换成二进制数
//但是即使long long存储两数相加结果 也是报溢出的错误
//所以我就觉得要用模拟的方法
//
//模拟的方法做了好久 思路不难 但是细节有点多
//下面主要说下易错点
//1. 首先需要一个c 来保存进位
//2. 结果要先设一个空串 方便往后面加数
//3. 两个字符串由于长度不相等 所以首先找出小的串 按照小串的长度 一个一个遍历相加
//4. 遍历完小串后 接着遍历大串 这里也需要有个进位c来记录
//5. 由于我们一开始不知道哪个是小串  需要比较长度后 再选择串
//6. 如果最后一位也有进位 即最后c=1 则需要额外加个1
//7. 结果需要反转
string addBinary(string a, string b) {
        char c = '0';
        int alen = a.length();
        int blen = b.length();
        int minlen = min(alen,blen);
        int maxlen = max(alen,blen);
        int xx = maxlen - minlen;
        string res = "";
        for(int i = minlen-1; i >= 0;i--){
            int j = i + xx;
            int sumnum;
            //因为不知道ab哪个长 所以需要比较后才能确定a的索引是i还是b的索引是i
            if(alen<blen)
                sumnum = (c - '0') + (a[i] - '0') + (b[j] - '0');
            else
                sumnum = (c - '0') + (a[j] - '0') + (b[i] - '0');
            if(sumnum <= 1){
                c = '0';
                if(sumnum==1)
                    res = res + '1';
                else
                    res = res + '0';
            }else{
                c = '1';
                sumnum = sumnum%2;
                if(sumnum==1)
                    res = res + '1';
                else
                    res = res + '0';
            }
        }
        //遍历长串的高位
        for(int i = maxlen-minlen-1; i >=0;i--){
            int sumnum = c - '0' + b[i] - '0';
            if(alen<blen)
                sumnum = c - '0' + b[i] - '0';
            else
                sumnum = c - '0' + a[i] - '0';
            if(sumnum <= 1){
                c = '0';
                if(sumnum==1)
                    res = res + '1';
                else
                    res = res + '0';
            }else{
                c = '1';
                sumnum = sumnum%2;
                if(sumnum==1)
                    res = res + '1';
                else
                    res = res + '0';
            }
        }
        //最后一位是否进位了
        if(c=='1')
            res += '1';
        //反转结果
        reverse(res.begin(),res.end());
        return res;
}
int main(){
    string a,b;
    cin>>a>>b;
    string res = addBinary(a,b);
    cout<<res<<endl;
    return 0;
}

#include <iostream>
#include <vector>
#include <string>
using namespace std;
//我先抒发一下 内心波涛汹涌的感情
//wdnmd 这什么勾八破头 草了 爷自己写的 结果一摸一样过不了 我真的日了狗了

//抒发结束 下面写题解思路
//我自己的思路就不说了，什么勾八  附上自己写的代码 看不看无所谓
//当numRows=1时情况就不说了 单列出来就好了
//大体思想就是采用模拟的方法，遍历整个s串，每个字符放到对应的位置
//我们可以看出 它是一个从上到下 又从下到上 填入的过程
//在两头的时候需要反向 这里就用到了一个flag来实现
//从上到下的时候flag为1 每次string下标都加1
//同理 从下到上的时候flag为-1 
//实现反向只需要一次判断就好
//最终结果是每行串连起来
string convert(string s , int numRows){
    if(numRows == 1)
        return s;
    else {
        vector<string> tmp(numRows);
        int i = 0;
        //设置标志位 从0开始 根据反向判断 一开始要反向  所以设为-1
        int flag = -1;
        for ( char &a : s){
            //对应行 储存对应的字符
            tmp[i] += a;
            //判断是否该反向
            if(i == 0 || i == numRows - 1){
                flag = -flag;
            }
            i += flag;
        }
        string res;
        for (int i = 0; i < numRows; i++){
            res += tmp[i];
        }
        return res;
    }

}
int main(){
    int num;
    string s;
    cin>>s;
    cin>>num;
    string output = convert(s,num);
    cout<<output<<endl;
    return 0;
}


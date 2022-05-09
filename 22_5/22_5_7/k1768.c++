#include<iostream>
#include<string>
using namespace std;
//这道题简单 但是想复杂了 想到了双指针发现不太好写出来
//其实单指针就可以 在两个串都没到其最大长度前 每次两个串各放一个
//这里我把string也想复杂了  
//我以为string res;  在用res[i]时是不合法的，而且string res(n)也是不合法的
//所以无法用string只能用char
//但是我忽略了string可以直接在后面+字符
string mergeAlternately(string word1, string word2) {
        int w1Size = word1.length();
        int w2Size = word2.length();
        string res;
        for(int i = 0; i < w1Size || i < w2Size;i++){
            if(i<w1Size){
                res += word1[i];
            }
            if(i<w2Size){
                res += word2[i];
            }
        }
        return res;
    }
int main(){
    string word1,word2;
    cin>>word1;
    cin>>word2;
    string res = mergeAlternately(word1,word2);
    cout<<res<<endl;
    return 0;
}
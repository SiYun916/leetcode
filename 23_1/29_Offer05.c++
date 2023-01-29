#include <iostream>
#include <string>
using namespace std;

//The main problem is that how to append char after a string
//1. use string.append(int n,char a) n represents how many times the char a repeat  
//2. use string.push_back()
//and use string.append(str) to append a string to another string
class Solution{
    public:
        string result;
        string replaceSpace(string s){
            for(int i = 0; i < s.size(); i++){
                if(s[i]==' '){
                    result.append("%20");
                }
                else{
                    result.push_back(s[i]);
                }
            }
            return result;
        }
};

int main(){
    string str = "We are happy";
    Solution* obj = new Solution();
    string res = obj->replaceSpace(str);
    cout<<res<<endl;
    return 0;
}

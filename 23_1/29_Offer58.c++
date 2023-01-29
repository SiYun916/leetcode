#include <iostream>
#include <string>
using namespace std;
class Solution{
    public:
    string reverseLeftWords(string s, int n){
        return s.substr(n,s.size())+s.substr(0,n);
    }
};
int main(){
    string s = "abcdefg";
    int k = 2;
    Solution* obj = new Solution();
    string result = obj->reverseLeftWords(s,k);
    cout<<result<<endl;
    return 0;
}

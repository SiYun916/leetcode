#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
//hashmap两遍遍历
class Solution{
    public:
    char firstUniqChar(string s){
        unordered_map<char,int> hashMap;
        for(char c : s){
            hashMap[c]++;
        }
        for(char c : s){
            if(hashMap[c] == 1)
                return c;
        }
        return ' ';
    }
};

int main(){
    char res1,res2;
    string s1 = "aa";
    string s2 = "leetcode";
    Solution* obj = new Solution();
    res1 = obj->firstUniqChar(s1);
    res2 = obj->firstUniqChar(s2);
    cout<<"aa result is "<<res1<<endl;
    cout<<"leetcode result is "<<res2<<endl;
    return 0;
}

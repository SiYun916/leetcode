#include <iostream>
#include <string>
#include <map>
using namespace std;

//大体思路：采用滑动窗口的模式，通过窗口的扩张和收缩选取最小的范围
//使用两个指针，left和right。right用于扩张，left用于收缩。
//窗口变化的时候，每次更新最小len以及开始位置

int main(){
    //输入s,t
    string s,t;
    cin>>s;
    cin>>t;
    //定义hashmap，存储目的字符串中的字母q及其个数
    map<char,int> hashmap_t;
    //遍历t，填充hashmap_t。map 默认int value初始值为0，所以可以直接加加。
    for (auto a : t)
        hashmap_t[a]++;
    //从零开始遍历
    int left = 0;
    int right = 0;
    //定义最大长度以及初始位置
    int len = INT32_MAX;
    int startPlace = -1;
    //定义距离目标字符串的长度
    int count = t.size();
    //再窗口右指针遍历完字符串之前
    while (right < s.size()){
        //如果s串中，该位置的字符是t中的目标字符之一，意味着离目标串近了一步，count--
        if(hashmap_t[s[right]] > 0)
            count--;
        //更新hashmap_t的中的值和right，准备下一次的循环。这个更新要注意，一开始我写在了if里面，是不对的，思路不清晰 ！！
        hashmap_t[s[right]]--;
        right++;
        //如果窗口包含了t的所有字符，将窗口缩小，判断是否还可以进一步压缩窗口
        while(count == 0){
            //更新窗口起始位置以及大小
            if(right - left < len){
                len = right -left;
                startPlace = left;
            }
            //如果因left右移，导致原来有的t中的字符被抛弃，那么说明里目标要远一步，count需要更新
            if(hashmap_t[s[left]] == 0)
                count++;
            //如果left右移对于目标没有影响，更新left位置
            hashmap_t[s[left]]++;
            left++;
        }

    }
    //输出结果
    if(startPlace == -1) 
        cout<<""<<endl;
    else
        cout<<s.substr(startPlace,len)<<endl;
}

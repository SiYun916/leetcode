#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
using namespace std;

int main(){
    //输入num 以及 k
    string num;
    int k;
    cin>>num>>k;
    //创建一个栈，用于存放挑选的数字
    stack<char> nn;
    //用num_length代替num.size()
    int num_length = num.size();
    /*第一种情况 当k>=num.size时，返回值为'0'*/
    if(num_length <= k)
        cout<<"0"<<endl;
    /*第二种情况*/
    for(int i = 0; i < num_length; i++){
        //临时变量，保存当前位的数字
        char tmp = num[i];
        //考虑什么时候出栈要比进栈简单点
        //如果 当前栈非空 且 k>0即没有删除完 且 新来的数字要小于原来的数字 时出栈 换句话说就是删除该数
        while(k > 0 && !nn.empty() && nn.top() > tmp){
            nn.pop();
            k--;
        }
        //下面排除首位是0的影响
        //在不出栈的情况下 当 数为非零 或者 不是第一位的时候 数进栈
        if(tmp != '0' || nn.size() != 0)
            nn.push(tmp);
    }
    
    if(nn.empty())
        cout<<"0"<<endl;

    //下面就是10001 4 示例需要注意的地方，如果栈为空的话，就不能再pop了
    while (k > 0 && !nn.empty()){
        nn.pop();
        k--;
    }
    
    if(nn.empty())
        cout<<"0"<<endl;
    
    string num_f;
    for (int i = nn.size(); i >= 0; i--){
        num_f.append(1,nn.top());
        nn.pop();
    }
    reverse(num_f.begin(),num_f.end());
    cout<<num_f;
}



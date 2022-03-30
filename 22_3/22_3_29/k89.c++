#include <iostream>
#include <vector>
using namespace std;
//格雷编码 之前专业课的时候听过但早就忘记了
//要想写出这道题 首先要了解格雷编码的构造方式
//百度百科上其实对于格雷码的生成有许多介绍 可以尝试下去一个个实现
//这里主要讲下对称生成的思路
//通过观察（我其实一开始并没观察出来） 我们可以找到规律对于n的格雷码其实是依赖于n-1的
//n的格雷码的前半部分可以有n-1全体的格雷码最前面加一个0构成  其实是一个都没变得
//下面主要介绍后半部分
//在n-1全体格雷码前加一个1 我们可以发现两两之间也是满足条件得
//但是如果直接添加到后面  我们会发现 中间位置两个不满足条件
//如果后面序列反转一下  就保证了中间两个满足条件
//思路就是这样  
//具体实现得细节再说
vector<int> grayCode(int n){
    vector<int> res;
    //n=0的时候特殊情况
    res.push_back(0);
    //采用迭代的方法 n从1开始每次都保存 所以算n的时候就可以直接用n-1的结果了
    for(int i = 1; i <= n; ++i){
        int m = res.size();
        //选取n-1的最后一项 最前面添1后放入结果 依次向前
        //添1 即加上2^(n-1)  可以用或来代表加
        for(int j = m - 1; j >= 0; --j){
            res.push_back(res[j]|1<<(i-1));
        }
    }
    return res;
}
int main(){
    int n;
    cin>>n;
    vector<int> result;
    result = grayCode(n);
    for(int i = 0; i < result.size(); ++i){
        cout<<result[i]<<" ";
    }
    return 0;
}

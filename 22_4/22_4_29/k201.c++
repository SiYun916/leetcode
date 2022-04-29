#include <iostream>
using namespace std;
//这道题 除了暴力我就想不出来别的办法了但很明显暴力是超时的
//所以
//我看了题解  看题解分析才知道是求最大最小数公共序列前缀
//至于为什么是最大最小数  在我看来 最大最小数 理论上是相差最多的
//只要保证他们两个的最前面的数相同 其他的自然也就相同
//题解用了两种方法 这里写一起了
//方法一：位移
//将两个数字不断向右移动，直到数字相等，即数字被缩减为它们的公共前缀。然后，通过将公共前缀向左移动，将零添加到公共前缀的右边以获得最终结果。
 int rangeBitwiseAnd1(int left, int right) {
        int shnum = 0;
        while(left < right){
            left = left >> 1;
            right = right >> 1;
            shnum++;
        }
        return left <<shnum;
}
//方法二：Brian Kernighan 算法
//我们每次对number 和number−1 之间进行按位与运算后，number 中最右边的 1 会被抹去变成 0
//当最大最小两个值不等时  一直抹去大值的最右边的1
//直到相等
//所求得的既是公共前缀
int rangeBitwiseAnd2(int left, int right) {
        while(left < right){
            right = right & (right - 1);
        }
        return right;
}
int main(){
    int n,m;
    cin>>n>>m;
    int res1 = rangeBitwiseAnd1(n,m);
    int res2 = rangeBitwiseAnd2(n,m);
    cout<<"res1:"<<res1<<endl;
    cout<<"res2:"<<res2<<endl;
    return 0;
}


#include <iostream>
#include <vector>
using namespace std;
//只能说  我真的就不会dp 我一定要找一个时间 系统学习一下
//思路明显 2*(1/2/3...)  3*(1/2/3...) 5*(1/2/3...) 中选最小的   明显不对  
//寄  理解错了  比如35 就不满足
//实际上是3个指针 每次取最小的一个
int nthUglyNumber(int n) {
        vector<int> dp(n+1);
        dp[1] = 1;
        int p2 = 1, p3 = 1, p5 =1;
        for(int i = 2; i <= n; i++){
            int num1 = dp[p2]*2, num2 = dp[p3]*3,num3 = dp[p5]*5;
            dp[i] = min(min(num1,num2),num3);
            //下边是看谁最小  最小的一个 系数加一
            if(dp[i]==num1)
                p2++;
            if(dp[i]==num2)
                p3++;
            if(dp[i]==num3)
                p5++;
        }
        return dp[n]; 
}
int main(){
    int n;
    cin>>n;
    int res = nthUglyNumber(n);
    cout<<res<<endl;
    return 0;
}

#include <iostream>
using namespace std;
//官解 一个很巧妙的方法是使用了迭代
//对于一个y=pow(x,n)来说  y可以表示成若干个x或者x的m次幂的乘积
//对于幂n 把它转换成二进制 
//以示例说明  对于5（110）来说  它可以表示成100+010   又或者111 可以表示成100+010+001
//按照上述拆法 对于5来说 可以把y拆成 x^4*x^2
//所以 我们可以考虑 在把幂n变成二进制的时候 如果该位置上是1就乘该位置代表的二进制数 如果是0就略过
//而怎么保证在100的时候 结果乘的是x^4呢？
//我们就需要一个数 来记录当前位置是x的几次幂
//这里需要注意 每次新的xc都是原来的xc的平方
double myPow(double x, int n) {
    bool flag;
    long long N = n;
    if(N>0)
        flag = 1;
    else {
         flag = 0;
         N = -N;
    }
    double res=1.0;
    double xc = x;
    while(N>0){
        if(N%2==1)
            res = res * xc;
        xc = xc * xc;
        N = N/2;
    }    
    if(flag)
        return res;
    else
        return 1/res;
}
int main(){
    double x;
    int n;
    cin>>x>>n;
    double result = myPow(x,n);
    cout<<result<<endl;
    return 0;
}
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

double calArea(int a,int b,int c){
    double p = (a + b + c) / 2;
    if(a+b<=c || a+c<=b || b+c<=a)
        return 0.00;
    else
        return sqrt(p*(p-a)*(p-b)*(p-c));
}

int main(){
    int n;
    vector<double>  res;
    cin>>n;
    while(n--){
        int a,b,c;
        cin>>a>>b>>c;
        res.push_back(calArea(a,b,c));
    }
    for(int i = 0; i < res.size(); i++){
        if(res[i] == 0.00)
            cout<<"NaN"<<endl;
        else
            printf("%.2f\n",res[i]);
    }
    return 0;
}
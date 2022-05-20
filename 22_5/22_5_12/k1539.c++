#include <iostream>
#include <vector>
using namespace std;
//简单题
//一开始用hash存储1-1000中有的数
//然后while(k)  如果缺失tmp[num]  就k-1
//否则跳过  每次num都加1 来看tmp中是否存在该数
//时间复杂度和空间复杂度太高  考虑优化
//优化的时候想完全不需要map 
//num一直自增 如果num在严格递增数组里则i++看数组中的下一个
//如果不再数组里则k--
   int findKthPositive(vector<int>& arr, int k) {
        int num = 1;
        int i = 0;
        while(k){
            //这里有判断是为了防止数组越界
            //一旦数组遍历完 但缺失的数还没找完 就会有i>arr.size()的情况
            if(i<arr.size()&&arr[i]==num){
                i++;
            }else{
                k--;
            }
            num++;
        }
        return num-1;
    }
int main(){
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int res = findKthPositive(arr,k);
    cout<<res<<endl;
    return 0;
}
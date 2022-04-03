#include <iostream>
#include <vector>
using namespace std;
//这道题不难 虽然我就想到一种方法
//方法一 把nums2放到1里面 然后使用sort
//方法二 创建另外一个数组 两个指针分别指向nums1 2开头 选其中最小的加进去 如果其中一个结束
//把另外一个直接加到其末尾  空间有额外的开销
//方法三 思路与二大致相同 这里是从后往前找 找两个指针中大的一个数  直接加到nums1的末尾 然后指针前移
//如果nums1先结束 把nums2复制到1开头 如果nums2先结束则不用管
//
//我主要是没想到新建数组 思维太固化了 想直接用它的数组
//这里一二比较见到我就不再写了  leetcode上有记录  直接写三
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int cur;
        int p1=m-1,p2=n-1,i=m+n-1;
        while(p1>=0&&p2>=0){
            if(nums1[p1]<nums2[p2]){
                cur = nums2[p2];
                p2--;
            }else{
                cur = nums1[p1];
                p1--;
            }
            nums1[i] = cur;
            i--;
        }
        if(p1<0){
            for(i;i>=0;i--){
                nums1[i] = nums2[p2];
                p2--;
            }
        }
}
int main(){
    int m,n;
    cin>>m>>n;
    vector<int> nums1(m+n);
    vector<int> nums2(n);
    for(int i = 0; i < m; i++){
        cin>>nums1[i];
    }
    for(int i = 0; i < n; i++){
        cin>>nums2[i];
    }
    merge(nums1,m,nums2,n);
    for(int i = 0; i < m+n;++i){
        cout<<nums1[i]<<" ";
    }
    cout<<endl;
    return 0;
}



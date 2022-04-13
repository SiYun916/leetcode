#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//这道题 理解起来有点费劲  比较绕
//自己做的时候就被绕进去了
//看了2小时的这道题 才算明白一点
//这里写三种方法 除了第一种方法 其他两种我还是不清晰
//直接看代码
//第一种：
//首先 按照引用次数从小到大排序 
//我们返回的是文章数
//要保证引用次数的最小值是大于文章数的  在遇到相同的引用次数时也无所谓
//只要保证其值是大于文章数即可
int hIndex1(vector<int>& citations) {
        sort(citations.begin(),citations.end());
        int n = citations.size();
        int h = 0;
        //这里没有等号的原因是 当等于时 如果h再加1 就不满足最小引用次数大于文章数了  
        for(int i = n - 1; i>=0&&citations[i]>h;i--){
            h++;
        }
        return h;
}
//第二种方法 
//首先理解一点  最大的返回值就是总文章数 所以按照引用数统计文章的数量 当引用数的大于文章总数的文章统一记到最大文章数
//那一位置即可
//下面开始比较引用量与当前引用量之后所有文章的总数之间的关系 
//如果i引用量大的化 说明最小引用量大于文章数 还可以再加文章
//一旦i小于等于文章数了 说明文章数再加了最后一次之后够了 需要返回了
//但是这里为什么不反回文章数呢？
//我还是不太清晰
//我的想法就是 此时res的值是大于等于i的 意味着 大于该引用量的文章都可算进去
//此时引用量决定着文章数 所有返回引用量 而不是文章数
//
//突然想到另一种说法
//当引用量大时，取决定因素的是文章数 引用数要减少的同时增加文章数
//而一旦文章数大于引用时 取决定因素的是引用数 同时引用数一路减下来 前面的文章数是一定满足条件的
int hIndex2(vector<int>& citations) {
        int n = citations.size();
        vector<int> count(n+1);
        for(int i = 0; i < n; i++){
            if(citations[i]>=n)
                count[n]++;
            else
                count[citations[i]]++;
        }
        int i = n;
        int res = count[n];
        while(i>=0&&i>res){
            i--;
            res = res + count[i];
        }
        return i;
}
//第三种 二分法
//我只能说 我太菜了  理解不到位
//下次再写吧  我再理解一下
//我们一定返回的是某个文章数x 且保证这些文章引用数也必须大于等于x 
//二分法 让我们选取中间的一个文章数x=mid
// 记录所有范围内的 大于等于x的个数
// 如果个数小于x说明 选取的这个文章数太大了 要减小文章数
// 注意 每次都要全部遍历整个citations
int hIndex3(vector<int>& citations) {
        int n = citations.size();
        int left = 0;
        int right = n;
        int mid;
        while(left<right){
            mid = (left + right + 1)/2;
            int count = 0;
            for(int i =0; i < n; i++){
                if(citations[i]>=mid)
                    count++;
            }
            if(count>=mid)
                left = mid;
            else 
                right = mid-1;
        } 
        return left;
}
int main(){
    int n;
    cin>>n;
    vector<int> c(n);
    for(int i = 0; i < n;i++){
        cin>>c[i];
    }
    int res1 = hIndex1(c);
    int res2 = hIndex2(c);
    int res3 = hIndex3(c);
    cout<<res1<<" "<<res2<<" "<<res3<<endl;
    return 0;
}




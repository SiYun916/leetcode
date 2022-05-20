#include <iostream>
#include <vector>
#include <map>
using namespace std;
//这道题如果直接模拟，时间复杂度是O(n^2)，超时了，但空间复杂度是O(1)
//所以如果考虑优化就是空间换时间
//模拟的第二层循环是遍历整个vector找到一个大于end的最接近的start
//本质就是查找一个数  所以二分查找是最快的 对于一个给定顺序的数组最小时间复杂度是O(log2(n))
//而具体实现较为巧妙 没有再写二分查找的代码 而是用一个函数lower_bound搞定
//map::lower_bound(key):返回map中第一个大于或等于key的迭代器指针
vector<int> findRightInterval(vector<vector<int>>& intervals){
    vector<int> res;
    map<int,int> start_index;
    int index;
    //记录start值以及下标值
    //例如[[3,4][2,3][1,2]]
    //key: 3 2 1
    //value: 0 1 2
    for(auto v : intervals){
            start_index[v[0]] = index;
            index++;
    }
    for(auto v : intervals){
        //返回map中第一个大于或等于key的迭代器指针
        auto it = start_index.lower_bound(v[1]);
        //如果没有 则说明没有符合要求的区间返回-1
        if(it==start_index.end()) res.push_back(-1);
        //记录
        else res.push_back(it->second);
    }
    return res;
}
int main(){
    int n;
    cin>>n;
    vector<vector<int>> intervals(n,(vector<int>)2);
    for(int i=0;i<n;i++){
        for(int j=0;j<2;j++){
            cin>>intervals[i][j];
        }
    }
    vector<int> result = findRightInterval(intervals);
    for(int i = 0; i < result.size();i++){
        cout<<result[i]<<" "; 
    }
    cout<<endl;
    return 0;
}
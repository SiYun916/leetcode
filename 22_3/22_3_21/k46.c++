#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//雾 做了10天题了 今天终于自己作出一道中等题  虽然之前做过两道类似的回溯题 但这次完全是自己写出来的
//有一丢丢成就感 总算可以说我会回溯了
//
//先来说下我自己的想法：
//采用回溯的方法 每次push_back一个数 并把它从原数组中删除 剩下的数重新排序 然后继续DFS搜索下一个 
//当找到一个答案后 pop_back最后一个数 并把最后一个数加入原数组  重新排序 然后进行下一次的循环或结束函数
//按此回溯即可得到答案
//
//主要有三点易错：
//1.这里DFS函数的nums是在不断变化的，所以终止条件需要额外的fl（不变且值为原数组长度）来规定结束条件
//2.主函数原nums数组要先进行从小到大的排序  如果不提前排序好会出现重复的序列
//3.使用一个tmp变量保存元素 以恢复数组
void DFS(vector<vector<int>>& res,vector<int>& cur,int n,vector<int>& nums,int fl){
        if(n == fl){
            res.push_back(cur);
            return ;
        }

        for(int i = 0; i < nums.size(); ++i){
            cur.push_back(nums[i]);
            int tmp = nums[i];
            swap(nums[i],nums[nums.size()-1]);
            nums.pop_back();
            sort(nums.begin(),nums.end());
            DFS(res,cur,n+1,nums,fl);
            cur.pop_back();
            nums.push_back(tmp);
            sort(nums.begin(),nums.end());
        }
    }


int main(){
	int number;
	cin>>number;
	vector<int> nums;
	for (int i = 0; i < number;i++){
		int tmp;
		cin>>tmp;
		nums.push_back(tmp);
	}
        vector<vector<int>> res;
        vector<int> cur;
        int fl = nums.size();
        sort(nums.begin(),nums.end());
        DFS(res,cur,0,nums,fl);
	for(int i = 0;i < res.size();i++){
		for(int j = 0; j < res[i].size();j++){
			cout<<res[i][j];
		}
		cout<<endl;
	}
        return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//看了一份别人的c++题解
//他是采用了一个判断是否使用过的bool数组
//使用过了变1   回溯的时候将其变0
//其实感觉思路上是一样的
void DFS(vector<vector<int>>& res,vector<int>& cur,vector<int>& nums,vector<bool>& usage){
        if(cur.size() == nums.size()){
            res.push_back(cur);
            return ;
        }

        for(int i = 0; i < nums.size(); ++i){
		//判断是否使用过该数  使用过就跳过该数
		if(!usage[i]){
			usage[i] = 1;
			cur.push_back(nums[i]);
			DFS(res,cur,nums,usage);
			cur.pop_back();
			usage[i] = 0;
		}
        }
}

int main(){
	//输入nums
	int number;
	cin>>number;
	vector<int> nums;
	for (int i = 0; i < number;i++){
		int tmp;
		cin>>tmp;
		nums.push_back(tmp);
	}
	//回溯
        vector<vector<int>> res;
        vector<int> cur;
        vector<bool> usage(nums.size());
        DFS(res,cur,nums,usage);
	//打印
	for(int i = 0;i < res.size();i++){
		for(int j = 0; j < res[i].size();j++){
			cout<<res[i][j];
		}
		cout<<endl;
	}
        return 0;
}

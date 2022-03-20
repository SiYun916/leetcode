#include <iostream>
#include <vector>
#include <string>
using namespace std;
//对于这道题 我一开始的思路是DFS回溯 但是我并不会如何具体实现
//包括22_3_14那道字母电话号码的题 我并不会回溯的通用步骤 只是记住了一道题的解法
//所以在这里我想总结一下回溯的步骤
//
//首先是 回溯函数一般无返回值 参数要根据题意列出 当前状态 结果存储变量 控制回溯的变量
//函数体内部第一部分要写何时返回 即此次回溯结果返回的条件 并将其记录在结果存储变量当中
//第二部分就是回溯 根据不同的条件进行回溯
//回溯通常情况下就是
//push_back 添加一个元素
//回溯函数（）
//pop_back 删除该元素 
//
//对于不同的问题一定要找其特性 
//对于这道题来说 我一直纠结于用哪种方法  而没有总结其特性 导致写代码的时候没有一点思路
void backtrack(vector<string>& res,string& cur,int left,int right,int n){
	//明显 当字符串长度等于左右括号总数的时候 此次回溯就到终点了	
	if(2*n == cur.size()){
		res.push_back(cur);
		return ;
	}
	//当左括号数量小于n时，当前状态还可以再添加左括号
	if(left < n){
		cur.push_back('(');
		backtrack(res,cur,left+1,right,n);
		cur.pop_back();
	}
	//当右括号数量小于左括号时，当前状态可以再添加右括号
	if(right < left){
		cur.push_back(')');
		backtrack(res,cur,left,right+1,n);
		cur.pop_back();
	}
}
int main(){
	int n;
	cin>>n;
	vector<string> res;
	string cur;
	backtrack(res,cur,0,0,n);
	for(int i = 0; i < res.size(); ++i)
		cout<<res[i]<<endl;
	return 0;
}


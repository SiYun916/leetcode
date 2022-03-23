#include <iostream>
#include <vector>
using namespace std;
//二叉树 主要注意下这种创建格式 以后写树的时候可以参考
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
//总体思想：回溯
//我只能说我是个懒狗 没怎么思考 直接看了题解 
//一开始没有想到回溯的方法 甚至一开始我连中序遍历都不知道
//中序遍历：先输出左节点然后中间节点最后右节点
//回溯的方法理解起来比较简单
//首先一直向左遍历 如果为空了就返回输出 然后遍历右子树
void backtracking(TreeNode* root,vector<int>& res){
    if(root == NULL)
        return ;
    backtracking(root->left,res);
    res.push_back(root->val);
    backtracking(root->right,res);
}
vector<int> inorderTraversal(TreeNode* root){
    vector<int> res;
    backtracking(root,res);
    return res;
}
//主函数主要用来创建了节点 按照leetcode第一个例子创建
int main(){
    TreeNode *root,*b,*c;
    root = (TreeNode*)malloc(sizeof(TreeNode));
    b = (TreeNode*)malloc(sizeof(TreeNode));
    c = (TreeNode*)malloc(sizeof(TreeNode));
    root->left = NULL;root->val = 1;root->right=b;
    b->left = c;b->val = 2;b->right = NULL;
    c->left = NULL;c->val = 3;c->right = NULL;
    vector<int> result;
    result = inorderTraversal(root);
    for(int i = 0; i < result.size();i++){
        cout<<result[i]<<endl;
    }
    return 0;
}

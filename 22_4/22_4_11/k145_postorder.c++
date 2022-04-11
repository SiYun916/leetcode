#include <iostream>
#include <vector>
#include <stack>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
//今天看看二叉树的遍历 之前做过一个二叉树的前序遍历 今天来中序遍历和后续遍历
//以递归的方法来说这几种遍历方式差别不大，主要就是结果写入的位置不同
//还有要注意的一点是判断返回条件仅仅需要判断一个root根节点即可
/*
还有 要它喵注意vector作为参数传递时 要引用&
*/
//这里使用一个递归作为示例，随后将用迭代的方法写
void DFS(TreeNode* root,vector<int>& res){
    if(root==NULL)
        return ;
    DFS(root->left,res);
    DFS(root->right,res);
    res.push_back(root->val);
}
vector<int> postorderTraversal(TreeNode* root) {
    vector<int> res;
    DFS(root,res);
    return res;
}
int main(){
    TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
    TreeNode* p = (TreeNode*)malloc(sizeof(TreeNode));
    TreeNode* q = (TreeNode*)malloc(sizeof(TreeNode));
    root->val = 1;
    root->left = NULL;
    root->right = p;
    p->val = 2;
    p->left = q;
    p->right = NULL;
    q->val = 3;
    q->left = NULL;
    q->right = NULL;
    vector<int> result;
    result = postorderTraversal(root);
    for(int i = 0; i < result.size();i++){
        cout << result[i] <<endl;
    }
    return 0;
}
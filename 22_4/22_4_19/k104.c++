#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//好吧  就当我今天凌晨放屁了
//我果然又写了一个简单的题 
//一个二叉树的题 二叉树的深度 自己写出来了 代码贴下面
//但时间和空间的效率都很低 递归的简化版放在另外一个里面
//再复习一下struct malloc
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
//递归 把每一个子树的深度都记录下来 最后求最大值 
void DFS(TreeNode* root,int n,vector<int>& tmp){
        if(root==NULL){
            tmp.push_back(n);
            return ;
        }
        DFS(root->left,n+1,tmp);
        DFS(root->right,n+1,tmp);
    }
int maxDepth(TreeNode* root) {
    vector<int> t;
    DFS(root,0,t);
    int maxValue = *max_element(t.begin(),t.end());
    return maxValue;
}
int main(){
    TreeNode *root,*a,*b,*c,*d;
    root = (TreeNode*)malloc(sizeof(TreeNode));
    a = (TreeNode*)malloc(sizeof(TreeNode));
    b = (TreeNode*)malloc(sizeof(TreeNode));
    c = (TreeNode*)malloc(sizeof(TreeNode));
    d = (TreeNode*)malloc(sizeof(TreeNode));
    root->val=3; root->left=a; root->right=b;
    a->val=9; a->left=NULL; a->right=NULL;
    b->val=20; b->left=c; b->right=d;
    c->val=15; c->left=NULL; c->right=NULL;
    d->val=7; d->left=NULL; d->right=NULL;
    int depth = maxDepth(root);
    cout<<depth<<endl;
    return 0;
}

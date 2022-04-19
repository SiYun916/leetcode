#include <iostream>
#include <algorithm>
using namespace std;
//看了题解的递归 我发现 我就是个瘠薄
//如果我们知道了左子树和右子树的最大深度 l 和 r，那么该二叉树的最大深度即为
//max(r,l)+1
//对于每个结点都是如此
//所以函数本身就能递归 如果遇到空结点 就返回0
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
int maxDepth(TreeNode* root) {
    if(root==NULL) return 0;
    return max(maxDepth(root->left),maxDepth(root->right))+1;
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

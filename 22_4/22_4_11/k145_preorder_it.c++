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
//翻了之前的题解 我才发现我写过迭代的代码
//日  当时肯定印象不深 这里重新写一遍
//迭代用了栈的思想 其实在这里 可以隐约感觉到其实递归也是使用了一个虚拟的栈
//主要谈下我的理解：
//所有遍历都是先一直遍历左子树 为空了就遍历右子树
//当为空了 要怎么返回呢？
//这就是建立栈的原因 使用栈这种后进先出的结构 来返回上一个的指针
//至于前中后 它的顺序 取决于遍历过程中 记录节点信息的位置 而不在于怎样遍历
vector<int> postorderTraversal(TreeNode* root) {
    vector<int> res;
    if(root==NULL)
        return res;
    stack<TreeNode*> stk;
    while(!stk.empty()||root!=NULL) {
        while(root!=NULL) {
            res.push_back(root->val);
            stk.push(root);
            root = root->left;
        }
        root = stk.top();
        stk.pop();
        root = root->right;
    }
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
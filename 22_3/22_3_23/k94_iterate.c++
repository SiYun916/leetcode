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
//总体思想：迭代
//主要说下思路
//迭代也是直接遍历左子树
//每次遍历一个节点都要把它记录在一个栈里面
//注意 栈里记录的是节点 指针
//所以当遍历到空结点后 将栈的最后一个指针拿出来
//记录其值
//然后遍历它的右子树
//若为空的话 继续将栈的最后一个指针拿出来
//重复上述步骤
vector<int> inorderTraversal(TreeNode* root){
    vector<int> res;
    stack<TreeNode*> tmp;
    //如果root不为空说明没有遍历完 如果tmp不为空说明还没有记录完
    //这两种情况下都要继续进行
    while(root != NULL || !tmp.empty()){
        //如果root不为空 记录将当前结点压栈 并遍历其左子树
        while(root != NULL){
            tmp.push(root);
            root = root->left;
        }
        //如果为空 就要把栈顶结点拿出来 记录其值 并遍历右子树
        root = tmp.top();
        res.push_back(root->val);
        tmp.pop();
        root = root->right;
    }
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

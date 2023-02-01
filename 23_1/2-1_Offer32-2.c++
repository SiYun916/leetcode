//这道题的关键在于要多一个队列或着栈去临时存储，并返回该层的值
//然后根据临时栈得到下一层的值
//看下图就回想起来了
//一开始用栈写的，不想重复一遍
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root==NULL)  return {};
        queue<TreeNode*>    biTreeQueue;
        queue<TreeNode*>    tmp;
        biTreeQueue.push(root);
        while(!biTreeQueue.empty()){
            vector<int> v;
            while(!biTreeQueue.empty()){
                TreeNode* t = biTreeQueue.front();
                tmp.push(t);
                biTreeQueue.pop();
            }
            while(!tmp.empty()){
                TreeNode* p = tmp.front();
                v.push_back(p->val);
                if(p->left != NULL)
                    biTreeQueue.push(p->left);
                if(p->right != NULL)
                    biTreeQueue.push(p->right);
                tmp.pop();
            }
            result.push_back(v);
        }
        return  result;
    }
};


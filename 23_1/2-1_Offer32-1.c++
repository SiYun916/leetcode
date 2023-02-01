//树的层序遍历
//学过用队列先进先出的性质
class Solution {
public:
    vector<int> levelOrder(TreeNode* root) {
        if(root == NULL)    return {};
        queue<TreeNode*>    biTreeQueue;
        vector<int> result;
        biTreeQueue.push(root);
        while(!biTreeQueue.empty()){
            TreeNode* tmp = biTreeQueue.front();
            biTreeQueue.pop();
            result.push_back(tmp->val);
            if(tmp->left != NULL)
                biTreeQueue.push(tmp->left);
            if(tmp->right != NULL)
                biTreeQueue.push(tmp->right);
        }
        return result;
    }
};
//自己写的不想再写一遍了

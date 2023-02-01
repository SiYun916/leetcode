//在2的基础上加个奇偶层的判断即可
//看了题解的双向队列，我只能说猪脑过载了
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root==NULL)  return {};
        queue<TreeNode*>    biTreeQueue;
        queue<TreeNode*>    tmp;
        biTreeQueue.push(root);
        bool isOdd = true;
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
            if(isOdd){
                result.push_back(v);
                isOdd = false;
            }
            else{
                reverse(v.begin(),v.end());
                result.push_back(v);
                isOdd = true;
            }
        }
        return  result;
    }
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> set;
        TreeNode* curr=root;
        while(curr!=nullptr||!set.empty())
        {
            while(curr)
            {
                set.push(curr);
                curr=curr->left;
            }
            curr=set.top();
            res.push_back(set.top()->val);
            set.pop();
            curr=curr->right;
        }
        return res;
        
        
        
    }
};
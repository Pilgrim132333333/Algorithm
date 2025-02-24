class Solution{
    public:
    vector<vector<int>> levelorder(TreeNode* root)
    {
        queue<TreeNode*> que;
        if(root!=nullptr)
        {
            que.push_back(root);
        }
        vector<vector<int>> res;
        while(!que.empty())
        {
            vector<int> vec;
            int size=que.size();
            for(int i=0;i<size;i++)
            {
                TreeNode* node=que.front();
                que.pop();
                vec.push_back(node->val);
                if(node->left)
                {
                    que.push_back(node->left);
                }
                if(node->right)
                {
                    que.push_back(node->right);
                }
                res.push_back(vec);

            }
        }
        return res;
    }
}
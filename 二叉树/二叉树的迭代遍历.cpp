
class Solution{
    public:

    //前序遍历
    vector<int> preordertraversal(TreeNode* root)
    {
        vector<int> res;
        stack<TreeNode*> st;
        if(root!=nullptr)
        {
            st.push(root);
        }
        while(!st.empty())
        {
            TreeNode* node=st.top();
            if(cur!=nullptr)
            {
                st.pop();
                if(node->right!=nullptr)
                {
                    st.push(node->right);
                }
                if(node->left!=nullptr)
                {
                    st.push(node->left);
                }
                sta.push(node);
                sta.push(nullptr);
            }
            else{
                st.pop();
                TreeNode* cur=st.top();
                res.push_back(cur->val);
                st.pop();
            }
        }
        return res;
    }

    //中序遍历
    vector<int> inordertraversal(TreeNode* root)
    {
        vector<int> res;
        stack<TreeNode*> st;
        if(root!=nullptr)
        {
            st.push(root);
        }
        while(!st.empty())
        {
            TreeNode* node=st.top();
            if(node!=nullptr)
            {
                st.pop();

                if(node->right!=nullptr)
                {
                    st.push(node->right);
                }

                st.push(node);
                st.push(nullptr);

                if(node->left!=nullptr)
                {
                    st.push(node->left);
                }
            }
            else{
                st.pop();
                TreeNode* cur=st.top();
                res.push_back(cur->val);
                st.pop();
            }
        }
        return res;
    }

    //后序遍历
     vector<int> postordertraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;
        if (root != nullptr) {
            st.push(root);
        }
        while (!st.empty()) {
            TreeNode* node = st.top();
            if (node != nullptr) {
                st.pop();
                st.push(node);
                st.push(nullptr);
                if (node->right != nullptr) {
                    st.push(node->right);
                }
                if (node->left != nullptr) {
                    st.push(node->left);
                }
            } else {
                st.pop();
                TreeNode* cur = st.top();
                res.push_back(cur->val);
                st.pop();
            }
        }
        return res;
    }
}
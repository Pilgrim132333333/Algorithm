#include<iostream>

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode():val(0),left(nullptr),right(nullptr){}
}

class Solution{
    public:

    //前序遍历
    void traversal(TreeNode* cur,vector<int>& res)
    {
        if(cur==nullptr)
        {
            return ;
        }
        res.push_back(cur->val);
        traversal(cur->left,res);
        traversal(cur->right,res);
        return;
    }

    vector<int> preordertraversal(TreeNode* root)
    {
        TreeNode* cur=root;
        vector<int> res;
        traversal(cur,res);
        return res;
    }


    //中序遍历
    void traversal(TreeNode* cur,vector<int> res)
    {
        if(cur==nullptr)
        {
            return;
        }
        traversal(cur->left,res);
        res.push_back(cur->val);
        traversal(cur->right,res);
        return ;
    }
    vector<int> inordertraversal(TreeNode* root)
    {
        TreeNode* cur=root;
        vector<int> res;
        traversal(cur,res);
        return res;
    }


    //后序遍历
    void traversal(TreeNode* cur, vector<int> res)
    {
        if(cur==nullptr)
        {
            return;
        }
        traversal(cur->left,res);
        traversal(cur->right,res);
        res.push_back(cur->val);
        return;
    }
    vector<int> inordertraversal(TreeNode* root)
    {
        TreeNode* cur=root;
        vector<int> res;
        traversal(cur,res);
        return res;
    }



}
#include<iostream>
using namespace std;

 class BST{
    private:
    struct Node{
        int val;
        Node* left;
        Node* right;

        Node(int val) : val(val), left(nullptr),right(nullptr) {}
    };
    public:
    Node* root=nullptr;
    Node* insert(int val,Node* current)
    {
        if(current==nullptr)
        {
            return new Node(val);
        }
        if(val<current->val)
        {
            current->left=insert(val,current->left);
        }
        else if(val>current->val){
            current->right=insert(val,current->right);
        }
        return current;
    }
    void insert(int val)
    {
        root=insert(val,root);
    }
 };



int main() {
    BST bst;
    bst.insert(10);
    bst.insert(5);

    cout << "Root value: " << bst.root->val << endl;

    return 0;
}

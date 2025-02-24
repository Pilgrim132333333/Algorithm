#include<iostream>
#include<string>
#include<unordered_map>
#include<stdbool.h>
using namespace std;

//Trial节点
struct Node{
    unordered_map<char,Node*> children //字节点
    bool isEndofWord; //是否是结尾

    Node()  isEndofWord=false  {}
}

class Trie{
    public:
    Trie()
    {
        root=new *Node;
    }


    //insert
    void insert(string &s)
    {
        Node *node=root;
        for(char c:s)
        {
            if(node->children.find(c)==node->children.end())
            {
                node->children[c]=new *Node;
            }
            node=node->children[c];
        }
        node->isEndofWord=true;
    }

    //search

    bool search(string &s,Node* root)
    {
        for(char c:s)
        {
            if(root->children.find(c)==root->children.end())
            {
                return false;
            }
            root=root->children[c];
        }
        return root->isEndofWord;
    }

}
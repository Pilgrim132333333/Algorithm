#include<iostream>

class Node{
    public:
    int val;
    Node* next;
    Node(int n){
        this->val=n;
        this->next=nullptr;  
    }
};
int main()
{
    Node a=Node(2);
    Node b=Node(3);
    a.next=&b;
    std::cout<<a.val<<a.next->val<<std::endl;
}
#include <iostream>
#include <vector>

class Node{
    public:
        int data;
        Node* left;
        Node* right;

    Node(int key){
        data = key;
        left = nullptr;
        right = nullptr;
    }

};

static int idx = -1;

Node* buildTree(std::vector<int> preOrder){
    idx++;

    if (preOrder[idx] == -1)
    {
        return nullptr;
    }
    

    Node* root = new Node(preOrder[idx]);
    root->left = buildTree(preOrder);
    root->right = buildTree(preOrder);
    return root;
} 


int main(){
    std::vector<int> preOrder = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};

    Node* root = buildTree(preOrder);
    std::cout<<root->data<<std::endl;
    std::cout<<root->left->data<<std::endl;
    std::cout<<root->right->data<<std::endl;


    return 0;
}
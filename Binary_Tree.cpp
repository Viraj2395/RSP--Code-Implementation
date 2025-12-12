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


// Pre-Order Traversal
void preOrderTraversal(Node* root){

    if (root == nullptr)
    {
        return;
    }
    
    std::cout<<root->data<<" ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}


void inOrderTraversal(Node* root){

    if (root == nullptr)
    {
        return;
    }
    
    inOrderTraversal(root->left);
    std::cout<<root->data<<" ";
    inOrderTraversal(root->right);
}


void postOrderTraversal(Node* root){

    if (root == nullptr)
    {
        return;
    }
    
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    std::cout<<root->data<<" ";
}



int main(){
    std::vector<int> preOrder = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};

    Node* root = buildTree(preOrder);


    preOrderTraversal(root);

    std::cout<<std::endl;
    
    inOrderTraversal(root);
    
    std::cout<<std::endl;

    postOrderTraversal(root);

    return 0;
}
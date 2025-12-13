#include <iostream>
#include <vector>
#include <queue>

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

// In - Order Traversal
void inOrderTraversal(Node* root){

    if (root == nullptr)
    {
        return;
    }
    
    inOrderTraversal(root->left);
    std::cout<<root->data<<" ";
    inOrderTraversal(root->right);
}

// Post - Order Traversel
void postOrderTraversal(Node* root){

    if (root == nullptr)
    {
        return;
    }
    
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    std::cout<<root->data<<" ";
}

// Level-Order- Traversal
void levelOrderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }

    std::queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();

        std::cout << curr->data << " ";

        if (curr->left != nullptr) {
            q.push(curr->left);
        }

        if (curr->right != nullptr) {
            q.push(curr->right);
        }
    }
}



int main(){
    std::vector<int> preOrder = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};

    Node* root = buildTree(preOrder);

    std::cout<<"Pre-Order Traversal : ";
    preOrderTraversal(root);
    
    std::cout<<std::endl;
    
    std::cout<<"In-Order Traversal : ";
    inOrderTraversal(root);
    
    std::cout<<std::endl;
    
    std::cout<<"Post-Order Traversal : ";
    postOrderTraversal(root);


    std::cout<<std::endl;

    std::cout<<"Level-Order Traversal : ";
    levelOrderTraversal(root);

    return 0;
}
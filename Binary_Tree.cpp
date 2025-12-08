#include <iostream>

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

int main(){
    Node* firstNode = new Node(2);
    Node* secondNode = new Node(3);
    Node* thirdNode = new Node(4);
    Node* fouthNode = new Node(5);

    firstNode->left = secondNode;
    firstNode->right = thirdNode;
    secondNode->left = fouthNode;

    return 0;
}
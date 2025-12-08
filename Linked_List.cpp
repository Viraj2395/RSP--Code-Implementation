#include <iostream>

class Node
{
public:
    int data;
    Node* next;

    Node(int _data){
        data = _data;
        next = NULL; //initialize the next with NULL
    }
};

//Case 1 : insert at beginning
Node * insertAtFirst(Node * Head , int _data){
    Node * ptr = new Node(_data);
    ptr->next = Head;

    return ptr;
}

//Case 2 : insert in Between
Node * insertInBetween(Node * Head, int _data, int index){
    Node * ptr = new Node(_data);
    Node * p = Head;
    
    int i = 0;

    while (i != (index-1))
    {
        p = p->next;
        i++;
    }
    ptr->next = p->next;
    p->next = ptr;

    return Head;
}

Node * insertAtEnd(Node* Head, int _data){
    Node * ptr = new Node(_data);
    Node * p = Head;

    while (p->next != NULL)
    {
        p = p->next;
    }
    ptr->next = NULL;
    p->next = ptr;

    return Head;
}


void Traverse(Node * Head){
    while (Head != nullptr)
    {
        std::cout<<Head->data<<" ";
        Head = Head->next;
    }
    
}


void FreeList(Node*& Head){
    while (Head != nullptr){
        Node* tmp = Head;
        Head = Head->next;
        delete tmp;
    }
    Head = nullptr;
}

int main(){
    Node* Head = new Node(1);
    Head->next = new Node(2);
    Head->next->next = new Node(3);
    Head->next->next->next = new Node(4);
    Head->next->next->next->next = new Node(5);

 
    // Head = insertAtFirst(Head,20);

    // Head= insertInBetween(Head,45,3);

    // Head = insertAtEnd(Head, 83);

    Traverse(Head);
    std::cout << std::endl;

    // free allocated memory
    FreeList(Head);

    return 0;
}
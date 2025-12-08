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

// Case 3 : insert At the End
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

// Case 1 : Delete the First Node
Node * DeleteFirstNode(Node* Head,int _data){
    Node* ptr = Head;
    ptr->data = _data;

    Head = Head->next;

    free(ptr);

    return Head;
}

// Case 2 : Delete At the Index
Node * DeleteAtIndex(Node* Head,int index){
    Node* p = Head;
    Node* q = Head->next;

    for (int i = 0; i < index - 1 ; i++)
    {
        p = p->next;
        q = q->next;
    }
    
    p->next = q->next;
    free(q);

    return Head;
}


// Case 3 : Delete At the End


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

    // Head = DeleteFirstNode(Head,1);

    Head = DeleteAtIndex(Head, 3);

    Traverse(Head);
    std::cout << std::endl;

    // free allocated memory
    FreeList(Head);

    return 0;
}
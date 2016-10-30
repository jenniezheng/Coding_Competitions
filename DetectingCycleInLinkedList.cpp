/*
Detect a cycle in a linked list. Note that the head pointer may be 'NULL' if the list is empty.

A Node is defined as: 
    struct Node {
        int data;
        struct Node* next;
    }
*/


bool has_cycle(Node* head) {
    if (head==NULL)return false;
    Node* fast=head->next;
    Node* slow=head;
    while(slow!=fast){
        if(fast==NULL||fast->next==NULL)return false;
        fast=fast->next->next;
        slow=slow->next;
    }
       
    return true;;
}

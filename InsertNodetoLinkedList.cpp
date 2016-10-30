 Node* insert(Node *head,int data)
      {     Node* last= new Node(data);
          last->next=NULL;
     if(head==NULL) {head=last; return head;}
       
       Node* temp= head;
     while(temp->next!=NULL)temp=temp->next;
       temp->next=last;
       return head;

      }

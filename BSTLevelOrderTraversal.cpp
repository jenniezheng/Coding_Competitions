
void levelOrder(Node * root){
queue<Node*> q;
if(root!=NULL)
    q.push(root);
while(!(q.empty())){
  Node* c=q.front();
    q.pop();
   cout<<c->data<<" ";
   if(c->left!=NULL)q.push(c->left);
   if(c->right!=NULL)q.push(c->right); 
}
    
}
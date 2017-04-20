 bool checkBST(Node* root, int parentMin=NULL, int parentMax=NULL) {
     //true when reach root
if(root==NULL)return true;
    //check is root data is less than parentMin and greater than parent max
if( parentMax!=NULL && root->data >= parentMax || parentMin!=NULL && root->data <= parentMin ) return false;
    //check if left and right children follow same rules, setting max for left to be root's data and min for right to be root's     //data
     else return checkBST(root->left, parentMin, root->data )&&checkBST( root->right, root->data, parentMax);
}
#include <iostream>

using namespace std;
struct BSTNode
{
  BSTNode * up, * left, * right;
  int key;
};
void inorder(BSTNode *up) {
    if(up != NULL) {
        inorder(up -> left);
        cout << up -> key << " ";
        inorder(up -> right);
    }
}
void preorder(BSTNode *up) {
    if(up != NULL) {
        cout << up -> key << " ";
        preorder(up -> left);
        preorder(up -> right);
    }
}
void postorder(BSTNode *up) {
    if(up != NULL) {
        postorder(up -> left);
        postorder(up -> right);
        cout << up -> key << " ";
    }
}
void insertBST ( BSTNode * & root, int k )
{
  BSTNode * w, * p;
  w = new BSTNode;
  w->left = w->right = NULL;
  w->key = k;
  p = root;
  if( !p )
    root = w;
  else
    while( true )
      if( k < p->key )
      {
        if( !p->left )
        {
          p->left = w;
          break;
        }
        else p = p->left;
      }
      else
      {
        if( !p->right )
        {
          p->right = w;
          break;
        }
        else p = p->right;
      }
  w->up  = p;
}
int main( )
{
  BSTNode * root = NULL;
    int ile=0;
    while(ile!=-999)
    {
        cin>>ile;
        if(ile!=-999)
        {

            insertBST(root,ile);
        }
    }
  inorder(root );
  cout<<endl;
  preorder(root);
  cout<<endl;
  postorder(root);
  return 0;
}
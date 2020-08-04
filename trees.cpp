#include <bits/stdc++.h>
using namespace std;
class trees{
  public:
  int d;
  trees* right;
  trees* left;
};
trees* root;

void preOrder(trees* root){
  if(root==NULL)
    return;
  cout<<root->d<<" ";
  preOrder(root->left);
  preOrder(root->right);
}

void inOrder(trees* root){
  if(root==NULL)
    return;
  inOrder(root->left);
  cout<<root->d<<" ";
  inOrder(root->right);
}

void postOrder(trees* root){
  if(root==NULL)
    return;
  postOrder(root->left);
  postOrder(root->right);
  cout<<root->d<<" ";
}
trees* insert(trees* root, int data)
{
  trees* temp=new trees();
  //if no data is there in the tree
  if(root==NULL)
  {
    temp->d=data;
    temp->right=NULL;
    temp->right=NULL;
    root=temp;
  }
  else if(root->d>data){
    root->left=insert(root->left,data);
  }
  else if(root->d<data){
    root->right=insert(root->right,data);
  }
  return root;
}

trees* removeLeaf(trees* root){
  if(root==NULL)
    return NULL;
  if(root->right==NULL && root->left==NULL){
    free(root);
    return NULL;
  }
  root->left=removeLeaf(root->left);
  root->right=removeLeaf(root->right);
  return root;
}  

int main() {
  cout<<"Welcome to Tree Data Structure"<<endl;
  cout<<"-------------------------------"<<endl;
  int ask=1;
  while(ask!=0){
    cout<<"[1] Insert a number to the tree"<<endl;
    cout<<"[2] remove leaf node"<<endl;
    cout<<"[3] PreOrder"<<endl;
    cout<<"[4] PostOrder"<<endl;
    cout<<"[5] InOrder"<<endl;
    cout<<"Choose One Option: ";
    int opt;
    cin>>opt;
    switch(opt){
      case 1:
      {
        int data;
        cout<<"Enter the number: "<<endl;
        cin>>data;
        root=insert(root,data);
        break;
      }
      case 2:
        root=removeLeaf(root);
        break;
      case 3:
      {
        preOrder(root);
        cout<<endl;
        break;
      }
      case 4:
        postOrder(root);
        cout<<endl;
        break;
      case 5:
        inOrder(root);
        cout<<endl;
        break;
      default:
        cout<<"Not a valid number."<<endl;
        break;
    }
  }
}

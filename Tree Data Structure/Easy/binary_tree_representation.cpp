#include<iostream>
#include <queue>
using namespace std;

class node
{
    public: 
        int data;
        node* left;
        node* right;

    //constructor 
    node(int d)
    {
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
};
node* buildTree(node* root )
{
    cout<<"Enter the data"<<endl;
    int data;
    cin>>data;

    root=new node(data);

    if(data== -1)
    {
        return NULL;
    } 

    cout<<"Enter data in left side of Node "<<data<<endl;
    root->left= buildTree(root->left);

      cout<<"Enter data in right side of Node "<<data<<endl;
    root->right= buildTree(root->right);

    return root;

} 

void levelOrderTraversal(node* root)
{
    queue<node*> q;
    q.push(root);
    //seperator 
    q.push(NULL);

    while(!q.empty())
    {
        node* temp=q.front();
        
        q.pop();

        if(temp==NULL)
        {
            //purana level is over
            cout<<endl;
            if(!q.empty())
            {
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left)
            {
                q.push(temp->left);
            }
             if(temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

void inorderTraversal(node* root)
{
    //base case
    if(root==NULL)
    {
        return ;
    }

    //L
    inorderTraversal(root->left);
    //N
    cout<<root->data<<" ";
    //R
     inorderTraversal(root->right);
}

void preOrder(node* root)
{   
     //base case
    if(root==NULL)
    {
        return ;
    }

    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
    
}

void postOrder(node* root)
{   
     //base case
    if(root==NULL)
    {
        return ;
    }

    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
   
}
int main( )
{
    node* root= NULL;
    root =buildTree(root); 
  // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    cout<<"Level order Traversal"<<endl;
    levelOrderTraversal(root);
    cout<<"Inorder Traversal"<<endl;
    inorderTraversal(root);
    cout<<endl;
    cout<<"PreOrder Traversal"<<endl;
    preOrder(root);
    cout<<endl;
    cout<<"PostOrder Traversal"<<endl;
    postOrder(root);
    return 0;
}
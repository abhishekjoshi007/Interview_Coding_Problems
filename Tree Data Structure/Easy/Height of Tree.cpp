/*
Height of Tree
Given a binary tree, your task is to print the height of the tree. Consider root node height as 
1
.

Note - You have to complete calculateHeight() function, no need to implement the tree.

Input format
Root of the tree is passed to the calculateHeight()
And the tree is constructed in level order format.

Output format
Return height of the tree.

Constraints
1
<=
N
<=
64

Time Limit
1 second

Example
Input
1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
Note : Level order traversal of input tree, where 
−
1
 represents null nodes.

Output
3
*/

#define REP(i, n) for (i = 0; i < n; i++)
#define pb(a) push_back(a)
#define vi vector<long>
#define ll long long
#include <bits/stdc++.h>
using namespace std;
struct node
{
    ll value;
    node *left;
    node *right;
};

node *createNode(ll value)
{
    node *t = new node();
    t->value = value;
    t->right = t->left = NULL;
    return t;
}

void deleteNode(node *t)
{
    delete t;
}


node *replaceNegativeOne(node *root)
{
    if (root == NULL || (root->value == -1 && root->left == NULL && root->right == NULL))
        return NULL;
    root->left = replaceNegativeOne(root->left);
    root->right = replaceNegativeOne(root->right);
    return root;
}

node *createTreeByLevelTree()
{
    ll n, m;
    queue<node *> q;

    node *root, *t;

    root = NULL;

    while (cin >> n)
    {
        if (q.empty())
        {
            root = createNode(n);
            q.push(root);
            continue;
        }
        cin >> m;

        t = q.front();
        q.pop();

        t->left = createNode(n);
        t->right = createNode(m);

        if (t->left->value != -1)
        {
            q.push(t->left);
        }

        if (t->right->value != -1)
        {
            q.push(t->right);
        }
          if (q.empty())
        {
            break;
        }
    }

    return root;
}

void deleteTree(node *node)
{
    if (node == NULL)
        return;

    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
}

// Complete the calculateHeight function below.
/* For your reference
struct node
{
    long long value;
    node *left;
    node *right;
};
*/

int calculateHeight(node* node)
{
    if (node==NULL)
    return 0;
    
    else 
    {
      int left_height=calculateHeight(node->left);
      int right_height=calculateHeight(node->right);
      
      if(left_height>right_height)
      return left_height+1;
      
      else return right_height+1;
      
    }
}


int main()
{
    node *root = NULL;
    root = createTreeByLevelTree();
    root = replaceNegativeOne(root);
    cout<< calculateHeight(root)<<endl;
    deleteTree(root);
    return 0;
}

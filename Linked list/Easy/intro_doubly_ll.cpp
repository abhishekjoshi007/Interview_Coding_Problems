#include <iostream>
  using namespace std;
  
  class node{
    public:
    int data;
    node* next;
    node* prev;

    node(int val)
    {
        data=val;
        next=NULL;
        prev=NULL;
    }
 };

void insertAtHead(node* &head, int data)
{
    node* n =new node(data);

    n->next=head;
//if LL is empty then head->prev doesn't exist
    if(head!=NULL)
    {
    head->prev=n;
    }
    head=n;

}

void insertAtTail(node* &head,int data)
{
    node* n=new node(data);
    node* temp=head;
     if(head==NULL)
    {
        insertAtHead(head,data);
        return;

    }

    while(temp->next!=NULL)
    {
        temp=temp->next;
    }

    temp->next=n;
    n->prev=temp;
}

void deleteAthead(node* &head)
{
    node* toDelete=head;
    head=head->next;
    head->prev=NULL;

    delete toDelete;
}
void deleteNode(node* &head,int pos)
{
    if(pos==1)
    {`
        deleteAthead(head);
        return;
    }
    node* temp=head;
    int count=1;

    while(temp!=NULL && count!=pos)
    {
        temp=temp->next;
        count++;
    }
    
    temp->prev->next=temp->next;
    
    //not for the last node 
    if(temp->next!=NULL)
    {
    temp->next->prev=temp->prev;
    }

    delete temp; 
}

void display(node* head)
{
    node* temp=head;

    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

  int main()
  { 
    node* head= NULL;
    insertAtTail(head,3);
    insertAtTail(head,5);
    insertAtTail(head,8);
    display(head);
    insertAtHead(head,7);
    display(head);
    
    return 0;
  }
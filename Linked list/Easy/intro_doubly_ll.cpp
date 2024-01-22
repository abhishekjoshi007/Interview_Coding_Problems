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
    {
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

//length of dll
int length(node *head)
{
    int l=0;
    node* temp=head;
    while(temp!=NULL)
    {
        l++;
        temp=temp->next;
    }
return l;

}

//append means id pos =4 last 4 elemensts will moeve in front of the LL
node* kappend(node* &head, int pos)
{   
    node* newHead;
    node* newTail;
    node* tail=head;

    int l=length(head);
    int count =1;
    pos=pos%l;

    while(tail->next!=NULL)
    {
        if(count==l-pos)
        newTail=tail;

        if(count==l-pos+1){
            newHead=tail;
        }

        tail=tail->next;
        count++;
    }

    newTail->next=NULL;
    tail->next=head;

    return newHead;
    
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
    int arr[]={6,5,7,8,4,5};

    for(int i=0;i<6;i++)
    {
        insertAtTail(head,arr[i]);
        
    }
    display(head);

    node* newHead=kappend(head, 4);
    display(newHead);
    return 0;
  }
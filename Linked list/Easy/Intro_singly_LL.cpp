  #include <iostream>
  using namespace std;

  class node
  {
    public:
    int data;
    //defining reference link 
    node* next;

    //Constructor (whwnever a new node is created using new operator constructor will be called. )
    node(int val )
    {
        data=val;
        next=NULL;
    }
  };

//here we are modifying the LL that's why we have passed by reference
  void insertAtTail(node* &head,int val)
  {
    
    node* n=new node(val);
    //if we dont have any element 
    if(head==NULL)
    {
        head=n;
        return;
    }
    node* temp=head;

    while (temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=n;

  }

void insertAtHead(node* &head,int data)
{
  node* n=new node(data);

  if(head==NULL)
  {
    head=n;
    return;
  }

  //n of head will point towards head
  n->next=head;
  head=n;
}

// searching in Node
bool search(node* head, int data)
{
  node* temp=head;
  while (temp!=NULL)
  {
    if(temp->data==data)
    {
      return true;
    }
    temp=temp->next;
  }
  return false;
}

//Deleting of node in ll
void deletion(node* &head, int data)
{   
  node* temp=head;

//no element in the ll
  if(head==NULL)
  {
    return;
  }

//1st element needs to be deleted 
 else if(temp->data==data)
 {
  head=temp->next;
  delete temp;
  return;
 }
 else {
  while(temp->next->data!=data)
  {
    temp=temp->next;
  }
  node* toDelete=temp->next;
  temp->next= temp->next->next;

  delete toDelete;
 }
}

//reverseing a ll iterative way 
node* reverse(node* &head)
{
  node* prevptr=NULL;
  node* currptr=head;
  node* nextptr;

 while(currptr!=NULL)
 {
   nextptr=currptr->next;
   currptr->next=prevptr;
    
  prevptr=currptr;
  currptr=nextptr;

 }
 return prevptr;
}

//reverseing a ll recursive way
Node* reverseRecursive(node* &head)
{
if(head==NULL ||head->next==NULL)
{
return head;
}
node* newHead=reverseRecursive(head->next);
node* front =head->next;
front->next=head;
head=NULL;

return newHead;
}

bool detectCycle(node* &head)
{
  node* slow=head;
  node* fast=head;
  
  while(fast!=NULL && fast->next!=NULL)

  {
    slow=slow->next;
    fast=fast->next->next;

    if(slow==fast)
    return true;

  }
  return false;
}

void removeCyle(node* &head)
{
 node* slow=head;
  node* fast=head;
  
  do{
     slow=slow->next;
     fast=fast->next->next;
  }
  while(slow!=fast);
  //make any one pointer to point to head
  fast=head;

  while(slow->next!=fast->next)
  {
    slow=slow->next;
    fast=fast->next;

  }
  slow->next=NULL;


}

//here we are not modifying the LL that's why we passing by value 
  void display(node* head)
  {
    //twmp pointer pointing to head 
    node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next; 
    }
    cout<<endl;

  }
  
  int main()
  {
    node* head= NULL;
    insertAtTail(head,3);
    insertAtTail(head,5);
    display(head);
    insertAtHead(head, 9);
    display(head);
    cout<< search(head,5)<<endl;
    deletion(head,5);
    display(head);

    node* newhead=reverse(head);
    display(newhead);
    
    return 0;
  }
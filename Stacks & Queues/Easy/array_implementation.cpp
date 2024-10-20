#include<iostream>
#include<stack>
using namespace std;

class Stack{
    //properties
    public:
    int *arr;
    int top;
    int size;

    //constructor
    //behavious
    Stack(int length){

        this->size=length;
        arr=new int [size];
        top=-1;
    }

    void push(int element)
    {
        if(size-top>1)
        {
            top++;
            arr[top]=element;
        }
        else{
            cout<<"Stack overflow"<<endl;
        }
    }

    void pop()
    {
        if(top>=0){
            top--;
        }
        else{
            cout<<"Stack underflow"<<endl;
        }
    }

    int peak()
    {
        if(top>=0 && top<size)
        return arr[top];

        else
        {
         cout<<"Stack is Empty"<<endl;
         return -1;
        }
    }

    bool isEmpty()
    {
        if(top<0)
        {
            return true ;
        }
        else{
            return false;
        }

    }
    
};


int main()
{
    Stack st(5);
    st.push(22);
    st.push(43);
    st.push(44);

    cout<<st.peak()<<endl;

    st.pop();

    cout<<st.peak()<<endl;

    st.pop();

    cout<<st.peak()<<endl;

     st.pop();

    if(st.isEmpty())
    {
        cout<<"stack is empty"<<endl;
    }
    else{
         cout<<"stack is not-empty"<<endl;
    }


}
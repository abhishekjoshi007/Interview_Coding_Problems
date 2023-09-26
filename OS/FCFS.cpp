#include <bits/stdc++.h>
  using namespace std;
  void FCFS(queue<int> arr, int head, int size)
  {
    //Seek_count to calculate total number of seek operations
    int seek_count=0;
    //distance to calculate the distance between head and the current disk
    int distance, curr_track;

    for(int i=0;i<size;i++)
    {
        curr_track=arr[i];

        distance=abs(curr_track-head);
        seek_count+=distance;
        head=curr_track;
    }

    
        cout<<"Total number of seek operations="<<seek_count<<endl;
  
  }
  int main()
  {
    //initilising a queue
    queue <int> sstf;
    //defining size /you can use any size of your choice
    int size=50;
    //int arr[size];
    queue<int> arr;
    //Randomly generating 50 elements in the array 
    for(int i=0;i<size;i++)
    {
        arr.push(rand()%100);
    }
    while (!arr.empty()) {
         cout<<arr.front();
        arr.pop();
    }
    


    //initilising Head as 50 
    int head=50;
    
    //Calling function FCFS
    FCFS(arr, head, size);
    
    return 0;
  }
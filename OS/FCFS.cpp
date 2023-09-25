#include <bits/stdc++.h>
  using namespace std;
  void FCFS(int arr[], int head, int size)
  {
    int seek_count=0;
    int distance, curr_track;

    for(int i=0;i<size;i++)
    {
        curr_track=arr[i];

        distance=abs(curr_track-head);
        seek_count+=distance;

        head=curr_track;
    }

    
        cout<<seek_count<<endl;
  
  }
  int main()
  {
    int size=50;
    int arr[size];
    //Randomly generating 50 elements in the array 
    for(int i=0;i<size;i++)
    {
        arr[i]=rand()%100;
    }

    //initilising Head 
    int head=50;

    FCFS(arr, head, size);
    
    return 0;
  }
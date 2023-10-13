//Problem -https://www.geeksforgeeks.org/generate-binary-strings-without-consecutive-1s/
 
/*
Idea
to print all binary no without consecutive 1s 
K : size of string 
First We Generate All string starts with '0'
initialize n = 1 . 
GenerateALLString ( K  , Str , n )
  a. IF n == K 
     PRINT str.
  b. IF previous character is '1' :: str[n-1] == '1'
     put str[n] = '0'
     GenerateAllString ( K , str , n+1 )
  c. IF previous character is '0' :: str[n-1] == '0'
     First We Put zero at end and call function 
      PUT  str[n] = '0'
           GenerateAllString ( K , str , n+1 )  
      PUT  str[n] = '1'
           GenerateAllString ( K , str , n+1 )

Second Generate all binary string starts with '1'
DO THE SAME PROCESS

*/ 


#include <bits/stdc++.h>
  using namespace std;
  void printbinary(int arr[],int k, int n)
  {
    if(k==n)
    {
      for(int i=0;i<n;i++)
      {
        cout<<arr[i];
      }
      cout<<endl;
      return;
      
    }
    
    if(arr[k-1]==0)
    {
      arr[k]=0;
      printbinary(arr,k+1,n);
      arr[k]=1;
      printbinary(arr,k+1,n);
    }
    else if(arr[k-1] == 1){
      arr[k]=0;
      printbinary(arr,k+1,n);
    }
    
  }
  int main()
  {
    int t;
    cin>>t;
    
    while (t--)
    {
      int n;
      cin>>n;
      //to store the elements ``
      int arr[n];
      
      arr[0]=0;
      
      printbinary(arr,1,n);
      arr[0]=1;
      
      printbinary(arr,1,n);
      
    }
    
    return 0;
  }
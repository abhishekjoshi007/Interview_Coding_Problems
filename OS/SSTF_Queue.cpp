#include <bits/stdc++.h>
using namespace std;
int main()
{
  int t;
  cin>>t;
  while(t--){
    string str;
    cin>>str;
    int freq[26]={0}; //creating frequency array and initilize to 0
       for(int i=0;i<str.length();i++)
    {
      freq[str[i]-'a']++;     //freq counting
    }
    int flag=0;
    for(int i=0;i<26;i++)
    {
      if(freq[i]>1)    //a[i] for character
      {
      flag=1;
       cout<<char('freq'+i)<<"="<<freq[i]<<" ";  //see char initilize
      freq[i]=0;
      }
  }
     if(flag==0)
     {
       cout<<"-1";
     }
    cout<<endl;
  }
  return 0;
}
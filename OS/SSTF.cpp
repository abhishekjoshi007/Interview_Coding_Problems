/*Using a programming language of your choice, implement the SSTF algorithm. You will use a queue to store the 
next location to move the disk head. Randomly generate these numbers. Place 50 of them in the queue and then 
let the algorithm run. Finally, as the output let it print the total movement in the number of cylinders. 
Properly comment/document your code.*/

#include <bits/stdc++.h>
using namespace std;
    
    // Function to calculate absolute seek time
    int calSeekTime(int currentPos,int nextPos)
    {
        return abs(nextPos-currentPos);
    }
    
  int main()
  {
    int size=50;

    //dynamic vector of size 50
    vector<int> arr(size);

    //Randomly putting up element in the vector array of size 50 
    for(int i=0;i<arr.size();i++)
    {
        arr[i]=rand()%100;
    }
    
    int totalCount=0,  currentPosition = 60; // Starting position (you can change this as needed)
    while(!arr.empty())
    {
        int minseektime=INT_MAX;
        int nearestPointer=-1;
        // Find the nearest request
        for (int i = 0; i < arr.size(); ++i) {
            int request = arr[i];
            int seekTime=calSeekTime(currentPosition,request);
            if(seekTime<minseektime)
            {
                minseektime=seekTime;
                nearestPointer=i;
            }
            }
        
        // Calculate seek time to the nearest request
        totalCount += minseektime;

        // Update the current position
        currentPosition = arr[nearestPointer];

        // Remove the processed request from the vector 
        arr.erase(arr.begin() + nearestPointer);
      
      cout << "Disk head moved to cylinder " << currentPosition << ", Total Movement: " << totalCount << " cylinders" << endl;
    }

    

    
    cout << "Total movement of the disk head: " << totalCount << " cylinders" << endl;  
            
    return 0;
  
  }
#include <bits/stdc++.h>
using namespace std;

int main() {
    
    //To cal. total movement in the number of cylinders.
    int totalMovement = 0;
    // Starting position (you can change this as needed)
    int currentPosition = 30; 

    //initialising a queue then filling it up with random 50 numbers 
    queue<int> requestQueue;
        for (int i=0;i<50;i++)
            {
                queue.push(rand()%100);
            }
        
       

    while (!requestQueue.empty()) {
        
        //miniSeekTime to cal the minimum distance among the giving cylinder 
        int minSeekTime = INT_MAX;
        //to tranck down the nearest cylinder 
        int nearestRequest = -1;

        // Find the nearest request in the queues
        queue<int> tempQueue;
        
        while (!requestQueue.empty()) {
            int request = requestQueue.front();
            
            int seekTime = abs(currentPosition - request);
            if (seekTime < minSeekTime) {
                minSeekTime = seekTime;
                nearestRequest = request;
            }
            tempQueue.push(requestQueue.front());
            requestQueue.pop();
        }
        
        

        // Calculate seek time to the nearest request
        totalMovement += minSeekTime;

        // Update the current position
        currentPosition = nearestRequest;
        int found=0;
        // Restore the queue with remaining requests
        while (!tempQueue.empty()) 
        {
        	
            if(tempQueue.front()==currentPosition && found==0)
            {
            // If the current front of the queue is currentposition and
           // we have not found it earlier, i.e. found==0 then, this is the first
           // occurrence. So we pop it out and don't insert into the vector
           tempQueue.pop();
           found = 1; // Update the value of found to 1 as we have found the first occurrence
           // of k in this cas
            }
            else {
            requestQueue.push(tempQueue.front());
            tempQueue.pop();
            }
            
        }
        cout << "Disk head moved to cylinder " << currentPosition << ", Total Movement: " << totalMovement << " cylinders" << endl;
    }
    cout << "Total movement of the disk head: " << totalMovement << " cylinders" << endl;
    return 0;
}

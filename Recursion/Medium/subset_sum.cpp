/*https://practice.geeksforgeeks.org/problems/subset-sums2234/1*/

class solution {
public:
    void ss(vector<int> arr, vector<int> &ans, int i, int sum)
    {
        if(i==arr.size())
        {   
            
            ans.push_back(sum);
            return;
        }
        
        //include 
        ss(arr,ans,i+1,sum+arr[i]);
        
        //exclude 
        ss(arr,ans,i+1, sum);
        
    }

    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int >ans;
       
        int i=0,sum=0;
        
        ss(arr,ans,i,sum);
        return ans;
        
    }
}
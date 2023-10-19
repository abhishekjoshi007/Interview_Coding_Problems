/*https://leetcode.com/problems/permutation-sequence/description/

Algo-
1- think like you will fix the first element and find permutation of rest 
2- repeat the above process
3- we need to take care of fact variable and k variable which the term of the sequence 
4- erase elemnet from the sequence 

Video - https://www.youtube.com/watch?v=wT7gcXLYoao&t=115s

*/



class Solution {

public:
    string getPermutation(int n, int k) {
        //for factorial of n-1 numbers
        int fact=1;

        //for storing n numbers 
        vector<int> nums;

        for(int i=1;i<n;i++)
        {
            fact=fact*i;
            nums.push_back(i);
        }
        nums.push_back(n);

        string ans="";
        k=k-1;

        while(n--)
        {
            ans+=to_string(nums[k/fact]);
            nums.erase(nums.begin()+k/fact);

            if(nums.size()==0)
            {
                break;
            }
            k=k%fact;
            //imp
            fact=fact/nums.size();

        }
        return ans;

    }
};

public:
    string getPermutation(int n, int k) {
        //for factorial of n-1 numbers
        int fact=1;

        //for storing n numbers 
        vector<int> nums;

        for(int i=1;i<n;i++)
        {
            fact=fact*i;
            nums.push_back(i);
        }
        nums.push_back(n);

        string ans="";
        k=k-1;

        while(true)
        {
            ans+=to_string(nums[k/fact]);
            nums.erase(nums.begin()+k/fact);

            if(nums.size()==0)
            {
                break;
            }
            k=k%fact;
            //imp
            fact=fact/nums.size();

        }
        return ans;

    }
};
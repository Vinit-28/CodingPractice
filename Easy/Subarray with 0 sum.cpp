

// Question Link :: "https://practice.geeksforgeeks.org/problems/subarray-with-0-sum-1587115621/1#"


// Solution //

class Solution{
    public:
    //Complete this function
    //Function to check whether there is a subarray present with 0-sum or not.
    bool subArrayExists(int arr[], int n)
    {
        //Your code here
        map<int, bool> hash;
        
        for(int i=0,sum=0; i<n;i++){
            
            sum += arr[i];
            if( hash[sum] )
                return true;
            hash[sum]=true;
        }
        return hash[0];
    }
};


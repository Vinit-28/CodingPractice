

// Question Link :: "https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1"


// Solution //

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        // Your code here
        int ans=0, sum=0;
        map<int, int> hash;
        
        for(int i=0;i<n;i++){
            
            sum += A[i];
            
            if( hash[sum] > 0 || sum==0){
                ans = max(ans, (i+1) - hash[sum] );
            }
            else{
                hash[sum] = i+1;
            }
        }
        return ans;
    }
};



// Question Link :: "https://practice.geeksforgeeks.org/problems/smallest-subarray-with-sum-greater-than-x5651/1"


// Solution //

class Solution{
  public:

    int smallestSubWithSum(int arr[], int n, int x)
    {
        // Your code goes here  
        int sum=0, start=0, ans=INT_MAX;
        
        for(int i=0;i<n;i++){
            
            sum+= arr[i];
            
            while((sum-arr[start])>x) sum-=arr[start], start++;
            
            ans = (sum > x)? min(ans, (i-start)+1) : ans;
        }
        
        return ans;
    }
};

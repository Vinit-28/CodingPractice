

// Question Link :: "https://practice.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1"


// Solution //

class Solution{
    public:
    int maxSubarraySum(int arr[], int n){
        
        // Your code here
        int sum=arr[0], max_sum=arr[0];
        for(int i=1;i<n;i++){
            
            sum = max(arr[i], arr[i]+sum);
            max_sum = max(sum,max_sum);
        }
        return max_sum;
    }
};

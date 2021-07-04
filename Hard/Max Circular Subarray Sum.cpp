

// Question Link :: "https://practice.geeksforgeeks.org/problems/max-circular-subarray-sum-1587115620/1"


// Solution //

class Solution{
    public:
    // arr: input array
    // num: size of array
    //Function to find maximum circular subarray sum.
    int circularSubarraySum(int arr[], int num){
        
        // your code here
        int sum1 = arr[0], sum2 = arr[0], max_positive_sum = arr[0], max_negative_sum= arr[0], total_sum = arr[0];
        
        for(int i=1;i<num;i++){
            
            sum1 = max(arr[i], arr[i]+sum1);
            sum2 = min(arr[i], arr[i]+sum2);
            
            max_positive_sum = max(max_positive_sum, sum1);
            max_negative_sum = min(max_negative_sum, sum2);
            total_sum += arr[i];
        }
        if( total_sum != max_negative_sum )
            return max(max_positive_sum , (total_sum - max_negative_sum));
        return max_positive_sum;
    }
};
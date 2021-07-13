

// Question Link :: "https://practice.geeksforgeeks.org/problems/subarrays-with-sum-k/1#"


// Solution //

class Solution{
    public:
    int findSubArraySum(int arr[], int n, int k)
    {
        // code here
        int ans = 0, sum = 0;
        map<int, int> freq;
        freq[sum] = 1;
        
        for(int i=0;i<n;i++){
            sum += arr[i];
            ans += freq[sum-k];
            freq[sum]+=1;
        }
        return ans;
    }
};
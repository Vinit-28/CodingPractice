

// Question Link :: "https://leetcode.com/problems/shortest-unsorted-continuous-subarray/"


// Solution //

class Solution {
public:
    
    
    int findUnsortedSubarray(vector<int>& nums) {
        
        int start=-1, end=-1, n = nums.size();
        int maxi = nums[0], mini = nums[n-1];
        
        for(int i=1;i<n;i++){
            if( nums[i] < maxi ) end = i;
            else maxi = nums[i];
        }
        
        for(int i=n-2;i>=0;i--){
            if( nums[i] > mini ) start = i;
            else mini = nums[i];
        }
        
        return (start == -1)? 0 : (end-start+1);
    }
};
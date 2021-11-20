

// Question Link :: "https://leetcode.com/problems/rotate-array/"


// Solution //

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        int n = nums.size(), i;
        
        if( k <= n ){
            vector<int> temp(n);
            for(i=0;i<k;i++)
                temp[i] = nums[n-k+i];
            for(i; i<n; i++)
                temp[i] = nums[i-k];

            nums=temp;
        }
        else{
            rotate(nums, n);
            rotate(nums, k-n);
        }
    }
};
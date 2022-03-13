

// Question Link :: "https://leetcode.com/problems/maximize-the-topmost-element-after-k-moves/"


// Solution //

class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {

        int n = nums.size(), maxi=0;
        
        if( k == 0 ) return nums[0];
        else if( n==1 && (k&1) ) return -1;
        
        if( k<=n ){
            for(int i=0;i<(k-1);i++) maxi = max(maxi, nums[i]);
            maxi = (k==n)? maxi : max(maxi, nums[k]);
        }
        else{
            for(int i=0;i<n;i++) maxi = max(maxi, nums[i]);
        }
        return maxi;
    }
};
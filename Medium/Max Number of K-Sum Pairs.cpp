

// Question Link :: "https://leetcode.com/problems/max-number-of-k-sum-pairs/"


// Solution //

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        
        int n = nums.size();
        if( n == 1 ) return 0;
        
        sort(nums.begin(), nums.end());
        int i = 0, j = n-1, ans = 0;
        while( i<j ){
            int sum = (nums[i] + nums[j]);
            if( sum == k ) ans += 1, i += 1, j -= 1;
            else if( sum > k ) j -= 1;
            else i += 1;
        }
        return ans;
    }
};


// Question Link :: "https://leetcode.com/problems/arithmetic-slices-ii-subsequence/"


// Solution //

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        
        int n=nums.size(), ans=0;
        vector<unordered_map<int, int>> hash(n);
        
        for(int i=0;i<n;i++) 
            for(int j=0;j<i;j++){
                
                long int diff = long(nums[j])-long(nums[i]);
                
                if( diff <= INT_MIN || diff >= INT_MAX )
                    continue;
                
                int dif = int(diff);
                
                ans += hash[j][dif];
                hash[i][dif] += (hash[j][dif]+1);
            }
        return ans;
    }
};

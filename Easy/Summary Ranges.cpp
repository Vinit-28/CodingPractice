

// Question Link :: "https://leetcode.com/problems/summary-ranges/"


// Solution //

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        
        vector<string> ans;
        int start, last, n=nums.size();
        if( !n ) return ans;
        
        start = last = nums[0];
        for(int i=1;i<n;i++){
            if( nums[i] == nums[i-1]+1 ) last = nums[i];
            else{
                string range = (start==last)? (to_string(start)) : (to_string(start) + "->" + to_string(last));
                ans.push_back( range );
                start = last = nums[i];
            }
        }
        ans.push_back( (start==last)? (to_string(start)) : (to_string(start) + "->" + to_string(last)) );
        return ans;
    }
};


// Question Link :: "https://leetcode.com/problems/longest-consecutive-sequence/"


// Solution //

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        if( nums.size() == 0 || nums.size() == 1 ) return nums.size();
        map<int, bool> hash;
        int nextMax = INT_MIN, ans=1;
        for(auto &ele : nums){
            hash[ele] = true;
        }
        
        for(auto &p : hash){
            
            if( p.first > nextMax ){
                int count = 1, ele = p.first+1;
                while( hash.find(ele) != hash.end() ) count+=1, ele+=1;
                ans = max(ans, count);
                nextMax = ele-1;
            }
        }
        return ans;
    }
};


// Question Link :: "https://leetcode.com/problems/contiguous-array/"


// Solution //

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        
        unordered_map<int, int> hash;
        int zero=0, one=0, n=nums.size(), ans=0;
        auto hashEnd = hash.end();
        
        hash[0] = -1;
        for(int i=0;i<n;i++){
            
            (nums[i])? one++ : zero++;
            
            if( hash.find( (zero-one) ) != hashEnd ){
                ans = max(ans, (i - hash[(zero-one)]) );
            }
            else{
                hash[(zero-one)] = i;
            }
        }
        
        return ans;
    }
};
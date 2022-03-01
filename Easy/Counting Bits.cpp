

// Question Link :: "https://leetcode.com/problems/counting-bits/"


// Solution //

class Solution {
public:
    vector<int> countBits(int n) {
        
        vector<int> ans(n+1, 0);
        for(int i=31;i>=0;i--){
            
            for(int j=0;j<=n;j++){
                int bit = ((j>>i)&1);
                ans[j] += bit;
            }
        }
        return ans;
    }
};
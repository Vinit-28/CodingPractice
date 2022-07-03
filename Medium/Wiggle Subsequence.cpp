

// Question Link :: "https://leetcode.com/problems/wiggle-subsequence/"


// Solution //

class Solution {
public:
    
    char getSign(int &num){
        return num >= 0? '+' : '-';
    }
    
    int wiggleMaxLength(vector<int>& nums) {
        
        int n = nums.size();
        char signs[n];
        int ans[n];

        for(int i=0;i<n;i++){
            
            ans[i] = 1;
            for(int j=0;j<i;j++){
                
                int diff = nums[i] - nums[j];
                if( diff!=0 && ans[j] >= ans[i] && ( ans[j] == 1 || getSign(diff) != signs[j] ) ){
                    signs[i] = getSign(diff);
                    ans[i] = ans[j]+1;
                }
            }
        }
        
        return ans[n-1];
    }
};
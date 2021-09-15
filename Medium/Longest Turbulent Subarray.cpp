

// Question Link :: "https://leetcode.com/problems/longest-turbulent-subarray/"


// Solution //

class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        
        int S=1, B=1, ans=1;
        
        for(int i=arr.size()-2; i>=0; i--){
            
            if( arr[i] < arr[i+1] ) S = 1 + B, B = 1;
            else if( arr[i] > arr[i+1] ) B = 1 + S, S = 1;
            else S=1, B=1;
            ans = max(ans, max(S, B));
        }
        return ans;
    }
};
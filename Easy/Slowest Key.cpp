

// Question Link :: "https://leetcode.com/problems/slowest-key/"


// Solution //

class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        
        char ans=keysPressed[0];
        int maxi=releaseTimes[0];
        for(int i=1;i<releaseTimes.size();i++){
            
            int diff = (releaseTimes[i] - releaseTimes[i - 1]);
            if( (maxi < diff) || (maxi == diff && keysPressed[i] > ans) )
                maxi = diff, ans = keysPressed[i];
        }
        return ans;
    }
};


// Question Link :: "https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/"


// Solution //

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        
        map<string, bool> uniqueSubs;
        int n = s.length();
        
        for(int i=0;(i+k)<=n;i++){
            
            uniqueSubs[s.substr(i, k)] = true;
        }
        
        if( uniqueSubs.size() == (1<<k) ) return true;
        
        return false;
    }
};
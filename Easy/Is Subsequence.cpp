

// Question Link :: "https://leetcode.com/problems/is-subsequence/"


// Solution //

class Solution {
public:
    bool isSubsequence(string s, string t) {
        
        int sIndex=0, tIndex=0, sLen = s.length(), tLen = t.length();
        
        while( (sIndex < sLen) && (tIndex < tLen) ){
            
            if( s[sIndex] == t[tIndex] ) sIndex+=1;
            
            tIndex+=1;
        }
        return (sIndex >= sLen);
    }
};
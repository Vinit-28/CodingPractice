

// Question Link :: "https://leetcode.com/problems/implement-strstr/"


// Solution //

class Solution {
public:
    
    bool isMatch(string &haystack, string &needle, int iH, int &neeLen){
        
        for(int iN=0; iN<neeLen; iH++, iN++){
            if( haystack[iH] != needle[iN] ) return false;
        }
        return true;
    }
    
    
    int strStr(string haystack, string needle) {
        
        if( needle == "" ) return 0;
        
        int hayLen = haystack.length(), neeLen = needle.length();
        
        for(int i=0;i<=hayLen-neeLen;i++){
            
            if( haystack[i] == needle[0] && haystack[i+neeLen-1] == needle[neeLen-1] && isMatch(haystack, needle, i, neeLen) ){
                return i;
            }
        }
        return -1;
    }
};
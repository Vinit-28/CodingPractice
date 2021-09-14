

// Question Link :: "https://leetcode.com/problems/reverse-only-letters/"


// Solution //

class Solution {
public:
    
    bool isValid(char c){
        return ( c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z' );
    }
    
    string reverseOnlyLetters(string s) {
        
        string ans = s;
        
        for(int i=0,j=s.length()-1;i<j;){
            
            if( isValid(s[i])==false ) ans[i] = s[i], i++;
            
            else if( isValid(s[j])==false ) ans[j] = s[j], j--;
            
            else ans[i] = s[j], ans[j] = s[i], i++, j--;
        }
        
        return ans;
    }
};
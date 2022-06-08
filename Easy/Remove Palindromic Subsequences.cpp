

// Question Link :: "https://leetcode.com/problems/remove-palindromic-subsequences/"


// Solution //

class Solution {
public:
    
    bool isPalindrome(string &s){
        
        int i=0, j=s.length()-1;
        while(i<j){
            if( s[i] != s[j] ) return false;
            i+=1,j-=1;
        }
        return true;
    }
    
    int removePalindromeSub(string s) {
        
        return isPalindrome(s)? 1 : 2;
    }
};
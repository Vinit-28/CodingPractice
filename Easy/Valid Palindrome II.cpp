

// Question Link :: "https://leetcode.com/problems/valid-palindrome-ii/"


// Solution //

class Solution {
public:
    bool validPalindrome(string s) {
        
        bool isAlreadyDeleted = false;
        return validPalindrome_Helper(s, 0, s.length()-1, isAlreadyDeleted);
    }
    
    
    bool validPalindrome_Helper(string &s, int i, int j, bool &isAlreadyDeleted){
        
        while( i<j ){
            
            if( s[i] != s[j] ){
                
                if( isAlreadyDeleted ) return false;
                
                if( s[i+1] == s[j]  ){
                    isAlreadyDeleted = true;
                    if( validPalindrome_Helper(s, i+1, j, isAlreadyDeleted) ) return true;
                }
                if( s[i] == s[j-1]  ){
                    isAlreadyDeleted = true;
                    if( validPalindrome_Helper(s, i, j-1, isAlreadyDeleted) ) return true;
                }
                return false;
            }
            
            i+=1, j-=1;
        }
        return true;
    }
};
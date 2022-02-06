

// Question Link :: "https://leetcode.com/problems/palindrome-number/"


// Solution //

class Solution {
public:
    
    bool isValidToDo(int &reversed, int rem){
        
        int rev = abs(reversed);
        return !( rev == INT_MAX || (rev+rem) >= ((INT_MAX/10) + (INT_MAX%10)) );
    }
    
    bool isPalindrome(int x) {
        
        int reversed=0, backup = x;
        
        while(x>0)
            if( isValidToDo(reversed, (x%10)) )
                reversed = (reversed*10) + (x%10), x/=10;
            else
                break;
        
        return (reversed == backup);
    }
};
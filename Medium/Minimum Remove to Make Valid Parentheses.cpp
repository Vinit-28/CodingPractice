

// Question Link :: "https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/"


// Solution //

class Solution {
public:
    
    string minRemoveToMakeValid(string s) {
        
        stack<char> open, close;
        int n = s.length();
        string newString = "";
        
        // Eleminating all the extra closed paranthesis ')' //        
        for(int i=0;i<n;i++){
            
            if( s[i] == '(' || s[i] != ')' || (s[i] == ')' && open.size()) ){
                newString += s[i];
                
                if( s[i] == '(') open.push(s[i]);
                else if( s[i] == ')' ) open.pop();
            }
        }
        
        s = newString, newString = "";
        // Eleminating all the extra open paranthesis '(' //        
        for(int i=s.length()-1;i>=0;i--){
            
            if( s[i] == ')' || s[i] != '(' || (s[i] == '(' && close.size()) ){
                newString += s[i];
                
                if( s[i] == ')') close.push(s[i]);
                else if( s[i] == '(' ) close.pop();
            }
        }
        reverse(newString.begin(), newString.end());
        return newString;
    }
};
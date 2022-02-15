

// Question Link :: "https://leetcode.com/problems/generate-parentheses/"


// Solution //

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        
        vector<string> combinations;
        int open = 0, close = 0;
        generateCombinations(open, close, n, "", combinations);
        return combinations;
    }
    
    void generateCombinations(int &open, int &close, int &limit, string pattern, vector<string> &combinations){
        
        if( open == limit && close == limit ){
            combinations.push_back(pattern);
            return;
        }
        
        if( open < limit ){
            open++;
            generateCombinations(open, close, limit, pattern+"(", combinations);
            open--;
        }
        
        if( close < open && close < limit ){
            close++;
            generateCombinations(open, close, limit, pattern+")", combinations);
            close--;
        }
    }
};
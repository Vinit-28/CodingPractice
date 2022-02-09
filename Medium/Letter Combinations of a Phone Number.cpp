

// Question Link :: "https://leetcode.com/problems/letter-combinations-of-a-phone-number/"


// Solution //

class Solution {
public:
    
    vector<string> combinations;
    unordered_map<char, string> patterns;
    
    Solution(){
        patterns['2'] = "abc";
        patterns['3'] = "def";
        patterns['4'] = "ghi";
        patterns['5'] = "jkl";
        patterns['6'] = "mno";
        patterns['7'] = "pqrs";
        patterns['8'] = "tuv";
        patterns['9'] = "wxyz";  
    }
    
    void findLetterCombinations(string &digits, int &digitLen, int digitIndex, string combination){
        
        if( digitIndex >= digitLen ){
            if( combination != "" ) combinations.push_back(combination);
            return;
        }
        string pattern = patterns[digits[digitIndex]];
        
        for(auto &ch : pattern){
            findLetterCombinations(digits, digitLen, digitIndex+1, combination+ch);
        }
    }
    
    
    vector<string> letterCombinations(string digits) {
        combinations.clear();
        int digitLen = digits.length();
        cout<<endl;
        findLetterCombinations(digits, digitLen, 0, "");
        return combinations;
    }
};
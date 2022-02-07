

// Question Link :: "https://leetcode.com/problems/find-the-difference/"


// Solution //

class Solution {
public:
    char findTheDifference(string s, string t) {
        
        int sum_s=0, sum_t=0;
        
        for(auto &ch : s) sum_s += int(ch);
        
        for(auto &ch : t) sum_t += int(ch);
        
        return char(sum_t-sum_s);
    }
};
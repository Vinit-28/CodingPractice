

// Question Link :: "https://leetcode.com/problems/maximum-number-of-balloons/"


// Solution //

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        
        string s = "balon";
        int dict[26], ans=INT_MAX;
        memset(dict, 0, sizeof(dict));
        
        for(int i=0;text[i];i++) dict[text[i]-'a']++;
        
        for(int i=0;s[i];i++) ans = min( ans, (s[i]=='l' || s[i]=='o')? (dict[s[i]-'a']/2) : dict[s[i]-'a'] );
        
        return ans;
    }
};
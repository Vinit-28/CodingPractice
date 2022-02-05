

// Question Link :: "https://leetcode.com/problems/longest-common-prefix/"


// Solution //

class Solution {
public:
    
    
    string getLCP(string &s1, string &s2){
        
        string lcp = "";
        int n1 = s1.length(), n2 = s2.length();
        
        for(int i=0; (i<n1 && i<n2 && s1[i] == s2[i]); lcp+=s1[i], i++);
        return lcp;
    }
    
    
    string longestCommonPrefix(vector<string>& strs) {
       
        string lcp="";
        int index = 0;
        for(auto &s : strs){
            if( index == 0 ) lcp = getLCP(s, s);
            else lcp = getLCP(s,lcp);
            
            index++;
        }
        return lcp;
    }
};
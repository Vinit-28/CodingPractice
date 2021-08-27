

// Question Link :: "https://leetcode.com/problems/longest-uncommon-subsequence-ii/"


// Solution //

class Solution {
public:
    
    
    bool isSubsequence(string &s1, string &s2){
        
        int i=0,j=0;
        
        while(s1[i] && s2[j]){
            
            if( s1[i] == s2[j] )
                i++;
            j++;
        }
        return (s1[i]==0);
    }
    
    int findLUSlength(vector<string>& strs) {
        
        int answer=0, n=strs.size();
        
        for(int i=0;i<n;i++){
            
            bool isFound = false;
            for(int j=0;j<n;j++){
                
                if( j!=i )
                    if( isSubsequence(strs[i], strs[j]) ){
                        isFound = true;
                        goto bhar;
                    }
            }
            bhar: {}
            if( isFound==false ){
                int len = strs[i].length();
                answer = max(answer, len);
            }
        }
        return (answer==0)? -1 : answer;
    }
};
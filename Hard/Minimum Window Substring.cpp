

// Question Lik :: "https://leetcode.com/problems/minimum-window-substring/"


// Solution //

class Solution {
public:
    string minWindow(string s, string p)
    {
        // Your code here
        string ans="";
        int plen = p.length(), slen = s.length();
        
        if( slen >= plen ){
            
            map<char, int> pchars, found;
            int charFound = 0, i, tempStart=0, ansStart=INT_MIN, ansEnd = INT_MAX;
            
            for(i=0; i<plen; pchars[p[i]]++, i++);
            
            for(i=0;i<slen;i++){
                
                if( pchars[s[i]] > 0 ){
                    
                    found[s[i]]++;
                    charFound = ( found[s[i]] <= pchars[s[i]] )? charFound+1 : charFound;
                }
                
                if( charFound == plen ){
                    
                    // Minimizing the Window //
                    while( pchars[s[tempStart]] < 1 || found[s[tempStart]] > pchars[s[tempStart]] )
                        found[s[tempStart]]--, tempStart++;
                    
                    if( ansStart == INT_MIN || abs(ansStart-ansEnd) > abs(tempStart - i) ){
                        ansStart = tempStart, ansEnd = i;
                    }
                    found[s[tempStart]]--, tempStart++, charFound--; 
                }
            }
            if( ansStart != INT_MIN )
                for(i=ansStart,ans=""; i<=ansEnd; ans+=s[i],i++);
        }
        return ans;
    }
};


// Question Link :: "https://leetcode.com/problems/long-pressed-name/"


// Solution //

class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int i=0, j=0, n1=name.length(), n2 = typed.length();
        
        for(; j<n2; ){
            
            if( i<n1 ){
                if( name[i] == typed[j] ) i++;
                else if( i==0 || name[i-1] != typed[j] ) return false;
            }
            else if( name[n1-1] != typed[j] ) return false;
            j++;
        }
        return (i>=n1);
    }
};
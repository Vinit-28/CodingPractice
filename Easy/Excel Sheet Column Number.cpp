

// Question Link :: "https://leetcode.com/problems/excel-sheet-column-number/"


// Solution //

class Solution {
public:
    
    int toInt(char &ch){
        return (ch-65)+1;
    }
    
    int titleToNumber(string columnTitle) {
        
        int len = columnTitle.length(), ans = 0;
        
        for(int i=0;i<len;i++){
            ans += (pow(26, (len-i-1)) * toInt(columnTitle[i]));
        }
        return ans;
    }
};
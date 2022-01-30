

// Question Link :: "https://leetcode.com/problems/roman-to-integer/"


// Solution //

class Solution {
public:
    map<char, int> hash = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
    
    
    int romanToInt(string s) {
        
        int num=0, n=s.length();
        
        for(int i=0; i<n; ){
            
            if( i < n-1 ){
                if( s[i] == 'I' && s[i+1] == 'V' )
                    num += 4, i+=2;
                else if( s[i] == 'I' && s[i+1] == 'X' )
                    num += 9, i+=2;
                else if( s[i] == 'X' && s[i+1] == 'L' )
                    num += 40, i+=2;
                else if( s[i] == 'X' && s[i+1] == 'C' )
                    num += 90, i+=2;
                else if( s[i] == 'C' && s[i+1] == 'D' )
                    num += 400, i+=2;
                else if( s[i] == 'C' && s[i+1] == 'M' )
                    num += 900, i+=2;
                else
                    num +=hash[s[i]], i+=1;
            }
            else
                num +=hash[s[i]], i+=1;
        }
        return num;
    }
};
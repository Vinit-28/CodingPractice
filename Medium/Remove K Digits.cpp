

// Question Link :: "https://leetcode.com/problems/remove-k-digits/"


// Solution //

class Solution {
public:
    
    string removeKdigits(string num, int k) {
        
        vector<char> numStack;
        int len = num.length(), n;
        
        for(int i=0;i<len;i++){
            
            if( numStack.size() == 0 && num[i] != '0' ) numStack.push_back(num[i]);
            else{
                
                while( k && numStack.size() && numStack.back() > num[i] ) numStack.pop_back(), k--;
                
                if( numStack.size() || ( numStack.size() == 0 && num[i] != '0' )  ) numStack.push_back(num[i]);
            }
        }
        n = (k)? (numStack.size()-k) : numStack.size();
        num = "";
        
        for(int i=0;i<n;i++) num += numStack[i];
        
        return (num=="")? "0" : num;
    }
};
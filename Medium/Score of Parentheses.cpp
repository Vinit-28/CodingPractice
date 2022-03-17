

// Question Link :: "https://leetcode.com/problems/score-of-parentheses/"


// Solution //

class Solution {
public:
    int scoreOfParentheses(string s) {
        
        vector<int> st;
        int len = s.length();
        st.push_back(0);
        
        for(int i=0;i<len;i++){
            
            if( s[i] == '(' ){
                st.push_back(0);
            }
            else{
                int top = st.back(), stLen = st.size()-1;
                st.pop_back();
                st[stLen-1] += (top == 0)? 2 : top*2;
            }
        }
        return st.back()/2;
    }
};
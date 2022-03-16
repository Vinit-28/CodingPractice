

// Question Link :: "https://leetcode.com/problems/validate-stack-sequences/"


// Solution //

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        
        stack<int> st;
        int pushedIndex = 0, poppedIndex = 0, pushedLen = pushed.size(), poppedLen = popped.size();
        bool doContinue = true;
        while(doContinue){
            
            doContinue = false;
            if( pushedIndex < pushedLen && (st.size() == 0 || st.top() != popped[poppedIndex]) ){
                st.push(pushed[pushedIndex]);
                pushedIndex+=1;
                doContinue = true;
            }
            else if( st.size() && st.top() == popped[poppedIndex] ){
                st.pop();
                poppedIndex += 1;
                doContinue = true;
            }
        }
        return st.empty();
    }
};
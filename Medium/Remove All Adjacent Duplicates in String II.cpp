

// Question Link :: "https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/"


// Solution //

class Solution {
public:
    string removeDuplicates(string s, int k) {
        
        int len = s.length(), size=1;
        vector<pair<char, int>> st;
        st.push_back({s[0], 1});
        
        for(int i=1;i<len;i++){
            
            if( !size ) st.push_back({s[i], 1}), size += 1;
            else{
                auto top = st.back();
                if( top.first == s[i] ){
                    if( (top.second+1) == k ){
                        int temp = k;
                        while( temp > 1 ) st.pop_back(), temp -= 1, size -= 1;
                    }
                    else st.push_back({s[i], top.second+1}), size += 1;
                }
                else st.push_back({s[i], 1}), size += 1;
            }
        }
        s = "";
        for(auto &p : st){
            s += p.first;
        }
        return s;
    }
};
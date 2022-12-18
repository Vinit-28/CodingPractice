

// Question Link :: "https://leetcode.com/problems/daily-temperatures/description/"


// Solution //
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        int n = t.size();
        vector<int> ans(n, 0);
        stack<int> s;
        s.push(n-1);
        for(int i=n-2;i>=0;i--){
            while( !s.empty() && t[i] >= t[s.top()] ) s.pop();
            if( !s.empty() ) ans[i] = s.top()-i;
            s.push(i);
        }
        return ans;
    }
};
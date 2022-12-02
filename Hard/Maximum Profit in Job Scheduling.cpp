

// Question Link :: "https://leetcode.com/problems/maximum-profit-in-job-scheduling/description/"


// Solution //

class Solution {
public:

    int getIndex(vector<vector<int>> &lst, int st, int ed, int curr_index){
        int md = (st+ed)/2, index=-1;
        while(st<=ed){
            if( lst[md][0] >= lst[curr_index][1] ) index = md, ed = md-1;
            else st = md+1;
            md = (st+ed)/2;
        }
        return index;
    }

    int jobScheduling(vector<int>& st, vector<int>& et, vector<int>& p) {
        
        int n = st.size(), dp[n], ans=0, index;
        vector<vector<int>> lst;
        for(int i=0;i<n;i++) lst.push_back({st[i], et[i], p[i]});
        
        sort(lst.begin(), lst.end());
        for(int i=n-1;i>=0;i--){
            dp[i] = lst[i][2];
            index = getIndex(lst, i+1, n-1, i);
            if( index != -1 ){
                dp[i] = max(dp[i], (lst[i][2] + dp[index]));
            }
            ans = max(ans, dp[i]);
            dp[i] = ans;
        }
        return dp[0];
    }
};
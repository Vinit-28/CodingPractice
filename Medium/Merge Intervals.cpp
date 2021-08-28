

// Question Link :: "https://leetcode.com/problems/merge-intervals/"


// Solution //

class Solution {
public:
    
    static bool comp(vector<int> &a, vector<int> &b){
        
        return a[0] < b[0];
    }
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(), intervals.end(), comp);
        
        vector<vector<int>> ans;
        int start=intervals[0][0], end=intervals[0][1];
        
        for(int i=0; i<intervals.size(); i++){
            
            if( intervals[i][0] >= start && intervals[i][0] <= end ){
                end = max(end, intervals[i][1]);
            }
            else
                ans.push_back({start,end}), start=intervals[i][0], end=intervals[i][1];
        }
        ans.push_back({start,end});
        return ans;
    }
};
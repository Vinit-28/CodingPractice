

// Question Link :: "https://leetcode.com/problems/remove-covered-intervals/"


// Solution //

class Solution {
public:
    
    static bool comp(vector<int> &a, vector<int> &b){
        if(a[0] < b[0]) return true;
        return (a[0] == b[0] && b[1] < a[1]);
    }
    
    bool isCovered(vector<int> &a, vector<int> &b){
        return (b[0] >= a[0] && b[1] <= a[1]);
    }
    
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        
        int ans = 0, lastMaxInterval = 0, n=intervals.size();
        
        sort(intervals.begin(), intervals.end(), comp);
        
        for(int i=0;i<n;i++){
            
            if( ! isCovered(intervals[lastMaxInterval], intervals[i]) ){
                ans += 1;
                lastMaxInterval = i;
            }
        }
        
        return ans+1;
    }
};
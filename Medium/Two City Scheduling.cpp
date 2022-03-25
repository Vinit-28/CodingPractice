

// Question Link :: "https://leetcode.com/problems/two-city-scheduling/"


// Solution //

class Solution {
public:
    
    static bool comp(vector<int> &a, vector<int> &b){
        
        return (abs(a[0]-a[1]) >= abs(b[0]-b[1]));
    }
    
    
    int twoCitySchedCost(vector<vector<int>>& costs) {
        
        int n = costs.size(), a = 0, b = 0, minCost = 0, req = n/2;
        sort(costs.begin(), costs.end(), comp);
        
        for(int i=0;i<n;i++){
            if( a==req ){
                minCost += costs[i][1];
                b += 1;
            }
            else if( b==req ){
                minCost += costs[i][0];
                a += 1;
            }
            else{
                if( costs[i][0] < costs[i][1] ) minCost += costs[i][0], a += 1;
                else minCost += costs[i][1], b += 1;
            }
        }
        return minCost;
    }
};
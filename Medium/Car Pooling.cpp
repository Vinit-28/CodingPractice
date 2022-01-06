

// Question Link :: "https://leetcode.com/problems/car-pooling/"


// Solution //

class Solution {
public:
    
    static bool compare1(vector<int>&a, vector<int> &b){
        return a[1] < b[1];
    }
    
    static bool compare2(vector<int>&a, vector<int> &b){
        return a[2] < b[2];
    }
    
    bool carPooling(vector<vector<int>>& trips, int &capacity) {
        
        vector<vector<int>> starting = trips, ending = trips;
        int remCap = capacity,i,j,n=trips.size();
        
        sort(starting.begin(), starting.end(), compare1);
        sort(ending.begin(), ending.end(), compare2);
        
        for(i=0,j=0; i<n&&j<n;){
            
            if( starting[i][0] > capacity || ending[j][0] > capacity ) return false;
            
            if( starting[i][1] < ending[j][2] ){
                if( starting[i][0] > remCap ) return false;
                remCap -= starting[i][0], i++;
            }
            else
                remCap += ending[j][0], j++;
        }
        return true;
    }
};
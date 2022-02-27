

// Question Link :: "https://leetcode.com/problems/minimum-time-to-complete-trips/"


// Solution //

class Solution {
public:
    
    bool isPossible(vector<int>& time, int &n, int trips, long long timeAvailable){
        
        for(int i=0; ( i<n && timeAvailable >= time[i] && trips>0 ); i++){
            trips -= (timeAvailable/time[i]);
        }

        return (trips>0)? false : true;
    }
    
    long long int multiply(long long int a, long long int b){
        return a*b;
    }
    
    long long int minimumTime(vector<int>& time, int totalTrips) {
        
        long long int timeTaken = 0, u = multiply(*min_element(time.begin(), time.end()), totalTrips), l=1, m=(l+u)/2;
        int n = time.size();
        sort(time.begin(), time.end());
        
        while( l<=u ){
            
            if( isPossible(time, n, totalTrips, m) ){
                timeTaken = m, u = m - 1;
            }
            else{
                l = m + 1;
            } 
            
            m = (l+u)/2;
        }
        
        return timeTaken;
    }
};
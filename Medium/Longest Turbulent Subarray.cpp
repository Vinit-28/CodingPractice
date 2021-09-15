

// Question Link :: "https://leetcode.com/problems/longest-turbulent-subarray/"


// Solution //

class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        
        int ans = 0, n = arr.size(), count;
        char sig;
        
        for(int i=0;i<n;i++){
            
            count=1, sig='S';
            for(int j=i+1;j<n;j++){
                
                if( sig=='B' && arr[j] > arr[j-1] ) count++, sig='S';
                else if( sig=='S' && arr[j] < arr[j-1] ) count++, sig='B';
                else break;
            }
            ans = max(ans, count);
            
            count=1, sig='B';
            for(int j=i+1;j<n;j++){
                
                if( sig=='B' && arr[j] > arr[j-1] ) count++, sig='S';
                else if( sig=='S' && arr[j] < arr[j-1] ) count++, sig='B';
                else break;
            }
            ans = max(ans, count);
        }
        return ans;
    }
};
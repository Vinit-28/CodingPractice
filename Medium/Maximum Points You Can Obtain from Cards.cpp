

// Question Link :: "https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/"


// Solution //

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        
        int n=cardPoints.size(), mini = INT_MAX, size = n-k;
        int prefixSum[n];
        prefixSum[0] = cardPoints[0];
        for(int i=1;i<n;i++) prefixSum[i] = prefixSum[i-1] + cardPoints[i];
        
        if( k == n ) return prefixSum[n-1];
        
        for(int i=(size-1); i<n; i++){
            
            int sum = (i == size-1)? prefixSum[i] : prefixSum[i] - prefixSum[i-size];
            mini = min(mini, sum);
        }
        return prefixSum[n-1] - mini;
    }
};
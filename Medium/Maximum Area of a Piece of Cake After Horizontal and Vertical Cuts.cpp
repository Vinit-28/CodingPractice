

// Question Link :: "https://leetcode.com/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts/"


// Solution //


class Solution {
public:
    int mod = 1000000007;
    int maxArea(int h, int w, vector<int>& hC, vector<int>& vC) {
        
        long maxi1 = INT_MIN, maxi2 = INT_MIN;
        hC.push_back(0), hC.push_back(h);
        vC.push_back(0), vC.push_back(w);
        
        sort(hC.begin(), hC.end());
        sort(vC.begin(), vC.end());
        
        for(int i=1;i<hC.size();i++){
            if( (hC[i] - hC[i-1]) > maxi1 ) maxi1 = hC[i] - hC[i-1];
        }
        for(int i=1;i<vC.size();i++){
            if( (vC[i] - vC[i-1]) > maxi2 ) maxi2 = vC[i] - vC[i-1];
        }
        return ((maxi1%mod)*(maxi2%mod)%mod);
    }
};
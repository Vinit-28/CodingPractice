

// Question Link :: "https://leetcode.com/problems/4sum-ii/"


// Solution //

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        
        unordered_map<int, int> hash1;
        int n = nums1.size(), ans=0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                hash1[nums1[i]+nums2[j]] += 1;
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                
                if( hash1.find( -(nums3[i] + nums4[j]) ) != hash1.end() )
                    ans += hash1[-(nums3[i] + nums4[j])];
            }
        }
        
        return ans;
    }
};
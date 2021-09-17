

// Question Link :: "https://leetcode.com/problems/intersection-of-two-arrays-ii/"


// Solution //

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        
        vector<int> ans;
        map<int,int> hash1, hash2;
        for(auto ele : nums1) hash1[ele]++;
        
        for(auto ele : nums2){
            hash2[ele]++;
            if( hash1[ele] >= hash2[ele] ) ans.push_back(ele);
        }
        return ans;
    }
};
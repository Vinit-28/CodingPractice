

// Question Link :: "https://leetcode.com/problems/merge-sorted-array/"


// Solution //

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        int i=m-1, j=n-1, index=(m+n)-1;
        while( index >= 0 ){
            
            if( (i>=0 && j<0) || (i>=0 && j>=0 && nums1[i] >= nums2[j]) ){
                nums1[index] = nums1[i];
                i-=1, index-=1;
            }
            else if( (j>=0 && i<0) || (j>=0 && i>=0 && nums1[i] < nums2[j]) ){
                nums1[index] = nums2[j];
                j-=1, index-=1;
            }
        }
    }
};


// Question Link :: "https://leetcode.com/problems/minimum-cost-to-move-chips-to-the-same-position/"


// Solution //

class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        
        int odd=0, even=0, n=position.size();
        for(int i=0;i<n;i++) (position[i]%2==0)? (even++) : (odd++);
        return (even>odd)? odd : even;
    }
};